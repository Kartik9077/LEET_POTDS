class Solution {
    private:
        bool backtrack(string& num, int start, vector<long long>& store, int size) {
            if (start == num.size()) {
                return size > 2;
            }
            long long curr = 0;
            for (int i = start; i < num.size(); i++) {
                curr = (curr * 10) + num[i] - '0';
                if (curr > LLONG_MAX / 10 && i + 1 < num.size()) {
                    break;
                }
                if (size >= 2) {
                    if (store[size - 1] + store[size - 2] == curr) {
                        store.push_back(curr);
                        if (backtrack(num, i + 1, store, size + 1)) {
                            return true;
                        }
                        store.pop_back();
                    } else if (store[size - 1] + store[size - 2] < curr) {
                        break;
                    }
                } else {
                    store.push_back(curr);
                    if (backtrack(num, i + 1, store, size + 1)) {
                        return true;
                    }
                    store.pop_back();
                }
    
                if (i == start && num[i] == '0') {
                    break;
                }
            }
            return false;
        }
    public:
        bool isAdditiveNumber(string num) {
            vector<long long> store;
            return backtrack(num, 0, store, 0);
        }
    };
    int main(){
        // main function 
    }