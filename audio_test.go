package main

import (
	"testing"
	"time"
)

func TestPlay(t *testing.T) {
	p := make(chan int)

	audio := newAudio(p, "2489__jobro__piano-ff")
	go audio.watch()

	p <- 1
	time.Sleep(time.Second * 1)
	p <- 2
	time.Sleep(time.Second * 1)
	p <- 1
	p <- 2
	time.Sleep(time.Second * 1)

	close(p)
}
