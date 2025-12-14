class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size() , n = matrix[0].size();
            int lo = 0,hi=m-1;
            int row=-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(matrix[mid][0]<= target && matrix[mid][n-1]>=target){
                    row=mid;
                    break;
                }else if(matrix[mid][n-1]>target){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            if(row==-1) return false;
            int left=0,right=n-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(matrix[row][mid]==target) return true;
                else if(matrix[row][mid]>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            return false;
        }
    };