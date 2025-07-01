class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp;
        int i=0,j=0;
        while(j<s.size()){
            if((j-i)<k)temp+=s[j++];
            else{
                ans.push_back(temp);
                temp.clear();
                i=j;
            }
        }
        if(i<s.size()){
            while(temp.size()!=k)temp+=fill;
        }
        ans.push_back(temp);
        return ans;
    }
};