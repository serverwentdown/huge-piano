package main

import (
	"encoding/csv"
	"log"
	"os"
	"strconv"
)

type keymap struct {
	changes chan stateFlip
	mapped  map[int]int
	play    chan int
}

func (k *keymap) load(file string) {
	f, err := os.Open(file)
	if err != nil {
		panic(err)
	}

	r := csv.NewReader(f)
	mapping, err := r.ReadAll()
	if err != nil {
		panic(err)
	}

	k.mapped = make(map[int]int)
	for _, m := range mapping {
		key, err := strconv.Atoi(m[0])
		if err != nil {
			panic(err)
		}
		value, err := strconv.Atoi(m[1])
		if err != nil {
			panic(err)
		}
		k.mapped[key] = value
	}
}

func (k *keymap) lookup(key stateFlip) int {
	value, has := k.mapped[key.i]
	if !has {
		log.Printf("key %d not found", key.i)
		return -1
	}
	return value
}

func (k *keymap) watch() {
	log.Println("Awaiting stateFlips...")
	for key := range k.changes {
		play := k.lookup(key)
		if play >= 0 {
			log.Println(play)
			k.play <- play
			log.Println("change read")
		}
	}
	log.Println("No more stateFlips")
}

func newKeymap(changes chan stateFlip, mapFile string) *keymap {
	k := &keymap{
		changes: changes,
		play:    make(chan int),
	}
	k.load(mapFile)
	return k
}
