class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n=nums.size();
            vector<int>freq(n+1,0);
            for(int x:nums){
                if(freq[x]) return x;
                freq[x]++;
            }
            return 0;
        }
    };