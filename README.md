# Persistance
Persistance is a game for the Arduino in which you solve mazes. Persistance tests your ability to solve (or brute force) puzzles in the least number of moves. Persistance maps are hand-built to ensure a fun and entertaining experience, and to allow speedrunning to be possible.

# Hardware
Persistance is a hardware-based game (with in in-development CLI version). It requires the following things:

- Arduino Interface
- Arduino SD card shield
- Arduino Analog Joystick
- 16x16 RGB LED matrix

All the pins can be edited in `p_constants.h` if needed. By default, `p_constants.h` is configured for the Arduino Mega 2560.

A build guide is in the works.

# Building
Persistance requires the Adafruit NeoPixel library. Your SD card should be formatted with [this tool](https://www.sdcard.org/downloads/formatter_4/). Everything else should work out of the box.

# Contributing
Make a pull request if you fixed a bug or added a feature! We don't get many right now so we have no policies.

# Links
None right now
