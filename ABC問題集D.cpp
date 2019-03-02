#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <iomanip>
#include <utility>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)
#define ld long double
#define ll long long

using namespace std;

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;


int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  int k;
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  int V_MAX=10000010;
  vector<int> dp(N+1);
  for(int i=0;i<=N;i++){
    dp[i]=V_MAX;
  }
  for(int i=0;i<N;i++){
    dp[lower_bound(dp.begin(),dp.end(),P[i])-dp.begin()]=P[i];
  }
  cout << lower_bound(P.begin(),P.end(),V_MAX-1)-P.begin() << endl;
  cout << N-(lower_bound(dp.begin(),dp.end(),V_MAX) -dp.begin())<< endl;
  return 0;
}


==================================================
int A,B,C;
int ans=0;
cin >> A >> B >> C;
ans=min(C,A+B+1)+B;
cout << ans << endl;
return 0;
}
==================================================
string S;
cin >> S;
int c[200010];
int cnt=0;
for(int i=0;i<S.size();i++){
  if(S[i]=='B'){
    c[i]=-1;
    cnt++;
  }else{
    c[i]=0;
  }
}
ll ans=0;
for(int i=S.size()-1;cnt!=0;i--){
  ans+=i;
  cnt--;
}
for(int i=0;i<S.size();i++){
  if(c[i]==-1){
    ans-=i;
  }
}
cout << ans << endl;
return 0;
==================================================
ll N,M;
cin >> N >> M;

ll dist[310][310];
for(int i=1;i<=N;i++){
  for(int j=1;j<=N;j++){
    if(i==j){
      dist[i][j]=0;
    }
    else{
      dist[i][j]=INF;
    }
  }
}

int a,b,t;
for(int i=1;i<=M;i++){
  cin >> a >> b >> t;
    dist[a][b]=t;
    dist[b][a]=t;
}
for(int i=1;i<=N;i++){
  for(int j=1;j<=N;j++){
    for(int k=1;k<=N;k++){
      if(dist[j][i]==INF || dist[i][k]==INF)continue;
      dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
    }
  }
}
ll ans=INF;
ll cnt=0;
for(int i=1;i<=N;i++){
  cnt=0;
  for(int j=1;j<=N;j++){
    if(dist[i][j]==INF)continue;
    cnt=max(cnt,dist[i][j]);
  }
  ans=min(ans,cnt);
}
cout << ans << endl;
return 0;
==================================================
string S;
cin >> S;
int n=S.size();
ll a=0;
ll c=0;
ll q=0;
for(int i=0;i<n;i++){
  if(i==0){
    if(S[i]=='A')a++;
    else if(S[i]=='?')a++;
    continue;
  }

  if(S[i]=='C')c++;
  else if(S[i]=='?')q++;
}
ll ans=0;
ll p=0;
ll MOD1=1000000007;
for(int i=1;i<n-1;i++){
  if(S[i]=='B'){
    ans=ans+(a+3*p)*(c+3*q);
  }else if(S[i]=='A'){
    a++;
  }else if(S[i]=='C'){
    c--;
  }else if(S[i]=='?'){
    q--;
    ans=ans+(a+3*p-1)*(c+3*q-1);
    p++;
  }
}
cout << ans << endl;
return 0;
}
==================================================
int N,K;
cin >> N >> K;
vector<ll> h;
ll t;
ll ans=1000000001;
for(int i=0;i<N;i++){
  cin >> t;
  h.push_back(t);
}
sort(h.begin(),h.end());
for(int i=0;i<N-K+1;i++){
  ll x=h[K+i-1]-h[i];
  ans=min(ans,x);
}
cout << ans << endl;
return 0;
==================================================
int N;  cin >> N;
int c[N+1];
for(int i=0; i<N; i++) { cin >> c[i]; }


int dp[N+1];
int inf = 1000000000;
for(int i=0; i<=N; i++) { dp[i] = inf; }

  for(int i=0; i<N; i++){
    int t=lower_bound(dp, dp+N, c[i]);
      dp[t] = c[i];
  }
  int t=lower_bound(dp, dp+N,inf);
  cout << N - t << endl;
return 0;
}
==================================================
ll s[55],p[55];
ll N,X;

ll dfs(ll a,ll b){
  if(a==0)return 1;
  if(b==1)return 0;
  if(b<=s[a-1]+1) return dfs(a-1,b-1);
  if(b==s[a-1]+2) return p[a-1]+1;
  if(b==s[a-1]*2+3) return p[a];
  else return p[a-1]+1+dfs(a-1,b-2-s[a-1]);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> X;
  s[0]=1LL,p[0]=1LL;
  for(int i=0;i<N;i++){
    s[i+1]=s[i]*2+3;
    p[i+1]=p[i]*2+1;
  }

  cout << dfs(N,X) << endl;
  return 0;
}
==================================================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include<bits/stdc++.h>
#include <utility>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;
using ll = long long;
map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

#define MAX_V 110000
#define MAX_LOG_V 20

vector<int> G[MAX_V];

int parent[MAX_LOG_V][MAX_V]; // 2^k th parent
int depth[MAX_V]; // distance from root
int root = 0;

void dfs(int v,int p, int d){
  parent[0][v]=p;
  depth[v]=d;
  for(int i=0;i<G[v].size();i++){
    if(G[v][i]!=p){
      dfs(G[v][i],v,d+1);
    }
  }
}

void init(int V){
	dfs(root, -1, 0);
	for(int k = 0; k < MAX_LOG_V - 1; k++){
		for(int v = 0; v < V; v++){
			if(parent[k][v] < 0){
				parent[k + 1][v] = -1;
			}else{
				parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
}


int lca(int u, int v){
 if(depth[u] > depth[v]){
   swap(u, v);
 }
 for(int k = 0; k < MAX_LOG_V; k++){
   if((depth[v] - depth[u]) >> k & 1){
     v = parent[k][v];
   }
 }
 if(u == v){
   return u;
 }
 for(int k = MAX_LOG_V - 1; k >= 0; k--){
   if(parent[k][u] != parent[k][v]){
     u = parent[k][u];
     v = parent[k][v];
   }
 }
 return parent[0][u];
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int x,y;
  for(int i=0;i<N-1;i++){
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  init(N);

  int Q;
  cin >> Q;
  for(int i=0;i<Q;i++){
    cin >> x >> y;
    x--;
    y--;
    int p=lca(x,y);
    cout << depth[y]+depth[x]-depth[p]*2+1 << endl;
  }
  return 0;
}
==================================================
string S;
cin >> S;
int n=S.size();
int ans=10000;
for(int i=0;i<n-2;i++){
  string T=S.substr(i,3);
  ans=min(ans,abs(753-stoi(T)));
}
cout << ans << endl;
return 0;
}

  //string A_str=to_string(A);
==================================================

ll dfs(ll i,ll j){
  ll count =0;
  if(1>i || i>H || 1>j || j>W) return 0;
  if(dp[i][j]>=1)return dp[i][j];
  if(a[i][j]<a[i-1][j]) count+=dfs(i-1,j);
  if(a[i][j]<a[i+1][j]) count+=dfs(i+1,j);
  if(a[i][j]<a[i][j-1]) count+=dfs(i,j-1);
  if(a[i][j]<a[i][j+1]) count+=dfs(i,j+1);
  count=(count+1)%MOD;
  dp[i][j]=count;
  return count;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin >> a[i][j];
      dp[i][j]=0;
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      dfs(i,j);
    }
  }
  ll ans=0;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      ans=(ans+dp[i][j])%MOD;
    }
  }
  cout << ans%MOD << endl;
  return 0;
}
==================================================
int W,N,K;
cin >> W >> N >> K;
int A[1010],B[1010];
for(int i=0;i<N;i++){
  cin >> A[i] >> B[i];
}
int dp[100010][52];
for(int i=0;i<=W;i++){
  for(int j=0;j<=K;j++){
    dp[i][j]=0;
  }
}
for(int i=0;i<N;i++){
  for(int j=0;j<=W;j++){
    for(int k=1;k<=K;k++){
      if(j>=A[i]){
        if(dp[j][k]<dp[j-A[i]][k-1]+B[i]){
          cout << dp[j-A[i]][k-1]+B[i] << endl;
        }
        dp[j][k]=max(dp[j][k],dp[j-A[i]][k-1]+B[i]);
      }
    }
  }
}
cout << dp[W][K] << endl;
return 0;
}
==================================================
ll N,T;
cin >> N >> T;
ll A[100010];
for(int i=1;i<=N;i++){
  cin >> A[i];
}
ll ans=0;
ll min_v=A[1];
ll cost=0;
for(int i=2;i<=N;i++){
  if(cost<A[i]-min_v){
    cost=A[i]-min_v;
    ans=1;
  }else if(cost==A[i]-min_v){
    ans++;
  }
  min_v=min(min_v,A[i]);
}
cout << ans << endl;
return 0;
}
==================================================

class UnionFind {
public:
    vector<int> par, rank;
    int cnt;

    UnionFind(int n) : cnt(n) {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        rank = vector<int>(n, 0);
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        cnt--;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N,K,L;
  cin >> N >> K >> L;
  UnionFind uf1= UnionFind(N+1);
  UnionFind uf2= UnionFind(N+1);

  for(int i=1;i<=K;i++){
    int p,q;
    cin >> p >> q;
    uf1.unite(p,q);
  }
  for(int i=1;i<=L;i++){
    int r,s;
    cin >> r >> s;
    uf2.unite(r,s);
  }
  ll root1[N+10];
  ll root2[N+10];
  map<P,ll> m;

  for(int i=1;i<=N;i++){
    root1[i]=uf1.root(i);
    root2[i]=uf2.root(i);
    m[P(root1[i],root2[i])]++;
  }

  for(int i=1;i<=N;i++){
    cout << m[P(root1[i],root2[i])];
    if(i==N){
      cout << endl;
    }else{
      cout << " ";
    }
  }
  return 0;
}


==================================================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include<bits/stdc++.h>
#include <utility>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;
using ll = long long;
map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<int> v;
  for(int i=1;i<=N;i++){
    for(int j=5;j<=55555;j++){
      if(IsPrime(j) && j%5==1){
        v.push_back(j);
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i==0){
      cout << v[i];
      continue;
    }
    cout << ' ' << v[i];
  }
  cout << endl;
  return 0;
}
==================================================
const int MAX = 100010;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// NのP乗をMで割った余りを返す
ll pow_mod(ll n,ll k,ll m){
  if(k==0){
    return 1;
  }else if(k%2==1){
    return pow_mod(n,k-1,m)*n%m;
  }else{
    ll t=pow_mod(n,k/2,m);
    return (t*t)%m;
  }
}

//(10*9*8)/(3*2*1);
//10*9*8 -> ansMul
//3*2*1 -> ansDiv
long calcComb(int a, int b) {
	if (b > a - b) return calcComb(a, a - b);


	long ansMul = 1;
	long ansDiv = 1;
	for (int i = 0; i < b; i++)
	{
		ansMul *= (a - i);
		ansDiv *= (i + 1);
		ansMul %= MOD;
		ansDiv %= MOD;
	}
	//ansMul / ansDivをやりたい
	//ansDivの逆元を使って求めよう！

	long ans = ansMul * pow_mod(ansDiv,MOD - 2,MOD);
	return ans;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vector<double> a;
  cin >> n;
  double t;
  for(int i=0;i<n;i++){
    cin >> t;
    a.push_back(t);
  }
  sort(a.rbegin(),a.rend());
  COMinit();
  int ans1=a[0],ans2=a[n];
  double cnt=a[0]/2.0;
  for(int i=0;i<n;i++){
    if(abs(a[i]-a[0]/2.0)<cnt){
      ans2=a[i];
      cnt=abs(a[i]-a[0]/2);
    }
  }
  printf("%d %d",ans1,ans2);
  return 0;
}
==================================================
int N,M,Q;
cin >> N >> M >> Q;
vector<pair<int,int>> v;
int l,r;
int P[510][510]={0};
for(int i=0;i<M;i++){
  cin >> l >> r;
  P[l][r-l]++;
}
for(int i=1;i<N;i++){
  for(int j=0;j<N;j++){
    P[i][j+1]=P[i][j]+P[i][j+1];
  }
}
int p,q;
for(int i=0;i<Q;i++){
  cin >> p >> q;
  int ans=0;
  for(int j=p;j<=q;j++){
    ans+=P[j][q-j];
  }
  cout << ans << endl;
}
return 0;
}
==================================================
double N,M;
cin >> N >> M;
vector<pair<double,double>> v;
double a,b;
for(int i=0;i<M;i++){
  cin >> a >> b;
  v.push_back({b,a});
}
sort(v.begin(),v.end());
int ans=1;
double stone=v[0].first-0.5;
for(int i=0;i<M;i++){
  if(v[i].second <=stone && stone <=v[i].first){
    continue;
  }else{
    stone=v[i].first-0.5;
    ans++;
  }
}
cout << ans << endl;
return 0;
}
