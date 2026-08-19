# 🎯 Change Shot

A simple 2D shooter game built with C++ and SDL2.


---

## 🕹️ About the Game

**Change Shot** is a fast-paced top-down shooter where you control a green square that moves around the screen and shoots at a red enemy. The game features:

- **Player Movement**: Use `WASD` keys to move the player around the screen.
- **Shooting**: Press `SPACE` to shoot bullets from your gun.
- **Screen Wrapping**: The player wraps around the screen when moving off the edges.
- **Enemy Spawning**: The enemy spawns at a random location when hit, ensuring it doesn't appear too close to the player.

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
- **SDL2** – Graphics, input handling, and window management
- **MinGW** – Compilation for Windows

---

## 📦 Installation & Running

### Prerequisites

- **SDL2** library installed on your system.
- A C++ compiler (e.g., `g++`, MinGW, or MSVC).

### 1. Clone the Repository
```
git clone https://github.com/pin-toto/Change_shot.git
cd Change_shot
g++ main.cpp - o change_shot -lSDL2
./change_shot
```

🧑‍💻 Development
Project Structure
text

Change_shot/
├── main.cpp          # Main game logic
├── Collision.h       # Collision detection utilities
├── README.md         # This file
└── SDL2-2.32.8/      # SDL2 development files (for Windows build)

Collision Detection

The Collision.h header provides a simple function for detecting rectangle intersections:
cpp

bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}

📝 License

This project is open source and available under the MIT License.
👤 Author

Pintoto

    GitHub: @pin-toto

    Repository: Change_shot

🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page.
⭐ Show Your Support

Give a ⭐️ if this project helped you or if you enjoyed the game!
