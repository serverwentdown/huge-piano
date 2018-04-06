package main

import (
	"testing"
	"time"
)

func TestPlay(t *testing.T) {
	m := make(chan int)

	audio := newAudio(m, "2489__jobro__piano-ff")
	go audio.watch()

	m <- 1
	time.Sleep(time.Second * 2)
	m <- 2
	time.Sleep(time.Second * 2)
	m <- 2
	time.Sleep(time.Second * 2)
}
