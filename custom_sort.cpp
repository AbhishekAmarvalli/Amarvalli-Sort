/*
 * Custom Two-Pointer Selection Sort (C++)
 * Time:  O(n^2)   Space: O(1)   Stable: No
 */
#include <iostream>
#include <vector>

void two_pointer_selection_sort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int sptr = 0; sptr < n - 1; ++sptr) {
        int eptr = n - 1;
        int min_diff = arr[eptr] - arr[sptr];
        int minptr = eptr;
        --eptr;

        while (eptr != sptr) {
            int diff = arr[eptr] - arr[sptr];
            if (diff < min_diff) {
                min_diff = diff;
                minptr = eptr;
            }
            --eptr;
        }

        if (arr[sptr] > arr[minptr]) {
            std::swap(arr[sptr], arr[minptr]);
        } else {
            std::swap(arr[sptr + 1], arr[minptr]);
        }
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 7};

    std::cout << "Before: ";
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';

    two_pointer_selection_sort(arr);

    std::cout << "After:  ";
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}
