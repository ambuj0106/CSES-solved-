/*
Just Another Source code by -
Ambuj              
*/
#include<bits/stdc++.h>
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define VP vector< pll >
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define FF first
#define SS second
#define teji  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define DI int n;cin>>n;
#define rep(i,a,b) for(ll i=a;i<b;i++)

int sum() { return 0; }

template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }
bool desc(int a,int b)
{
	return a> b;
}
int gcd(int a,int b)
{
	if(a==0)return b;
	if(b==0)return a;
	return gcd(b,a%b);
}
ll recpow(ll n,ll p, ll m)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans= ans * n %m;
		 n= n * n %m;
		 
		
		 p>>=1;
	}
	return ans;
}
ll dp[505][505];
int main(){
// #ifndef ONLINE_JUDGE
// freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt","r",stdin);
// freopen ("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt","w",stdout);
// #endif

 int n,m;
 cin>>n>>m;
 
 rep(i,1,m+1)dp[1][i]=i-1;
 rep(i,1,n+1)dp[i][1]=i-1;

rep(i,2,n+1)
{
	rep(j,2,m+1)
	{ll tmp=1e10;
		if(i==j)continue;
		rep(k,1,j)
		{ 
			tmp=min(tmp,dp[i][j-k]+dp[i][k]);
		}
		//dp[i][j]=tmp;

		rep(k,1,i)
		{
			tmp=min(tmp,dp[i-k][j]+dp[k][j]);
		}
		dp[i][j]=tmp+1;
	}
} 
//rep(i,0,n+1)rep(j,0,m+1)cout<<dp[i][j]<<" \n"[j==m];
cout<<dp[n][m]<<endl;

 return 0;
}