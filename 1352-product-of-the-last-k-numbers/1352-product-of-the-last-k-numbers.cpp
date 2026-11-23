class ProductOfNumbers {
    int size = 0;
    int zero = -1;
    vector<int> where, factor;

public:
    void add(int num) {
        if (num == 0) {
            zero = size;
            where.clear();
            factor.clear();
        } else if (num > 1) {
            where.push_back(size);
            factor.push_back(num);
        }
        ++size;
    }

    int getProduct(int k) {
        int start = size - k;
        if (zero >= start)
            return 0;
        // Find how many stored numbers are before the window
        auto outside =
            lower_bound(where.begin(), where.end(), start) - where.begin();
        int ans = 1;
        // Multiply the numbers inside the window
        for (int i = outside; i < factor.size(); ++i) {
            ans *= factor[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */