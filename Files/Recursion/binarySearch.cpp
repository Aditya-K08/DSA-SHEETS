#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target, int n, int start, int end)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return BinarySearch(arr, target, n, start, mid - 1);
    else
        return BinarySearch(arr, target, n, mid + 1, end);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    BinarySearch(arr, target, n, 0, n - 1);
}