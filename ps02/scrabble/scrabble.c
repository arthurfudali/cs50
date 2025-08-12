#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// points for each letter
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // prompt for 2 words
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    // compute the score for each word
    int score1 = compute_score(w1);
    int score2 = compute_score(w2);

    // prints the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {

        if (isupper(word[i]))
        {
            /* a subtracao de 'A' ou 'a' e feita para conseguir achar a posicao correta no array, ja
            que em C os caracteres sao armazenados como seu valor em ASCII, por exemplo, 'c' = 99,
            entao, ao subtrair 'a' = 97, teriamos o resultado de 2, assim obtendo a posicao 2 do
            array que equivale a letra 'c' */
            score += points[word[i] - 'A'];
        }
        if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
