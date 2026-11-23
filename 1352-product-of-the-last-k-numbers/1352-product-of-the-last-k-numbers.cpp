class ProductOfNumbers {
    vector<int>
        prefix; // prefix[i] stores the product of numbers since the last 0

public:
    ProductOfNumbers() {
        prefix.push_back(1); // Base case for multiplication
    }

    void add(int num) {
        if (num == 0) {
            // A 0 resets the product history because any window including 0 is
            // 0
            prefix.clear();
            prefix.push_back(1);
        } else {
            // Multiply the new number with the running product
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        // If k is larger than the numbers since the last 0, the window includes
        // a 0
        if (k >= prefix.size())
            return 0;

        // Product of last k numbers is total product divided by product before
        // them
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */