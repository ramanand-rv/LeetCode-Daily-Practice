class Solution {
public:
    int brokenCalc(int a, int z) {
        int res = 0;
        while(z>a)
        {
            res++;
            if(z%2 == 0)
                z = z / 2;
            else
                z += 1;
        }
        res = res + (a - z);
        return res;
    }
};