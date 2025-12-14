class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(n, vector<int>(m, 0));
            int dx[2] = {1, 0}; 
            int dy[2] = {0, 1};  
    
            dp[0][0] = 1;
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 2; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < n && nj < m) {
                            dp[ni][nj] += dp[i][j];
                        }
                    }
                }
            }
    
            return dp[n-1][m-1];
        }
    };
    