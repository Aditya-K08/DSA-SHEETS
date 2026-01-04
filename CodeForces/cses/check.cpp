#include <bits/stdc++.h>
using namespace std;

// ---------------- DSU ----------------
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

// ---------------- Brute force check ----------------
bool canSortBrute(vector<int> arr, int k) {
    int n = arr.size();
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((arr[i] & arr[j]) <= k) {
                    swap(arr[i], arr[j]);
                    changed = true;
                }
            }
        }
    }
    return is_sorted(arr.begin(), arr.end());
}

int bruteSolve(vector<int> arr) {
    int n = arr.size();
    int best = 0;
    for (int k = 0; k < n; k++) {
        if (canSortBrute(arr, k)) best = k;
    }
    return best;
}

// ---------------- Optimized check ----------------
bool canSortWithK(const vector<int>& arr, int k) {
    int n = arr.size();
    DSU dsu(n);

    int allowedMask = k;
    unordered_map<int, vector<int>> buckets;
    buckets.reserve(n * 2);

    for (int num = 0; num < n; num++) {
        int key = num & allowedMask;
        buckets[key].push_back(num);
    }

    for (auto& [key, nums] : buckets) {
        for (int i = 1; i < (int)nums.size(); i++) {
            dsu.unite(nums[0], nums[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (dsu.find(arr[i]) != dsu.find(i)) return false;
    }
    return true;
}

int fastSolve(vector<int> arr) {
    int n = arr.size();
    int low = 0, high = n - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canSortWithK(arr, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// ---------------- Main ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Exhaustive check for small n
    for (int n = 2; n <= 8; n++) {
        cerr << "[INFO] Testing n = " << n << "...\n";
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 0);
        int testCount = 0;
        do {
            int bruteAns = bruteSolve(arr);
            int fastAns = fastSolve(arr);
            if (bruteAns != fastAns) {
                cerr << "[ERROR] Mismatch found!\n";
                cerr << "n = " << n << "\nArray: ";
                for (int x : arr) cerr << x << " ";
                cerr << "\nBrute = " << bruteAns << ", Fast = " << fastAns << "\n";
                return 0;
            }
            testCount++;
            if (testCount % 500 == 0) {
                cerr << "  Progress: " << testCount << " permutations tested...\n";
            }
        } while (next_permutation(arr.begin(), arr.end()));
        cerr << "[INFO] n = " << n << " passed all " << testCount << " tests.\n";
    }

    cerr << "[INFO] All small-n tests passed!\n";

    // 2. Large random stress test
    int n = 100000;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    random_shuffle(arr.begin(), arr.end());

    cerr << "[INFO] Running large random test for n = " << n << "...\n";
    auto start = chrono::high_resolution_clock::now();
    int ans = fastSolve(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Large n = " << n << " answer = " << ans
         << " in " << chrono::duration<double>(end - start).count() << "s\n";

    return 0;
}
