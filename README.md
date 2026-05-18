# DungeonEscape 🗝️

A first-person puzzle adventure game built with **Unreal Engine 5.6** and **C++**, developed as part of the [GameDev.tv Unreal Engine 5 C++ Developer course](https://www.udemy.com/course/unrealcourse/) by Kaan Alpar — created in collaboration with Epic Games.

---

## About

DungeonEscape is a first-person puzzle game where the player navigates through a dungeon, solving environmental puzzles to find a way out. The project focuses on interaction systems, line tracing, trigger mechanics, and UI — all implemented in C++.

---

## Concepts Covered

- Unreal Engine 5.6 project setup and C++ workflow with Visual Studio
- First-person character movement and camera
- Line tracing (`SweepSingleByChannel`) for interaction detection
- Trigger volumes and overlap events
- Door and pressure plate mechanics
- AI Module integration
- UMG (Unreal Motion Graphics) for in-game UI
- State Tree and Gameplay State Tree for game state management
- Blueprint and C++ interop
- Level design with Modeling Tools

---

## Tech Stack

- **Engine:** Unreal Engine 5.6
- **Language:** C++ (98%), C#, C
- **IDE:** Visual Studio 2022
- **Plugins:** StateTree, GameplayStateTree, ModelingToolsEditorMode
- **Dependencies:** Engine, AIModule, UMG
- **Course:** [Unreal Engine 5 C++ Game Development – GameDev.tv / Kaan Alpar](https://www.udemy.com/course/unrealcourse/)

---

## Project Structure

```
DungeonEscape/
├── Source/          # C++ source files
├── Content/         # Assets, maps, blueprints
├── Config/          # Project configuration
├── DungeonEscape.uproject
├── .gitattributes
├── .gitignore
├── .vsconfig
└── LICENSE
```

---

## Getting Started

**Requirements**
- Unreal Engine 5.6
- Visual Studio 2022 (with Unreal Engine workload)

**Steps**

1. Clone the repo:
```bash
git clone https://github.com/QZenQ/DungeonEscape.git
```

2. Right-click `DungeonEscape.uproject` → **Generate Visual Studio project files**

3. Open the `.sln` in Visual Studio, build (Development Editor | Win64)

4. Launch `DungeonEscape.uproject` in Unreal Engine 5.6

---

## License

MIT — see [LICENSE](LICENSE) for details.

---

## Course Reference

**Unreal Engine 5 C++ Game Development** by Kaan Alpar & GameDev.tv
Created in collaboration with Epic Games.
[View on Udemy](https://www.udemy.com/course/unrealcourse/) | [View on GameDev.tv](https://gamedev.tv/courses/unreal-c-dev)
