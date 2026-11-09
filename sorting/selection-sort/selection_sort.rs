pub fn selection_sort(values: &mut [i32]) {
    for i in 0..values.len() { let mut min = i; for j in i + 1..values.len() { if values[j] < values[min] { min = j; } } values.swap(i, min); }
}

fn main() { let mut values = [5, 1, 4, 2, 8]; selection_sort(&mut values); println!("{:?}", values); }
