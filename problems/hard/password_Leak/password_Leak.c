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

int* find_anagram_indices(const char* s, const char* p, int* returnSize) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int* result = (int*)malloc(MAX_RESULT * sizeof(int));
    *returnSize = 0;

    if (s_len < p_len) return result;

    int p_count[26] = {0};
    int window_count[26] = {0};

    for (int i = 0; i < p_len; i++) {
        p_count[p[i] - 'a']++;
        window_count[s[i] - 'a']++;
    }

    for (int i = 0; i <= s_len - p_len; i++) {
        if (i > 0) {
            window_count[s[i - 1] - 'a']--;
            window_count[s[i + p_len - 1] - 'a']++;
        }

        if (is_anagram(p_count, window_count)) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}

int main() {
    const char* s = "cbaebabacd";
    const char* p = "abc";
    int returnSize;
    int* indices = find_anagram_indices(s, p, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    free(indices);
    return 0;
}

