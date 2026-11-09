pub fn merge_sort(values: &mut [i32]) {
    fn split(a: &mut [i32], tmp: &mut [i32]) {
        let n = a.len();
        if n < 2 {
            return;
        }
        let mid = n / 2;
        let (left, right) = a.split_at_mut(mid);
        let (tl, tr) = tmp.split_at_mut(mid);
        split(left, tl);
        split(right, tr);
        let (mut i, mut j) = (0, mid);
        for out in tmp.iter_mut().take(n) {
            if j == n || (i < mid && a[i] <= a[j]) {
                *out = a[i];
                i += 1;
            } else {
                *out = a[j];
                j += 1;
            }
        }
        a.copy_from_slice(&tmp[..n]);
    }
    let mut tmp = values.to_vec();
    split(values, &mut tmp);
}

fn main() {
    let mut values = [5, 1, 4, 2, 8];
    merge_sort(&mut values);
    println!("{:?}", values);
}
