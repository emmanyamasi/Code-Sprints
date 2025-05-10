#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

char* organizingContainers(int** container, int n) {
    int* containerSums = (int*)calloc(n, sizeof(int));
    int* typeSums = (int*)calloc(n, sizeof(int));

    if (!containerSums || !typeSums) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Calculate container row sums
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            containerSums[i] += container[i][j];

    // Calculate type column sums
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            typeSums[j] += container[i][j];

    // Sort both arrays
    qsort(containerSums, n, sizeof(int), compare);
    qsort(typeSums, n, sizeof(int), compare);

    // Compare sorted sums
    for (int i = 0; i < n; i++) {
        if (containerSums[i] != typeSums[i]) {
            free(containerSums);
            free(typeSums);
            return "Impossible";
        }
    }

    free(containerSums);
    free(typeSums);
    return "Possible";
}

