# 💻 Computer Engineering Labs

> A central repository documenting my journey through **Algorithms**, **Data Structures**, and **Object-Oriented Programming (OOP)**.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

## 📖 About

This repository serves as a portfolio of my academic exercises and labs developed during my **Computer Engineering** studies (UFSC). It showcases the progression from low-level memory management and procedural programming in **C** to complex software architecture and abstractions using **Modern C++**.

The goal is to demonstrate a solid understanding of computer science fundamentals, efficient coding practices, and software design patterns.

## 📂 Repository Structure

The projects are organized by language and specific topics:

### 🚀 C Programming (Fundamentals)
Focus on memory management, pointers, and manual data structure implementation.

| Project / File | Key Concepts |
| :--- | :--- |
| **Employee Manager** | `structs`, Linked Lists, CRUD operations. |
| **Binary Persistence** | Handling `.bin` files, `fwrite`/`fread`, data serialization. |
| **Dynamic Matrices** | Pointer arithmetic, `malloc`/`free`, flattened 2D arrays. |
| **Prime Indices** | Dynamic arrays, mathematical algorithms, optimization. |
| **Multi-Export Registry** | Generating HTML/CSV reports from C code, multiple file formats. |

### 🚀 C++ Programming (OOP & Modern Features)
Focus on abstraction, inheritance, polymorphism, and STL.

| Project / Folder | Key Concepts |
| :--- | :--- |
| **CPU Scheduler Policies** | **Polymorphism**, Strategy Pattern, FIFO/LIFO logic. |
| **Banking System** | Operator Overloading (`>>`, `+=`), Class relationships. |
| **Substitution Cipher** | `std::vector`, Cryptography logic, ASCII manipulation. |
| **Vehicle Inheritance** | Class Hierarchy, Virtual Methods, Inheritance. |
| **Geometry Composition** | Object Composition, Setters/Getters, modular design. |
| **Polymorphic Web Cards** | Abstract Base Classes, Virtual Destructors, `std::vector` of pointers. |

## 🛠️ Technologies & Tools

* **Languages:** C (C99), C++ (C++11/14/17)
* **Compilers:** GCC / G++ / Clang
* **Concepts:**
    * **Data Structures:** Linked Lists, Vectors, Arrays, Matrices.
    * **Memory:** Stack vs Heap, Pointers, References, Memory Leaks prevention.
    * **OOP:** Encapsulation, Inheritance, Polymorphism, Abstraction.
    * **I/O:** File streams, Serialization, CLI interfaces.

## ⚙️ How to Compile & Run

Since this is a monorepo, each folder or file is independent. You can compile them individually using `g++` or `gcc`.

**Example: Compiling the CPU Scheduler (C++)**
```bash
cd C++/CPU-scheduler-policies
g++ main.cpp -o scheduler
./scheduler
