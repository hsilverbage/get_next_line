# 📄 get_next_line – 42 Project

`get_next_line` is a project from the École 42 common core.  
The goal is to implement a function that reads and returns one line at a time from a file descriptor, handling memory, buffers, and edge cases like a pro. 🧠

---

## 🧩 Project Objectives

- Master file I/O in C (`read`, `open`, `close`)
- Handle **buffers**, **memory allocation**, and **string manipulation**
- Build a function that returns a line with each call, including:
  - Lines with/without `\n`
  - Empty lines
  - Very long lines
- Manage **multiple file descriptors** at once

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

Reads from the file descriptor `fd` and returns the next line each time it’s called.  
Returns `NULL` when there’s nothing left to read or an error occurs.

---

## 📁 Project Files

```
get_next_line/
├── get_next_line.c         # Core logic
├── get_next_line_utils.c   # String manipulation helpers
├── get_next_line.h         # Function prototypes and macros
├── main.c                  # Optional test file
├── Makefile                # Build system
```

---

## 🧪 How to Use

### ✅ Compile:

```bash
make
```

### 🚀 Test:

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## ⚙️ BUFFER_SIZE

You can define `BUFFER_SIZE` at compile time:

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Or inside `get_next_line.h`:

```c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
```

---


## 📚 Resources

- [`man 2 read`](https://man7.org/linux/man-pages/man2/read.2.html)
- [`man 3 malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [42 Subject PDF / Peer feedback]

---

## 👤 Author

**42 Login**: hsilverb  
**Contact**: [LinkedIn](https://www.linkedin.com/in/henrik-silverbage/)

---

## 📝 License

This project was developed as part of the 42 School curriculum.  
For educational and personal use only.
