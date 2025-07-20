# 🏨 Hotel Management System in C++

## 📌 Introduction

Managing a hotel effectively is key to ensuring great customer service and smooth business operations. The **Hotel Management System in C++** is a console-based application designed to handle essential hotel functions such as:

- Room booking  
- Customer information maintenance  
- Room allotment and overview  
- Customer checkout  
- Restaurant service management  

This system uses standard input/output streams to provide a simple, user-friendly command-line interface suitable for hotel staff.

---

## 📋 Project Overview

The system allows hotel staff to perform daily operations efficiently, ensuring a smooth workflow and excellent guest experience.

---

## ✅ Key Features

### 🛏️ Room Booking
Staff can book rooms by entering customer details:
- Name  
- Address  
- Phone number  
- Number of days  

Room categories:
- Deluxe  
- Executive  
- Presidential  

### 👤 Customer Information Management
Maintains a detailed customer database for quick retrieval and updates.

### 📊 Room Allocation Overview
Displays a tabular view of allocated rooms showing:
- Room number  
- Guest name  
- Address  
- Room type  
- Contact number  

### ✏️ Edit Customer Details
Modify existing data like:
- Name  
- Phone number  
- Address  
- Duration of stay  

### 🍽️ Restaurant Service Management
Customers can order:
- Breakfast  
- Lunch  
- Dinner  

Charges are added to their final bill.

### 🖥️ Console-Based Interface
Runs on terminal/command prompt. Lightweight and platform-independent with minimal system requirements.

---

## ⚙️ Technical Details

Built using standard C++ libraries only — no external dependencies required. It compiles and runs in any standard C++ environment.

---

## 🛠️ Tools & Requirements

### 🧰 C++ Compiler
- GCC (MinGW for Windows)  
- Any modern C++ compiler

### 📚 Standard C++ Libraries Used
- `iostream`  
- `fstream`  
- `stdio.h`  
- `string.h` / `cstring`  
- `iomanip`  

These libraries support:
- File handling  
- Console I/O  
- String operations  
- Output formatting  

---

## 🖥️ Installation & Execution (Windows)

### 🔧 Step 1: Install MinGW
- Download from [https://osdn.net/projects/mingw/](https://osdn.net/projects/mingw/)
- During installation, choose the `g++` component

### 🔧 Step 2: Configure Environment Variables
- Add `C:\MinGW\bin` to your system's PATH

### 🔧 Step 3: Compile the Program
g++ hotel.cpp -o hotel

---

## 🔍 System Architecture

### 📁 File Handling

The system uses binary files to store and retrieve customer records persistently. All customer-related operations interact with a file named `Record.DAT`. The key functions that manage this file are:

- `add()` – Adds a new customer record
- `display()` – Displays current records
- `modify()` – Edits existing records
- `delete_rec()` – Deletes a specific customer record

This ensures data persistence even after the application is closed.

### 🧑‍💻 User Interaction

The `main_menu()` function serves as the central hub for user interaction. It presents a structured menu with various options like booking rooms, managing customer details, restaurant service, and checkout. Based on the user's input, it redirects to the appropriate function, ensuring a seamless and logical workflow throughout the system.

## 💡 Future Enhancements

- GUI version using Qt or C++ WinForms  
- Room availability calendar  
- Admin authentication system  
- Online reservation support  
- PDF invoice generation  

