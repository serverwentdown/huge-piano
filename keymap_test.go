package main

import (
	"log"
	"testing"
)

func TestLookup(t *testing.T) {
	sf := make(chan stateFlip)

	k := newKeymap(sf, "2489__jobro__piano-ff/map.csv")
	go k.watch()
	go func() {
		for play := range k.play {
			log.Println("new change!")
			log.Println(play)
		}
	}()

	sf <- stateFlip{0, true, 0, 0}
	sf <- stateFlip{1, true, 0, 0}
	sf <- stateFlip{2, true, 0, 0}
	sf <- stateFlip{3, true, 0, 0}
	sf <- stateFlip{4, true, 0, 0}

	close(sf)
}
