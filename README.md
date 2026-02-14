# 🛡 Advanced Log-Based Intrusion Detection System (C++)

## About This Project

This project is a log-based Intrusion Detection System (IDS) built using C++.

It analyzes authentication/system log files and detects suspicious activities such as repeated failed login attempts, unauthorized access, and potentially dangerous command execution.

Instead of manually scanning long log files, this program automates the detection process and generates alerts when something unusual is found.

The goal of this project was to understand how security monitoring systems work at a conceptual level and to apply core C++ programming skills to a real-world cybersecurity problem.

---

## 🔍 What It Does

- Reads a log file (`logs.txt`)
- Processes it line by line
- Detects suspicious patterns using rule-based logic
- Tracks failed login attempts per IP address
- Triggers alerts when defined thresholds are exceeded
- Displays a structured threat report

---

## 🚀 Key Features

- Signature-based detection
- IP-based brute-force tracking using `std::map`
- Configurable threshold for attack detection
- Modular and readable code structure
- Structured alert reporting system

---

## 🧠 How It Works 

1. **Log Loading**  
   The program opens and reads the log file using C++ file streams.

2. **Parsing Engine**  
   Each line is analyzed for suspicious keywords.

3. **State Tracking**  
   Failed login attempts are counted per IP address.

4. **Detection Logic**  
   If attempts exceed the defined threshold, an alert is generated.

5. **Reporting**  
   All detected threats are displayed in a clean summary format.

---

## 🛠 Technologies Used

- C++
- STL (`map`, `vector`, `string`)
- File I/O (`ifstream`)
- String pattern matching

---

## ▶️ How to Run

### Compile:
```bash
g++ PROJECT.cpp -o ids
