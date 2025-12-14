class Solution{
    public:
        int longestSubarray(vector<int> &nums, int target){
            int n = nums.size();
            int lo=0;
            int sum =0,ans=0;;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                while(lo<=i && sum>target){
                    sum-=nums[lo++];
                }
                if(sum==target){
                    ans=max(ans,i-lo+1);
                }
            }
            return ans;
        }
    };
    