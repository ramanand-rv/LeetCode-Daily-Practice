impl Solution {
    pub fn lexicographically_smallest_array(nums: Vec<i32>, limit: i32) -> Vec<i32> {
    let mut nums = nums;
    let n = nums.len();

    // Step 1: Create array of (value, index) pairs
    let mut pairs: Vec<(i32, usize)> = nums.iter().enumerate().map(|(i, &v)| (v, i)).collect();

    // Step 2: Sort by value
    pairs.sort_by_key(|&(v, _)| v);

    // Step 3: Group by the limit condition
    let mut groups: Vec<(usize, usize)> = Vec::new();
    let mut start = 0;
    for i in 1..=n {
        if i == n || pairs[i].0 - pairs[i - 1].0 > limit {
            groups.push((start, i - 1));
            start = i;
        }
    }

    // Step 4: Process each group
    for (start, end) in groups {
        let len = end - start + 1;
        let mut values = Vec::with_capacity(len);
        let mut indices = Vec::with_capacity(len);

        for i in start..=end {
            values.push(pairs[i].0);
            indices.push(pairs[i].1);
        }

        // Sort indices to assign values lexicographically
        indices.sort_unstable();

        for i in 0..len {
            nums[indices[i]] = values[i];
        }
    }

    nums
}
}