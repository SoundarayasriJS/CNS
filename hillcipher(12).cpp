#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
void hillCipherEncrypt(char *message, int keyMatrix[2][2]) {
    int len = strlen(message);
    if (len % 2 != 0) 
	{
        message[len] = 'X';
        message[len + 1] = '\0';
        len++;
    }
    for (i = 0; i < len; i++) 
	{
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - 'A';
        }
    }
    for (i = 0; i < len; i += 2) 
	{
        int matrix[2] = {message[i], message[i + 1]};
        int result[2] = {
            keyMatrix[0][0] * matrix[0] + keyMatrix[0][1] * matrix[1],
            keyMatrix[1][0] * matrix[0] + keyMatrix[1][1] * matrix[1]
        };
        result[0] %= 26;
        result[1] %= 26;
        message[i] = result[0];
        message[i + 1] = result[1];
    }
    for (i = 0; i < len; i++) 
	{
        message[i] += 'A';
    }
}
int main() 
{
    char message[] = "meet me at the usual place at ten rather than eight o clock";
    int keyMatrix[2][2] = {{9, 4}, {5, 7}};
    hillCipherEncrypt(message, keyMatrix);
    printf("Encrypted Message: %s\n", message);
    return 0;
}
