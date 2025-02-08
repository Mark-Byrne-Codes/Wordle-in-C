#include "wordle.h"

/*
 *  By: [Your Name/Login] <[Your Email]>
 *  Subject: input_output.c
 */
/*
 * Prints a single result character with the appropriate color.
 *
 * @param result: The result code (RESULT_GREEN, RESULT_YELLOW, RESULT_GRAY).
 * @param c: The character to print.
 */
void	print_single_result(t_result result, char c)
{
	if (result == RESULT_GREEN)
	{
		printf("\033[32m%c\033[0m", c);
	}
	else
	{
		if (result == RESULT_YELLOW)
		{
			printf("\033[33m%c\033[0m", c);
		}
		else
		{
			if (result == RESULT_GRAY)
			{
				printf("\033[90m%c\033[0m", c);
			}
			else
			{
				printf("?");
			}
		}
	}
}

/*
 * Prints the results of a guess, showing each letter with its
 * corresponding color (green, yellow, or gray).
 *
 * @param results: Array of result codes (one for each letter).
 * @param index: The current index of the letter being printed.
 * @param guess: the users guess.
 */
void	print_results(const t_result *results, int index, const char *guess)
{
	if (index < WORD_LENGTH)
	{
		print_single_result(results[index], guess[index]);
		print_results(results, index + 1, guess);
	}
	else
	{
		printf("\n");
	}
}

/*
 * Asks the user if they want to play again.
 *
 * @return: true if the user enters 'y' or 'Y', false otherwise.
 */
bool	play_again(void)
{
	char	choice;
	int		c;

	printf("Play again? (y/n): ");
	scanf(" %c", &choice);
	c = getchar();
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
	if (choice == 'y')
		return (true);
    else if(choice == 'Y')
        return (true);
    else
	    return (false);
}