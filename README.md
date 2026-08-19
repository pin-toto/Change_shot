# 🎯 Change Shot

![Gameplay](https://i.imgur.com/Rno5QqH.jpeg)

---

## 🕹️ About the Game

**Change Shot** is a fast-paced top-down shooter where you control a green square that moves around the screen and shoots at a red enemy.

### Features:
- **Player Movement**: Use `WASD` keys to move around.
- **Shooting**: Press `SPACE` to shoot bullets.
- **Screen Wrapping**: Player wraps around the screen edges.
- **Smart Enemy Spawning**: Enemy spawns far enough from the player.

---

## 🎮 Controls

| Key          | Action                |
|--------------|-----------------------|
| `W`          | Move Up               |
| `A`          | Move Left             |
| `S`          | Move Down             |
| `D`          | Move Right            |
| `A` / `D`    | Aim Gun Left / Right  |
| `SPACE`      | Shoot                 |

---

## 🛠️ Built With

- **C++** – Core game logic
- **SDL2** – Graphics, input, and window management
- **MinGW** – Windows compilation

---

## 📦 Installation & Running

### Prerequisites

- **SDL2** library installed on your system
- A C++ compiler (e.g., `g++`, MinGW, or MSVC)

### 1. Clone the Repository

Linux / macOS:

```bash
git clone https://github.com/pin-toto/Change_shot.git
cd Change_shot
g++ main.cpp -o Change_shot -lSDL2
./Change_shot
```

Windows (MinGW):

```
g++ main.cpp -o Change_shot.exe -I"SDL2-2.32.8/x86_64-w64-mingw32/include" -L"SDL2-2.32.8/x86_64-w64-mingw32/lib" -lmingw32 -lSDL2main -lSDL2 -mwindows
```

📁 Project Structure
text

Change_shot/
├── main.cpp          # Main game logic
├── Collision.h       # Collision detection utilities
├── README.md         # This file
└── SDL2-2.32.8/      # SDL2 development files (for Windows build)

Collision Detection

The Collision.h header provides a simple function for rectangle collision detection:
cpp

bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}

    Different difficulty levels

📝 License

MIT License – see LICENSE file for details.
👤 Author

Pintoto

    GitHub: @pin-toto

    Repository: Change_shot

🤝 Contributing

Contributions, issues, and feature requests are welcome!
Feel free to open an issue or submit a pull request.
⭐ Show Your Support

Give a ⭐️ if you enjoyed this project!
