#include <stdio.h>
#include <string.h>
#include <openssl/dsa.h>
#include <openssl/sha.h>

int main()
{
    DSA *dsa;
    unsigned char hash[SHA_DIGEST_LENGTH];
    unsigned int siglen;
    unsigned char signature[256];
    char message[200];

    printf("Enter the message to sign: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    dsa = DSA_new();

    if (dsa == NULL)
    {
        printf("DSA initialization failed!\n");
        return 1;
    }

    printf("\nGenerating DSA keys...\n");

    if (!DSA_generate_parameters_ex(dsa, 1024, NULL, 0,
                                    NULL, NULL, NULL))
    {
        printf("Parameter generation failed!\n");
        DSA_free(dsa);
        return 1;
    }

    if (!DSA_generate_key(dsa))
    {
        printf("Key generation failed!\n");
        DSA_free(dsa);
        return 1;
    }

    printf("DSA key pair generated successfully.\n");

    SHA1((unsigned char *)message, strlen(message), hash);

    printf("\nMessage: %s\n", message);

    printf("SHA-1 Hash: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");

    if (!DSA_sign(0, hash, SHA_DIGEST_LENGTH,
                  signature, &siglen, dsa))
    {
        printf("Signature generation failed!\n");
        DSA_free(dsa);
        return 1;
    }

    printf("\nDigital Signature generated successfully.\n");

    printf("Signature: ");
    for (unsigned int i = 0; i < siglen; i++)
        printf("%02x", signature[i]);
    printf("\n");

    if (DSA_verify(0, hash, SHA_DIGEST_LENGTH,
                   signature, siglen, dsa) == 1)
    {
        printf("\nSignature Verification: VALID\n");
    }
    else
    {
        printf("\nSignature Verification: INVALID\n");
    }

    DSA_free(dsa);

    return 0;
}
