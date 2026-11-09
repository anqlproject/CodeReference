pub fn shell_sort(values: &mut [i32]) {
    let mut gap = values.len() / 2; while gap > 0 { for i in gap..values.len() { let value = values[i]; let mut j = i; while j >= gap && values[j - gap] > value { values[j] = values[j - gap]; j -= gap; } values[j] = value; } gap /= 2; }
}

fn main() { let mut values = [5, 1, 4, 2, 8]; shell_sort(&mut values); println!("{:?}", values); }
