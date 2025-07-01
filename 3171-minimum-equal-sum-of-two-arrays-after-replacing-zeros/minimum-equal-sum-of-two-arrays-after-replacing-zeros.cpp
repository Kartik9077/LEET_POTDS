class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,count1=0,count2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            if(nums1[i]==0)count1++;
        }
         for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
            if(nums2[i]==0)count2++;
        }
        long long min1=sum1+count1;
        long long min2=sum2+count2;
        if(count1==0&&count2==0){
            return sum1==sum2?sum1:-1;

        }
        if(count1==0){
            return min2<=sum1?sum1 :-1;
        }
        if(count2==0){
            return min1<=sum2?sum2 :-1;
        }
        return max(min1,min2);
       
        
    }
};