#include "wordle.h"

/*
 * Initializes the game by loading words from the dictionary file
 * and seeding the random number generator.
 *
 * @param words: 2D array to store the loaded words.
 * @param num_words: Pointer to an integer to store the number of words loaded.
 */
void	init_game(char words[][WORD_LENGTH + 1], int *num_words)
{
	*num_words = load_words("wordle.txt", words, MAX_WORDS, 0);
	if (*num_words == 0)
	{
		fprintf(stderr, "Error: Could not load words or file empty.\n");
		exit(1);
	}
	srand(time(NULL));
}

/*
 * Entry point of the Wordle game.  Initializes the game,
 * selects a random word, and starts the guessing process.
 *
 * @param argc: Number of command-line arguments (unused).
 * @param argv: Array of command-line arguments (unused).
 * @return: 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	char	words[MAX_WORDS][WORD_LENGTH + 1];
	int		num_words;
	char	*word;

	(void)argc;
	(void)argv;

	init_game(words, &num_words);
	word = choose_random_word(words, num_words);
	printf("Welcome to Wordle!\n");
	process_guess(NULL, word, 0, words, num_words);
	return (0);
}

/*
 * Reads a guess from the user, validates its length, and converts it
 * to uppercase.  Handles invalid input by prompting the user again.
 *
 * @param new_guess: Buffer to store the user's guess.
 * @param word: The secret word to be guessed.
 * @param num_guesses: The current number of guesses made.
 * @param words: The array of words loaded from the dictionary.
 * @param num_words: The number of words in the `words` array.
 */
void	process_guess_input(char *new_guess, const char *word, int num_guesses,
							char words[][WORD_LENGTH + 1], int num_words)
{
    size_t len;
	int i;

    printf("Enter guess (%d/%d): ", num_guesses + 1, MAX_GUESSES);
    if (fgets(new_guess, sizeof(new_guess), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(1);
    }

    len = strlen(new_guess);
    if (len > 0 && new_guess[len - 1] == '\n') {
        new_guess[len - 1] = '\0';
        len--;
    }

    if (len != WORD_LENGTH) {
        printf("Invalid guess. Please enter a %d-letter word.\n", WORD_LENGTH);
        process_guess(NULL, word, num_guesses, words, num_words);
        return;
    }

    i = 0;
    while (i < WORD_LENGTH) {
        new_guess[i] = toupper(new_guess[i]);
        i++;
    }
}

/*
 * Handles the end of the game, either when the user wins or runs out
 * of guesses.  Asks the user if they want to play again.
 *
 * @param num_guesses: The number of guesses taken.
 * @param word: The secret word.
 * @param words: The array of words loaded from the dictionary.
 * @param num_words: The number of words in the `words` array.
 */
void	handle_game_end(int num_guesses, const char *word,
						char words[][WORD_LENGTH + 1], int num_words)
{
    if (num_guesses >= MAX_GUESSES)
	{
        printf("You ran out of guesses. The word was: %s\n", word);
	}
    if (play_again())
	{
		init_game(words, &num_words);
        char *new_word;
        new_word = choose_random_word(words, num_words);
        printf("Welcome to Wordle!\n");
        process_guess(NULL, new_word, 0,words, num_words);
    }
	else
	{
		printf("Thanks for playing!\n");
	}
}

/*
 * Processes a single guess in the Wordle game.  Gets input, checks
 * the guess, prints results, and handles win/loss conditions.
 * Recursively calls itself for the next guess.
 *
 * @param guess: The previous guess (or NULL for the first guess).
 * @param word: The secret word to be guessed.
 * @param num_guesses: The current number of guesses made.
 * @param words: The array of words loaded from the dictionary.
 * @param num_words: The number of words in the `words` array.
 */
void	process_guess(char *guess, const char *word, int num_guesses,
			char words[][WORD_LENGTH + 1], int num_words)
{
	char		new_guess[WORD_LENGTH + 1];
	t_result	*results;
	bool		won;
	int			j;

	if (num_guesses < MAX_GUESSES)
	{
        process_guess_input(new_guess, word, num_guesses, words, num_words);
        (void)guess;
		results = check_word(new_guess, word);
		print_results(results, 0, new_guess);
		won = true;
		j = 0;
		while (j < WORD_LENGTH)
		{
			if (results[j] != RESULT_GREEN)
				won = false;
			j++;
		}
		if (won)
		{
			printf("Congrats! You guessed in %d tries.\n", num_guesses + 1);
            handle_game_end(num_guesses, word, words, num_words);
		}
		else
		{
			process_guess(new_guess, word, num_guesses + 1, words, num_words);
		}
	}
	else
		handle_game_end(num_guesses, word, words, num_words);
}