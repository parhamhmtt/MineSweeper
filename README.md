# 💣 Minesweeper — C++ Console Edition

A lightweight **console-based implementation of Minesweeper written in C++**.

The game runs on a fixed **10×10 board** and implements the core Minesweeper logic, including hidden cells, randomly placed mines, adjacent-mine calculation, recursive empty-cell expansion, bomb marking, win/loss detection, and score calculation.

> This project is a simple educational implementation focused on practicing C++ fundamentals such as arrays, structs, functions, recursion, loops, conditionals, and basic game-state management.

---

## 🎮 About the Game

Minesweeper is a single-player logic game in which mines are hidden across a grid.

The player's goal is to reveal all safe cells without selecting a mine.

Each revealed cell may contain:

* A number indicating how many mines exist around that cell
* An empty space when no adjacent mines exist
* A mine if the player selects a dangerous cell

This implementation also provides an option to identify a cell as a suspected bomb.

---

## ✨ Features

* 💻 Written entirely in **C++**
* 🖥️ Console-based user interface
* 🔲 Fixed **10×10 game board**
* 💣 Random mine placement
* 🔢 Automatic neighboring-mine calculation
* 🌊 Recursive expansion of empty areas
* 🚩 Bomb identification system
* 💥 Game-over detection
* 🏆 Win-condition detection
* 📊 Score calculation
* 🔄 Board initialization and reset logic
* 📦 Precompiled Windows executable included
* 🧩 No external libraries or frameworks required

---

## 🛠️ Technology Stack

| Technology         | Usage                                   |
| ------------------ | --------------------------------------- |
| C++                | Main programming language               |
| Standard Library   | Input/output and core program logic     |
| Console / Terminal | User interface                          |
| `rand()`           | Mine-position generation                |
| Recursion          | Automatic empty-cell expansion          |
| Windows Console    | Screen clearing through `system("cls")` |

The current source code also includes Windows-specific headers/behavior, so the project is primarily intended to run on **Windows**.

---

## 📂 Project Structure

```text
MineSweeper/
│
├── c++_Minesweeper/
│   │
│   ├── Minesweeper.cpp
│   │
│   └── output/
│       └── Minesweeper.exe
│
└── README.md
```

### Files

#### `Minesweeper.cpp`

Contains the complete game implementation, including:

* Board initialization
* Mine placement
* Board rendering
* Coordinate handling
* Mine detection
* Neighbor calculation
* Recursive cell revealing
* Win/loss detection
* Score calculation
* Main game loop

#### `output/Minesweeper.exe`

Precompiled Windows executable that can be used to run the game without manually compiling the C++ source code.

---

## ⚙️ Game Configuration

The board configuration is currently defined directly in the source code:

```cpp
const int row = 10;
const int column = 10;
const int bombcounts = 10;
```

This means the intended configuration is:

| Property              | Value |
| --------------------- | ----: |
| Rows                  |    10 |
| Columns               |    10 |
| Total cells           |   100 |
| Configured mine count |    10 |

The board is stored in a two-dimensional integer array:

```cpp
int matrix[10][10];
```

---

## 🧠 Internal Cell Representation

The game uses integer values inside the board matrix to represent different cell states.

| Value | Meaning                                    |
| ----: | ------------------------------------------ |
|  `-2` | Hidden/unopened cell                       |
|  `-1` | Mine                                       |
|   `0` | Revealed empty cell                        |
| `1–8` | Number of neighboring mines                |
|   `9` | Mine successfully identified by the player |

These internal values are converted into more readable symbols when the board is printed.

---

## 🖥️ Board Symbols

During gameplay, the console displays cells using the following representation:

| Display | Meaning                                 |
| ------- | --------------------------------------- |
| `.`     | Hidden cell                             |
| `#`     | Mine / identified mine                  |
| `1–8`   | Number of adjacent mines                |
| blank   | Revealed cell with no neighboring mines |

A typical board may look similar to:

```text
    a   b   c   d   e   f   g   h   i   j

  +---+---+---+---+---+---+---+---+---+---+
1 | . | . | . | . | . | . | . | . | . | . |
  +---+---+---+---+---+---+---+---+---+---+
2 | . | . | . | . | . | . | . | . | . | . |
  +---+---+---+---+---+---+---+---+---+---+
3 | . | . | . | . | . | . | . | . | . | . |
  +---+---+---+---+---+---+---+---+---+---+
```

Rows are displayed as `1` through `10`, while columns are visually labeled `a` through `j`.

> Note: although the board displays letter-based column labels, the current input implementation expects **numeric row and column coordinates**.

---

## 🎯 How to Play

When the application starts, the following prompt is displayed:

```text
Enter 1 to start, and 0 to exit:
```

Enter:

```text
1
```

to start the game.

Enter:

```text
0
```

to exit.

---

## 🎮 Player Actions

During the game, you are asked to select an action:

```text
Enter 1 to Find Bomb and 2 to find blank:
```

### Option `1` — Find Bomb

Use this option when you believe a specific cell contains a mine.

```text
1
```

Then enter the row and column.

If the selected cell actually contains a mine, it is marked internally as a discovered mine.

If the selected cell does **not** contain a mine, the current implementation immediately ends the game.

### Option `2` — Reveal Cell

Use:

```text
2
```

to reveal a cell that you believe is safe.

If the selected cell is safe:

* The cell is revealed
* The number of surrounding mines is calculated
* If no mines surround the cell, neighboring empty cells are automatically explored

If the selected cell contains a mine:

```text
*******************GAME OVER*****************
```

is displayed and the game ends.

---

## 📍 Entering Coordinates

The game requests:

```text
enter the coord row and column:
```

Enter two numbers separated by a space.

For example:

```text
4 7
```

means:

```text
Row:    4
Column: 7
```

Both coordinates are expected to be in the range:

```text
1 - 10
```

Internally, the program converts them to zero-based array indices:

```cpp
entry.row--;
entry.column--;
```

---

## 🌊 Automatic Empty-Cell Expansion

One of the main pieces of game logic is implemented by:

```cpp
aroundCoordSearch()
```

When a safe cell is selected, the function checks all cells surrounding it.

For a selected coordinate `(row, column)`, the program examines the surrounding area:

```text
┌─────┬─────┬─────┐
│ ↖   │ ↑   │ ↗   │
├─────┼─────┼─────┤
│ ←   │ X   │ →   │
├─────┼─────┼─────┤
│ ↙   │ ↓   │ ↘   │
└─────┴─────┴─────┘
```

If neighboring mines exist, their number is stored in the selected cell.

For example:

```text
1
2
3
```

indicates how many mines surround that location.

If the number of neighboring mines is zero, the cell becomes empty and the function recursively searches neighboring hidden cells.

This creates the familiar Minesweeper behavior where selecting an empty region automatically reveals a larger safe area.

---

## 💣 Mine Generation

Mine placement is handled by:

```cpp
randomBombFixer()
```

Coordinates are generated using:

```cpp
rand() % row
rand() % column
```

and mine cells are represented internally using:

```cpp
-1
```

---

## 🏆 Winning the Game

The program checks the current game state using:

```cpp
checkTheGameEnd()
```

The game considers the board completed when no cells with the hidden-safe-cell state (`-2`) remain.

When this happens, the application prints:

```text
*******************YOU WON THE GAME*****************
```

and displays the final board.

---

## 💥 Losing the Game

The game ends when:

* The player attempts to reveal a mine
* The player incorrectly identifies a safe cell as a mine

When the game is lost, mines become visible on the board.

Example:

```text
*******************GAME OVER*****************
```

---

## 📊 Score System

The final score is calculated by:

```cpp
score()
```

The function scans the board and counts cells whose stored value is greater than or equal to zero.

At the end of the application, the result is displayed as:

```text
Your score is : <score>
```

---

## 🧩 Main Functions

### `firstMatrixFixer()`

Initializes every board cell to:

```cpp
-2
```

which represents an unopened cell.

---

### `randomBombFixer()`

Selects random coordinates and places mines into the board.

Mine cells are represented by:

```cpp
-1
```

---

### `boardDisplay()`

Renders the complete game board in the terminal.

It handles:

* Row numbering
* Column labels
* Cell borders
* Hidden cells
* Mines
* Revealed numbers
* Empty cells

---

### `aroundCoordSearch(coord source)`

Calculates the number of mines surrounding a selected cell.

If no adjacent mine exists, it recursively expands into surrounding hidden cells.

This function provides the game's flood-fill-like behavior.

---

### `searchTheBombCounts()`

Counts cells that are currently stored as:

```cpp
-1
```

and displays the current number using:

```text
info Bombs: ...
```

Successfully identified mines are changed to another internal state and therefore no longer count as undiscovered mines.

---

### `checkTheGameEnd()`

Searches the matrix for hidden safe cells.

If no `-2` cells remain, the player wins.

---

### `score()`

Counts revealed/processed cells and returns the final score.

---

### `reset()`

Reinitializes the board and generates another set of mines.

The function exists in the source code, although the current main game loop does not expose an interactive restart command.

---

### `main()`

Controls the overall application flow:

```text
Initialize board
       ↓
Generate mines
       ↓
Ask user to start
       ↓
Display board
       ↓
Select action
       ↓
Enter coordinates
       ↓
Process selected cell
       ↓
Update board
       ↓
Check win/loss
       ↓
Repeat or finish
       ↓
Display score
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/parhamhmtt/MineSweeper.git
```

Enter the project directory:

```bash
cd MineSweeper
```

---

## ▶️ Run the Precompiled Version

A compiled executable is already available at:

```text
c++_Minesweeper/output/Minesweeper.exe
```

On Windows PowerShell:

```powershell
.\c++_Minesweeper\output\Minesweeper.exe
```

Alternatively, open the `output` directory and launch:

```text
Minesweeper.exe
```

---

## 🔨 Build from Source

### Requirements

To compile the source code, install a C++ compiler such as:

* MinGW-w64 / `g++`
* Microsoft Visual C++ compiler
* Visual Studio with the **Desktop development with C++** workload

---

### Build with g++

From the repository root:

```bash
g++ "c++_Minesweeper/Minesweeper.cpp" -o "c++_Minesweeper/output/Minesweeper.exe"
```

Optionally specify a C++ standard:

```bash
g++ "c++_Minesweeper/Minesweeper.cpp" -std=c++11 -o "c++_Minesweeper/output/Minesweeper.exe"
```

Then run:

```powershell
.\c++_Minesweeper\output\Minesweeper.exe
```

---

### Build with Microsoft Visual C++

Open a **Developer Command Prompt for Visual Studio** and run:

```cmd
cl /EHsc "c++_Minesweeper\Minesweeper.cpp" /Fe:"c++_Minesweeper\output\Minesweeper.exe"
```

Then execute:

```cmd
c++_Minesweeper\output\Minesweeper.exe
```

---

## 🪟 Platform Compatibility

The current implementation is primarily designed for **Windows**.

This is because the source uses Windows-oriented functionality such as:

```cpp
#include <conio.h>
```

and:

```cpp
system("cls");
```

`system("cls")` clears the Windows command prompt.

Compilation on Linux or macOS therefore requires small portability changes.

---

## ⚠️ Current Implementation Notes

This repository is a learning-oriented implementation and intentionally remains relatively small. There are several aspects of the current source code worth knowing.

### 1. Mine Count

The configuration contains:

```cpp
const int bombcounts = 10;
```

but mine generation currently uses:

```cpp
for (int i = 0; i <= bombcounts; i++)
```

which performs **11 placement attempts** rather than 10.

Additionally, two random attempts may select the same cell.

As a result, the actual number of unique mines on the board is not guaranteed to be exactly 10.

---

### 2. Random Generator Is Not Seeded

Mine positions are generated using `rand()`, but the current program does not initialize the pseudo-random generator with `srand()`.

Depending on the runtime environment, this can cause the same mine sequence to appear across multiple program launches.

---

### 3. First Move Is Not Guaranteed Safe

Unlike some modern Minesweeper implementations, the first selected cell is not protected from containing a mine.

The player can therefore lose on the first move.

---

### 4. Coordinate Validation

The current program directly accesses the matrix after converting the user's input:

```cpp
entry.row--;
entry.column--;
```

There is currently no explicit validation that the entered coordinates are within the valid `1–10` range.

Users should therefore only enter coordinates between:

```text
1 and 10
```

for both dimensions.

---

### 5. Displayed Column Labels vs Input

The board visually labels columns using:

```text
a b c d e f g h i j
```

but coordinate input currently expects integers.

For example, use:

```text
3 5
```

rather than:

```text
3 e
```

---

### 6. Bomb Marking Differs from Classic Minesweeper

Classic Minesweeper normally allows the player to place and remove flags without immediately knowing whether the flag is correct.

In this implementation, choosing the **Find Bomb** action immediately checks the selected cell.

A correct bomb guess succeeds.

An incorrect bomb guess causes an immediate game over.

---

### 7. Marked Mines Affect Neighbor Calculation

A successfully identified mine changes internally from:

```cpp
-1
```

to:

```cpp
9
```

while neighbor calculation specifically searches for cells equal to `-1`.

Therefore, identifying a mine before revealing neighboring cells can affect the later neighboring-mine count in the current implementation.

This is an implementation detail that could be improved in a future version.

---

## 🚧 Possible Improvements

Potential future improvements include:

* [ ] Guarantee exactly the configured number of unique mines
* [ ] Seed the random-number generator
* [ ] Add input validation
* [ ] Guarantee a safe first move
* [ ] Separate mine state from display/flag state
* [ ] Add traditional flag/unflag mechanics
* [ ] Correct mine counting after a mine has been marked
* [ ] Accept `a-j` column coordinates
* [ ] Add selectable difficulty levels
* [ ] Support custom board dimensions
* [ ] Support custom mine counts
* [ ] Add an in-game restart option
* [ ] Add timer support
* [ ] Track high scores
* [ ] Improve terminal rendering
* [ ] Add cross-platform terminal clearing
* [ ] Replace `rand()` with modern C++ random utilities
* [ ] Split game logic into multiple source/header files
* [ ] Add automated unit tests
* [ ] Add a graphical user interface

---

## 🗺️ Suggested Future Architecture

As the project grows, it could be separated into dedicated components:

```text
MineSweeper/
│
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Game.h
│   ├── Board.cpp
│   ├── Board.h
│   ├── Cell.cpp
│   └── Cell.h
│
├── tests/
│   └── ...
│
├── output/
│   └── Minesweeper.exe
│
└── README.md
```

This would separate:

* Board state
* Game rules
* Rendering
* User input
* Mine generation
* Scoring

and make the project easier to test and maintain.

---

## 🤝 Contributing

Contributions, improvements, and bug fixes are welcome.

A typical contribution workflow is:

```bash
git clone https://github.com/parhamhmtt/MineSweeper.git
cd MineSweeper
git checkout -b feature/my-improvement
```

After making your changes:

```bash
git add .
git commit -m "Add my improvement"
git push origin feature/my-improvement
```

Then open a Pull Request on GitHub.

---

## 👨‍💻 Repository

**Owner:** `parhamhmtt`
**Project:** `MineSweeper`
**Language:** C++
**Interface:** Console
**Primary Platform:** Windows

---

## ⭐ Support

If you find the project useful or interesting, consider starring the repository.

Bug reports and suggestions can be submitted through GitHub Issues.
