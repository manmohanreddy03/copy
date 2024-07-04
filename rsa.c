#include<stdio.h>
// Function to calculate (base^exp) % modulus
long long int power(long long int base, long long int exp, long long int modulus) {
long long int result = 1;
while (exp > 0) {
if (exp % 2 == 1) {
result = (result * base) % modulus;
}
base = (base * base) % modulus;
exp /= 2;
}
return result;
}

// Function to perform RSA encryption
long long int encrypt(long long int plaintext, long long int e, long long int n) {
return power(plaintext, e, n);
}

// Function to perform RSA decryption
long long int decrypt(long long int ciphertext, long long int d, long long int n) {
return power(ciphertext, d, n);
}

int main() {
// User input for prime numbers p and q
long long int p, q;
printf("Enter prime number p: ");
scanf("%lld", &p);
printf("Enter prime number q: ");
scanf("%lld", &q);

// Public and private keys
long long int n = p * q;
long long int phi = (p - 1) * (q - 1);

// User input for public exponent e
long long int e;
printf("Enter public exponent e (such that 1 < e < phiNo and e is coprime to phiNo): ");
scanf("%lld", &e);

// Private exponent calculation
long long int d = 1;
while (((d * e) % phi) != 1) {
d++;
}

// Message to be encrypted
long long int plaintext;
printf("Enter plaintext message: ");
scanf("%lld", &plaintext);

// Encryption
long long int ciphertext = encrypt(plaintext, e, n);
printf("Encrypted message: %lld\n", ciphertext);

// Decryption
long long int decryptedtext = decrypt(ciphertext, d, n);
printf("Decrypted message: %lld\n", decryptedtext);

return 0;
}
