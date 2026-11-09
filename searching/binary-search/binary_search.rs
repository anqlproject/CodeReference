fn binary_search(a: &[i32], x: i32) -> Option<usize> {
    let (mut l, mut r) = (0, a.len());
    while l < r {
        let m = l + (r - l) / 2;
        if a[m] < x {
            l = m + 1
        } else {
            r = m
        }
    }
    if l < a.len() && a[l] == x {
        Some(l)
    } else {
        None
    }
}
fn main() {
    println!("{:?}", binary_search(&[1, 3, 5, 7], 5));
}
