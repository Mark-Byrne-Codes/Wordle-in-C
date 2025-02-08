# Wordle in C

This is a console-based implementation of the popular word game Wordle, written in C.

## Features

*   **Classic Wordle Gameplay:**  Guess a five-letter word within six attempts.
*   **Color-Coded Feedback:**  Provides feedback after each guess:
    *   **Green:** Letter is in the correct position.
    *   **Yellow:** Letter is in the word, but in the wrong position.
    *   **Gray:** Letter is not in the word.
*   **Word List:** Uses a `wordle.txt` file for the word list (you provide this file).
*  **Makefile:** Included `Makefile` for easy compilation.

## Requirements

*   A C compiler (like GCC)
*   `make` (usually comes with your C development environment)
*   A text file named `wordle.txt` containing a list of five-letter words, one word per line.  Example:

    ```
    HELLO
    WORLD
    THERE
    WORDS
    GAMES
    ```

## How to Compile and Run

1.  **Clone the repository (or download the files):**
    ```bash
    git clone <repository_url>  # If you have it on a git repository
    # OR
    # Download the .c, .h, and Makefile files.
    ```

2.  **Create `wordle.txt`:** Create a text file named `wordle.txt` in the same directory as the source files.  Populate it with your list of five-letter words.

3.  **Compile:** Open a terminal, navigate to the directory containing the files, and run:
    ```bash
    make
    ```

4.  **Run:** Execute the compiled program:
    ```bash
    ./wordle
    ```

## File Structure

*   **`wordle.h`:** Header file containing declarations and constants.
*   **`wordle.c`:**  Main game loop and overall control.
*   **`check_word.c`:** Functions for checking guesses against the target word.
*   **`file.c`:** Functions for reading the word list from the file.
*   **`input.c`:** Functions for handling user input and displaying output.
*   **`utils.c`:** Utility functions (like `isin`).
*   **`Makefile`:**  Build automation script.
*  **`wordle.txt`:**  The wordlist (you create this).

## How to Play

1.  The program will select a random five-letter word from `wordle.txt`.
2.  You have six attempts to guess the word.
3.  Enter a five-letter word and press Enter.
4.  The program will provide feedback using colored letters:
    *   Green: The letter is in the word and in the correct position.
    *   Yellow: The letter is in the word but in the wrong position.
    *   Gray: The letter is not in the word.
5.  Use the feedback to refine your guesses.
6.  If you guess the word correctly within six attempts, you win!  Otherwise, the word will be revealed.
7. You will be prompted if you wish to play again.
