// @author- razor123
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#include<sstream>
#include<algorithm>
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
int const MAXN=1501;
double func(double  p,double q,double r ,double s,double t,double u,double X){
	return (p*exp(X*-1)+q*sin(X)+r*cos(X)+s*tan(X)+t*X*X+u);
}
int main() {
    syn;
    string s;
    while(getline(cin ,s)){
	    stringstream ss(s);
	     double p,q,r,s,t,u;

	    ss>> p>>q>>r>>s>>t>>u;
	    if(func(p,q,r,s,t,u,0)*func(p,q,r,s,t,u,1)>0){
		    cout << "No solution";
		    continue;
	    }
	    
	    double l=0.0,h=1.0,mid;
	
	   // cout << func(p,q,r,s,t,u,7071);
	    while(h-l>=1e-7){
		   mid=(h+l)/2.0;
		  double calc=func(p,q,r,s,t,u,mid);
		  if(calc>0)l=mid;
		else h=mid; 
	    }

	    printf("%.4lf\n",l);
    }
    return 0;
}


