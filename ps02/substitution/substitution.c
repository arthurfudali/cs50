#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // verifica se há mais argumentos do que o pedido
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // salva a key
    string key_str = argv[1];

    int len = strlen(key_str);
    // verifica se a key tem 26 caracteres
    if (len != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        // cria um vetor de booleanos para verificar a reincidencia de caracteres
        bool rep[26] = {false};
        for (int i = 0; i < len; i++)
        {
            char c = toupper(key_str[i]);
            // verifica se é um digito aceito
            if (isdigit(c) || !isalpha(c))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            // verifica se ja apareceu mais de uma vez
            int index = c - 'A';
            if (rep[index])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            rep[index] = true;
        }
    }
    // pede ao usuario o texto
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        // funcoes diferentes para upper e lower para presenvar o case
        if (isupper(c))
        {
            int index = c - 'A';
            // acha o equivalente na key
            char sub = toupper(key_str[index]);
            printf("%c", sub);
        }
        else if (islower(c))
        {
            int index = c - 'a';
            char sub = tolower(key_str[index]);
            printf("%c", sub);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
