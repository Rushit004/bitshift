

# Number System Toolkit

## Overview

**Number System Toolkit** is a menu-driven console application built in **C** that combines a **Number Base Converter** and **Multi-Base Calculator**.

It supports:

* Binary (Base 2)
* Octal (Base 8)
* Decimal (Base 10)
* Hexadecimal (Base 16)

This project demonstrates core C programming concepts, modular coding structure, and number system logic.

***

## Features

### Number Converter

Convert numbers between:

* Binary ↔ Decimal
* Decimal ↔ Octal
* Decimal ↔ Hexadecimal
* And other supported combinations

Supports:

* Integer values
* Fractional values
* Negative numbers

### Calculator

Perform arithmetic operations in selected number systems:

* Addition
* Subtraction
* Multiplication
* Division

***

## Folder Structure

```bash
Number_System_Toolkit/
├── include/          
│   ├── calculator.h
│   └── converter.h
├── src/               
│   ├── main.c
│   ├── calculator.c
│   └── converter.c
├── screenshots/      
├── docs/             
└── README.md
```

***

## Project Screenshots

View all screenshots : [screenshots/](screenshots/)

***

## How to Run

1.  **Compile the project:**

    ```bash
    gcc src/main.c src/calculator.c src/converter.c -Iinclude -o toolkit
    ```
2.  **Execute the application:**

    ```bash
    ./toolkit
    ```

***

## Concepts Applied

* **Modular Programming:** Separation of concerns using `.h` and `.c` files.
* **Data Structures:** Heavy use of **Arrays & Strings** for base representation.
* **Logic:** Implementation of iterative and recursive algorithms for base conversion.
* **Control Flow:** Robust menu navigation using nested loops and conditional statements.

***

## About the author

Rushit Tholiya — 2nd year B.Tech (Computer Science) at Nirma University, Ahmedabad

Currently building skills in data analysis and preparing for a career in **data science / data analytics**.

* [LinkedIn](https://linkedin.com/in/rushit-tholiya-605341311)
* [GitHub profile](https://github.com/Rushit004)

***
