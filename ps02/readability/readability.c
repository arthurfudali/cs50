#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text, int len);
int count_words(string text, int len);
int count_sentences(string text, int len);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    int len = strlen(text);

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text, len);
    // printf("letters: %i\n", letters);

    int words = count_words(text, len);
    // printf("words: %i\n", words);

    int sentences = count_sentences(text, len);
    // printf("sentences: %i\n", sentences);

    // Compute the Coleman-Liau index
    // L is the average number of letter per 100 words
    // S is the average number of sentences per 100 words
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
int count_letters(string text, int len)
{
    int letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
int count_words(string text, int len)
{
    int words = 0;
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    words++;
    return words;
}
int count_sentences(string text, int len)
{
    int sentences = 0;
    for (int i = 0; i < len; i++)
    {
        // tbh i hate this solution
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
