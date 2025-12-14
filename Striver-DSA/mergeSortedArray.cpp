class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int lo = 0, ri = 0;
            vector<int> ans;
            while (lo < m && ri < n) {
                if (nums1[lo] < nums2[ri]) {
                    ans.push_back(nums1[lo++]);
                } else if (nums1[lo] == nums2[ri]) {
                    ans.push_back(nums1[lo++]);
                    ans.push_back(nums2[ri++]);
                } else {
                    ans.push_back(nums2[ri++]);
                }
            }
            while (lo < m) {
                ans.push_back(nums1[lo++]);
            }
    
            while (ri < n) {
                ans.push_back(nums2[ri++]);
            }
    
            nums1 = ans; 
        }
    
    };