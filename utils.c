#include "wordle.h"

/*
 * Recursively checks if a given character exists within a word.
 *  Used by check_char to determine if a letter is present
 *  but in the wrong position (RESULT_YELLOW).
 *
 * @param word: The word to search within.
 * @param guess: The character to search for.
 * @param index: The current index being checked in the word.
 * @param result: Pointer to a boolean that will be set to true if found,
 *                otherwise remains false.
 */
void	recursive_isin(const char *word, char guess, int index, bool *result)
{
	if (index < WORD_LENGTH)
	{
		if (word[index] == guess)
		{
			*result = true;
			return ;
		}
		recursive_isin(word, guess, index + 1, result);
	}
}

/*
 * Checks if a given character is present within a word (using recursion).
 * This is a wrapper for the recursive_isin function.
 *
 * @param word: The word to search within.
 * @param guess: The character to search for.
 * @param index: Starting index for the search (usually 0).
 * @return: true if the character is found, false otherwise.
 */
bool	isin(const char *word, char guess, int index)
{
	if (index < WORD_LENGTH)
	{
		if (word[index] == guess)
		{
			return (true);
		}
		return (isin(word, guess, index + 1));
	}
	return (false);
}