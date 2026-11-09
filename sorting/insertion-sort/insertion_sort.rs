pub fn insertion_sort(values: &mut [i32]) {
    for i in 1..values.len() {
        let value = values[i];
        let mut j = i;
        while j > 0 && values[j - 1] > value {
            values[j] = values[j - 1];
            j -= 1;
        }
        values[j] = value;
    }
}

fn main() {
    let mut values = [5, 1, 4, 2, 8];
    insertion_sort(&mut values);
    println!("{:?}", values);
}
