class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int,int>map;
            for(int x:nums){
                map[x]++;
            }
            int n = nums.size();
            vector<int>ans;
            for(auto it:map){
                if(it.second>n/3) ans.push_back(it.first);
            }
            return ans;
        }
    };