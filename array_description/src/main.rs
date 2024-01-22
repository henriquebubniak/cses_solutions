use std::io;

fn read() -> (usize, usize, Vec<usize>) {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let input_vec: Vec<usize> = buf
        .trim()
        .split(' ')
        .map(|str| str.parse().unwrap())
        .collect();

    let (n, m) = (input_vec[0], input_vec[1]);
    buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let x: Vec<usize> = buf
        .trim()
        .split(' ')
        .map(|str| str.parse().unwrap())
        .collect();
    (n, m, x)
}

fn main() {
    let (n, m, x) = read();
    let mut ult: Vec<usize> = Vec::new();
    ult.resize(m+1, 0);
    if x[0] == 0 {
        for i in 1..m+1 {
            ult[i] = 1;
        }
    } else {
        ult[x[0]] = 1;
    }
    for i in 1..n {
        if x[i] == 0 {
            let mut ult_buf = ult.clone();
            for j in 1..m+1 {
                if j > 1 {
                    ult_buf[j] += ult[j-1];
                    ult_buf[j] = ult_buf[j] % (10_usize.pow(9) + 7);
                }
                if j < m {
                    ult_buf[j] += ult[j+1];
                    ult_buf[j] = ult_buf[j] % (10_usize.pow(9) + 7);
                }
            }
            ult = ult_buf;
        } else {
            let mut ult_buf = ult.clone();
            for j in 1..m+1 {
                if j == x[i] {
                    if j > 1 {
                        ult_buf[j] += ult[j-1];
                        ult_buf[j] = ult_buf[j] % (10_usize.pow(9) + 7);
                    }
                    if j < m {
                        ult_buf[j] += ult[j+1];
                        ult_buf[j] = ult_buf[j] % (10_usize.pow(9) + 7);
                    }
                } else {
                    ult_buf[j] = 0;
                }
            }
            ult = ult_buf;
        }
    }
    println!("{}", ult.iter().sum::<usize>()% (10_usize.pow(9) + 7));
}
