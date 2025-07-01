class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>visited(nums.size(),-1);
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int low=max(i-k,0),high=min((int)nums.size()-1,i+k);
                for(int j=low;j<=high;j++)
                {
                if(visited[j]==-1)
                {visited[j]=1;
                  ans.push_back(j);}
                }
            }
        }
        return ans;
    }
};