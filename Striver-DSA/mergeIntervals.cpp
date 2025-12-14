class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>>ans;
            vector<pair<int,int>>overlap;
            for(auto it : intervals){
                int f=it[0],s=it[1];
                overlap.push_back({f,1});
                overlap.push_back({s,0});
            }
    
            sort(overlap.begin(),overlap.end(),[](auto &a, auto &b){
                if(a.first==b.first) return a.second>b.second;
                return a.first<b.first;
            });
            int merge =0;
            int start=-1;
            for(auto it:overlap){
                if(it.second==1){
                    if(merge==0) start=it.first;
                    merge++;
                }else{
                    merge--;
                    if(merge==0) ans.push_back({start,it.first});
                }
            }
        return ans;
        }
    };