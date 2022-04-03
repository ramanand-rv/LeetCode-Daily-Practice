class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    auto i = is_sorted_until(nums.rbegin(), nums.rend());
    if (i != nums.rend())
        swap(*i, *upper_bound(nums.rbegin(), i, *i));
    reverse(nums.rbegin(), i);    }
};