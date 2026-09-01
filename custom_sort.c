/*
 * Custom Two-Pointer Selection Sort (C)
 * Time:  O(n^2)   Space: O(1)   Stable: No
 */
#include <stdio.h>

void two_pointer_selection_sort(int arr[], int n) {
    for (int sptr = 0; sptr < n - 1; sptr++) {
        int eptr = n - 1;
        int min_diff = arr[eptr] - arr[sptr];
        int minptr = eptr;
        eptr--;

        while (eptr != sptr) {
            int diff = arr[eptr] - arr[sptr];
            if (diff < min_diff) {
                min_diff = diff;
                minptr = eptr;
            }
            eptr--;
        }

        if (arr[sptr] > arr[minptr]) {
            int tmp = arr[sptr];
            arr[sptr] = arr[minptr];
            arr[minptr] = tmp;
        } else {
            int tmp = arr[sptr + 1];
            arr[sptr + 1] = arr[minptr];
            arr[minptr] = tmp;
        }
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    print_arr(arr, n);

    two_pointer_selection_sort(arr, n);

    printf("After:  ");
    print_arr(arr, n);

    return 0;
}
