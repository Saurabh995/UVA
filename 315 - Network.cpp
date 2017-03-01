//@Author:razor123
#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
typedef  unsigned long long ULL;
typedef pair<int,int> PI; 
typedef pair<int,PI> IPI ;
typedef pair<PI,int> PII;
#define mem(a,n) memset((a), (n), sizeof(a))
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define INF INT_MAX
#define NINF INT_MIN
#define ison(x, i) (((x)>>(i))&1)
#define syn (ios::sync_with_stdio(false))
int const MAXN=3010;
vector<vector<int>> g(MAXN);
bool vis[MAXN];
int low[MAXN];
int disc[MAXN];
int parent[MAXN];
bool art[MAXN];
int numart;
int n,t;
void reset(){
    REP(i,n+1){g[i].clear();low[i]=INF;vis[i]=false;parent[i]=-1;art[i]=0;}
    numart=0;
}
void dfs(int u){
    vis[u]=true;
    int child=0;
    low[u]=disc[u]=++t;
    REP(i,g[u].size()){
        int v=g[u][i];
        if(!vis[g[u][i]]){
            child++;parent[v]=u;
            dfs(g[u][i]);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1&&child>1){
                art[u]=true;
            }
            else if(parent[u]!=-1&&low[v]>=disc[u]){
                   art[u]=true;
            }
            
        }
        else if(parent[u]!=v){
            low[u]=min(low[u],disc[v]);
        }
    }
}

int main(){
    syn;
    while(cin >> n,n!=0){
        reset();
        string s;
        while(getline(cin ,s),s!="0"){
            stringstream ss(s);
            int u,v;
            ss>>u;
            while(ss>>v){
                g[u].PB(v);
                g[v].PB(u);
            }
        }
        FOR(i,1,n){
            if(!vis[i]){
                t=0;
                dfs(i);
            }
        }
        int ans=0;
        FOR(i,1,n)ans+=art[i];
        cout << ans<<"\n";
    }
    return 0;
   
}

    

