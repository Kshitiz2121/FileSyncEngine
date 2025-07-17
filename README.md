# In-Memory File Sync Engine 🗂️

This project is a Git-style file synchronizer built in C that performs:
- Line-by-line diff with ANSI coloring
- 3-way merge conflict resolution
- File version tracking using stat()
- Modular architecture with separate components

## 📂 Features
- Built using standard C (C11)
- Manual 3-way merge: `base.txt`, `version1.txt`, `version2.txt`
- Highlighted terminal diff with `+`, `-`, and `~`
- Custom memory management (no external libraries)

## 🔧 Compile and Run

```bash
make           # Builds the project
make run       # Runs it using default inputs
make clean     # Removes binaries
