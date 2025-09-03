# 15 Puzzle Game (Sliding Puzzle)

This project implements a text-based version of the **15 Puzzle Game** in C.

## 📋 Description

- The board is a 4x4 grid filled with numbers from 1 to 15 and one empty space.
- The player must arrange the numbers in ascending order (from 1 to 15) by sliding adjacent tiles into the empty space.
- The game ends when the tiles are in the correct order.

## ▶️ How to Play

1. Compile the program:
   ```bash
   gcc gioco.c -o game
   ```
2. Run it:
   ```bash
   ./game
   ```
3. Each turn, the board will be displayed.  
   Enter the number of the tile you want to move into the empty space.  
   - Only numbers adjacent to the empty space are valid.  
   - If you enter an invalid value, you will be asked to try again.

4. Continue until the tiles are sorted.  
   At the end, the program will display the number of moves you used to win.

## 📌 Code Structure

- **`main`**: controls the game loop.
- **`init`**: initializes the board with random numbers and one empty space.
- **`check`**: verifies if the board is sorted.
- **`print`**: prints the current board state.
- **`play`**: handles player input and moves the tiles.

## 🔧 Requirements

- A standard C compiler (e.g., `gcc`, `clang`).
- Works on Linux, macOS, or Windows.

## 🚀 Example Output

```
***************
 1   2   3   4  
 5   6   7   8  
 9  10  11  12  
13  14  15  __  
***************

Insert a valid input:
```
