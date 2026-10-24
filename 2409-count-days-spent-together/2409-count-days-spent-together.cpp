class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto f = [&](const string& s) {
            int m = stoi(s.substr(0, 2));
            int q = stoi(s.substr(3));
            int res = q;
            for (int i = 1; i < m; ++i)
                res += days[i];
            return res;
        };
        int a = f(arriveAlice), b = f(leaveAlice);
        int c = f(arriveBob), d = f(leaveBob);
        return max(0, min(b, d) - max(a, c) + 1);
    }
};