class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int>st(nums.begin(),nums.end());
            int ans=0;
            for(int x:st){
                int cnt = 1;
                if(!st.count(x-1)){
                    while(st.count(x+1)){
                        cnt++;
                        x=x+1;
                    }
                    ans=max(cnt,ans);
                }
            }
            return ans;
        }
    };