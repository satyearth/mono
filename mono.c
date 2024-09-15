#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256
void encrypt(char *plaintext, char *key, char *ciphertext)
{
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int offset = toupper(plaintext[i]) - 'A';
            ciphertext[i] = key[offset];
            if (islower(plaintext[i]))
            {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext)
{
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            int offset = toupper(ciphertext[i]);
            for (int j = 0; j < 26; j++)
            {
                if (key[j] == offset)
                {
                    plaintext[i] = 'A' + j;
                    if (islower(ciphertext[i]))
                    {
                        plaintext[i] = tolower(plaintext[i]);
                    }
                    break;
                }
            }
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

int main()
{
    char plaintext[MAX_LEN];
    char key[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decrypted[MAX_LEN];

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    
    printf("Enter the key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    if (strlen(key) != 26)
    {
        printf("Error: Key must be 26 characters long.\n");
        return 1;
    }

    printf("\nPlaintext: %s\n", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
