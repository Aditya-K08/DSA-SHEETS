#include <iostream>
#include <vector>

#define ll long long
using namespace std;

ll mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    ll inversions = 0;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

ll mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    ll inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSortAndCount(arr, temp, left, mid);
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);
        inversions += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversions;
}

ll mergeAndCountDescending(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    ll inversions = 0;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

ll mergeSortAndCountDescending(vector<int>& arr, vector<int>& temp, int left, int right) {
    ll inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSortAndCountDescending(arr, temp, left, mid);
        inversions += mergeSortAndCountDescending(arr, temp, mid + 1, right);
        inversions += mergeAndCountDescending(arr, temp, left, mid, right);
    }
    return inversions;
}

int main() {
    ll n;
    cin >> n;
    vector<int> arr(n);
    vector<int> arr2(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    vector<int> temp(n);
    ll inversions = mergeSortAndCount(arr, temp, 0, n - 1);
    vector<int> temp2(n);
    ll inversions2 = mergeSortAndCountDescending(arr2, temp2, 0, n - 1);

    cout << min(inversions, inversions2) << endl;

    return 0;
}
