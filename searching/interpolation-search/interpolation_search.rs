// Input is sorted ascending; when duplicates occur, any matching index may be returned.
fn interpolation_search(a: &[i64], x: i64) -> Option<usize> {
    let (mut l, mut r) = (0, a.len().checked_sub(1)?);
    while l <= r && a[l] <= x && x <= a[r] {
        if a[l] == a[r] {
            return if a[l] == x { Some(l) } else { None };
        }
        let p = l + (((x - a[l]) as i128 * (r - l) as i128 / (a[r] - a[l]) as i128) as usize);
        if a[p] == x {
            return Some(p);
        }
        if a[p] < x {
            l = p + 1
        } else {
            if p == 0 {
                break;
            }
            r = p - 1
        }
    }
    None
}
fn main() {
    println!("{:?}", interpolation_search(&[1, 2, 2, 4], 2));
}
