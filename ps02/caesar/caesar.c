#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // argc = contagem de argumentos. tem que ser = 2 pois ./caesar ja conta como 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // salva a key
    string key_str = argv[1];

    // percorre a string verificando os digitos
    for (int i = 0; i < strlen(key_str); i++)
    {
        if (!isdigit(key_str[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // converte de ASCII para int, ex '13' -> 13
    int key = atoi(argv[1]);

    // pega o texto a ser convertido
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // converte o plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        // subtrai c de base 'A' para pegar o valor posicional no array,
        // depois adiciona a chave (para avancar) e volta a base para termos o caracter certo
        // o % 26 e usado para voltar ao inicio caso chegue no fim da cifra
        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
