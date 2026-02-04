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

The JavaScript adaptation is currently in early demo stage (`index.html`) and does not yet implement the full anagram game logic from the C++ version.

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
