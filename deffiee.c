#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define P 23 // Prime number
#define G 5 // Primitive root modulo

// Function to calculate modular exponentiation (base^exp % modulus)
int mod_exp(int base, int exp, int modulus) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

// Function to perform Diffie-Hellman Key Exchange
void diffie_hellman(int private_key, int *public_key) {
    *public_key = mod_exp(G, private_key, P);
}

int main() {
    int private_key_client, private_key_server;
    int public_key_client, public_key_server;
    int shared_secret_client, shared_secret_server;

    // Take private keys for client and server from user
    printf("Enter the client's private key (integer): ");
    scanf("%d", &private_key_client);
    printf("Enter the server's private key (integer): ");
    scanf("%d", &private_key_server);

    // Perform Diffie-Hellman Key Exchange for client
    diffie_hellman(private_key_client, &public_key_client);
    // Perform Diffie-Hellman Key Exchange for server
    diffie_hellman(private_key_server, &public_key_server);

    // Calculate shared secrets
    shared_secret_client = mod_exp(public_key_server, private_key_client, P);
    shared_secret_server = mod_exp(public_key_client, private_key_server, P);

    // Print shared secrets
    printf("Client shared secret: %d\n", shared_secret_client);
    printf("Server shared secret: %d\n", shared_secret_server);

    return 0;
}
