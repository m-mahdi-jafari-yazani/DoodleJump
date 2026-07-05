# Doodle Jump

A modern C++ implementation of the classic **Doodle Jump** game built with **SFML**.
The project follows an object-oriented and modular architecture, making it easy to extend with new gameplay mechanics, platform types, and interactive items.

---

## 📸 Screenshots

### Main Menu

![Main Menu](screenshots/MainMenu.png)

### Gameplay

![Gameplay](screenshots/Gameplay.png)

### Game Over

![Game Over](screenshots/GameOver.png)

---

## ✨ Features

* Classic Doodle Jump gameplay
* Three platform types

  * Normal Platform
  * Moving Platform
  * Broken Platform
* Spring item that boosts the player's jump
* Automatic jumping mechanics
* Camera system
* Collision management
* Score tracking
* Persistent high score system
* Main menu
* Pause functionality
* Game Over screen
* Resource management
* Modular object-oriented architecture

---

## 🎮 Controls

| Key                 | Action                                   |
| ------------------- | ---------------------------------------- |
| **←** / **A**       | Move Left                                |
| **→** / **D**       | Move Right                               |
| **Enter**           | Start the game / Restart after Game Over |
| **Esc**             | Pause the game                           |
| **Esc** (Game Over) | Return to Main Menu                      |

> The player jumps automatically after landing on a platform, just like in the original Doodle Jump.

---

## 🏗️ Project Architecture

The project is designed with a modular architecture where each system has a clear responsibility.

### Core

Responsible for game state management and global resources.

* Game State Manager
* Resource Manager
* High Score Manager
* Configuration

### Platform System

Handles generation and behavior of all platform types.

Current platform types:

* Normal Platform
* Moving Platform
* Broken Platform

Platforms are created using the Factory Pattern and managed through the Platform Manager.

### Item System

Interactive gameplay elements are implemented separately from platforms.

Current item:

* Spring

The spring can be attached to a platform and launches the player significantly higher than a normal jump.

This separation allows new items (such as Jetpacks, Shields, Coins, etc.) to be added without modifying the platform hierarchy.

### Physics & Collision

Responsible for:

* Player movement
* Gravity
* Jump mechanics
* Collision detection
* Camera interaction

### UI System

Contains all user interface components:

* Main Menu
* HUD
* Game Over Screen

---

## 📂 Project Structure

```text
.
├── assets/
├── fonts/
├── include/
│   ├── Core/
│   ├── Item/
│   ├── Physics/
│   ├── Platform/
│   └── UI/
├── screenshots/
├── src/
│   ├── Core/
│   ├── Item/
│   ├── Platform/
│   └── UI/
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

## 🛠️ Technologies

* C++17
* SFML
* CMake

---

## 🚀 Build

Clone the repository:

```bash
git clone https://github.com/m-mahdi-jafari-yazani/DoodleJump.git
```

Enter the project directory:

```bash
cd DoodleJump
```

Create a build directory:

```bash
mkdir build
cd build
```

Generate the project:

```bash
cmake ..
```

Build:

```bash
make
```

Run:

```bash
./DoodleJump
```

---

## 📈 Design Principles

The project follows several software engineering principles:

* Object-Oriented Design
* Separation of Concerns
* Modular Architecture
* Factory Pattern
* Resource Management
* Single Responsibility Principle
* Extensible Item System

---

## 🚀 Future Improvements

* Additional items (Jetpack, Shield, Coin, etc.)
* Monsters and enemies
* Sound effects
* Background music
* Settings menu
* Animated sprites
* Additional platform behaviors
* More game modes

---

## 📄 License

This project is licensed under the MIT License.

See the LICENSE file for details.

---

## 👨‍💻 Author

**Mohammad Mahdi Jafari Yazani**

GitHub: https://github.com/m-mahdi-jafari-yazani
