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

int main(){
// #ifndef ONLINE_JUDGE
// freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt","r",stdin);
// freopen ("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt","w",stdout);
// #endif

 int n;
 cin>>n;
 int a[n+1],sum=0;
 rep(i,0,n)
 {
 	cin>>a[i],sum+=a[i];
 }
 int dp[n+1][sum+1];
 rep(i,0,n+1)
 {
 	dp[i][0]=1;
 }
 rep(i,1,sum+1)
 {
 	dp[0][i]=0;
 }
 sort(a,a+n);
rep(i,1,n+1)
{
rep(j,1,sum+1)
{
	dp[i][j]=dp[i-1][j];  ///not including 

	///including
	if(a[i-1]<=j) 
	dp[i][j]|=dp[i-1][j-a[i-1]];


}
}

// rep(i,0,n+1)
// {
// 	rep(j,0,sum+1)
// 	{
// 		cout<<dp[i][j]<<" \n"[j==sum];
// 	}
// }
vi v;
rep(i,1,sum+1)
{
	if(dp[n][i])v.pb(i);
}

cout<<v.size()<<endl;
for(int i:v)cout<<i<<" ";
return 0;
}