#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	vector<int>wheels(n);
    for(int i=0;i<n;i++){
        cin>>wheels[i];
    }
    sort(wheels.begin(),wheels.end());
    int cnt = 0;
    int i=0,j=n-1;
    while(i<=j){
        if(wheels[i]+wheels[j]<=x){
            i++;
            j--;
        }
        else if(wheels[i]+wheels[j]>x){
            j--;
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
