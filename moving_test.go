package main

import (
	"testing"
	"time"
)

func TestChann(t *testing.T) {
	samp := make(chan []byte)

	m := newMoving(samp)
	go m.watch()
	go func() {
		for {
			<-m.changes
		}
	}()

	samp <- []byte{0, 0, 0, 0}
	time.Sleep(time.Second * 2)
	samp <- []byte{2, 2, 2, 2}
	time.Sleep(time.Second * 2)
	samp <- []byte{0, 0, 0, 0}
	time.Sleep(time.Second * 2)

	close(samp)
}
