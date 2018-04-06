package main

import (
	"bufio"
	"fmt"
	"log"

	"github.com/goburrow/serial"
)

type port struct {
	*serial.Config
	samp chan []byte
}

func (p *port) watch() {
	log.Println("Opening serial port...")
	port, err := serial.Open(p.Config)
	if err != nil {
		panic(err)
	}
	defer port.Close()

	buf := bufio.NewReader(port)

	for {
		f, err := buf.ReadBytes(0xff)
		if err != nil {
			panic(err)
		}

		if len(f) < 9*8 {
			continue
		}

		fmt.Print(".")
		p.samp <- f
	}
}

func newPort(addr string) *port {
	return &port{
		Config: &serial.Config{
			Address:  addr,
			BaudRate: 115200,
			//BaudRate: 1000000,
			Parity: "N",
		},
		samp: make(chan []byte),
	}
}
