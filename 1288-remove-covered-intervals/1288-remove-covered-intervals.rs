impl Solution {
    pub fn remove_covered_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        let mut intervals = intervals;
        
        // Sort by start ascending, and for equal starts, by end descending
        intervals.sort_by(|a, b| {
            match a[0].cmp(&b[0]) {
                std::cmp::Ordering::Equal => b[1].cmp(&a[1]), // larger end first
                other => other,
            }
        });

        let mut res = 0;
        let mut max_end = 0;

        for interval in &intervals {
            let start = interval[0];
            let end = interval[1];

            // If end > max_end, this interval is NOT covered
            if end > max_end {
                res += 1;
                max_end = end;
            }
            // Otherwise, it's covered by a previous interval
        }

        res
    }
}