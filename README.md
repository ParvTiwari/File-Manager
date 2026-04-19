# 📁 File Manager

A simple **command-line File Manager** built in C using low-level Unix system calls. This project demonstrates how basic file operations work internally without relying on high-level libraries.

---

## 🚀 Features

### 📄 Copy File (`mycp`)
Copy contents from one file to another using system calls like `open()`, `read()`, and `write()`.

### 🔗 Merge Files (`mergefiles`)
Append the contents of one file into another file.

### 📊 File Information (`mystat`)
Display metadata of a file:
- File Size  
- Inode Number  
- File Permissions  

### 📖 View File Content (`mycat`)
Display file contents directly in the terminal (similar to the `cat` command).

### 🔢 Word & Character Count (`mycount`)
Count:
- Number of characters  
- Number of words  

---

## 🛠️ Tech Stack

- **Language:** C  
- **Concepts Used:**  
  - File Handling  
  - System Calls  
  - Buffer I/O  

- **System Calls:**  
  - `open()`  
  - `read()`  
  - `write()`  
  - `close()`  
  - `stat()`  

---

## 💡 Learning Objectives

- Understand low-level file operations in C  
- Learn how Unix file system calls work  
- Build basic versions of common Unix utilities  
- Practice efficient file handling using buffers  

---

## ▶️ How to Run

```bash
gcc file_manager.c -o file_manager
./file_manager

```

---

## 📌 Menu Options
1. Copying a file to another file
2. Merging of file f2 with file f1
3. Display info of a file
4. Display contents of a file
5. Counting number of words & characters in a file
6. Exit
