# Requirements
### espeak-ng
You may be able to install this via package manager, but I built the shared lib from source

[espeak-ng](https://github.com/espeak-ng/espeak-ng)

```
sudo apt-get install espeak-ng-espeak 
```

Not sure on the diff, but espeak (no -ng) was available for cygwin package management.

Using it required removing -ng from the link in the g++ command and include in speechsynth.h

When I use it on linux, it has some noise about my sound card printed to stdout/err, but other than that seems to work fine

```
sudo apt-get install libespeak-dev
```

### ncurses

```
sudo apt-get install libncurses5-dev
```

## Install
using makefile for now

`make && ./bin/app`

or

`make && gdb bin/app`
