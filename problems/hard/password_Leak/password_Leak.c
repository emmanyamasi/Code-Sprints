#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESULT 1000

int is_anagram(const int* a, const int* b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int* find_anagram_indices(char* s, char* p, int* returnSize) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int* result = (int*)malloc(MAX_RESULT * sizeof(int));
    *returnSize = 0;

    if (s_len < p_len) return result;

    int p_count[26] = {0};
    int s_count[26] = {0};

    for (int i = 0; i < p_len; i++) {
        p_count[p[i] - 'a']++;
        s_count[s[i] - 'a']++;
    }

    for (int i = 0; i <= s_len - p_len; i++) {
        if (i > 0) {
            // Slide the window: remove one, add one
            s_count[s[i - 1] - 'a']--;
            s_count[s[i + p_len - 1] - 'a']++;
        }

        if (is_anagram(p_count, s_count)) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}
