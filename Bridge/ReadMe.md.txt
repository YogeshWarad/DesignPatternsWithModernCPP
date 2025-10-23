# 🎯 Design Patterns with Modern C++

## 🧩 Overview

This repository — **DesignPatternWithModernCPP** — demonstrates how to implement classic **Object-Oriented Design Patterns** using **modern C++ (C++11/14/17)** features.  
Each pattern focuses on **clean architecture**, **memory safety**, and **maintainability**, leveraging modern concepts such as `std::shared_ptr`, `std::unique_ptr`, `std::thread`, and `std::condition_variable`.

---

## 🧠 Purpose

Design patterns provide **proven solutions** to common software engineering problems.  
This project helps you:
- Understand **core design principles** behind patterns.
- Learn how to apply **C++11/14/17 idioms** effectively.
- See how **smart pointers**, **RAII**, and **modern syntax** simplify classical patterns.

---

## 📁 Project Structure

```

DesignPatternWithModernCPP/
│
├── ObserverPattern/
│   ├── main.cpp
│   └── README.md
│
├── BridgePattern/
│   ├── main.cpp
│   └── README.md
│
└── (more patterns coming soon...)

````

Each subfolder contains:
- `main.cpp` → Fully working example.  
- `README.md` → Explanation, UML diagram (optional), build/run instructions, and key insights.

---

## 🧩 Implemented Patterns

### 1️⃣ [Observer Pattern](ObserverPattern/)
**Category:** Behavioral  
**Concept:** Defines a one-to-many dependency so when one object changes state, all dependents are notified automatically.  
**Highlights:**
- Uses `std::shared_ptr` and `std::weak_ptr` for safe observer management.  
- Dynamic attach/detach of observers.  
- Clean RAII-based memory handling.  
- Compatible with C++11 and newer.

### 2️⃣ [Bridge Pattern](BridgePattern/)
**Category:** Structural  
**Concept:** Decouples abstraction from implementation so both can vary independently.  
**Highlights:**
- Demonstrates `Abstraction` (`RemoteControl`) and `Implementor` (`Device`).  
- Concrete implementations like `TV` and `Radio`.  
- Extensible — add new devices or remotes without modifying existing code.  
- Uses composition and smart pointers (`std::shared_ptr<Device>`).

---

## 🛠️ Build & Run Instructions

### Prerequisites
- **C++ compiler** supporting C++11 or higher (e.g. GCC, Clang, MSVC)
- (Optional) **CMake** for build automation

### Compile and Run (Directly)
```bash
g++ -std=c++17 main.cpp -o pattern_demo
./pattern_demo
````

### Using CMake

```bash
mkdir build && cd build
cmake ..
make
./pattern_demo
```

---

## 📚 Key Learnings

* Modernizing classic GoF (Gang of Four) patterns using smart pointers and RAII.
* Applying **SOLID principles** with practical C++ implementations.
* Avoiding pitfalls of raw pointers and manual memory management.
* Writing **reusable, maintainable, and testable** pattern-based code.

---

## 🚀 Upcoming Patterns

* ✅ **Observer Pattern**
* ✅ **Bridge Pattern**
* 🔜 **Factory Method**
* 🔜 **Strategy Pattern**
* 🔜 **Singleton (Thread-Safe)**
* 🔜 **Command Pattern**

Stay tuned as more patterns are added, each with full explanations and modern C++ idioms.

---

## 🧰 Technologies & Standards Used

* **C++11 / C++14 / C++17**
* **STL Containers & Algorithms**
* **Smart Pointers (shared_ptr, weak_ptr, unique_ptr)**
* **Multithreading (std::thread, std::mutex, condition_variable)**
* **CMake** (optional for build automation)

---

## 🧑‍💻 Author

**[Yogesh Warad]**
C++ Developer | Software Engineer | AI Enthusiast
