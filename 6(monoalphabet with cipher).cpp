#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherKey(char *keyword, char *cipherKey) {
    int i, j;
    int keywordLen = strlen(keyword);
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    strcpy(cipherKey, keyword);
    for (i = keywordLen, j = 0; i < 26; ++i) {
        if (strchr(keyword, alphabet[j]) == NULL) {
            cipherKey[i] = alphabet[j];
            ++j;
        }
    }

    cipherKey[i] = '\0';
}
void monoalphabeticEncrypt(char *plaintext, char *cipherKey) {
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int index = tolower(plaintext[i]) - 'a';
            plaintext[i] = cipherKey[index] + (base - 'A');
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[1000]; 
    char cipherKey[27];    
    generateCipherKey(keyword, cipherKey);

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    monoalphabeticEncrypt(plaintext, cipherKey);
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

