#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key = "mykey123";
    DES_key_schedule schedule;
    DES_cblock plaintext = "ABCDEFGH";
    DES_cblock ciphertext;
    DES_cblock decryptedtext;

    DES_set_key_unchecked(&key, &schedule);

    DES_ecb_encrypt(&plaintext, &ciphertext, &schedule, DES_ENCRYPT);

    DES_ecb_encrypt(&ciphertext, &decryptedtext, &schedule, DES_DECRYPT);

    printf("Plaintext : %s\n", plaintext);

    printf("Ciphertext: ");
    for (int i = 0; i < 8; i++)
        printf("%02X ", ciphertext[i]);
    printf("\n");

    printf("Decrypted : %s\n", decryptedtext);

    return 0;
}
