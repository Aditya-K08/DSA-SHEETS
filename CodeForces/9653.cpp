#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes                                                                   \
  cout << "YES"                                                                \
       << "\n";
#define pno                                                                    \
  cout << "NO"                                                                 \
       << "\n";
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

void solve(vector<int> &arr, string &pattern) {
  if (arr.size() != pattern.size()) {
    cout << "NO" << endl;
    return;
  }

  unordered_map<int, char> numToChar;
  unordered_map<char, int> charToNum;

  for (int i = 0; i < arr.size(); i++) {
    int num = arr[i];
    char ch = pattern[i];
    if (numToChar.find(num) != numToChar.end() && numToChar[num] != ch) {
      cout << "NO" << endl;
      return;
    }
    if (charToNum.find(ch) != charToNum.end() && charToNum[ch] != num) {
      cout << "NO" << endl;
      return;
    }
    numToChar[num] = ch;
    charToNum[ch] = num;
  }
  cout << "YES" << endl;
  return;
}

void concept() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int t;
  cin >> t;
  while (t--) {
    string s1;
    cin >> s1;
    solve(arr, s1);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    concept();
    cout << "\n";
  }
  return 0;
}
