class Solution {
    const long long  mod =1e9+7;
    long long mod_add(long long a,long long b){
        a=a%mod;b=b%mod;return (((a+b)%mod)+mod)%mod;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>nums(26,0);long long ans=0;
        for(int i=0;i<s.size();i++){
            nums[s[i]-'a']++;
        }

        while(t--){
            int curr[26]={0};
            for(int j=0;j<26;j++){

                if(j==25&&nums[j]!=0){
                   curr[0]=mod_add(curr[0],nums[j]);
                   curr[1]=mod_add(curr[1],nums[j]);
                }
                else if( nums[j]!=0){
                    
                    curr[j+1]=mod_add(curr[j+1],nums[j]);

                }
            }
            for(int j=0;j<26;j++){
                nums[j]=curr[j];
            }

        }
        for(auto ti:nums)ans=mod_add(ans,ti);

        
        return ans % mod;





        }
};