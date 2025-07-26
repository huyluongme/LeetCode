#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void preprocess(const char* s, char* t) {
    int n = strlen(s);
    t[0] = '^';
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = s[i];
    }
    t[2 * n + 1] = '#';
    t[2 * n + 2] = '$';
    t[2 * n + 3] = '\0';
}

void manacher(const char* s, char* result) {
    int n = strlen(s);
    if (n == 0) {
        result[0] = '\0';
        return;
    }

    char* t = (char*)malloc(2 * n + 4);
    preprocess(s, t);

    int len = strlen(t);
    int* P = (int*)calloc(len, sizeof(int));
    int center = 0, right = 0;
    int maxLen = 0, centerIndex = 0;

    for (int i = 1; i < len - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = (P[mirror] < (right - i)) ? P[mirror] : (right - i);

        while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }

        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    free(t);
    free(P);
}

char* longestPalindrome(char* s) {
    char *result = (char *)malloc(strlen(s) + 1);
    manacher(s, result);
    return result;
}

int main() {
    char* input = "babad";
    printf("Longest Palindromic Substring: %s\n", longestPalindrome(input));

    return 0;
}