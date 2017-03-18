// @author- razor123
#include<iostream>
#include<string>
#include <cstring>
#include<queue>
#include<vector>
#include<climits>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
typedef  long long ULL;
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
#define syn ios::sync_with_stdio(false)

struct compare{
    bool operator()(const PII &a, const PII &b){
    return a.F.F>b.F.F;
}

};

int main(){
    vector<PII> a;
    int w,i;
    int count=1;
    while(cin >> w>>i){
        a.PB(MP(MP(i,w),count++));
        
    }
   
    sort(a.begin(),a.end(),compare());
    //REP(i,a.size())cout << a[i].F.F;
   
    vector<PI> dp(a.size());
    int n=a.size();
    REP(i,n)dp[i].F=1,dp[i].S=-1;
    int maxn=-1,maxi;
    //cout << n<<endl;
    FOR(i,1,n-1){
        FORD(j,i-1,0){
            if(a[i].F.S>a[j].F.S&&a[i].F.F<a[j].F.F&&dp[i].F<dp[j].F+1)
                {
                dp[i].F=dp[j].F+1;
                dp[i].S=j;
            }
        }
        if(dp[i].F>maxn){maxn=dp[i].F,maxi=i;}
        
    }
    cout << maxn<<'\n';
    stack<int> st;
     i=maxi;
    while(i!=-1){st.push(a[i].S);i=dp[i].S;}
    while(!st.empty()){cout << st.top()<<'\n';st.pop();}
    
    
    
    
    return 0;
    
}