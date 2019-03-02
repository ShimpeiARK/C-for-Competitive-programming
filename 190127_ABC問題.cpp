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
#include <utility>
#include <iomanip>

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

#define ld long double
#define ll long long

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int a=1;
  int number=1;
  int ans=0;
  for(int i=1;i<=N;i++){
    if(a==i)continue;
    int dist;
    cout << "? " << a << " " << i << endl;
    cin >> dist;
    if(ans<dist){
      ans=dist;
      number=i;
    }
  }
  for(int i=1;i<=N;i++){
    if(i==ans)continue;
    int dist;
    cout << "? " << i << " " << number << endl;
    cin >> dist;
    if(ans<dist){
      ans=dist;
    }
  }
  cout << "! " << ans << endl;
  return 0;
}

==========================================
==========================================
==========================================
==========================================
==========================================
==========================================
double N,K;
cin >> N >> K;
double a=0+(N-K)*(K-1)*6+(K-1)*3+(N-K)*3+1;
a/=N*N*N;
cout << fixed << setprecision(10) << a << endl;
return 0;
}

// ABC028_乱数生成
==========================================

int N,K;
double w[1010],p[1010];

double calc(double g){
  vector<pair<double,int>> V(N);
  double a[1010];
  for(int i=0;i<N;i++){
    a[i]=w[i]*(p[i]-g);
    V[i]={a[i],i};
  }
  sort(V.rbegin(),V.rend());
  double ans_t=0;
  double ans_u=0;
  for(int i=0;i<K;i++){
    int b=V[i].second;
    ans_t+=w[b]*p[b];
    ans_u+=w[b];
  }
  double ans=ans_t/ans_u;
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >> w[i] >> p[i];
  }
  int cnt=0;
  double lb=0,ub=101;
  double mid =(lb+ub)/2.0;
  while(cnt<=100){
    cnt++;
    mid =(lb+ub)/2.0;
    double sum=calc(mid);
    if(sum>mid){
      lb=mid;
    }else{
      ub=mid;
    }
  }
  cout << fixed << setprecision(10) << lb << endl;
  return 0;
}


//ABC_34_食塩
==========================================

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

// Nのk乗をMで割った余りを返す
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll A,B,C;
  cin >> A >> B >> C;
  ll x_t=((B*C%MOD)-(A*C%MOD)+MOD)%MOD;
  ll a=pow_mod((A*B%MOD)-(B*C%MOD)+(A*C%MOD)+MOD,MOD-2,MOD);
  ll y_t=((B*C%MOD)-(A*B%MOD)+MOD)%MOD;
  ll x=(x_t*a)%MOD;
  ll y=(y_t*a)%MOD;
  cout << x << " " << y << endl;
  return 0;
}

// ABC24_動的計画法_式変形_逆元_組み合わせ

==========================================
int T,X;
cin >> T >>X;
double ans=0;
cout << setprecision << T/X << endl;
return 0;
}
==========================================
ll N,M;
cin >> N >> M;
vector<ll> X;
ll t;
if(N>=M){
  cout << 0 << endl;
  return 0;
}
for(int i=0;i<M;i++){
  cin >> t;
  X.push_back(t);
}
sort(X.begin(),X.end());
ll ans=0;
vector<ll> Y;
ll a,b;
for(int i=0;i<M-1;i++){
  a=X[i];
  b=X[i+1];
  Y.push_back(abs(a-b));
}
sort(Y.begin(),Y.end());
for(int i=0;i<M-N;i++){
  ans+=Y[i];
}

cout << ans << endl;
return 0;
}
==========================================
int N;
cin >> N;
int L[20]={0};
int ma=0;
int sum=0;
for(int i=1;i<=N;i++){
  cin >> L[i];
  sum+=L[i];
  ma=max(L[i],ma);
}
if(sum-ma>ma){
  cout << "Yes" << endl;
}else{
  cout << "No" << endl;
}
return 0;
}

==========================================
==========================================
==========================================
==========================================

==========================================
==========================================
==========================================
==========================================
==========================================
==========================================
==========================================

==========================================
ll N,K;
cin >> N >> K;
vector<ll> A(N);

for(int i=0;i<N;i++){
  cin >> A[i];
}
ll sum=0;
for(int i=62;i>=0;i--){
  ll x=0;
  for(int j=0;j<N;j++){
    x+=(A[j]>> i &1);
  }
  if(N>2*x && (sum|(1LL<<i))<=K){
    sum|=1LL<<i;
  }
}
ll ans=0;
for(int i=0;i<N;i++){
  ans+=sum^A[i];
}
cout << ans << endl;
return 0;
}

// ABC_117_bit_1LL<<i


int N,M;
cin >> N >> M;
int a[13][13]={0};
int x,y;
int ans=0;
for(int i=0;i<M;i++){
cin >> x >> y;
a[x-1][y-1]=a[y-1][x-1]=1;
}
for(int bit= (1<<N) ;bit--;){
int t=bitset<32>(bit).count();
if(t<=ans)continue;

bool flag=true;
for(int i=0;i<N;i++){
  for(int j=0;j<i;j++){
    if(bit >> i & bit >>j & 1 && a[i][j]!=1){
      flag =false;
    }
  }
}
if(flag){
  ans=t;
}
}
cout << ans << endl;
return 0;
}

cin >> N >> K;
ll ans=0;

for(int i=1;i<=N;i++){
cin >> A[i];
}
if(K==0){
ll op=0;
for(int i=1;i<=N;i++){
  op+=A[i];
}
cout << op << endl;
return 0;
}
ll B[100]={0};
ll a;
ll dp=0;
for(int i=1;i<=N;i++){
a=A[i];
ll cnt=0;
while(a>0){
  if(a%2==1){
    B[cnt]++;
    cnt++;
  }else{
    cnt++;
  }
  a/=2;
}
}

ll sum=0;
ll k=K;
while(K>0){
dp++;
K/=2;
}

for(ll i=0;i<dp;i++){
if(N-B[i]>N/2 && (sum|(1<<i))<=k){
  sum+=pow(2,i);
}
}

for(int i=1;i<=N;i++){
ans+=sum^A[i];
}

cout << ans << endl;
return 0;
}


==========================================
ll N,M;
cin >> N >> M;
//ll M_MAX=1000000001;
ll N_MAX=100100;
ll a[100100];
ll A;
a[0]=0;
for(int i=1;i<=N;i++){
  cin >> A;
  A%=M;
  a[i]=A;
}
for(int i=1;i<=N;i++){
  a[i]=a[i-1]+a[i];
  a[i]%=M;
}
ll ans=0;
map<ll,ll> m;
for(int i=0;i<=N;i++){
  ans+=m[a[i]];
  m[a[i]]++;
}
/*ll ans=0;
for(int i=0;i<N;i++){
  for(int j=i+1;j<=N;j++){
    if((a[j]-a[i])%M==0)ans++;
  }
}*/

cout << ans << endl;
return 0;
}
==========================================

bool IsPrime[100100];
bool nearPrime[100010];

void Sieve_Eratosthenes(int max){
    /*if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    }*/
    for(int i=0;i<max;i++){
      IsPrime[i]=true;
    }
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  int l,r;
  cin >> Q;
  Sieve_Eratosthenes(100010);
  for(int i=3;i<100010;i+=2){
    if(IsPrime[i]==true && IsPrime[(i+1)/2]){
      nearPrime[i]=true;
      //cout << i << endl;
    }
  }
  int a[100010]={0};
  for(int i=1;i<100010;i++){
    if(nearPrime[i]){
      a[i]=a[i-1]+1;
    }else{
      a[i]=a[i-1];
    }
  }
  for(int i=0;i<Q;i++){
    int ans=0;
    cin >> l >> r;
    ans=a[r]-a[l-1];
    cout << ans << endl;
  }
  return 0;
}

// ABC084_素数_エラストテネスの篩

==========================================
void add(ll &a,ll b){
  a+=b;
  if(a>=MOD) a-=MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string S;
  cin >> S;
  ll n=S.size();
  ll dp[100100][4]={0};
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      if(S[i]=='?'){
        add(dp[i+1][j],dp[i][j]*3%MOD);
      }else{
        add(dp[i+1][j],dp[i][j]);
      }
    }
    if(S[i]=='A' || S[i]=='?')add(dp[i+1][1],dp[i][0]);
    if(S[i]=='B' || S[i]=='?')add(dp[i+1][2],dp[i][1]);
    if(S[i]=='C' || S[i]=='?')add(dp[i+1][3],dp[i][2]);
  }
  cout << dp[n][3] << endl;
  return 0;
}

// ABC104_Dp
==========================================

const ll MAX = 10000000;

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
  int N,M;
  cin >> N >> M;
  map<int,int> mp;
  ll ans=1;
  for(int i=2;i*i<=M;i++){
    while(M%i==0){
      mp[i]++;
      M/=i;
    }
  }
  COMinit();
  if(M!=1)mp[M]++;
  for(auto e:mp){
    ans*=calcComb(e.second+N-1,N-1)%MOD;
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}

//ABC_110_素因数分解
==========================================
ll N,M;
cin >> N >> M;
int ans_MAX=M/N;
for(int i=0;i<ans_MAX;i++){
  if(M%(ans_MAX-i)==0){
    cout << ans_MAX-i << endl;
    return 0;
  }
}
return 0;
}

//ABC_112_数学
==========================================
int N;
cin >> N;
int a[110];

for(int i=0;i<110;i++){
  a[i]=0;
}

for(int i=2;i<=N;i++){
  int m=i,l=2;
    while(m>1){
      if(m%l==0){
        a[l]++;
        m/=l;
      }else{
        l++;
      }
    }
}

int p=0,q=0,r=0,s=0,t=0;
for(int i=0;i<110;i++){
    if(a[i]>=74) p++;
    if(a[i]>=24) q++;
    if(a[i]>=14) r++;
    if(a[i]>=4) s++;
    if(a[i]>=2) t++;
}
int ans=p+q*(t-1)+r*(s-1)+s*(s-1)/2*(t-2);
cout << ans << endl;
return 0;
}

//ABC114_素因数分解
==========================================
int N,M;
int f[100100];
ll dp[100100];

ll dfs(int n){
  if(n==N+1) return 1;
  set<int> st1;
  int size=0;
  ll cnt=0;
  for(int i=n;i<=N;i++){
    st1.insert(f[i]);
    if(size==st1.size()){
      break;
    }else{
      size=st1.size();
    }
    cnt+=dfs(i+1)%MOD;
    if(size==M)break;
  }
  dp[n]=cnt;
  return dp[n]%MOD;
}

cin >> N >> M;
for(int i=1;i<=N;i++){
  cin >> f[i];
}
ll ans=dfs(1)%MOD;
cout << ans << endl;
return 0;


==========================================
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
#include <utility>
#include <iomanip>

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

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A,B;
  cin >> A >> B;
  char a[110][110];

  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(i<50)a[i][j]='.';
      else if(i>=50)a[i][j]='#';
    }
  }

  int cnt=0;
  bool flag=false;
  for(int i=0;i<49;i+=2){
    for(int j=0;j<100;j+=2){
      if(cnt==B-1)flag=true;
      if(flag)break;
      a[i][j]='#';
      cnt++;

      /*if(i%2==0 && j%2==1){
        a[i][j]='#';
        cnt++;
      }else if(i%2==1 && j%2==0){
        a[i][j]='#';
        cnt++;
      }*/
    }
    if(flag)break;
  }

  cnt=0;
  flag=false;
  for(int i=51;i<100;i+=2){
    for(int j=0;j<100;j+=2){
      if(cnt==A-1)flag=true;
      if(flag)break;
      a[i][j]='.';
      cnt++;

      /*if(i%2==0 && j%2==0){
        a[i][j]='.';
        cnt++;
      }else if(i%2==1 && j%2==1){
        a[i][j]='.';
        cnt++;
      }*/
    }
    if(flag)break;
  }
  cout << 100 << " " << 100 << endl;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}

//ABC_092
==========================================

int N,M;

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
        return (root(x) == root(y));
    }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int N_MAX=101000;
  int p[N_MAX];
  int ans=0;
  int b;
  for(int i=0;i<N;i++){
    cin >> b;
    p[i]=b-1;

  }
  int x,y;
  UnionFind uf1=UnionFind(N);
  for(int i=0;i<M;i++){
    cin >> x >> y;
    x--;
    y--;
    uf1.unite(p[x],p[y]);
    //uf1.unite(i,i);
  }
  for(int i=0;i<N;i++){
    if(i==p[i]){
      //cout << "A" << endl;
      ans++;
    }
    else if(uf1.same(p[i],i)){
      //cout << "B" << endl;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

//ABC097_D

==========================================
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,K;
  cin >> N >> K;
  bool used[101000]={0};
  vector<pair<int,int>> v;
  ll ans=0;
  int t,d;
  for(int i=0;i<N;i++){
    cin >> t >> d;
    v.push_back(make_pair(d,t));
  }
  sort(v.rbegin(),v.rend());
  priority_queue<int,vector<int>,greater<int>> que;
  ll cnt=0;
  for(int i=0;i<K;i++){
    ans+=v[i].first;
    if(!used[v[i].second]){
      cnt++;
      used[v[i].second]=true;
    }else{
      que.push(v[i].first);
    }
  }
  ll point =ans+cnt*cnt;

  for(int i=K;i<N;i++){
    if(cnt==K)break;
    if(!used[v[i].second]){
      cnt++;
      ans=ans-que.top()+v[i].first;
      que.pop();
      used[v[i].second]=true;
      point=max(point,ans+cnt*cnt);
    }else{
      continue;
    }
  }
  cout << point << endl;
  return 0;
}

//ABC116_priority_queue_pair_vector
==========================================
int N_MAX=110;
int h[N_MAX];
int mi=111;
int ma=0;
int ans=0;
for(int i=1;i<=N;i++){
  cin >> h[i];
  mi=min(mi,h[i]);
}
if(mi!=0){
  for(int i=1;i<=N;i++){
    h[i]-=mi;
  }
  ans+=mi;
}
h[N+1]=0;
h[0]=0;
int l=1,r=1;
bool flag=true;
bool plus=false;
bool minus=false;
mi=110;
ma=0;
while(l<=N){
  if(h[l]==0 && flag){
    l++;
    r=l;
    continue;
  }else if(h[r]==0 && !flag){
    if((plus && !minus) || (!plus && minus)){
      ans+=ma;
      l=r+1;
      r=l;
      mi=110;
      ma=0;
      flag=true;
      plus=false;
      minus=false;
      //cout << "A" << endl;
      //cout << ans << endl;
      continue;
    }
    for(int i=l;i<=r-1;i++){
      h[i]-=mi;
    }
    ans+=mi;
    mi=110;
    ma=0;
    flag=true;
    plus=false;
    minus=false;
    //cout << "B" << endl;
    r=l;
    //cout << ans << endl;
    continue;
  }else{
    if(h[r-1]<h[r]){
      plus=true;
    }else if(h[r-1]>h[r]){
      minus=true;
    }
    mi=min(mi,h[r]);
    ma=max(ma,h[r]);
    r++;
    flag=false;
  }
}
cout << ans << endl;
return 0;
}



while(l<=N){
  if(h[l]==0 && flag){
    l++;
    r=l;
    continue;
  }else if(h[r]==0 && !flag){
    for(int i=l;i<=r-1;i++){
      h[i]-=mi;
    }
    ans+=mi;
    mi=110;
    ma=0;
    flag=true;
    continue;
  }else{
    mi=min(mi,h[r]);
    r++;
    flag=false;
  }
}
cout << ans << endl;
return 0;
}

for(int i=1;i<=N+2;i++){
if(i==N+2){
  cout << ans << endl;
  return 0;
}
ma=max(ma,h[i]);
if(h[i]==0 && ma!=0){
  for(int j=1;j<=i;j++){
    h[j]-=mi;
  }
  ans+=mi;
}
if(h[i]!=0) mi=min(mi,h[i]);
}
}
==========================================
int s;
cin >> s;
vector<int> v;
v.push_back(s);
set<int> st;
st.insert(s);
int ans=1;
while(1){
  if(s%2==0){
    s/=2;
    v.push_back(s);
    st.insert(s);
    ans++;
  }else{
    s=3*s+1;
    v.push_back(s);
    st.insert(s);
    ans++;
  }
  if(st.size()!=v.size()){
    cout << ans << endl;
    return 0;
  }
}
}


==========================================
ll ans;
ll a,b,c;
cin >> a >> b >> c;
cout << a*b*c/2*max({a,b,c}) << endl;
return 0;
