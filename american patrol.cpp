#include <stdio.h>
#include <string.h>
void findPosition(char key[5][5], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (*row = 0; *row < 5; (*row)++)
        for (*col = 0; *col < 5; (*col)++)
            if (key[*row][*col] == ch)
                return;
}
void decryptPlayfair(char cipher[100], char key[5][5]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(cipher); i += 2) {
        findPosition(key, cipher[i], &row1, &col1);
        findPosition(key, cipher[i + 1], &row2, &col2);

        if (row1 == row2) {
            printf("%c%c", key[row1][(col1 - 1 + 5) % 5], key[row2][(col2 - 1 + 5) % 5]);
        } else if (col1 == col2) {
            printf("%c%c", key[(row1 - 1 + 5) % 5][col1], key[(row2 - 1 + 5) % 5][col2]);
        } else {
            printf("%c%c", key[row1][col2], key[row2][col1]);
        }
    }
}

int main() {
    char key[5][5] = {{'K', 'X', 'J', 'E', 'Y'},
                      {'U', 'R', 'E', 'B', 'Z'},
                      {'W', 'H', 'Y', 'T', 'U'},
                      {'H', 'E', 'Y', 'F', 'S'},
                      {'K', 'R', 'E', 'H', 'E'}};

    char cipher[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    printf("Encrypted Message:\n%s\n", cipher);
    printf("\nDecrypted Message:\n");
    decryptPlayfair(cipher, key);

    return 0;
}
