#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Block size for CBC-MAC
#define BLOCK_SIZE 16

// Example key for CBC-MAC
static const uint8_t key[BLOCK_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
                                        0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10};

// Perform CBC-MAC on the given message
void cbc_mac(const uint8_t *message, size_t message_length, uint8_t *mac) {
    // Initialize the CBC-MAC with the key
    uint8_t cbc_mac[BLOCK_SIZE];
    memcpy(cbc_mac, key, BLOCK_SIZE);

    size_t num_blocks = message_length / BLOCK_SIZE;
    const uint8_t *ptr = message;

    for (size_t i = 0; i < num_blocks; ++i) {
        // XOR the current block with the current MAC value
        for (size_t j = 0; j < BLOCK_SIZE; ++j) {
            cbc_mac[j] ^= ptr[j];
        }

        // Update the MAC value with the current block
        for (size_t j = 0; j < BLOCK_SIZE; ++j) {
            cbc_mac[j] = cbc_mac[j] ^ (cbc_mac[j] << 1) ^ (0x87 & -(cbc_mac[j] >> 7));
        }

        // Move to the next block
        ptr += BLOCK_SIZE;
    }

    // Copy the final MAC value to the output
    memcpy(mac, cbc_mac, BLOCK_SIZE);
}

int main() {
    const char *message = "Hello, this is a CBC-MAC example!";
    size_t message_length = strlen(message);

    // Ensure the message length is a multiple of the block size
    size_t padded_length = (message_length / BLOCK_SIZE + 1) * BLOCK_SIZE;
    uint8_t padded_message[padded_length];
    memcpy(padded_message, message, message_length);
    memset(padded_message + message_length, 0, padded_length - message_length);

    uint8_t mac[BLOCK_SIZE];

    // Calculate CBC-MAC
    cbc_mac(padded_message, padded_length, mac);

    // Display the result
    printf("Message: %s\n", message);
    printf("CBC-MAC: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%02x", mac[i]);
    }
    printf("\n");

    return 0;
}

