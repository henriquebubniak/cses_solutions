use std::io;

fn dp(n: i32) -> i32 {
    if n < 10 {
        return 1;
    }
    let mut n1 = n;
    let mut max = 0;
    while n1 > 0 {
        if n1 % 10 > max {
            max = n1 % 10;
        }
        n1 /= 10;
    }
    dp(n - max) + 1
}

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: i32 = buf.trim().parse().unwrap();
    println!("{}", dp(n));
}
