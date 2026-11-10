#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main() {
    BF_KEY key;
    unsigned char text[16] = "HELLO WORLD";
    unsigned char encrypted[16], decrypted[16];
    unsigned char password[] = "secret";
    BF_set_key(&key, strlen((char *)password), password);
    for(int i = 0; i < 16; i += 8)
        BF_ecb_encrypt(text + i, encrypted + i, &key, BF_ENCRYPT);
    printf("Encrypted: ");
    for(int i = 0; i < 16; i++)
        printf("%02X", encrypted[i]);
    for(int i = 0; i < 16; i += 8)
        BF_ecb_encrypt(encrypted + i, decrypted + i, &key, BF_DECRYPT);
    printf("\nDecrypted: %s\n", decrypted);
    return 0;
}
