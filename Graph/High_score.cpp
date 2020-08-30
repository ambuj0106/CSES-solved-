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
vvi adj(100000,vi());
int vis[100000],inc[100000];

set<int>s;
void dfs(int u)
{
vis[u]=1;
//s.insert(u);
    
	for(int c: adj[u])
	{
		if(!vis[c])
		dfs(c);
		if(inc[c]==1){
			inc[u]=1;
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
 vector<tuple<int,int,int> >edges;
 inc[n-1]=1;
rep(i,0,m)
{
int a,b,c;
cin>>a>>b>>c;
a--;b--;
adj[a].pb(b);

tuple<int,int,int> tmp;
tmp=make_tuple(a,b,c);
edges.pb(tmp);


}dfs(0);
rep(i,1,n)
{
	rep(j,0,n)vis[j]=0;
	if(inc[i])
	dfs(i);}
ll dist[n+1];
rep(i,0,n)
{
	dist[i]=-1e18;
}
dist[0]=0;
rep(i,1,n)
{  
	rep(i,0,m)
	{
		int a,b,c;
		tie(a,b,c)=edges[i];
	    ll ed=dist[a]+c;

	   //relaxation 
	    if(ed>dist[b])
	    {
	    	dist[b]=ed;
	    }
	}
}
int f=0;
rep(i,0,m)
{
    int a,b,c;
    tie(a,b,c)=edges[i];
    ll ed=dist[a]+c;
    if(ed>dist[b]&&inc[b])
    {
    	f=1;
    }	
}
if(f==1)
{
	cout<<-1<<endl;
}else{
	cout<<dist[n-1]<<endl;
}

return 0;
}
