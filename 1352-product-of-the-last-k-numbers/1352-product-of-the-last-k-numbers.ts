class ProductOfNumbers {
    private prefix: number[];

    constructor() {
        this.prefix = [1]; // Base case for multiplication
    }

    add(num: number): void {
        if (num === 0) {
            // A 0 resets the product history
            this.prefix = [1];
        } else {
            // Multiply the new number with the running product
            this.prefix.push(this.prefix[this.prefix.length - 1] * num);
        }
    }

    getProduct(k: number): number {
        const n = this.prefix.length;
        // If k is larger than the numbers since the last 0, the window includes a 0
        if (k >= n) return 0;

        // Product of last k numbers is total product divided by product before them
        return this.prefix[n - 1] / this.prefix[n - 1 - k];
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */