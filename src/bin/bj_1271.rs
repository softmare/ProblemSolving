use std::error::Error;
use std::cmp::Ordering;
use std::fmt;

type Result<T> = std::result::Result<T, MyNumError>;

#[derive(Debug, Clone)]
struct MyNumError;

impl fmt::Display for MyNumError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "my num error occured")
    }
}

const MY_NUM_ARRAY_MAX : usize = 1001;

struct MyNum{
    array : [u8; MY_NUM_ARRAY_MAX],
}

impl MyNum {
    fn cmp(&self, this : MyNum) -> Ordering{
        let self_len = self.len();
        let this_len = this.len();
        if self_len != this_len {
            match self_len > this_len {
                true => return Ordering::Greater,
                false => return Ordering::Less,
            }
        }
        for i in 0..MY_NUM_ARRAY_MAX {
            if self.array[i] == this.array[i] {
                continue
            }
            match self.array[i] > this.array[i] {
                true => return Ordering::Greater,
                false => return Ordering::Less,
            }
        }
        Ordering::Equal
    }

    fn len(&self) -> usize{
        let mut len = MY_NUM_ARRAY_MAX as i32;
        for u in self.array {
            match u {
                0 => { len =- 1;continue},
                _ => break,
            }  
        } 
        (MY_NUM_ARRAY_MAX as i32 - len) as usize
    }

    pub fn sub(&mut self, suber : MyNum) -> Result<MyNum>{

        Err(MyNumError)
    }

    pub fn receive(&mut self, input : &str) {
        self.array = [0; MY_NUM_ARRAY_MAX];
        let mut str_i = input.len();
        if str_i > MY_NUM_ARRAY_MAX{
            str_i = MY_NUM_ARRAY_MAX;
        }
        let my_enum = input.chars().enumerate();
        for (i, c)  in my_enum.rev(){
            
        }        
    }

    pub 

}

fn main() {

}