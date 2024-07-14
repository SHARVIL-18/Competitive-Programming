#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define inf 9223372036854775807
#define iinf 2147483647
#define PB push_back
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vp;
typedef vector<char> vc;
#define F first
#define S second
#define all(C) C.begin(), C.end()
#define show(C) for(auto J: C) cout<<J<<" "; cout << endl;
//greater <>() opp sort function
int n;
int arr[100100];
int t[400400];//Never forget : size of tree has to be atleast 4X

void build(int index,int l,int r){
  if(l==r){
        t[index]  = arr[l];//Leaf condition
        return;
  }
  int mid = (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);
  t[index] = t[2*index] + t[2*index + 1]; //Any required FUNCTION INSTEAD OF ADDITON (eg MAX)
}

void update(int index,int l,int r,int pos,int val){
    if(pos<l||pos>r)return;
    if(l==r){
        t[index] = val;
        arr[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = t[2*index] + t[2*index+1];


}
int query(int index,int l,int r,int lq,int rq){
    if(l>rq || lq>r){return 0;}
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid = (l+r)/2;
    return query(index*2,l,mid,lq,rq) +  query(index*2+1,mid+1,r,lq,rq);


}


void solve(){
    cin>>n;
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    for(int i=0;i<q;i++){
        //process queries  with update or query
    }
}








int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

solve();



return 0;
}