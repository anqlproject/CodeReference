pub fn counting_sort(values: &mut [i32]) {
    // The integer range must be small enough for its count array to fit in memory.
    if values.is_empty() { return; } let min = *values.iter().min().unwrap() as i64; let max = *values.iter().max().unwrap() as i64; let mut counts = vec![0usize; (max - min + 1) as usize]; for &v in values.iter() { counts[(v as i64 - min) as usize] += 1; } let mut k = 0; for (offset, count) in counts.into_iter().enumerate() { for _ in 0..count { values[k] = (min + offset as i64) as i32; k += 1; } }
}

fn main() { let mut values = [5, 1, 4, 2, 8]; counting_sort(&mut values); println!("{:?}", values); }
