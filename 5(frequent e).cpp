#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char findMostFrequentChar(char *text) {
    int count[26] = {0};
    char mostFrequentChar;
    int maxCount = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';
            count[index]++;
            if (count[index] > maxCount) {
                maxCount = count[index];
                mostFrequentChar = text[i];
            }
        }
    }

    return mostFrequentChar;
}

void decryptWithKey(char *text, char key) {
    int shift = tolower(key) - 'e';

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

int main() {
    char ciphertext[1000]; 
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    char mostFrequentChar = findMostFrequentChar(ciphertext);
    printf("Assumed key character: %c\n", mostFrequentChar);
    decryptWithKey(ciphertext, mostFrequentChar);
    printf("Decrypted text: %s\n", ciphertext);

    return 0;
}

