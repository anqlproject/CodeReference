pub fn quick_sort(values: &mut [i32]) {
    fn partition(a: &mut [i32], lo: isize, hi: isize) {
        let (mut i, mut j) = (lo, hi);
        let pivot = a[(lo + (hi - lo) / 2) as usize];
        while i <= j {
            while a[i as usize] < pivot {
                i += 1;
            }
            while a[j as usize] > pivot {
                j -= 1;
            }
            if i <= j {
                a.swap(i as usize, j as usize);
                i += 1;
                j -= 1;
            }
        }
        if lo < j {
            partition(a, lo, j);
        }
        if i < hi {
            partition(a, i, hi);
        }
    }
    if !values.is_empty() {
        let hi = values.len() as isize - 1;
        partition(values, 0, hi);
    }
}

fn main() {
    let mut values = [5, 1, 4, 2, 8];
    quick_sort(&mut values);
    println!("{:?}", values);
}
