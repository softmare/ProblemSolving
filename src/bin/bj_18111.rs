use std::error;
use std::io;

fn main() -> Result<(), Box<dyn error::Error>> {
    let inputs = read_int_vector()?;
    let (n, _m, b) = (inputs[0] as usize, inputs[1] as usize, inputs[2]);
    let mut map = vec![Vec::new(); n];

    for r in 0..n as usize {
        let inputs = read_int_vector()?;
        for i in inputs{
            map[r].push(i)
        }
    }

    let mut res_time = 987654321;
    let mut res_level = 0;

    for i in 0..257 {
        let cost = required_time(&i, &map, b);
        if cost == -1 {
            continue
        } else{
            if res_time >= cost{
                res_time = cost;
                res_level = i;
            }
        }
    }

    println!("{} {}", res_time, res_level);

    Ok(())
}

fn read_int_vector() -> Result<Vec<i32>, Box<dyn error::Error>> {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer)?;
    let inputs: Vec<i32> = buffer
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    Ok(inputs)
}

fn required_time(target_level: &i32, map: &Vec<Vec<i32>>, block_have : i32) -> i32 {
    let mut res = 0;
    let mut block_have = block_have;
    for r in map{
        for c in r{
            if c > target_level {
                res += (c-target_level) * 2;
                block_have += c - target_level;
            } else{
                res += target_level - c;
                block_have -= target_level - c;
            }
        }
    }

    if block_have >= 0 {
        res
    } else {
        -1
    }
}