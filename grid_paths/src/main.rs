use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: usize = buf.trim().parse().unwrap();
    let mut matrix: Vec<Vec<i32>> = Vec::new();
    matrix.resize(n, vec![]);
    for line in matrix.iter_mut().take(n) {
        line.resize(n, -1);
    }
    for line in matrix.iter_mut().take(n) {
        let mut buf = String::new();
        io::stdin().read_line(&mut buf).unwrap();
        for (j, c) in buf.char_indices() {
            if c == '*' {
                line[j] = 0;
            }
        }
    }
    if matrix[n - 1][n - 1] == -1 {
        matrix[n - 1][n - 1] = 1;
    }
    for i in (0..n - 1).rev() {
        if matrix[n - 1][i] == -1 {
            matrix[n - 1][i] = matrix[n - 1][i + 1];
        }
        if matrix[i][n - 1] == -1 {
            matrix[i][n - 1] = matrix[i + 1][n - 1];
        }
    }
    for i in (0..n - 1).rev() {
        for j in (0..n - 1).rev() {
            if matrix[i][j] == -1 {
                matrix[i][j] = (matrix[i][j + 1] + matrix[i + 1][j]) % (10_i32.pow(9) + 7);
            }
        }
    }
    println!("{}", matrix[0][0]);
}
