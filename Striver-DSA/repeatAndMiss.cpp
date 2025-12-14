class Solution {
    public:
        vector<int> findMissingRepeatingNumbers(vector<int> nums) {
            int n = nums.size();
            vector<int>freq(n+1,0);
            int a,b;
            for(int x:nums){
                if(freq[x]) a=x;
                freq[x]++;
            }
            for(int i=1;i<=n;i++){
                if(freq[i]==0) b=i;
            }
            return {a,b};
        }
    };