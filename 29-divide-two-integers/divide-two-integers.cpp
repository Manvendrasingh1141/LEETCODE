class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = a / b;

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};