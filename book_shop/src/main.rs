use std::{cmp::max, io};

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let input_vec: Vec<usize> = buf
        .trim()
        .split(' ')
        .map(|str| str.parse().unwrap())
        .collect();

    let (n, x) = (input_vec[0], input_vec[1]);
    buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let h: Vec<usize> = buf
        .trim()
        .split(' ')
        .map(|str| str.parse().unwrap())
        .collect();

    buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let s: Vec<i32> = buf
        .trim()
        .split(' ')
        .map(|str| str.parse().unwrap())
        .collect();

    let mut matrix: Vec<Vec<i32>> = Vec::new();
    matrix.resize(n + 1, vec![]);
    for line in &mut matrix {
        line.resize(x + 1, 0);
    }
    for i in 1..n + 1 {
        for j in 1..x + 1 {
            if h[i - 1] > j {
                matrix[i][j] = matrix[i - 1][j];
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - h[i - 1]] + s[i - 1]);
            }
        }
    }
    println!("{}", matrix[n][x]);
}
