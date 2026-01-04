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

struct point{
    int x,y;
};

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

void solve(){
    int n, m;
    cin >> n >> m;

    bool ok = false;

    if (n >= m && n <= 2*m - 2) ok = true;
    else if (n >= 2*m && (n % 2 == 0)) ok = true;

    if (ok) pyes else pno
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
