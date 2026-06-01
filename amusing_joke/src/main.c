#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 102

int main() {
    int letters[26] = {0};

    char s1[STRLEN] = {0};
    char s2[STRLEN] = {0};
    char s3[STRLEN] = {0};

    fgets((char*)&s1, STRLEN, stdin);
    fgets((char*)&s2, STRLEN, stdin);
    fgets((char*)&s3, STRLEN, stdin);

    /*
    printf("s1: %s", s1);
    printf("s2: %s", s2);
    printf("s3: %s", s3);
    */

    size_t s1_len = strlen(s1)-1;
    size_t s2_len = strlen(s2)-1;
    size_t s3_len = strlen(s3)-1;

    // store s3 letters in the
    for (size_t i = 0; i < s3_len; i++) {
        char ch = s3[i];
        letters[ch - 65]++;
    }

    // decrease the count of the each letter from letters array
    for (size_t i = 0; i < s1_len; i++) {
        char ch = s1[i];
        letters[ch - 65]--;
    }

    // decrease the count of the each letter from letters array
    for (size_t i = 0; i < s2_len; i++) {
        char ch = s2[i];
        letters[ch - 65]--;
    }

    // check if any extra letters remains 
    // if so then return NO
    // else return YES
    for (size_t i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
