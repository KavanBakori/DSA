class Solution {
private:
    const long long MOD = 1e9 + 7;

    // Fast modular exponentiation: (base^exp) % MOD in O(log exp)
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long count5 = (n + 1) / 2;
        long long count4 = n / 2;      

        long long first = power(5, count5);
        long long second = power(4, count4);

        return (first * second) % MOD;
    }
};