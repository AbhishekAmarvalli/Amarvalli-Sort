/*
 * Custom Two-Pointer Selection Sort (Java)
 * Time:  O(n^2)   Space: O(1)   Stable: No
 */
public class CustomSort {

    public static void twoPointerSelectionSort(int[] arr) {
        int n = arr.length;
        for (int sptr = 0; sptr < n - 1; sptr++) {
            int eptr = n - 1;
            int minDiff = arr[eptr] - arr[sptr];
            int minptr = eptr;
            eptr--;

            while (eptr != sptr) {
                int diff = arr[eptr] - arr[sptr];
                if (diff < minDiff) {
                    minDiff = diff;
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

    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 7};

        System.out.print("Before: ");
        printArr(arr);

        twoPointerSelectionSort(arr);

        System.out.print("After:  ");
        printArr(arr);
    }

    private static void printArr(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int v : arr) sb.append(v).append(' ');
        System.out.println(sb.toString().trim());
    }
}
