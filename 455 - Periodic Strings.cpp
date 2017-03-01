//@Author-razor123
#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef  long long ULL;
typedef pair<int,int> PI; 
typedef pair<int,PI> PPI ;  
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
const int mod=1e9+7;


int main(){
    syn;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int m=s.length();
        vector<int> f(m+1);
        f[0]=0;
        f[1]=0;
        FOR(i,2,m){
            int j=f[i-1];
            while(true){
                if(s[j]==s[i-1]){
                    f[i]=j+1;
                    break;
                }
                if(j==0){f[i]=0;break;}
                j=f[j];
            }
        }
        int k=m-f[m];
        if(m%k)cout << m<<"\n";
        else cout << m-f[m]<<"\n";
        if(t)cout <<"\n";
    }
    return 0;
    
}