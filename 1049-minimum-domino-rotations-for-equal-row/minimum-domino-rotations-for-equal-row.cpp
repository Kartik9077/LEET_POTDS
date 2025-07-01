class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
     int n=tops.size();
     bool hasx=1;
     bool hasy=1;
     int num1=tops[0];
     int num2=bottoms[0];
     int countxa=0,countxb=0;
     int countya=0,countyb=0;
     for(int i=0;i<n;i++){
        if(hasx){
            if(tops[i]!=num1&&bottoms[i]!=num1){
                hasx=0;
            }
            else{
                if(tops[i]!=num1){
                    countxa++;
                }
                if(bottoms[i]!=num1){
                    countxb++;
                }
            }
        }
        if(hasy){
            if(tops[i]!=num2&&bottoms[i]!=num2){
                hasy=0;
            }
            else{
                if(tops[i]!=num2){
                    countya++;
                }
                if(bottoms[i]!=num2){
                    countyb++;
                }
            }

        }if(hasx==0&&hasy==0){
        return -1;
     }
     }
     
     int ans=INT_MAX;
     if(hasx) ans=min(ans,min(countxa,countxb));
     if(hasy) ans=min(ans,min(countya,countyb));
     return ans;

        
    }
};