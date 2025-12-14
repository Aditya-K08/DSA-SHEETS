class Solution {
    public:
        long long reverseCount = 0;
    
        void countAndMerge(vector<int>& nums, int l, int m, int r) {
            int j = m + 1;
            for (int i = l; i <= m; i++) {
                while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                    j++;
                }
                reverseCount += (j - (m + 1));
            }
            int n1 = m - l + 1, n2 = r - m;
            vector<int> left(n1), right(n2);
            for (int i = 0; i < n1; i++) left[i] = nums[l + i];
            for (int i = 0; i < n2; i++) right[i] = nums[m + 1 + i];
    
            int i = 0, k = l;
            j = 0;
            while (i < n1 && j < n2) {
                if (left[i] <= right[j]) nums[k++] = left[i++];
                else nums[k++] = right[j++];
            }
            while (i < n1) nums[k++] = left[i++];
            while (j < n2) nums[k++] = right[j++];
        }
    
        void mergeSort(vector<int>& nums, int l, int r) {
            if (l >= r) return;
            int m = l + (r - l) / 2;
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            countAndMerge(nums, l, m, r);
        }
    
        int reversePairs(vector<int>& nums) {
            reverseCount = 0;
            mergeSort(nums, 0, nums.size() - 1);
            return (int)reverseCount;
        }
    };
    