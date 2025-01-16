## Message Manipulator: A Hybrid C and Assembly Encryption/Decryption Tool

The **Message Manipulator** project showcases the integration of C programming and x86_64 assembly language for string manipulation, encryption, and decryption. This project demonstrates proficiency in interfacing high-level and low-level programming languages, focusing on dynamic memory allocation, encryption techniques, and performance optimization.

---

### **Table of Contents**
1. [Overview](#overview)
2. [Tools and Technologies](#tools-and-technologies)
3. [Features](#features)
4. [System Workflow](#system-workflow)
    - [Menu Options](#1-menu-options)
    - [Caesar Cipher Encryption](#2-caesar-cipher-encryption)
    - [Frequency Analysis Decryption](#3-frequency-analysis-decryption)
5. [Future Improvements](#future-improvements)
6. [Conclusion](#conclusion)

---

### **Overview**
The Message Manipulator provides a menu-driven interface for users to manage and manipulate text messages. The system integrates:
- High-level C programming for user interaction and data management.
- Low-level assembly programming for optimized encryption (Caesar cipher).

This project highlights the ability to bridge C and assembly for efficient and secure operations.

---

### **Tools and Technologies**
- **C Language**: Core program logic and data handling.
- **x86_64 Assembly**: Implementation of the Caesar cipher for optimized encryption.
- **Makefile**: Automated build system for compilation.

---

### **Features**
1. **Menu-Driven User Interface**:
   - Intuitive menu system to navigate between functionalities.
   - Options include message display, input, encryption, and decryption.

2. **Caesar Cipher Encryption**:
   - Secure message encryption using a shift-based Caesar cipher algorithm.
   - Optimized using x86_64 assembly for performance.

3. **Frequency Analysis Decryption**:
   - Decrypts messages using frequency analysis of letter occurrences.
   - Displays possible decryption results for manual evaluation.

4. **Dynamic Message Storage**:
   - Manages up to 10 messages using a circular buffer system.
   - Supports message validation (capitalization, punctuation checks).

---

### **System Workflow**

#### **1. Menu Options**
- Users are presented with a menu to choose the desired functionality:
  - `S`: Display all current messages.
  - `R`: Read and store a new message.
  - `C`: Encrypt a message using the Caesar cipher.
  - `F`: Decrypt a message using frequency analysis.
  - `Q`: Quit the program.

#### **2. Caesar Cipher Encryption**
- Users input a shift value and select a message to encrypt.
- The x86_64 assembly function (`encrypt_caesar`) processes the message:
  - Non-alphabetic characters are ignored.
  - Uppercase and lowercase letters are shifted separately.
- Encrypted messages are displayed and stored for future use.

#### **3. Frequency Analysis Decryption**
- Analyzes the letter frequencies in a selected message.
- Identifies the top five most frequent letters and attempts decryption using these as possible `E` alignments.
- Displays the resulting decrypted messages for manual selection.

---

### **Future Improvements**
1. **Enhanced Encryption Options**:
   - Add support for advanced ciphers like Vigenère or RSA.

2. **Improved Decryption Logic**:
   - Automate the ranking of possible decryptions based on language heuristics.

3. **Expanded Message Capacity**:
   - Increase the number of storable messages with dynamic memory allocation.

4. **Error Handling**:
   - Add robust error handling for invalid inputs and edge cases.

---

### **Conclusion**
The Message Manipulator demonstrates the ability to combine high-level programming with low-level optimization for secure and efficient data manipulation. This project emphasizes the importance of performance, security, and usability in software development while showcasing the integration of C and assembly language.

