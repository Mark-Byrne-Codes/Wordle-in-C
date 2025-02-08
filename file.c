#include "wordle.h"

/*
 * Recursively reads words from the opened file.
 *
 * @param file: Pointer to the opened file.
 * @param words: 2D array to store the loaded words.
 * @param max_words: Maximum number of words to load.
 * @param count: Current number of words loaded.
 * @return: The total number of words loaded.
*/
int	load_words_recursive(FILE *file, char words[][WORD_LENGTH + 1],
		int max_words, int count)
{
	int	i;

	if (count < max_words)
	{
		if (fscanf(file, "%5s", words[count]) == 1)
		{
			i = 0;
			while (i < WORD_LENGTH)
			{
				words[count][i] = toupper(words[count][i]);
				i++;
			}
			return (load_words_recursive(file, words, max_words,
					count + 1));
		}
	}
	fclose(file);
	return (count);
}

/*
 * Loads words from the specified file into the provided array.
 *
 * @param filename: Name of the file to read from.
 * @param words: 2D array to store the loaded words.
 * @param max_words: Maximum number of words to load.
 * @param count: Initial count of words (should be 0).
 * @return: The number of words loaded, or 0 on error.
 */
int	load_words(const char *filename, char words[][WORD_LENGTH + 1],
		int max_words, int count)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (!file)
	{
		return (0);
	}
	return (load_words_recursive(file, words, max_words, count));
}

/*
 * Selects a random word from the loaded word list.
 *
 * @param words: 2D array containing the loaded words.
 * @param num_words: The number of words in the array.
 * @return: A pointer to the randomly selected word.
 */
char	*choose_random_word(char words[][WORD_LENGTH + 1], int num_words)
{
	int	index;

	index = rand() % num_words;
	return (words[index]);
}