class Solution{
    public:
    int inversions = 0;
        void countInversions(vector<int>&arr,int l,int mid,int r){
            int lenLeft=mid-l+1;
            int lenRight=r-mid;

            vector<int>left(lenLeft);
            vector<int>right(lenRight);

            for(int i=0;i<lenLeft;i++){
                left[i]=arr[l+i];
            }
            for(int i=0;i<lenRight;i++){
                right[i]=arr[mid+i+1];
            }
            
            int i=0,j=0;
            int k =l;
            while(i<lenLeft && j<lenRight){
                if(left[i]<=right[j]){
                    arr[k]=left[i];
                    i++;
                }else{
                    inversions+=lenLeft-i;
                    arr[k]=right[j];
                    j++;
                }
                k++;
            }

            while(i<lenLeft){
                arr[k++]=left[i++];
            }
            while(j<lenRight){
                arr[k++]=right[j++];
            }
        }

        void merge(vector<int>&arr,int l,int r){
            if(l>=r) return ;
            int mid = l + (r-l)/2;
            merge(arr,l,mid);
            merge(arr,mid+1,r);
            countInversions(arr,l,mid,r);
        }

        int count(vector<int>&arr){
            inversions=0;
            merge(arr,0,arr.size()-1);
            return inversions;
        }
};