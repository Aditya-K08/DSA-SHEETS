#include<bits/stdc++.h.
using namespace std;


class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            unordered_set<int>col,rows;
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==0){
                        col.insert(j);
                        rows.insert(i);
                    }
                }
            }
    
            for(auto it:col){
                for(int i=0;i<m;i++){
                    matrix[i][it]=0;
                }
            }
            for(auto it:rows){
                for(int i=0;i<n;i++){
                    matrix[it][i]=0;
                }
            }
        }
    };

int main(){
    
}