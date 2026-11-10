#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main() {
    BF_KEY key;
    unsigned char text[8] = "HELLO123";
    unsigned char encrypted[8], decrypted[8];
    unsigned char password[] = "secret";
    BF_set_key(&key, strlen((char *)password), password);
    BF_ecb_encrypt(text, encrypted, &key, BF_ENCRYPT);
    printf("Encrypted: ");
    for(int i = 0; i < 8; i++)
        printf("%02X", encrypted[i]);
    BF_ecb_encrypt(encrypted, decrypted, &key, BF_DECRYPT);
    printf("\nDecrypted: %s\n", decrypted);
    return 0;
}
