// wordle.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "wordle.h"

// Function prototypes
Results checkword(char *, char *);
Result checkchar(char,int,char *);
int main();


int main()
{
    printf("Welcome to Wordle!\n");

    return (0);
}

Result checkchar(char guess, int position, char *word)
{
    char correct;

    correct = word[position];
    if (isin(word, guess, position))
    {
        return ResultGreen;
    }
    else if (isin(word, guess, position))
    {
        return ResultYellow;
    }
    else
    {
        return ResultRed;
    }
}

Results check_word(char *guess, char *word)
{
    Results results;
    int i;

    i = 0;
    while (i < 5)
    {
        results[i] = checkchar(guess[i], i, word);
        i++;
    }

    return results;
}