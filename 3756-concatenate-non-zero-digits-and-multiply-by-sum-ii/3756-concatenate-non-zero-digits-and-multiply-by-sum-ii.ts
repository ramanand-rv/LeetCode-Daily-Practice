const MOD = 1000000007;
const MAX = 100001;

const pow = new Int32Array(MAX);
pow[0] = 1;

for (let i = 1; i < MAX; i++)
    pow[i] = (pow[i - 1] * 10) % MOD;

const sumAndMultiply = (s, queries) => {
    const n = s.length;
    const A = new Int32Array(n + 1);
    const B = new Int32Array(n + 1);
    const len = new Int32Array(n + 1);

    for (let i = 0; i < n; i++) {
        const d = Number(s[i]);
        A[i + 1] = A[i] + d;
        B[i + 1] = d ? (B[i] * 10 + d) % MOD : B[i];
        len[i + 1] = len[i] + (d ? 1 : 0);
    }

    const res = [];

    for (let [l, r] of queries) {
        r++;

        const ln = len[r] - len[l];
        const sub = Number((BigInt(B[l]) * BigInt(pow[ln])) % BigInt(MOD));
        let x = B[r] - sub;

        x = ((x % MOD) + MOD) % MOD;

        res.push((x * (A[r] - A[l])) % MOD);
    }

    return res;
};