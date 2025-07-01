class Solution {
public:
 static bool comp(pair<int,int>&a,pair<int,int>&b)
{return a.first>b.first;}
static bool mycmp(pair<int,int>&a,pair<int,int>&b){return a.second<b.second;}
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>ans;
        int i=0;
        for(auto it:nums){
            ans.push_back({it,i});
            i++;
        }
        sort(ans.begin(),ans.end(),comp);
        ans.resize(k);
        sort(ans.begin(),ans.end(),mycmp);
        vector<int>an;
        for(int i=0;i<ans.size();i++){
            an.push_back(ans[i].first);

        }
        return an;
    }
};