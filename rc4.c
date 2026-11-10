#include <stdio.h>
#include <string.h>

void rc4(unsigned char *data, int len, unsigned char *key, int keylen) {
    unsigned char S[256], temp;
    int j = 0, i;
    for(i = 0; i < 256; i++)
        S[i] = i;
    for(i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keylen]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
    i = 0;
    j = 0;
    for(int n = 0; n < len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        data[n] ^= S[(S[i] + S[j]) % 256];
    }
}

int main() {
    unsigned char text[] = "HELLO WORLD";
    unsigned char key[] = "secret";
    int len = strlen((char *)text);
    rc4(text, len, key, strlen((char *)key));
    printf("Encrypted: ");
    for(int i = 0; i < len; i++)
        printf("%02X", text[i]);
    rc4(text, len, key, strlen((char *)key));
    printf("\nDecrypted: %s\n", text);
    return 0;
}
