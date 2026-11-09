pub fn radix_sort(values: &mut [i32]) {
    assert!(
        values.iter().all(|&v| v >= 0),
        "radix sort supports non-negative integers only"
    );
    let mut exp = 1i64;
    let max = *values.iter().max().unwrap_or(&0) as i64;
    let mut out = vec![0i32; values.len()];
    while max / exp > 0 {
        let mut count = [0usize; 10];
        for &v in values.iter() {
            count[((v as i64 / exp) % 10) as usize] += 1;
        }
        for i in 1..10 {
            count[i] += count[i - 1];
        }
        for &v in values.iter().rev() {
            let d = ((v as i64 / exp) % 10) as usize;
            count[d] -= 1;
            out[count[d]] = v;
        }
        values.copy_from_slice(&out);
        exp *= 10;
    }
}

fn main() {
    let mut values = [5, 1, 4, 2, 8];
    radix_sort(&mut values);
    println!("{:?}", values);
}
