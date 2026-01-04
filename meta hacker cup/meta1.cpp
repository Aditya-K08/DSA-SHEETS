#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    for(int tc = 1; tc <= T; ++tc) {
        int N;
        long long A, B;
        cin >> N >> A >> B;

        // First N multipliers: all 1 (so coolness after N days = 1 <= A)
        vector<long long> first(N, 1), second(N, 1);

        // Factorize B into prime factors (with multiplicity)
        long long tmp = B;
        vector<long long> primes;
        for(long long p = 2; p * p <= tmp; ++p) {
            while(tmp % p == 0) {
                primes.push_back(p);
                tmp /= p;
            }
        }
        if(tmp > 1) primes.push_back(tmp);

        // Distribute prime factors into the second N slots (cycle if needed)
        for(size_t i = 0; i < primes.size(); ++i) {
            second[i % N] *= primes[i];
        }

        // Output
        cout << "Case #" << tc << ":";
        for(int i = 0; i < N; ++i) cout << " " << first[i];
        for(int i = 0; i < N; ++i) cout << " " << second[i];
        cout << "\n";
    }
    return 0;
}
