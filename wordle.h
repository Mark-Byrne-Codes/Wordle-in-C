#ifndef WORDLE_H
#define WORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define MAX_GUESSES 6
#define MAX_WORDS 1000

#define RESULT_GREEN  1
#define RESULT_YELLOW 2
#define RESULT_GRAY   4

typedef char	t_result;


// main.c
int		main(int argc, char **argv);
void	process_guess(char *guess, const char *word, int num_guesses,
			char words[][WORD_LENGTH + 1], int num_words);

// check_word.c
t_result	*check_word(const char *guess, const char *word);
t_result	check_char(char guess, int position, const char *word);

// file_io.c
int		load_words(const char *filename, char words[][WORD_LENGTH + 1],
			int max_words, int count);
char	*choose_random_word(char words[][WORD_LENGTH + 1], int num_words);
int		load_words_recursive(FILE *file, char words[][WORD_LENGTH + 1],
			int max_words, int count);

// input_output.c
void	print_results(const t_result *results, int index, const char *guess);
bool	play_again(void);
void	print_single_result(t_result result, char c);

// utils.c
void	recursive_isin(const char *word, char guess, int index, bool *result);
bool	isin(const char *word, char guess, int index);

#endif