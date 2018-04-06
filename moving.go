package main

import "log"

type moving struct {
	samp    chan []byte
	slowAvg []float64
	fastAvg []float64
	state   []bool
	changes chan stateFlip
}

type stateFlip struct {
	i       int
	lowHigh bool
	slow    float64
	fast    float64
}

func (m *moving) watch() {
	log.Println("Watching for samples...")
	for samp := range m.samp {
		for len(m.slowAvg) < len(samp) {
			i := len(m.slowAvg)
			m.slowAvg = append(m.slowAvg, float64(samp[i]))
			m.fastAvg = append(m.fastAvg, float64(samp[i]))
			m.state = append(m.state, true)
		}

		for i, s := range samp {
			if s == 0 {
				continue
			}
			m.slowAvg[i] += (m.slowAvg[i] - float64(s)) * 0.001
			m.fastAvg[i] += (m.fastAvg[i] - float64(s)) * 0.3

			// TODO: possible exception for 220kOhm resistors
			if m.slowAvg[i] < m.fastAvg[i]+1 {
				if !m.state[i] {
					log.Print("p")
					m.changes <- stateFlip{i, true, m.slowAvg[i], m.fastAvg[i]}
				}
				m.state[i] = true
			}
			if m.slowAvg[i] > m.fastAvg[i]-1 {
				if m.state[i] {
					log.Print("r")
					m.changes <- stateFlip{i, false, m.slowAvg[i], m.fastAvg[i]}
				}
				m.state[i] = false
			}
		}
	}
	log.Println("No more samples")
}

func newMoving(samp chan []byte) *moving {
	return &moving{
		samp:    samp,
		changes: make(chan stateFlip),
	}
}
