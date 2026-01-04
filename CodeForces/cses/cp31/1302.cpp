#include<bits/stdc++.h>
using namespace std;

vector<int>freq(26,0);
vector<int>tree(4*26,0);
void build(int node,int start,int end){
    if(start==end){
        tree[node]=freq[start] > 0 ? 1 : 0;
    }
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node,int start,int end,int l,int r){
    if(r<start || end<l) return 0;
    if(l<=start && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return query(2*node,start,mid,l,r) + query(2*node+1,mid+1,end,l,r);
}

void update(int node,int start,int end,int idx,char val){
    if(start==end){
        arr[idx]=val;
        tree[node]=val > 0 ? 1 : 0;
    }
    else{
        int mid=(start+end)/2;
        if(idx<=mid){
            update(2*node,start,mid,idx,val);
        }
        else{
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    build(1,0,25);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,s.size()-1,b-1,c);
        }
        else if(a==2){
            cout<<query(1,0,s.size()-1,b-1,c-1);
        }
    }
}