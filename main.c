#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int GetCharPositionInAplhabet(char ch)
{
    char* letter = strchr(alphabet, ch);
    return letter - alphabet;
}

void DisplayCharArray(char* str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}

char* Encrypt(char plainText[], char key[])
{
    int i = 0;
    int j = 0;
    char* cipherText  = (char *) malloc(sizeof(char) * strlen(plainText) -1);

    for(i = 0; i < strlen(plainText); i++)
    {
        int plainLetterIndex = GetCharPositionInAplhabet(tolower(plainText[i]));
        int keyLetterIndex = GetCharPositionInAplhabet(tolower(key[j]));

        int index = plainLetterIndex + keyLetterIndex;

        if(index > ALPHABET_SIZE)
        {
            index -= ALPHABET_SIZE;
        }

        cipherText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }

    }

    return cipherText;

}

char* Decrypt(char cipherText[], char key[])
{
    int i = 0;
    int j = 0;
    char* plainText  = (char *) malloc(sizeof(char) * strlen(cipherText) -1);

    for(i = 0; i < strlen(cipherText); i++)
    {
        int cipherLetterIndex = GetCharPositionInAplhabet(tolower(cipherText[i]));
        int keyLetterIndex = GetCharPositionInAplhabet(tolower(key[j]));
        int index = 0;
        if(cipherLetterIndex >= keyLetterIndex)
        {
            index = cipherLetterIndex - keyLetterIndex;
        }
        else
        {
            if(cipherLetterIndex + keyLetterIndex > ALPHABET_SIZE)
            {
                index = ALPHABET_SIZE - keyLetterIndex + cipherLetterIndex;
            }
            else
            {
                index = keyLetterIndex + cipherLetterIndex;
            }
        }

        plainText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }
    }
    return plainText;
}


int main()
{
    char* cipherText = Encrypt("people", "dintw");
    DisplayCharArray(cipherText);

    char* plainText = Decrypt("smbihh", "dintw");
    DisplayCharArray(plainText);


    return 0;
}
