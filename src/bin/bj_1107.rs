use std::io;
use std::error;

fn main()-> Result<(), Box<dyn error::Error>>{
    let mut ans;
    let target_channel = read_int_vector()?[0];
    let mut banned_number:Vec<i32> = Vec::new();
    if 0 != read_int_vector()?[0]{
        banned_number = read_int_vector()?;
    }
    let banned_number:Vec<usize> = banned_number.iter().map(|&e| e as usize).collect();
    let channel_range = (0..1000001 as usize).filter(
        |number| banned_number.iter().all(
            |one_of_banned| !number.to_string().contains(char::from_digit(*one_of_banned as u32, 10).unwrap())));

    ans = (target_channel - 100).abs();
    for n in channel_range{
        ans = std::cmp::min(ans, (n as i32 -target_channel).abs() + (n.to_string().len()) as i32 );
    }
    println!("{}", ans);
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