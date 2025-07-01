class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int c = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(c);
            if (c * 10 <= n) {
                c *= 10; 
            } else {
                if (c >= n) c /= 10;  
                c++;
                while (c % 10 == 0) c /= 10; 
            }
        }
        return res;
    }
};