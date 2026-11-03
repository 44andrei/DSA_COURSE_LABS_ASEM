#include <stdio.h>
#include <stdlib.h>

int partition(int* values, int lo, int hi) {
    int pivot = values[lo];
    int boundary = lo;
    for (int i = lo + 1; i < hi; i++) {
        if (values[i] < pivot) {
            boundary++;
            int temp = values[boundary];
            values[boundary] = values[i];
            values[i] = temp;
        }
    }
    int temp = values[lo];
    values[lo] = values[boundary];
    values[boundary] = temp;
    return boundary;
}

void quickSort(int* values, int lo, int hi) {
    if (hi - lo <= 1) return;
    int p = partition(values, lo, hi);
    quickSort(values, lo, p);
    quickSort(values, p + 1, hi);
}
