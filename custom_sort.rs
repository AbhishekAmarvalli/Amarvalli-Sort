// Custom Two-Pointer Selection Sort (Rust)
// Time:  O(n^2)   Space: O(1)   Stable: No

fn two_pointer_selection_sort(arr: &mut [i32]) {
    let n = arr.len();
    for sptr in 0..n.saturating_sub(1) {
        let mut eptr = n - 1;
        let mut min_diff = arr[eptr] - arr[sptr];
        let mut minptr = eptr;
        eptr -= 1;

        while eptr != sptr {
            let diff = arr[eptr] - arr[sptr];
            if diff < min_diff {
                min_diff = diff;
                minptr = eptr;
            }
            eptr -= 1;
        }

        if arr[sptr] > arr[minptr] {
            arr.swap(sptr, minptr);
        } else {
            arr.swap(sptr + 1, minptr);
        }
    }
}

fn main() {
    let mut arr = vec![5, 2, 9, 1, 7];

    println!("Before: {:?}", arr);
    two_pointer_selection_sort(&mut arr);
    println!("After:  {:?}", arr);
}
