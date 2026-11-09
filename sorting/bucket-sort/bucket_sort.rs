pub fn bucket_sort(values: &mut [i32]) {
    if values.len() < 2 {
        return;
    }
    let min = *values.iter().min().unwrap() as i64;
    let max = *values.iter().max().unwrap() as i64;
    if min == max {
        return;
    }
    let n = values.len();
    let span = max - min + 1;
    let mut buckets = vec![Vec::<i32>::new(); n];
    for &v in values.iter() {
        let b = (((v as i64 - min) * n as i64) / span).min(n as i64 - 1) as usize;
        buckets[b].push(v);
    }
    let mut k = 0;
    for bucket in &mut buckets {
        for i in 1..bucket.len() {
            let v = bucket[i];
            let mut j = i;
            while j > 0 && bucket[j - 1] > v {
                bucket[j] = bucket[j - 1];
                j -= 1;
            }
            bucket[j] = v;
        }
        for &v in bucket.iter() {
            values[k] = v;
            k += 1;
        }
    }
}

fn main() {
    let mut values = [5, 1, 4, 2, 8];
    bucket_sort(&mut values);
    println!("{:?}", values);
}
