## Arbor

> A lightweight tree-style directory visualizer written in C.

Arbor is a small command-line utility that displays directory structures in a clean tree format directly in your terminal.

Built as a learning project, Arbor focuses on simplicity, readability, and understanding low-level filesystem traversal in C.

> Arbor is not intended to replace `tree`. It's a project focused on learning systems programming and building a modern, maintainable implementation from scratch in C.

---

## Demo

![Arbor Demo](assets/demo.gif)

---

## Features

* 🌳 Recursive directory traversal
* 🔤 Alphabetically sorted entries
* 🚫 Hidden files and directories skipped by default
* ⚡ Fast and lightweight
* 🧩 Minimal dependencies
* 🐧 Designed for Unix-like systems

---

## Project Structure

```text
arbor
├── assets/
│   └── demo.gif
├── src/
│   ├── fs.c
│   ├── fs.h
│   ├── main.c
│   ├── tree.c
│   └── tree.h
├── CONTRIBUTING.md
├── LICENSE
├── Makefile
├── README.md
└── arbor
```

---

## Installation

### Build from Source

#### Requirements

* GCC or Clang
* GNU Make

#### Clone the Repository

```bash
git clone https://github.com/nilesh-padiyar/arbor.git
cd arbor
```

#### 1. Build and Run

```bash
make
./arbor
```

#### 2. Install System-Wide (Optional)

```bash
sudo make install
```

After installation:

```bash
arbor
```

can be executed from anywhere.

Uninstall:

```bash
sudo make uninstall
```

---

## Motivation

Arbor started as a personal project to learn:

* Recursive algorithms
* Filesystem traversal using `dirent.h`
* Terminal rendering techniques
* Modular C project structure
* Building Unix-style command-line tools
* Standard C code with `-std=c11`

Rather than relying on existing libraries, the goal is to understand how tree-style file explorers work internally.

---

## Current Status

Arbor is currently in **v0.3.0** and under active development.

The project is functional but still evolving as new features and improvements are added.

---

## Philosophy

Arbor aims to stay:

* Simple
* Fast
* Easy to understand
* Dependency-light

The codebase is intentionally kept approachable so that developers learning C can explore and understand how the tool works.

---

## Author

[Nilesh Padiyar](https://github.com/nilesh-padiyar)

---
