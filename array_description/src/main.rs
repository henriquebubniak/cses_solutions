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
    let mut ult: Vec<usize> = vec![0; m + 1];
    if x[0] == 0 {
        for num in ult.iter_mut().skip(1).take(m) {
            *num = 1;
        }
    } else {
        ult[x[0]] = 1;
    }
    for num in x.iter().take(n).skip(1) {
        if *num == 0 {
            let mut ult_buf = ult.clone();
            for j in 1..m + 1 {
                if j > 1 {
                    ult_buf[j] += ult[j - 1];
                    ult_buf[j] %= 10_usize.pow(9) + 7;
                }
                if j < m {
                    ult_buf[j] += ult[j + 1];
                    ult_buf[j] %= 10_usize.pow(9) + 7;
                }
            }
            ult = ult_buf;
        } else {
            let mut ult_buf = ult.clone();
            for j in 1..m + 1 {
                if j == *num {
                    if j > 1 {
                        ult_buf[j] += ult[j - 1];
                        ult_buf[j] %= 10_usize.pow(9) + 7;
                    }
                    if j < m {
                        ult_buf[j] += ult[j + 1];
                        ult_buf[j] %= 10_usize.pow(9) + 7;
                    }
                } else {
                    ult_buf[j] = 0;
                }
            }
            ult = ult_buf;
        }
    }
    println!("{}", ult.iter().sum::<usize>() % (10_usize.pow(9) + 7));
}
