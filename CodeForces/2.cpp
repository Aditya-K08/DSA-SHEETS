#include <bits/stdc++.h>
using namespace std;

bool isPossibleImportantInteger(int num) {
    string s = to_string(num);
    if (s.substr(0, 2) == "10" && s.size() >= 3) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        bool ans = isPossibleImportantInteger(n);
        if(ans) cout<<"yes";
        else cout<<"no";
    }
    return 0;
}
