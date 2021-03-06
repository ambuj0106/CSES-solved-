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
vvi adj(100005,vi(0));
vector<int> group;
bool is_biparted=1;
void dfs(int u,int p)
{

group[u]=(group[p]^1);
for(int c:adj[u])
{
	if(c!=p)
	{
		if(group[c]==-1)
		{
			dfs(c,u);
			
		}else
		{
			is_biparted&=(group[c]^group[u]);
		}
		
	}
}

}
int main(){
// #ifndef ONLINE_JUDGE
// freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt","r",stdin);
// freopen ("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt","w",stdout);
// #endif

 int n,m;
 cin>>n>>m;
 group.assign(n+1,-1);

 rep(i,0,m)
 {
 	int x,y;
 	cin>>x>>y;
 	x--;y--;
 	adj[x].pb(y);
 	adj[y].pb(x);
 }
 rep(i,0,n)
	 {
	 	if(group[i]==-1)
	   	{
	   		group[i]=1;
		  dfs(i,-1);
		}
	}
 if(is_biparted)
 {
 	rep(i,0,n)
 	{
 		cout<<group[i]+1<<" ";
 	}
 }else
 {
 	cout<<"IMPOSSIBLE";
 }

return 0;
}