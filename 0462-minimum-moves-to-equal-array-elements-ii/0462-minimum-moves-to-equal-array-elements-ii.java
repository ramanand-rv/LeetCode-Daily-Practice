import java.util.Random;

class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length, k = n / 2;
        Random rnd = new Random();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int pivot = nums[lo + rnd.nextInt(hi - lo + 1)];
            int lt = lo, gt = hi, i = lo;
            while (i <= gt) {
                if (nums[i] < pivot) {
                    swap(nums, lt++, i++);
                } else if (nums[i] > pivot) {
                    swap(nums, i, gt--);
                } else {
                    i++;
                }
            }
            if (k < lt) hi = lt - 1;
            else if (k > gt) lo = gt + 1;
            else break;
        }
        int median = nums[k];
        long res = 0;
        for (int x : nums) res += Math.abs((long) x - median);
        return (int) res;
    }

    private void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
};