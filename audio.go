package main

import (
	"io/ioutil"
	"log"
	"os"
	"path"
	"sort"
	"strings"
	"time"

	"github.com/faiface/beep"
	"github.com/faiface/beep/speaker"
	"github.com/faiface/beep/wav"
)

type audio struct {
	play       chan int
	packDir    string
	sampleRate beep.SampleRate
	pack       []beep.StreamSeeker
}

func (a *audio) load() {
	a.loadStreamers()
	a.initSpeaker()
}

func (a *audio) initSpeaker() {
	speaker.Init(a.sampleRate, a.sampleRate.N(time.Second/10))
}

func (a *audio) loadStreamers() {
	files, err := ioutil.ReadDir(a.packDir)
	if err != nil {
		panic(err)
	}

	sort.Sort(byFileInfoName(files))

	for _, file := range files {
		if !strings.HasSuffix(file.Name(), ".wav") {
			continue
		}

		a.loadStreamer(path.Join(a.packDir, file.Name()))
	}
}

func (a *audio) loadStreamer(fn string) {
	log.Printf("Loading file %d: %s", len(a.pack), fn)
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

func (a *audio) playSample(i int) {
	a.pack[i].Seek(0)
	speaker.Play(a.pack[i])
}

func (a *audio) watch() {
	log.Println("Awaiting for audio...")
	for play := range a.play {
		a.playSample(play)
	}
	log.Println("No more incoming audio")
}

func newAudio(play chan int, packDir string) *audio {
	a := &audio{
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
