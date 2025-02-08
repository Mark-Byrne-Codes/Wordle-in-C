#include "wordle.h"

/*
 * Recursively checks each letter of the guess against the word.
 *
 * @param guess: The user's guess.
 * @param word: The secret word.
 * @param results: Array to store the results of each letter check.
 * @param index: The current index of the letter being checked.
 * @return: Pointer to the results array.
 */
t_result	*check_word_recursive(const char *guess, const char *word,
		t_result *results, int index)
{
	if (index < WORD_LENGTH)
	{
		results[index] = check_char(guess[index], index, word);
		return (check_word_recursive(guess, word, results, index + 1));
	}
	return (results);
}

/*
 * Checks the user's guess against the secret word and returns an array
 * of results, indicating whether each letter is correct, present, or absent.
 *
 * @param guess: The user's guess.
 * @param word: The secret word.
 * @return: Pointer to an array of t_result values.
 */
t_result	*check_word(const char *guess, const char *word)
{
	static t_result	results[WORD_LENGTH];

	return (check_word_recursive(guess, word, results, 0));
}

/*
 * Checks a single character of the guess against the corresponding
 * character in the secret word.
 *
 * @param guess: The character from the user's guess.
 * @param position: The index (position) of the character in the word.
 * @param word: The secret word.
 * @return: A t_result value (RESULT_GREEN, RESULT_YELLOW, or RESULT_GRAY).
 */
t_result	check_char(char guess, int position, const char *word)
{
	char	correct;
	bool	found;

	correct = word[position];
	if (guess == correct)
	{
		return (RESULT_GREEN);
	}
	else
	{
		found = false;
		recursive_isin(word, guess, 0, &found);
		if (found)
		{
			return (RESULT_YELLOW);
		}
		else
		{
			return (RESULT_GRAY);
		}
	}
}