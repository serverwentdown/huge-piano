package main

import (
	"io/ioutil"
	"os"
	"sort"
	"time"

	"github.com/faiface/beep"
	"github.com/faiface/beep/speaker"
	"github.com/faiface/beep/wav"
)

type audio struct {
	play       chan int
	packDir    string
	sampleRate beep.SampleRate
	pack       []beep.Streamer
}

func (a audio) load() {
	a.loadStreamers()
	a.initSpeaker()
}

func (a audio) initSpeaker() {
	speaker.Init(a.sampleRate, a.sampleRate.N(time.Second/60))
}

func (a audio) loadStreamers() {
	files, err := ioutil.ReadDir(a.packDir)
	if err != nil {
		panic(err)
	}

	sort.Sort(byFileInfoName(files))

	for _, file := range files {
		if file.Name()[0] == '.' {
			continue
		}
		a.loadStreamer(file.Name())
	}
}

func (a audio) loadStreamer(fn string) {
	f, err := os.Open(fn)
	if err != nil {
		panic(err)
	}
	s, format, err := wav.Decode(f)
	if err != nil {
		panic(err)
	}
	a.pack = append(a.pack, s)
	a.sampleRate = format.SampleRate
}

func (a audio) playSample(i int) {
	speaker.Play(a.pack[i])
}

func (a audio) watch() {
	for play, ready := <-a.play; ready; {
		a.playSample(play)
	}
}

func newAudio(play chan int, packDir string) audio {
	a := audio{
		play:    play,
		packDir: packDir,
	}
	a.load()
	return a
}

type byFileInfoName []os.FileInfo

func (f byFileInfoName) Len() int {
	return len(f)
}
func (f byFileInfoName) Swap(i, j int) {
	f[i], f[j] = f[j], f[i]
}
func (f byFileInfoName) Less(i, j int) bool {
	return f[i].Name() < f[j].Name()
}
