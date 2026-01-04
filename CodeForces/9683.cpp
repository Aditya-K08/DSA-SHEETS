#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define br cout << "\n";
#define ff first
#define sc second
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll gcd(ll a, ll b) {
  if (a == 0ll) {
    return b;
  }
  return gcd(b % a, a);
}

bool compare(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

void concept() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> freq(26, 0);
  for (int i = 0; i < n; i++) {
      freq[s[i] - 'a']++;
  }

  string ans;
  while (true) {
      bool flag = false;
      for (int i = 0; i < 26; i++) {
          if (freq[i] > 0) {
              ans += (char)(i + 'a');
              freq[i]--;
              flag = true;
          }
      }
      if (!flag) break; 
  }

  cout << ans << endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while (t--) {
    concept();
    br;
  }
  return 0;
}
