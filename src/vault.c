/* Vault code: you do not need to read or modify this file :)
 *
 * The fragment is encrypted: it can only be decrypted with a key computed
 * from the correct triangle with the largest number of rows.
 */
#include <stdio.h>
#include <vault.h>

#define FNV_START 2166136261u

static unsigned int mix(unsigned int h, unsigned int v) {
    for (int i = 0; i < 4; i++) {
        h ^= (v >> (8 * i)) & 0xff;
        h *= 16777619u;
    }
    return h;
}

static unsigned int nextByte(unsigned int *s) {
    *s ^= *s << 13;
    *s ^= *s >> 17;
    *s ^= *s << 5;
    return *s & 0xff;
}

void vaultReveal(int **triangle, int n) {
    static const unsigned char enc[] = {0xf4, 0x47, 0x04, 0xf2, 0xed};
    const int len = sizeof(enc);
    char fragment[sizeof(enc) + 1];

    unsigned int s = mix(FNV_START, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            s = mix(s, triangle[i][j]);
        }
    }

    unsigned int h = FNV_START;
    for (int i = 0; i < len; i++) {
        fragment[i] = enc[i] ^ nextByte(&s);
        h = mix(h, (unsigned char)fragment[i]);
    }
    fragment[len] = '\0';

    if (h == 0xccb74eb1u) {
        printf("\n*** Vault fragment #2 of 4: \"%s\" ***\n", fragment);
    }
}
