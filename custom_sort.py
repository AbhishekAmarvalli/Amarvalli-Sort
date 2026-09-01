"""
Custom Two-Pointer Selection Sort
----------------------------------
A selection-sort variant that uses a two-pointer sweep (sptr, eptr) on
each pass to find the element with the smallest signed difference
relative to sptr, then places it correctly.

Time:  O(n^2) best/avg/worst
Space: O(1) auxiliary
Stable: No
"""

from typing import List


def two_pointer_selection_sort(arr: List[int]) -> List[int]:
    n = len(arr)
    for sptr in range(n - 1):
        eptr = n - 1
        min_diff = arr[eptr] - arr[sptr]
        minptr = eptr
        eptr -= 1

        while eptr != sptr:
            diff = arr[eptr] - arr[sptr]
            if diff < min_diff:
                min_diff = diff
                minptr = eptr
            eptr -= 1

        if arr[sptr] > arr[minptr]:
            arr[sptr], arr[minptr] = arr[minptr], arr[sptr]
        else:
            arr[sptr + 1], arr[minptr] = arr[minptr], arr[sptr + 1]

    return arr


if __name__ == "__main__":
    sample = [5, 2, 9, 1, 7]
    print("Before:", sample)
    print("After: ", two_pointer_selection_sort(sample.copy()))
