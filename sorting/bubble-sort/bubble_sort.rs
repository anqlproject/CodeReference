pub fn bubble_sort(values: &mut [i32]) {
    for end in (1..values.len()).rev() { let mut swapped = false; for i in 0..end { if values[i] > values[i + 1] { values.swap(i, i + 1); swapped = true; } } if !swapped { break; } }
}

fn main() { let mut values = [5, 1, 4, 2, 8]; bubble_sort(&mut values); println!("{:?}", values); }
