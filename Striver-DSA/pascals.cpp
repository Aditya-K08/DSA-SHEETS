class Solution {
    public:
        vector<vector<int>> generate(int n) {
            vector<vector<int>>ans(n);
            for(int i=0;i<n;i++){
                if(i==0){
                    ans[0].push_back(1);
                }
                else{
                    int sz=ans[i-1].size()+1;
                    for(int j=0;j<sz;j++){
                        if(j==0 || j==sz-1) ans[i].push_back(1);
                        else ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                    }
                }
            }
            return ans;
        }
    };