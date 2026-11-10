#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char text[1000];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    SHA256((unsigned char *)text, strlen(text), hash);
    printf("Hash: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}
