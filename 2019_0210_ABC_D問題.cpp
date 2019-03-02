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




===========================================
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
#include <numeric>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<30)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N,M;
  cin >> N >> M;
  ll A[10]={0,2,5,5,4,5,6,3,7,6};
  bool B[10];

  ll cnt=10;// 最小本数
  ll num=0;//その数字
  for(int i=0;i<M;i++){
    int t;
    cin >> t;
    B[t]=true;
    if(cnt>A[t]){
      cnt=A[t];
      num=t;
    }
  }
  ll digit=N/cnt;
  ll amari=N%cnt;
  bool flag=false;
  string S="";
  if(amari!=0){
    while(1){
      for(int i=9;i>=1;i--){
        if(B[i]==true && amari+A[num]==A[i]){
          digit--;
          while(digit){
            string c=to_string(num);
            S+=c;
            digit--;
          }
          if(num>i){
            string c=to_string(i);
            S+=c;
          }else{
            string c=to_string(i);
            S=c+S;
          }
          flag=true;
        }
        if(flag)break;
      }
      if(flag)break;
      digit--;
      amari=amari+cnt;
    }
    cout << S;
  }else{
    while(digit){
      cout << num;
      digit--;
    }
  }
  cout << endl;
  return 0;
}
===========================================
===========================================
===========================================
===========================================
int n,x;
cin >> n >> x;
int N=n;
if(x==1 || x==2*N-1){
  cout << "No" << endl;
  return 0;
}
if(N==2){
    cout<<"Yes"<<endl;
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    return 0;
}
cout<<"Yes"<<endl;
if(x>=n){
  for(int i=x-n+1;i<=2*n-1;i++) cout<<i<<endl;
  for(int i=1;i<x-n+1;i++) cout<<i<<endl;
}else{
  for(int i=n+x-1;i>=1;i--) cout<<i<<endl;
  for(int i=2*n-1;i>n+x-1;i--) cout<<i<<endl;
}
}

//AGC006
===========================================
ll N;
cin >> N;
ll ans=0;
ll A[1000100]={0};
for(int i=1;i<=N;i++){
  cin >> A[i];
}
for(int i=1;i<=N;i++){
  if(A[i]%2==1 && A[i+1]>0){
    A[i]--;
    A[i+1]--;
    ans++;
  }
  ans+=A[i]/2;
}
cout << ans << endl;
return 0;
}
// AGC003_考え方_0の初期化_数字の大きさ_
===========================================
string S;
cin >> S;
int n=S.size();
ll ans=n-1;
for(int i=2;i<=n;i++){
  if(i==n){
    ans+=n-1;
    break;
  }
  if(S[i-1]=='U'){
    ans+=(n-i);
    ans+=(i-1)*2;
  }else if(S[i-1]=='D'){
    ans+=(i-1);
    ans+=(n-i)*2;
  }
}
cout << ans << endl;
return 0;
}
//AGC15_考え方
===========================================
ll N,A,B,C,D;
cin >> N >> A >> B >> C >> D;
bool flag=false;
ll cnt=B-A;
for(int i=0;i<=N-1;i++){
  if(C*i-D*(N-1-i)<=cnt && cnt<=-C*(N-1-i)+D*i){
    flag=true;
    break;
  }
}

if(flag) cout << "YES" << endl;
else cout << "NO" << endl;
return 0;
}
//AGC17_考え方
===========================================
int N,K;
cin >> N >> K;
ll t[100100]={0};
ll s[100100]={0};
ll a;
t[0]=0;
s[0]=0;
for(int i=1;i<=N;i++){
  cin >> a;
  t[i]=t[i-1]+a;
  s[i]=s[i-1]+max(a,0LL);
}
ll ans=0;
for(int i=0;i<=N-K;i++){
  ans=max(ans,s[N]-s[i+K]+s[i]);
  ans=max(ans,s[N]-s[i+K]+s[i]+t[i+K]-t[i]);
}
cout << ans << endl;
return 0;
}

//AGC008_累積和_考え方
===========================================
int N;
cin >> N;
vector<ll> A;
ll a;
for(int i=1;i<=N;i++){
  cin >> a;
  A.push_back(a);
}
sort(A.begin(),A.end());
ll cnt=A[0];
ll ans=1;
for(int i=1;i<N;i++){
  if(cnt*2<A[i]){
    ans=1;
    cnt+=A[i];
  }else{
    ans++;
    cnt+=A[i];
  }
}
cout << ans << endl;
return 0;
}
// AGC11_考え方

===========================================
int N,M;
cin >> N >> M;
int dp[100010];
for(int i=1;i<=N;i++){
  dp[i]=1;
}
bool visited[100010]=false;
visited[1]=true;
int x,y;
for(int i=1;i<=M;i++){
  cin >> x >> y;
  dp[x]--;
  dp[y]++;
  if(visited[x]==true){
    visited[y]=true;
  }
  if(dp[x]==0){
    visited[x]=false;
  }
}
int ans=0;
for(int i=0;i<=N;i++){
  if(visited[i])ans++;
}
cout << ans << endl;
return 0;
}
//AGC002_考え方とDP?
===========================================

map<int,pair<int,int>> A;
int calcMagic(int a,int b,int c,int d){
  int cnt=abs(a-c)+abs(b-d);
  return cnt;
}

/*int magic(int p,int q, int r){
  if(p==q)return 0;
  int a,b,c,d;
  a=A[p].first;
  b=A[p].second;
  c=A[p+r].first;
  d=A[p+r].second;
  return calcMagic(a,b,c,d)+magic(p+r,q,r);
}*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int H,W,D;
  cin >> H >> W >> D;

  int a;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin >> a;
      A[a]=make_pair(i,j);
      //cout << A[a].first << " " << A[a].second << endl;
    }
  }
  int dp[900100]={0};
  dp[0]=0;
  for(int i=0;i<=H*W;i++){
    dp[i+D]=dp[i]+calcMagic(A[i].first,A[i].second,A[i+D].first,A[i+D].second);
  }

  int Q;
  cin >> Q;
  for(int i=1;i<=Q;i++){
    int l,r;
    cin >> l >> r;
    int ans=dp[r]-dp[l];
    cout << ans << endl;
  }
  return 0;
}
//ABC89_dp


===========================================
const ll MAX = 200010;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
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
long long calcComb(ll a, ll b) {
	if (b > a - b) return calcComb(a, a - b);


	ll ansMul = 1;
	ll ansDiv = 1;
	for (int i = 0; i < b; i++)
	{
		ansMul *= (a - i);
		ansDiv *= (i + 1);
		ansMul %= MOD;
		ansDiv %= MOD;
	}
	//ansMul / ansDivをやりたい
	//ansDivの逆元を使って求めよう！

	ll ans = ansMul * pow_mod(ansDiv,MOD - 2,MOD);
	return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll H,W,A,B;
  cin >> H >> W >> A >> B;
  ll ans=0;
  COMinit();
  for(int i=1;i<=H-A;i++){
    ans+=(COM(i-1+B-1,i-1)*COM(H+W-B-i-1,H-i)%MOD);
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}

//ABC58_組み合わせ
===========================================
ll N,W;
cin >> N >> W;

vector<ll> vec[5]; // vec(5)はダメ
for(int i=0;i<5;i++) vec[i].clear();

ll w,v,w0;
cin >> w0 >> v;
vec[0].push_back(v);
for(int i=1;i<N;i++){
  cin >> w >> v;
  vec[w-w0].push_back(v);
}
for(int i=0;i<4;i++)sort(vec[i].begin(),vec[i].end(),greater<ll>());

ll sum[5][120];
for(int it=0;it<4;it++){
  sum[it][0]=0;
  for(int i=0;i<110;i++){
    sum[it][i+1]=sum[it][i]+(i<vec[it].size()?vec[it][i]:0);
  }
}

ll ans=0;
for(int a=0;a<=N && w0*a <=W; a++){
  for(int b=0;b+a<=N && w0*a+(w0+1)*b <=W; b++){
    for(int c=0;c+b+a<=N && w0*a+(w0+1)*b+(w0+2)*c <=W; c++){
      //ll d = min(N-a-b-c, (W-w0*a-(w0+1)*b-(w0+2)*c)/(w0+3));
      //if (d < 0) continue;
      ll d=(W-w0*a-(w0+1)*b-(w0+2)*c)/(w0+3);
      if(d<0)continue;
      ll cnt=sum[0][a]+sum[1][b]+sum[2][c]+sum[3][d];
      if(ans<cnt)ans=cnt;
    }
  }
}
cout << ans << endl;
return 0;
}

// ABC73_Dp_高速化
===========================================
ll N,W;
cin >> N >> W;

vector<ll> vec[5]; // vec(5)はダメ
for(int i=0;i<5;i++) vec[i].clear();

ll w,v,w0;
cin >> w0 >> v;
vec[0].push_back(v);
for(int i=1;i<N;i++){
  cin >> w >> v;
  vec[w-w0].push_back(v);
}
for(int i=0;i<4;i++)sort(vec[i].begin(),vec[i].end(),greater<ll>());

ll sum[5][120];
for(int it=0;it<4;it++){
  sum[it][0]=0;
  for(int i=0;i<110;i++){
    sum[it][i+1]=sum[it][i]+(i<vec[it].size()?vec[it][i]:0);
  }
}

ll ans=0;
for(int a=0;a<=N && w0*a <=W; a++){
  for(int b=0;b+a<=N && w0*a+(w0+1)*b <=W; b++){
    for(int c=0;c+b+a<=N && w0*a+(w0+1)*b+(w0+2)*c <=W; c++){
      //ll d = min(N-a-b-c, (W-w0*a-(w0+1)*b-(w0+2)*c)/(w0+3));
      //if (d < 0) continue;
      ll d=(W-w0*a-(w0+1)*b-(w0+2)*c)/(w0+3);
      if(d<0)continue;
      ll cnt=sum[0][a]+sum[1][b]+sum[2][c]+sum[3][d];
      if(ans<cnt)ans=cnt;
    }
  }
}
cout << ans << endl;
return 0;
}

// ABC73_Dp_高速化
===========================================
int N,C;
cin >> N >> C;
int N_MAX=510;
int C_MAX=40;
int D[C_MAX][C_MAX]={0};
for(int i=1;i<=C;i++){
  for(int j=1;j<=C;j++){
    cin >> D[i][j];
  }
}
int c[10][40]={0};
int q;
for(int i=1;i<=N;i++){
  for(int j=1;j<=N;j++){
    cin >> q;
    c[(i+j)%3][q]++;
  }
}
ll cnt=0;
ll ans=INF;
for(int i=1;i<=C;i++){
  for(int j=1;j<=C;j++){
    if(i==j)continue;
    for(int k=1;k<=C;k++){
      if(j==k||k==i)continue;
      cnt=0;
      for(int m=1;m<=C;m++){
        cnt+=D[m][i]*c[0][m];
        cnt+=D[m][j]*c[1][m];
        cnt+=D[m][k]*c[2][m];
      }
      ans=min(cnt,ans);
    }
  }
}
cout << ans << endl;
return 0;
}
//ABC99_高速化

===========================================
int N,C;
cin >> N >> C;
int N_MAX=200100;
int s[N_MAX],t[N_MAX],c[N_MAX];
int time[35][N_MAX]={0};
int min_time=2000010,max_time=0;
int ans=0;
for(int i=1;i<=N;i++){
  cin >> s[i] >> t[i] >> c[i];
  for(int j=2*s[i]-1;j<=2*t[i];j++){
    time[c[i]][j]=1;
  }
  min_time=min(min_time,s[i]*2-1);
  max_time=max(max_time,t[i]*2);
}
for(int j=min_time;j<=max_time;j++){
  int cnt=0;
  for(int i=1;i<=30;i++){
    if(time[i][j]>0){
      cnt++;
    }
  }
  ans=max(ans,cnt);
}
cout << ans << endl;
return 0;
}
// ABC80

===========================================
ll H,W,N;
cin >> H >> W >> N;
map<P,ll> m;
ll a,b;
ll cnt[10]={0};
cnt[0]=(H-2)*(W-2);
for(int i=0;i<N;i++){
  cin >> a >> b;
  a--;
  b--;
  for(int k=a-2;k<=a;k++){
    for(int l=b-2;l<=b;l++){
      if(k<0 || l<0 || k>=H-2 || l>=W-2)continue;
      cnt[m[{k,l}]]--;
      m[{k,l}]++;
      cnt[m[{k,l}]]++;
    }
  }
}

/*for(int i=0;i<H-2;i++){
  for(int j=0;j<W-2;j++){
    black=m[{i,j}];
    cnt[black]++;
  }
}*/
for(int i=0;i<=9;i++){
  cout << cnt[i] << endl;
}
return 0;
}

//ABC61_高速化_map_pair
===========================================
int X,Y;
cin >> X >> Y;
if(X%Y==0){
  cout << -1 << endl;
  return 0;
}
int ans=X;
while(ans%Y==0){
  ans+=X;
}
cout << ans << endl;
return 0;
===========================================
double N,A,B;
cin >> N >> A >> B;
vector<double> v;
ll h;
for(int i=0;i<N;i++){
  cin >> h;
  v.push_back(h);
}
ll ans=0;
ll cnt=0;
sort(v.begin(),v.end());
ll lb=0,ub=1000000000;
while(ub-lb>1){
  cnt=0;
  ll mid=(lb+ub)/2;
  for(int i=0;i<N;i++){
    if(v[i]<=B*mid)continue;
    else if(v[i]>B*mid){
      cnt+=ceil((v[i]-B*mid)/(A-B));
    }
  }
  if(cnt<=mid){
    ub=mid;
  }else{
    lb=mid;
  }
}
cout << lb+1 << endl;
return 0;
}
// ABC075_にぶたん_ガウス
===========================================

vector<int> v[100010];
int d1[100010]={0};
int d2[100010]={0};

void dfs(int s, int m, int d[]){
  d[s]=d[m]+1;
  for(auto e:v[s]){
    if(e==m)continue;
    dfs(e,s,d);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int a,b;
  for(int i=1;i<=N-1;i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  d1[0]=-1;
  d2[0]=-1;

  dfs(1,0,d1);
  dfs(N,0,d2);

  int ans=0;

  for(int i=1;i<=N;i++){
    if(d1[i]<=d2[i])ans++;
    else ans--;
  }
  if(ans>0)cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
  return 0;
}
// ABC67_幅優先探索_擬似LCA
===========================================
ll dp[53][53];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int H,W;
int a[53][53]={0};
//bool visited[53][53];
bool flag=false;

void dfs(int p,int q,int cost){
  // if(visited[p][q])return dp[p][q];
  //visited[p][q]=true;
  if(p==H-1 && q==W-1){
    flag =true;
    dp[p][q]=cost;
    return;
  }
  if(dp[p][q]>cost){
    dp[p][q]=cost;
    for(int i=0;i<4;i++){
      int x=p+dx[i],y=q+dy[i];
      if(a[x][y]==1)continue;
      if(x<0 || y<0 || x>=H || y>=W) continue;
      dfs(x,y,cost+1);
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W;
  char c;
  ll kuro=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> c;
      if(c=='#'){
        a[i][j]=1;
        kuro++;
      }
      dp[i][j]=100000;
    }
  }
  dfs(0,0,1);
  if(!flag){
    cout << -1 << endl;
    return 0;
  }
  //cout << dp[H-1][W-1] << endl;
  ll ans=H*W-kuro-dp[H-1][W-1];
  cout << ans << endl;
  return 0;
}
// ABC88_幅優先探索_定石_重要
===========================================
ll N,Z,W;
cin >> N >> Z >> W;
ll a[2010];
ll score=abs(Z-W);
for(int i=1;i<=N;i++){
  cin >> a[i];
}
if(N==1){
  cout << abs(a[1]-W) << endl;
  return 0;
}
score=max(abs(a[N]-W),abs(a[N-1]-a[N]));
cout << score << endl;
return 0;
}
// ABC078_考え方
===========================================
int N;
cin >> N;
string S;
cin >> S;
string ans="";
bool flag=true;// trueは羊
for(int i=0;i<N;i++){
  if(i==0){
    ans+="S";
    flag=true;
  }
  if(S[i]=='o'){
    if(flag){
      ans+="S";
      flag=true;
    }else{
      ans+="W";
      flag=false;
    }
  }else if(S[i]=='x'){
    if(flag){
      ans+="W";
      flag=false;
    }else{
      ans+="S";
      flag=true;
    }
  }
  if(i==N-1){
    if(S[0]=='o' && ans[N-1]=='S'){
      cout << ans << endl;
      return 0;
    }else if(S[0]=='x' && ans[N-1]=='S'){
      cout << ans << endl;
      return 0;
    }
  }
}

for(int i=0;i<N;i++){
  if(i==0){
    ans+="W";
    flag=false;
  }
  if(S[i]=='o'){
    if(flag){
      ans+="W";
      flag=true;
    }else{
      ans+="S";
      flag=false;
    }
  }else if(S[i]=='x'){
    if(flag){
      ans+="S";
      flag=false;
    }else{
      ans+="W";
      flag=true;
    }
  }
  if(i==N-1){
    if(S[0]=='o' && ans[N-1]=='W'){
      cout << ans << endl;
      return 0;
    }else if(S[0]=='x' && ans[N-1]=='S'){
      cout << ans << endl;
      return 0;
    }
  }
}
cout << "-1" << endl;
return 0;
}
// ABC55
===========================================
ll X,Y;
cin >> X >>Y;
if(abs(X-Y)<=1LL){
  cout << "Brown" << endl;
}else{
  cout << "Alice" << endl;
}
return 0;
}
// ABC59_場合分けと帰納法
===========================================
ll N,K;
cin >> N >> K;
ll ans=0;
ll cnt;
if(K==0){
  cout << N*N << endl;
  return 0;
}
for(ll i=K+1;i<=N;i++){
  // cnt=0;
  ans+=(i-K)*(N/i);
  //cout << ans << " " << cnt << endl;
  ll r=N-(N/i)*i+1;
  ans+=max(0LL,r-K);
  //cout << ans << " " << cnt << endl;
}
cout << ans << endl;
return 0;
}

// ABC_90_数学_場合分け
===========================================
const ll N_MAX=100100;
ll depth[N_MAX];
vector<pair<ll,ll>> tree[N_MAX];

void dfs(ll p,ll q,ll r){
  depth[p]=r;
  for(auto &e:tree[p]){
    if(e.first==q)continue;
    //depth[e.first]=depth[p]+e.second;
    dfs(e.first,p,r+e.second);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  ll a,b,c;
  for(int i=0;i<N-1;i++){
    cin >> a >> b >> c;
    a--;
    b--;
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }
  ll Q,K;
  cin >> Q >> K;
  K--;
  dfs(K,-1,0);
  ll x,y;
  for(int i=0;i<Q;i++){
    cin >> x >> y;
    x--;
    y--;
    cout << depth[x]+depth[y] << endl;
  }
  return 0;
}
// ABC70_tree_重み

===========================================
int N;
cin >> N;
int v[110],t[110];
int total_time =0;
for(int i=1;i<=N;i++){
  cin >> t[i];
  total_time+=t[i];
}
for(int i=1;i<=N;i++){
  cin >> v[i];
}
int ans=0;
int time =0;
int max_speed=0;
int speed =0;
for(int i=1;i<=N;i++){
  while(time<=v[i]){
    time++;
    if(total_time/2>time)
    if(speed<=max_speed)

  }
}
cout << ans << endl;
return 0;
===========================================

ll N;
string S1,S2;
cin >> N >> S1 >> S2;
bool flag=true; // tureの時_縦
ll ans=0;
for(int i=0;i<N;i++){
  if(S1[i]==S2[i]){
    if(ans==0){
      ans=3;
      flag =true;
      continue;
    }
    if(flag){
      ans*=2;
    }else{
      ans*=1;
    }
    ans%=MOD;
    flag=true;
  }else if(S1[i]==S1[i+1]){
    if(ans==0){
      ans=6;
      flag =false;
      i+=1;
      continue;
    }
    if(flag){
      ans*=2;
    }else{
      ans*=3;
    }
    flag=false;
    i+=1;
    ans%=MOD;
  }
}
cout << ans%MOD << endl;
return 0;
}

// ABC071_場合分け
