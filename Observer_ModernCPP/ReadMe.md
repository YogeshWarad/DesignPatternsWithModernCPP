
# 🧩 Observer Pattern in C++

## 📘 Overview

This project demonstrates the **Observer Design Pattern** implemented using **modern C++ (C++11/14/17)**.  
The Observer Pattern defines a **one-to-many dependency** between objects so that when one object (the *Subject*) changes its state, all its dependent objects (*Observers*) are automatically notified and updated.

---

## 🎯 Features

- Implementation of the **Observer Pattern** using **OOP principles**.
- Uses **`std::shared_ptr`** and **`std::weak_ptr`** to manage object lifetimes safely.
- Clean separation between **Subject** and **Observer** interfaces.
- Demonstrates **dynamic attach/detach** of observers at runtime.
- Written in **modern C++**, compatible with **C++11, C++14, and C++17**.

---

## 🧱 Design Overview

### Classes and Responsibilities

| Class | Role | Description |
|-------|------|-------------|
| `Subject` | Interface | Declares methods for attaching, detaching, and notifying observers. |
| `Observer` | Interface | Declares the `update()` method for receiving notifications. |
| `ConcreteSubject` | Implementation of `Subject` | Maintains observer list and notifies them of state changes. |
| `ConcreteObserver` | Implementation of `Observer` | Receives updates from the subject and reacts to them. |

---

## ⚙️ Example Code Flow

1. **Observers subscribe** to the subject.
2. The **subject updates its state** and calls `notify()`.
3. Each attached **observer’s `update()` method** is invoked.
4. Observers can **unsubscribe** anytime.

---

## 🧩 Example Output

````

---

## 🛠️ Build Instructions

### 🔧 Prerequisites
- **C++ compiler** supporting at least C++11  

- **CMake**

### 💻 Compile and Run (using `g++`)

```bash
g++ -std=c++17 -pthread main.cpp -o observer_demo
./observer_demo
````

### 🧰 Using CMake (optional)

```bash
mkdir build && cd build
cmake ..
make
./observer_demo
```

---

## 🧠 Key Learnings

* Decoupling publishers (subjects) and subscribers (observers).
* Using `std::weak_ptr` to avoid circular references.
* Dynamic registration/deregistration of observers.
* Event-driven communication between objects.

---

## 🚀 Possible Extensions

* Make the notification **asynchronous** using `std::thread` or `std::async`.
* Use **templated subjects** to send typed events.
* Add **thread-safety** using `std::mutex` if used in a concurrent environment.
* Extend to a **real-world example** (e.g., chat app notifications, stock price updates).

---

## 📄 License

This project is open-source and available under the **MIT License**.
Feel free to use and modify it for your own learning or applications.

---

## 👨‍💻 Yogesh Warad
C++ Developer | Principle Software Engineer | Tech Enthusiast


---

⭐ *If you find this project useful, consider giving it a star on GitHub!* ⭐  
