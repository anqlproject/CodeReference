fn linear_search(a: &[i32], x: i32) -> Option<usize> {
    a.iter().position(|&v| v == x)
}
fn main() {
    println!("{:?}", linear_search(&[4, 2, 7], 2));
}
