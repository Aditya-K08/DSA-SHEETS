#include <bits/stdc++.h>
using namespace std;

struct Hash {
    size_t operator()(const vector<int>& v) const noexcept {
        size_t h = 0;
        for (int x : v) {
            h = h * 1315423911u + x;
        }
        return h;
    }
};

int min_operations_split_merge(const vector<int>& nums1, const vector<int>& nums2) {
    int n = nums1.size();
    if (nums1 == nums2) return 0;

    queue<pair<vector<int>, int>> q;
    unordered_set<vector<int>, Hash> set;

    q.push({nums1, 0});
    set.insert(nums1);

    while (!q.empty()) {
        auto [c, s] = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> temp(c.begin() + i, c.begin() + j+1);
                vector<int> rem;
                rem.insert(rem.end(), c.begin(), c.begin() + i);
                rem.insert(rem.end(), c.begin() + j + 1, c.end());
                for (int pos = 0; pos <= (int)rem.size(); pos++) {
                    vector<int> arr;
                    arr.insert(arr.end(), rem.begin(), rem.begin() + pos);
                    arr.insert(arr.end(), temp.begin(), temp.end());
                    arr.insert(arr.end(), rem.begin() + pos, rem.end());

                    if (arr == c) continue;
                    if (arr == nums2) return s + 1;

                    if (!set.count(arr)) {
                        set.insert(arr);
                        q.push({arr, s + 1});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<int> a = {3,1,2}, b = {1,2,3};
    cout << min_operations_split_merge(a,b) << "\n";

    vector<int> c = {1,1,2,3,4,5}, d = {5,4,3,2,1,1};
    cout << min_operations_split_merge(c,d) << "\n";
}
