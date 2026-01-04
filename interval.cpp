Variant 6: Reconstruction (how to get the actual split/choice)
vector<vector<int>> parent(n+1, vector<int>(n+1, -1));

for (...) {
  dp[i][j] = INF;
  for (int k=i; k<j; k++) {
    long long cand = dp[i][k] + dp[k+1][j] + cost;
    if (cand < dp[i][j]) {
      dp[i][j] = cand;
      parent[i][j] = k;
    }
  }
}

Variant 5: Circular interval DP (ring / circle)
// build b[1..2n]
for(int i=1;i<=n;i++) b[i]=b[i+n]=a[i];

int m = 2*n;
vector<vector<long long>> dp(m+1, vector<long long>(m+1, INF));

// run interval dp on 1..2n (but only lengths up to n)

for (int len=1; len<=n; len++){
  for (int i=1; i+len-1<=m; i++){
    int j=i+len-1;
    // compute dp[i][j]
  }
}

// answer = best over dp[i][i+n-1]


int n;
// dp[i][j] meaning depends on problem (min cost / max score / count / bool)
vector<vector<long long>> dp(n+1, vector<long long>(n+1));

for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;

        // compute dp[i][j] using smaller intervals (length < len)
    }
}


Variant 1: “Split the interval into two parts” (classic partition)
const long long INF = (1LL<<60);
vector<vector<long long>> dp(n+1, vector<long long>(n+1, INF));

for (int i = 1; i <= n; i++) dp[i][i] = 0; // base: single item cost often 0

for (int len = 2; len <= n; len++) {

    
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        dp[i][j] = INF;

        for (int k = i; k < j; k++) { // split point
            long long cost = 0; // problem-specific
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
        }
    }
}

vector<long long> pref(n+1,0);
for (int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
auto sum = [&](int l,int r){ return pref[r]-pref[l-1]; };

const long long INF = (1LL<<60);
vector<vector<long long>> dp(n+1, vector<long long>(n+1, INF));

for (int i=1;i<=n;i++) dp[i][i]=0;

for (int len=2; len<=n; len++){
    for (int i=1; i+len-1<=n; i++){
        int j=i+len-1;
        dp[i][j]=INF;
        for(int k=i; k<j; k++){
            dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+sum(i,j));
        }
    }
}



Variant 2: “Pick the LAST action inside the interval” (k is the last chosen)
vector<vector<long long>> dp(n+2, vector<long long>(n+2, 0));

for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        long long best = 0;

        for (int k = i; k <= j; k++) {
            // gain depends on outside neighbors of the interval
            long long gain = 0; // problem-specific, often uses i-1 and j+1
            best = max(best, dp[i][k-1] + dp[k+1][j] + gain);
        }
        dp[i][j] = best;
    }
}


Variant 3: “Two-end transitions” (shrink from ends)

vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
for (int i=1;i<=n;i++) dp[i][i]=1;

for (int len=2; len<=n; len++){
    for (int i=1; i+len-1<=n; i++){
        int j=i+len-1;
        if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
        else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
    }
}


Variant 4: “Count ways” instead of min/max

const long long MOD = 1'000'000'007;
vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));

// base cases depend heavily on problem

for (int len=1; len<=n; len++){
    for (int i=1; i+len-1<=n; i++){
        int j=i+len-1;

        long long ways = 0;
        for (int k=i; k<j; k++){
            // combine left and right
            ways = (ways + dp[i][k] * dp[k+1][j]) % MOD;
        }
        dp[i][j] = ways;
    }
}
