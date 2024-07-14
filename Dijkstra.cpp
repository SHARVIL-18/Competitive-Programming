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

int n,m;
vector<vp> adj;

vi dis;
vi processed;
void dijkstra(int x){
priority_queue<pair<int,int>> q;
 dis[x]=0;
 q.push({0,x});
 while(!q.empty()){
 int a= (q.top()).second;q.pop();
 if(processed[a])continue;
 processed[a]=true;
 for(auto u:adj[a]){
 int b=u.first,w=u.second;
 if(dis[a]+w<dis[b]){
 dis[b]=dis[a]+w;
 q.push({-1LL*dis[b],b});
 }
 }
 }
}
int32_t main(){
cin>>n>>m;
adj.resize(n+1);
processed.assign(n+1,0);
dis.assign(n+1,1e18);
for(int i=0;i<m;i++){
int x,y,w;
cin>>x>>y>>w;
adj[x].PB({y,w});
}
dijkstra(1);
for(int i=1;i<=n;i++){
    cout<<dis[i]<<" ";
}
cout<<endl;




return 0;
}
