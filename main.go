package main

import (
	"flag"
	"log"
)

var sp string
var pack string
var mapFile string

func main() {
	flag.StringVar(&sp, "serial", "", "connect serial port")
	flag.StringVar(&pack, "pack", "", "specify audio pack folder")
	flag.StringVar(&mapFile, "mapfile", "", "specify mapfile")
	flag.Parse()

	p := newPort(sp)
	ma := newMoving(p.samp)
	ch := chanLogger(ma.changes)
	go func() {
		for {
			<-ch
		}
	}()
	/*
		mapped := newKeymap(ch, mapFile)
		audio := newAudio(mapped.play, pack)

		go audio.watch()
		go mapped.watch()
	*/
	go ma.watch()
	p.watch()
}

func chanLogger(in chan stateFlip) chan stateFlip {
	out := make(chan stateFlip)
	go func() {
		for {
			sf := <-in
			log.Print(sf)
			out <- sf
		}
	}()
	return out
}
