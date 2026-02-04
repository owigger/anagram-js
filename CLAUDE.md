# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a JavaScript/HTML adaptation of a C++ anagram game originally written in 2010. The project creates anagrams interactively without a thesaurus, relying on the user's brain as the associative machine.

## Project Structure

- `anagramm.cpp` - Original C++ implementation using ncurses (reference implementation)
- `index.html` - Current demo page (static single-file HTML)
- `assets/` - Static assets (logo.png, favicon.ico)

## Architecture

The original C++ implementation (`anagramm.cpp`) provides the game logic reference:
- Takes a string as input
- Displays available letters (randomly shuffled after each selection)
- User selects letters to build an anagram
- Commands: C=clear, Q=quit, S=store to file

The JavaScript adaptation (`index.html`) now implements the core anagram game logic with the following features:

### Input Processing
- Input strings are converted to lowercase and filtered to letters only (a-z)
- Special characters, spaces, and digits are removed
- Original input is preserved for display in saved anagrams

### Game Controls
- **Uppercase C** - Clear current anagram and reset to full letter pool
- **Uppercase S** - Save current anagram to the saved list
- **Uppercase Q** - Quit to start screen
- **Space** - Manually shuffle remaining letters
- **Lowercase letters (a-z)** - Build anagram by selecting from available letters

### Key Implementation Details
- Case-sensitive input: uppercase keys are commands, lowercase letters build anagrams
- No collision between command keys (C/S/Q) and anagram letters (c/s/q)
- Letters are NOT auto-shuffled after each selection (only on manual Space press)
- Saved anagrams display with timestamp and original input string

## Development

This is a static HTML project with no build system, package manager, or dependencies. Open `index.html` directly in a browser to view/test.

The C++ reference can be compiled with:
```bash
g++ anagramm.cpp -o anagramm -lncurses
```

Run with:
```bash
./anagramm "your string here"
```
