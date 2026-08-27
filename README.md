# 💣 MineSweeper

A simple **console-based Minesweeper game written in C++**.

The game runs on a fixed **10×10 board** and includes random mine placement, recursive empty-cell expansion, score calculation, and win/loss detection.

## ✨ Features

* C++ console application
* 10×10 game board
* Random mine placement
* Adjacent mine calculation
* Recursive empty-cell revealing
* Mine detection
* Score system
* Win and Game Over states
* Precompiled Windows executable included
* No external libraries required

## 🎯 Objective

The goal is to reveal all safe cells without selecting a mine.

During each turn, the player can either:

```text
1 - Find Bomb
2 - Reveal Cell
```

If a mine is revealed, the game ends.

If all safe cells are discovered, the player wins.

## 🎮 Controls

At startup:

```text
1 - Start Game
0 - Exit
```

During gameplay, select an action and enter the row and column coordinates.

Example:

```text
4 7
```

means:

```text
Row: 4
Column: 7
```

Coordinates should be between:

```text
1 - 10
```

## 🧩 Board States

The game internally uses integer values to represent cells:

| Value | Meaning             |
| ----: | ------------------- |
|  `-2` | Hidden cell         |
|  `-1` | Mine                |
|   `0` | Empty revealed cell |
| `1-8` | Adjacent mine count |
|   `9` | Identified mine     |

The board displays:

```text
.   Hidden Cell
#   Mine
1-8 Adjacent Mines
```

## ⚙️ Configuration

The board configuration is defined directly in the source:

```cpp
const int row = 10;
const int column = 10;
const int bombcounts = 10;
```

The board is stored as:

```cpp
int matrix[10][10];
```

## 🌊 Empty Cell Expansion

When a revealed cell has no nearby mines, the game automatically checks surrounding cells.

This behavior is implemented recursively through:

```cpp
aroundCoordSearch()
```

and creates the familiar Minesweeper flood-fill effect.

## 🏆 Win Condition

The game checks whether any hidden safe cells remain.

If none remain:

```text
*******************YOU WON THE GAME*****************
```

is displayed.

## 💥 Game Over

The game ends when:

* A player reveals a mine
* A player incorrectly identifies a safe cell as a bomb

The final score is then displayed.

## 📊 Score

The game calculates a score based on revealed or processed cells.

At the end:

```text
Your score is : <score>
```

is printed.

## 📂 Project Structure

```text
MineSweeper/
├── c++_Minesweeper/
│   ├── Minesweeper.cpp
│   └── output/
│       └── Minesweeper.exe
└── README.md
```

## 🛠️ Technologies

* C++
* Standard Library
* Console / Terminal
* Recursion
* Arrays
* Structs
* Random number generation

The current implementation is mainly designed for **Windows**.

## 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/parhamhmtt/MineSweeper.git
```

Enter the project:

```bash
cd MineSweeper
```

## ▶️ Run Precompiled Version

A Windows executable is included:

```text
c++_Minesweeper/output/Minesweeper.exe
```

Run it from PowerShell:

```powershell
.\c++_Minesweeper\output\Minesweeper.exe
```

## 🔨 Build from Source

Using `g++`:

```bash
g++ "c++_Minesweeper/Minesweeper.cpp" -std=c++11 -o "c++_Minesweeper/output/Minesweeper.exe"
```

Then run:

```powershell
.\c++_Minesweeper\output\Minesweeper.exe
```

## ⚠️ Current Limitations

* Board size is fixed to 10×10
* Mine count is hard-coded
* Input validation is limited
* First move is not guaranteed safe
* Random generator is not explicitly seeded
* Column labels are shown as letters, while input uses numbers
* The game currently uses Windows-specific console behavior
* No graphical interface
* No automated tests

## 🚧 Possible Improvements

* Difficulty levels
* Custom board sizes
* Better input validation
* Safe first move
* Improved random mine generation
* Traditional flag/unflag system
* Cross-platform support
* Timer and high scores
* Graphical user interface
* Automated tests

## 👨‍💻 Repository

**MineSweeper**

C++ • Console Game • Recursion • Game Logic
