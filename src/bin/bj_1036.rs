use std::io;
use std::error;
use std::cmp::Ordering;

fn main() -> Result<(), Box<dyn error::Error>> {
    let mut input = String::new();
    let mut inputs = Vec::new();
    let mut num_accum = [[0; 53]; 36];
    let mut gap = [[0; 53]; 36];
    let base = 36;
    // read input
    io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<u32>().unwrap();
    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        // trim '0' from left
        input = input.trim_start_matches('0').to_string(); 
        inputs.push(input.clone());
        for (j, c) in input.trim().chars().rev().enumerate() {            
            let c = c.to_digit(base).unwrap();
            num_accum[c as usize][j] += c;
            gap[c as usize][j] += 35 - c;
        }
        
    }
    // apply organize_array
    for i in 0..36 {
        organize_array(&mut gap[i as usize]);
        //println!("i:{} {:?}",i, orgainzed_arr[i as usize])
    }
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let k = input.trim().parse::<usize>().unwrap();

    let mut rank: Vec<u32> = (0..36).collect();
    rank.sort_by(|a, b| cmp(&gap[*a as usize], &gap[*b as usize]));
    rank.reverse();
    // print Rank after convert to char
    //println!("rank: {:?}", rank.iter().map(|x| num_to_char(*x)).collect::<Vec<char>>());
    let conv_list = rank[..k].iter().map(|x| num_to_char(*x)).collect::<Vec<char>>();
    
    for s in inputs.iter_mut() {
        for c in conv_list.iter() {
            *s = s.replace(*c, "Z");
        }
    }
    let mut ansarr = [0; 53];
    for i in 0..36 {
        for j in 0..53 {
            ansarr[j] += num_accum[i as usize][j];
        }
    }
    for i in 0..k {
        for j in 0..53 {
            ansarr[j] += gap[rank[i] as usize][j];
        }
    }
    organize_array(&mut ansarr);

    print_arr(&ansarr);

    Ok(())
}

fn print_arr(arr: &[u32; 53]) -> () {
    if arr.iter().all(|&x| x == 0) {
        print!("0");
        return;
    }
    let mut writing = false;
    for i in (0..53).rev() {
        if arr[i] != 0 {
            writing = true;
        }
        if writing {
            print!("{}", num_to_char(arr[i]));
        }        
    }
}

fn num_to_char(n: u32) -> char {
    match n {
        0..=9 => (n as u8 + '0' as u8) as char,
        10..=35 => (n as u8 - 10 + 'A' as u8) as char,
        _ => panic!("invalid number"),
    }
}

fn organize_array(arr: &mut [u32; 53]) -> () {
    let mut accum = 0;
    let mut new_arr = [0; 53];
    for i in 0..53 {
        let cur = accum + arr[i];
        new_arr[i] = cur % 36;
        accum = cur / 36;
    }
    *arr = new_arr;
}

fn cmp(arr1: &[u32; 53], arr2: &[u32; 53]) -> Ordering {
    for i in (0..53).rev() {
        if arr1[i] > arr2[i] {
            return Ordering::Greater;
        } else if arr1[i] < arr2[i] {
            return Ordering::Less;
        }
    }
    Ordering::Equal
}