#include "wordle.h"

// Function prototypes
Result *checkword(char *, char *);
Result checkchar(char,int,char *);
bool isin(char *, char);
int main(int , char **);


int main(int argc, char **argv)
{
    char *word;
    char *guess;
    Result *results;

    word = "hello";
    if (argc != 2)
    {
        printf("Usage: %s <word>\n", argv[0]);
        return (1);
    }
    Results = check_word(argv[1], word);

    return (0);
}

Result checkchar(char guess, int position, char *word)
{
    char correct;

    correct = word[position];
    if (guess == correct))
        return ResultGreen;
    else if (isin(word, guess))
        return ResultYellow;
    else
        return ResultRed;
}

Result *check_word(char *guess, char *word)
{
    static Result results[5];
    int i;

    i = 0;
    while (i < 5)
    {
        results[i] = checkchar(guess[i], i, word);
        i++;
    }

    return results;
}

bool isin(char *word, char guess)
{
    int i;

    i = 0;
    while (i < 5)
    {
        if (word[i] == guess)
            return true;
        i++;
    }

    return false;
}