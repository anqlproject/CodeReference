pub fn heap_sort(values: &mut [i32]) {
    fn sift(a: &mut [i32], mut root: usize, end: usize) { loop { let child = root * 2 + 1; if child >= end { break; } let child = if child + 1 < end && a[child] < a[child + 1] { child + 1 } else { child }; if a[root] >= a[child] { break; } a.swap(root, child); root = child; } }
    for root in (0..values.len() / 2).rev() { sift(values, root, values.len()); } for end in (1..values.len()).rev() { values.swap(0, end); sift(values, 0, end); }
}

fn main() { let mut values = [5, 1, 4, 2, 8]; heap_sort(&mut values); println!("{:?}", values); }
