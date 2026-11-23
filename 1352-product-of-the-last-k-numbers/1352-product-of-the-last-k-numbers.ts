class ProductOfNumbers {
    size: number;
    zero: number;
    where: number[];
    factor: number[];

    constructor() {
        this.size = 0;
        this.zero = -1;
        this.where = [];
        this.factor = [];
    }

    add(num: number): void {
        if (num === 0) {
            // Reset everything since any window including 0 is 0
            this.zero = this.size;
            this.where = [];
            this.factor = [];
        } else if (num > 1) {
            // Only store numbers that affect the product
            this.where.push(this.size);
            this.factor.push(num);
        }
        this.size++;
    }

    getProduct(k: number): number {
        const start = this.size - k;
        // If the last zero is within or after the start of the window, product is 0
        if (this.zero >= start) {
            return 0;
        }

        // Binary search to find the first stored position >= start
        let left = 0, right = this.where.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (this.where[mid] < start) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Multiply all factors from 'left' to the end
        let ans = 1;
        for (let i = left; i < this.factor.length; i++) {
            ans *= this.factor[i];
        }
        return ans;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */