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

vvi graph(100005,vi());
int vis[100005];

int main(){
 int n,m;
 cin>>n>>m;
 while(m--)
 {
 	int u,v;
 	cin>>u>>v;
 	u--,v--;
 	graph[v].pb(u);
 	graph[u].pb(v);
 }
 
queue<int> q;
int a[n+1]={0};
rep(i,0,n)a[i]=-1;
q.push(0);
vis[0]=1;
while(!q.empty())
{
   //pii p=q.front();
  int x=q.front();
   if(x==n-1){break;}
   q.pop();
   
   for(int c: graph[x])
   {
	   	if(!vis[c])
	   	{
				vis[c]=1;
			a[c]=x;
			q.push(c);
		}

   }

}
vi v ;
int x=n-1;
v.pb(n-1);
while(a[x]!=-1)
{
v.pb(a[x]);
x=a[x];

}
if(a[n-1]!=-1)
 {
 	cout<<v.size()<<endl;
 	reverse(all(v));
 	rep(i,0,v.size())
 	{
 		cout<<v[i]+1<<" ";
 	}
 }else
 	{
 		cout<<"IMPOSSIBLE"<<endl;
 	}


return 0;
}