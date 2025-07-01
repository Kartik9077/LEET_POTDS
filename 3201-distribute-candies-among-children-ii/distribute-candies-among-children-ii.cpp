class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            int candies_spent=n-i;
            if (candies_spent<= 2 * limit)
                res += min(candies_spent, limit) - max(0, candies_spent - limit) + 1;
        }
        return res;
    }
};