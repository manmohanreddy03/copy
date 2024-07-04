#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

// Function to encrypt plaintext using Hill Cipher
void encrypt(char *plaintext, char *ciphertext, int keyMatrix[MAX_SIZE][MAX_SIZE], int keySize) {
int len = strlen(plaintext);
int blockSize = keySize;
int numBlocks = len / blockSize;
int i, j, k, sum;
int sumArr[MAX_SIZE]; // Define sumArr with a fixed size

// Iterate through blocks of plaintext
for (i = 0; i < numBlocks; i++) {
// Initialize sum array to 0
for (j = 0; j < keySize; j++) {
sumArr[j] = 0;
}

// Matrix multiplication
for (j = 0; j < keySize; j++) {
for (k = 0; k < keySize; k++) {
sumArr[j] += keyMatrix[j][k] * (plaintext[i * blockSize + k] - 'a');
}
sumArr[j] %= 26; // Apply modulo after summing up
}

// Convert result to characters and append to ciphertext
for (j = 0; j < keySize; j++) {
ciphertext[i * blockSize + j] = (char)(sumArr[j] + 'a');
}
}
ciphertext[len] = '\0'; // Add null terminator to the ciphertext
}

int main() {
int keySize, i, j;
int keyMatrix[MAX_SIZE][MAX_SIZE];

printf("Enter the size of the key matrix: ");
scanf("%d", &keySize);

// Input key matrix elements from the user
printf("Enter the key matrix elements:\n");
for (i = 0; i < keySize; i++) {
for (j = 0; j < keySize; j++) {
scanf("%d", &keyMatrix[i][j]);
}
}

char plaintext[100], ciphertext[100];

printf("Enter your Plaintext: ");
scanf(" %[^\n]s", plaintext); // Read plaintext with spaces

// Encrypt the plaintext
encrypt(plaintext, ciphertext, keyMatrix, keySize);

printf("Your CipherText is: %s\n", ciphertext);
 return 0;
}
