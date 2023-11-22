#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26
void letterFrequencyAttack(char ciphertext[], int topPlaintexts) {
    int frequencies[ALPHABET_SIZE] = {0};
    int i, j, shift, maxIndex;
    
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char uppercaseChar = toupper(ciphertext[i]);
            frequencies[uppercaseChar - 'A']++;
        }
    }
    for (i = 0; i < topPlaintexts; i++) 
	{
        maxIndex = 0;
        for (j = 1; j < ALPHABET_SIZE; j++) {
            if (frequencies[j] > frequencies[maxIndex]) {
                maxIndex = j;
            }
        }
        shift = (maxIndex - ('E' - 'A') + ALPHABET_SIZE) % ALPHABET_SIZE;

        printf("Plaintext %d (Shift %d): ", i + 1, shift);
        for (j = 0; ciphertext[j] != '\0'; j++) {
            if (isalpha(ciphertext[j])) {
                char uppercaseChar = toupper(ciphertext[j]);
                char decryptedChar = 'A' + (uppercaseChar - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
                printf("%c", islower(ciphertext[j]) ? tolower(decryptedChar) : decryptedChar);
            } else {
                printf("%c", ciphertext[j]);
            }
        }
        printf("\n");
        frequencies[maxIndex] = 0;
    }
}

int main() {
    char ciphertext[] = "WKLV LV D WHVW PHVVDJH.";
    int topPlaintexts = 5;

    printf("Ciphertext: %s\n", ciphertext);
    printf("Performing Letter Frequency Attack...\n\n");
    
    letterFrequencyAttack(ciphertext, topPlaintexts);

    return 0;
}
