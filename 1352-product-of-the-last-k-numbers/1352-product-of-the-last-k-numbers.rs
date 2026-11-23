struct ProductOfNumbers {
    prefix: Vec<i32>, // prefix[i] stores the product since the last 0
}

impl ProductOfNumbers {
    fn new() -> Self {
        Self {
            prefix: vec![1], // Base case for multiplication
        }
    }

    fn add(&mut self, num: i32) {
        if num == 0 {
            // A 0 resets the product history
            self.prefix.clear();
            self.prefix.push(1);
        } else {
            // Multiply the new number with the running product
            let last = *self.prefix.last().unwrap();
            self.prefix.push(last * num);
        }
    }

    fn get_product(&self, k: i32) -> i32 {
        let n = self.prefix.len();
        // If k is larger than the numbers since the last 0, the window includes a 0
        if k as usize >= n {
            return 0;
        }
        
        // Product of last k numbers is total product divided by product before them
        self.prefix[n - 1] / self.prefix[n - 1 - k as usize]
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */