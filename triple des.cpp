#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Initial permutation for the data block
static const int initial_permutation[] = {
    // ... (same as before)
};

// Example key for 3DES
static const uint64_t key[] = {0x0123456789ABCDEF, 0xFEDCBA9876543210};

// Perform the initial permutation on the data block
void initialPermutation(uint64_t *data) {
    // ... (same as before)
}

// Perform the 3DES encryption on a 64-bit data block
void encryptDES(uint64_t *data, const uint64_t *subkey) {
    // ... (same as before)
}

int main() {
    char plaintext[9]; // Allow for a null terminator
    uint64_t data;

    for (int round = 1; round <= 3; ++round) {
        // Get user input
        printf("Enter plaintext (8 characters): ");
        if (scanf("%8s", plaintext) != 1) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        // Convert the input to a 64-bit integer
        memcpy(&data, plaintext, sizeof(uint64_t));

        // Perform the initial permutation
        initialPermutation(&data);

        // Encrypt with 3DES using two keys
        encryptDES(&data, &key[0]);
        encryptDES(&data, &key[1]);
        encryptDES(&data, &key[0]);

        // Display the encrypted data
        printf("\nRound %d:\n", round);
        printf("Plaintext: %s\n", plaintext);
        printf("Encrypted: %016llx\n", data);

        // Decrypt the data
        encryptDES(&data, &key[0]); // Use the first key for decryption
        encryptDES(&data, &key[1]);
        encryptDES(&data, &key[0]);

        // Display the decrypted data
        printf("Decrypted: %s\n", (char *)&data);

        // Clear the buffer
        while (getchar() != '\n');
    }

    return 0;
}

