# Hacker Authentication & Password Cracker

## Overview
This repository contains two C++ programs:

1. **Hacker Authentication System** – A user authentication system that securely stores user credentials with hashing (MD5) and unique salts.
2. **Password Cracker** – A tool that attempts to crack password hashes by checking them against a pre-generated list of hashed passwords.

Both programs are designed with a **hacker aesthetic**, including animations, a typewriter effect, and a green text interface.

---

## 🚀 How to Set Up & Run

### 1️⃣ Install Dependencies
Ensure you have the required dependencies installed:
- **OpenSSL** (for hashing functions)
- **g++ compiler** (MinGW for Windows, or GCC for Linux/macOS)

For Windows (MSYS2):
```sh
pacman -S mingw-w64-x86_64-openssl
```
For Linux/macOS:
```sh
sudo apt install libssl-dev
```

### 2️⃣ Clone the Repository
```sh
git clone https://github.com/YOUR-REPO-NAME.git
cd YOUR-REPO-NAME
```

### 3️⃣ Compile the Programs
#### **Hacker Authentication System:**
```sh
g++ hacker_auth_cpp.cpp -o hacker_auth.exe -I"C:/msys64/mingw64/include" -L"C:/msys64/mingw64/lib" -lssl -lcrypto
```

#### **Password Cracker:**
```sh
g++ password_cracker.cpp -o password_cracker.exe -I"C:/msys64/mingw64/include" -L"C:/msys64/mingw64/lib" -lssl -lcrypto
```

### 4️⃣ Run the Programs
#### **Run the Authentication System:**
```sh
./hacker_auth.exe
```
#### **Run the Password Cracker:**
```sh
./password_cracker.exe
```

---

## 🛠 Hacker Authentication System (Features)
- **Create User** (Email + Secure Password Storage)
- **Test Login** (Checks credentials from `users.txt`)
- **Enforces strong password rules**
- **Uses MD5 hashing with a unique salt for each user**
- **Hacker-style animations and interface**

### 🔹 How It Works:
1. Enter **email & password** when creating a user.
2. The program generates a **unique salt**, hashes the password (MD5 + Salt), and stores it in `users.txt`.
3. On login, the program retrieves the salt, hashes the input password, and checks for a match.

### 📄 Users File Format (`users.txt`)
```
email@example.com:randomsalt:hashedpassword
admin@site.com:a1b2c3d4e5f6g7h8:098f6bcd4621d373cade4e832627b4f6
```

---

## 🔓 Password Cracker (Features)
- Loads common passwords from `hashes.txt`.
- Supports **MD5 and SHA256 hash lookup**.
- Allows the user to enter a **hash** and check if it exists in the pre-generated dictionary.
- Displays the **plaintext password** if found.

### 📄 Hashes File Format (`hashes.txt`)
```
password:5f4dcc3b5aa765d61d8327deb882cf99:e99a18c428cb38d5f260853678922e03
123456:25d55ad283aa400af464c76d713c07ad:e10adc3949ba59abbe56e057f20f883e
```

### 🔹 How It Works:
1. The user enters a hash (MD5/SHA256).
2. The program checks `hashes.txt` for a match.
3. If found, it displays the original password; otherwise, it informs the user that no match was found.

---

## 📌 Additional Notes
✅ **Ensure `users.txt` and `hashes.txt` exist** before running the programs.  
✅ **Extend `hashes.txt`** with more passwords for better cracking success.  
✅ **Use CrackStation.net** to generate test hashes for verification.  
✅ **Modify animation effects** for a cooler hacker aesthetic! 😈

---

## 👨‍💻 Contributors
- **NotBlonde**

---

## 📩 Contact
For issues or improvements, feel free to open a pull request or email me!
