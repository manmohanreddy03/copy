#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// AES key for encryption and decryption (128-bit key)
unsigned char aes_key[] = "0123456789abcdef";
// Function to encrypt plaintext using AES
void aes_encrypt(unsigned char *plaintext, unsigned char *ciphertext) {
  AES_KEY key;
  AES_set_encrypt_key(aes_key, 128, &key);
  AES_encrypt(plaintext, ciphertext, &key);
}
// Function to decrypt ciphertext using AES
void aes_decrypt(unsigned char *ciphertext, unsigned char *decryptedtext) {
  AES_KEY key;
  AES_set_decrypt_key(aes_key, 128, &key);
  AES_decrypt(ciphertext, decryptedtext, &key);
}
int main() {
  unsigned char plaintext[100];
  fgets(plaintext, 100, stdin);
  plaintext[strcspn(plaintext, "\n")] = '\0';
  unsigned char ciphertext[AES_BLOCK_SIZE]; // AES block size is 128 bits
  unsigned char decryptedtext[AES_BLOCK_SIZE];
  // Encrypt the plaintext
  aes_encrypt(plaintext, ciphertext);
  // Decrypt the ciphertext
  aes_decrypt(ciphertext, decryptedtext);
  printf("Original message: %s\n", plaintext);
  printf("Encrypted message: ");
  for (int i = 0; i < AES_BLOCK_SIZE; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");
  printf("Decrypted message: %s\n", decryptedtext);
  return 0;
}
//gcc aes.c -lssl -lcrypto
