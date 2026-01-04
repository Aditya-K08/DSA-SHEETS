#include<bits/stdc++.h>  
using namespace std;   

  
int main()  
{  
  int test_case;
  cin>>test_case;  
  while(test_case--)  
  {  
    int n;
    cin>>n;  
    vector<pair<int,int>>arr;  
    for(int i=0;i<n;i++)  
    {  
      int ele;
      cin>>ele;  
      arr.push_back({ele,i});  
    }  
  
    sort(arr.begin(),arr.end());  
    int inv=n;  
    for(int i=0;i<n;i++)  
    {  
      arr[i].first=inv--;
    }  
  
    int ans[n];  
    for(int i=0;i<n;i++)  
    {  
      ans[arr[i].second]=arr[i].first;  
    }  
    for(int i=0;i<n;i++)  
    cout<<ans[i]<<" ";  
    cout<<endl;  
  }  
  return 0;  
}