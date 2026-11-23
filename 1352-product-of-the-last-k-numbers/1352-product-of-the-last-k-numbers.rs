struct ProductOfNumbers {
    size: usize,
    zero: i32,
    positions: Vec<usize>, 
    factor: Vec<i32>,
}

impl ProductOfNumbers {
    fn new() -> Self {
        Self {
            size: 0,
            zero: -1,
            positions: vec![],
            factor: vec![],
        }
    }

    fn add(&mut self, num: i32) {
        if num == 0 {
            // Reset everything since any window including 0 is 0
            self.zero = self.size as i32;
            self.positions.clear();
            self.factor.clear();
        } else if num > 1 {
            // Only store numbers that affect the product
            self.positions.push(self.size);
            self.factor.push(num);
        }
        self.size += 1;
    }

    fn get_product(&self, k: i32) -> i32 {
        let start = self.size as i32 - k;
        // If the last zero is within or after the start of the window, product is 0
        if self.zero >= start {
            return 0;
        }

        // Binary search to find the first stored position >= start
        let mut left = 0;
        let mut right = self.positions.len();
        while left < right {
            let mid = (left + right) / 2;
            if (self.positions[mid] as i32) < start {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Multiply all factors from 'left' to the end
        let mut ans = 1;
        for i in left..self.factor.len() {
            ans *= self.factor[i];
        }
        ans
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */