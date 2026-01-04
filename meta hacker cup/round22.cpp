#include <bits/stdc++.h>
using namespace std;
#define vi vector<long long>
#define rep(i,st,n) for(int i=st;i<n;i++)
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
#define pno cout<<"NO"<<endl;
#define pyes cout<<"YES"<<endl;
using ll = long long;
const ll m = 1e9+7;

struct point{ int x,y; };

ll binpow(int a,int b){
    a%=m;
    int res=1;
    while(b>0){
        if(b&1) res=res*a %m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

bool feasible_groups(
    int K,
    int M,
    const vector<int> &groups,
    const vector<int> &prefG,
    const vector<long long> &S
){
    if(K == 0) return true;
    if(K > M) return false;

    int R = prefG[K];
    long long cur = 0;
    int idx = 0;

    for(int i = 0; i < K; ++i){
        int val = K - i;
        int cntg = groups[i];
        for(int c = 0; c < cntg; ++c){
            ++idx;
            cur += val;
            if(cur > S[idx]) return false;
            if(idx == R) break;
        }
        if(idx == R) break;
    }
    return true;
}

void solve(){
    int N, M;
    cin >> N >> M;

    vi A(N);
    rep(i,0,N) cin >> A[i];
    vi B(M);
    rep(i,0,M) cin >> B[i];

    if(N == 0){
        cout << 0 << '\n';
        return;
    }

    sort(all(A), greater<int>());
    vector<int> groups;
    for(int i = 0; i < N; ){
        int j = i;
        while(j < N && A[j] == A[i]) j++;
        groups.pb(j - i);
        i = j;
    }

    int G = groups.size();

    sort(all(B));
    vector<long long> prefB(M+1, 0);
    rep(i,0,M) prefB[i+1] = prefB[i] + B[i];

    vector<long long> S(N+1, 0);
    int pos = 0;
    for(int t = 1; t <= N; ++t){
        while(pos < M && B[pos] <= t) pos++;
        long long sumSmall = prefB[pos];
        long long sumLarge = (long long)(M - pos) * t;
        S[t] = sumSmall + sumLarge;
    }

    vector<int> prefG(G+1, 0);
    rep(i,0,G) prefG[i+1] = prefG[i] + groups[i];

    int lo = 0, hi = G, bestGroups = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(feasible_groups(mid, M, groups, prefG, S)){
            bestGroups = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    cout << prefG[bestGroups] << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
