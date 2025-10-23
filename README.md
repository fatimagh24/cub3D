# 🌀 Cub3D – Maze Runner

Welcome to **Cub3D**, a 3D maze exploration game inspired by *Wolfenstein 3D* 🕹️  
Developed as part of the **42 School curriculum**, this project dives deep into **raycasting**, **game loop mechanics**, and **low-level graphics programming** using the **MiniLibX** library.

---

## 🌟 Project Overview

The goal of **Cub3D** is to create a first-person 3D game where the player navigates through a maze from a 2D map using **raycasting**.  
It combines mathematical logic, rendering algorithms, and performance optimization — giving developers hands-on experience with core graphics concepts like **DDA (Digital Differential Analyzer)** and **ray-wall collision detection**.

You wake up inside a mysterious maze. The walls are high, the paths are endless, and the only way out is through **code**. 💻

---

## 🚀 Features

- 🔭 **Raycasting Engine**
  - Uses the DDA (Digital Differential Analyzer) algorithm for precise wall collision detection
  - Simulates 3D depth with perspective projection for a realistic first-person view

- 🧱 **Wall Rendering**
  - Supports textures for all directions: North, South, East, and West
  - Accurate texture mapping to make walls look immersive

- 📜 **Map Parsing & Validation**
  - Reads `.cub` files with textures, floor/ceiling colors, and maze layout
  - Checks map validity: player position, walls closure, and correct identifiers

- 👤 **Player Movement**
  - `W`, `A`, `S`, `D` to move around the maze
  - Arrow keys to rotate smoothly and explore corners
  - Collision detection prevents walking through walls

- 🎨 **Floor & Ceiling Colors**
  - Custom RGB colors for floor and ceiling from `.cub` configuration
  - Creates a more immersive maze atmosphere

## 🌌 Screenshots

| Exploring the Maze | Turning Corners | Inside the Grid |
|:------------------:|:----------------:|:----------------:|
| ![Gameplay Screenshot](images/game1.png) | ![Gameplay Screenshot 2](images/game2.png) | ![Gameplay Screenshot 3](images/game3.png) |

*Screenshots from the Maze Runner world.*

---

## 🧾 File Format Example (`.cub`)
```cub
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
1000110001
1000N00001
1111111111

NO/SO/WE/EA: Texture paths for walls
F/C: RGB colors for Floor and Ceiling
1: Wall, 0: Empty space
N: Player starting position and direction
```

## 👥 Team
This project was developed as part of the 42 School curriculum by:  
👩‍💻 [@fatimagh24](https://github.com/fatimagh24)  
👩‍💻 [@razanhasan42](https://github.com/razanhasan42)
