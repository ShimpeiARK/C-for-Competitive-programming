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
  int N,K;
  cin >> N >> K;
  string s;
  cin >> s;
  string ans=s;
  sort(ans.begin(),ans.end());
  //cout << ans << endl;
  do{
    int cnt=0;
    for(int i=0;i<N;i++){
      if(ans[i]!=s[i])cnt++;
    }
    if(K>=cnt){
      cout << ans << endl;
      return 0;
    }
  }while(next_permutation(ans.begin(),ans.end()));
  cout << s << endl;
  return 0;
}

ABC_009_辞書順列

https://atcoder.jp/contests/abc009/submissions/2336339


===================================================

===================================================
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
#define INFA (1<<29)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int R,C,K;
  int N_MAX=510;
  int ue[N_MAX][N_MAX],sita[N_MAX][N_MAX];
  string s;
  cin >> R >> C >>K;

  for(int i=0;i<R;i++){
    cin >> s[i];
  }
  for(int i=0;i<R;i++){
      cout << s[i];
    cout << endl;
  }

  /*for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(s[i][j]=='x')continue;
      ue[i][j]=1;
      for(int k=i-1;k>=0;k--){
        if(s[k][j]=='x') break;
        else ue[i][j]++;
      }
      sita[i][j]=1;
      for(int k=i+1;k<R;k++){
        if(s[k][j]=='x') break;
        else sita[i][j]++;
      }
    }
  }

  int ans=0;
  for(int i=K-1;i<=R-K;i++){
    for(int j=K-1;j<=C-K;j++){
      bool flag=true;
      int cnt=1;
      for(int k=j-K+1;k<=j;k++){
        if(cnt>ue[i][k] ||cnt>sita[i][k]){
          flag=false;
          break;
        }
        cnt++;
      }
      cnt=K-1;
      for(int k=j+1;k<=j+K-1;k++){
        if(cnt>ue[i][k] ||cnt>sita[i][k]){
          flag=false;
          break;
        }
        cnt--;
      }
      if(flag) ans++;
    }
  }
  cout << ans << endl;
  */
  return 0;
}

ABC_18_条件式

===================================================
const ll INF=10000000000;
char a[110][110];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int H,W,T;
  cin >> H >> W >>T;
  int S,G;
  int EN=W;
  int AN=H;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a[i][j];
      if(a[i][j]=='S') S=i*EN+j*AN;
      if(a[i][j]=='G') G=i*EN+j*AN;
    }
  }
  ll lb=1,ub=T;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    ll d[2*H*W][2*H*W];
    for(int i=0;i<2*H*W;i++){
      for(int j=0;j<2*H*W;j++){
        if(i==j)d[i][j]=0;
        else d[i][j]=INF;
      }
    }
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        for(int k=0;k<4;k++){
          int x=i+dx[k],y=j+dy[k];
          if(x<0||y<0||x>=H||y>=W)continue;
          ll ins=(a[x][y]=='#'?mid:1);
          d[i*EN+j*AN][x*EN+y*AN]=ins;
        }
      }
    }
    for(int k=0;k<2*H*W;k++){
      for(int i=0;i<2*H*W;i++){
        for(int j=0;j<2*H*W;j++){
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
      }
    }
    if(d[S][G]<=1LL*T) lb=mid;
    else ub=mid;
  }
  cout << lb << endl;
  return 0;
}

ABC_20壁抜け

===================================================
int N,Q;
cin >> N >> Q;
int N_MAX=200100;
int imos[N_MAX];
for(int i=0;i<N_MAX;i++){
  imos[i]=0;
}
int l,r;
for(int i=0;i<Q;i++){
  cin >> l >> r;
  imos[l-1]++;
  imos[r]--;
}
for(int i=0;i<N;i++){
  imos[i+1]=imos[i+1]+imos[i];
}
for(int i=0;i<N;i++){
  if(imos[i]%2==0){
    cout << 0;
  }else{
    cout << 1;
  }
}
cout << endl;
return 0;
}
===================================================
int N,M;
cin >> N >> M;
for(int i=0;i<=N;i++){
  int j=4*N-2*i-M;
  if(j>=0 && 2*i+3*j+4*(N-i-j)==M && N-i-j>=0){
    cout << i << " " << j << " " << (N-i-j) << endl;
    return 0;
  }
}
cout << -1 << " " << -1 << " " << -1 << endl;
return 0;
}
===================================================
ll N,H,A,B,C,D,E;
ll cost =LLONG_MAX;
cin >> N >> H >> A >> B >> C >> D >> E;
for(int i=0;i<=N;i++){
  ll j=floor((double)((N-i)*E-H-B*i)/(D+E))+1;
  if(j>=0 && j<=N-i){
    cost=min(cost,i*A+j*C);
  }/*else if(j<0){
    cost=min(cost,i*A);
  }*/
}
cout << cost << endl;
return 0;
}

ABC_節制条件式
===================================================
int N,K;
int s[100100]={0};
cin >> N >> K;
for(int i=1;i<=N;i++){
  cin >> s[i];
  if(s[i]==0){
    cout << N << endl;
    return 0;
  }
}
if(K==0){
  cout << 0 << endl;
  return 0;
}
ll ans=0;
ll product=1;
ll cnt=0;
ll p=1,q=0;
ll ul=1;
while(p<=N){
  while(product<=K){
    q++;
    product*=s[q];
    if(q>N){
      break;
    }
  }
  if(q>N){
    cnt=q-p;
    break;
  }
  cnt=q-p;
  ans=max(ans,cnt);
  //cout << ans << endl;
  while(product>K){
    product/=s[p];
    p++;
    if(p>N){
      break;
    }
  }
}
ans=max(ans,cnt);
cout << ans << endl;
return 0;
}
/*if(s[i]>K){
product=1;
cnt=0;
}else{
product=s[i];
cnt=1;
}
}else{
cnt++;
}*/


ABC_32列_しゃくとり法

===================================================
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
  ll N;
  cin >>N;
  ll N_MAX=100100;
  ll a[N_MAX]={0};
  ll b[N_MAX]={0};

  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  for(int i=0;i<N-1;i++){
    b[i]=a[i+1]-a[i];
  }
  ll ans=N;
  ll cnt=0;
  for(int i=0;i<N-1;i++){
    if(b[i]>0){
      cnt++;
    }else{
      cnt=0;
    }
    ans+=cnt;
  }
  cout << ans << endl;
  return 0;
}
===================================================
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


const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];
ll W,H;

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
  cin >> W >> H;
  COMinit();
  ll sum=COM(W+H-2,H-1);
  cout << sum << endl;
  return 0;
}
===================================================

int W,H;
ll dp[1010][1010];
bool used[1010][1010];

ll dfs(int s,int t){
  if(s<0 || t<0) return 0;
  if(1==s && 1==t) return 1;
  if(used[s][t])return dp[s][t];
  used[s][t]=true;
  dp[s][t]=(dfs(s-1,t)%MOD+dfs(s,t-1)%MOD)%MOD;
  return dp[s][t];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> W >> H;
  for(int i=0;i<1010;i++){
    for(int j=0;j<1010;j++){
      dp[i][j]=0;
    }
  }
  dp[1][1]=1;
  cout << dfs(W,H)%MOD << endl;
  return 0;
}
===================================================

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int D,G;
  cin >> D >> G;
  G/=100;
  int ans=10100;
  int p[20],c[20];
  for(int i=0;i<D;i++){
    cin >> p[i] >> c[i];
    c[i]/=100;
    //cout << c[i] << endl;
  }
  for(int bit=0;bit<(1<<D);bit++){
    int point=0;
    int cnt=0;
    //cout << cnt << endl;
    for(int i=0;i<D;i++){
      if(bit >> i & 1){
        point+=(i+1)*p[i]+c[i];
        cnt+=p[i];
        //cout << "a" << i << " " << cnt << endl;
      }
    }
    if(point>=G){
      ans=min(ans,cnt);
      continue;
    }
    bool flag =false;
    for(int i=D-1;i>=0;i--){
      if(flag)break;
      if((bit >> i & 1)==0){//bit^1などの真偽判定が重要
        //cout << "b"<< i << endl;
        int sum=0;
        while(G>point && p[i]>sum){
          point+=(i+1);
          cnt++;
          sum++;
        }

        flag=true;
      }
    }
    if(point>=G){
      ans=min(ans,cnt);
      //cout << ans << endl;
      //cout << endl;
    }
  }
  cout << ans << endl;
  return 0;
}




===================================================
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
  int N;
  string s="";
  cin >> N;
  while(N!=0){
    if(N%2==0){
      s="0"+s;
    }else{
      N--;
      s="1"+s;
    }
    N/=-2;
  }
  if(s=="") s='0';
  cout << s << endl;
  return 0;
}


C. Base -2 Number
===================================================
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

ll N;
ll dfs(ll s){
  if(s>N)return 0;
  string str=to_string(s);
  ll three=0,five=0,seven=0;
  ll cnt=0;
  for(int i=0;i<str.size();i++){
    if(str.size()<3)break;
    if(str[i]-'0'==3)three++;
    else if(str[i]-'0'==5)five++;
    else if(str[i]-'0'==7)seven++;
  }
  if(three*five*seven>0)cnt=1;
  else cnt=0;
  ll num=atoi(str.c_str());
  cnt+=dfs(num*10+7);
  cnt+=dfs(num*10+5);
  cnt+=dfs(num*10+3);
  return cnt;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  cout << dfs(0) << endl;
  return 0;
}

755
===================================================
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
  int ans=-10000;
  int N;
  cin >> N;
  int a[110];
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  int MAX_TAKAHASHI=-10000;
  for(int i=0;i<N;i++){
    int MAX_AOKI=-10000;
    for(int j=0;j<N;j++){
      if(i==j)continue;
      int Takahashi=0;
      int Aoki=0;
      for(int k=0;k<=abs(j-i);k++){
        if(k%2==0){
          Takahashi+=a[k+min(i,j)];
        }else{
          Aoki+=a[k+min(i,j)];
        }
      }
      if(MAX_AOKI<Aoki){
        MAX_AOKI=Aoki;
        MAX_TAKAHASHI=Takahashi;
      }
    }
    ans=max(ans,MAX_TAKAHASHI);
  }
  cout << ans << endl;
  return 0;
}
数列ゲーム

===================================================
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll ans;
  ll N;
  cin >> N;
  if(N==1){
    cout << "Aoki" << endl;
    return 0;
  }else if(N==2 || N==3){
    cout << "Takahashi" << endl;
    return 0;
  }
  ll depth=0;
  ll n=N;
  while(n>0){
    n/=2;
    depth++;
  }
  ll a=1;//1=高橋，-1=青木
  ll b=1;
  if(depth%2==0){
    while(b<=N){
      if(a==1){
        b=b*2;
      }else{
        b=b*2+1;
      }
      a=a*(-1);
    }
  }
  else{
    while(b<=N){
      if(a==1){
        b=b*2+1;
      }else{
        b=b*2;
      }
      a=a*(-1);
    }
  }
  if(a==1)cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
倍々ゲーム

===================================================
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N,M;
  cin >> N >> M;
  ll N_MAX=310;
  ll g[N_MAX][N_MAX];
  vector<int> a;
  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<N_MAX;j++){
      g[i][j]=1000000100;
      if(i==j)g[i][j]=0;
    }
  }
  ll u,v,l;
  for(int i=0;i<M;i++){
    cin >> u >> v >> l;
    g[u][v]=g[v][u]=l;
    if(u==1){
      a.push_back(v);
    }
  }
  for(int i=2;i<=N;i++){
    for(int j=2;j<=N;j++){
      for(int k=2;k<=N;k++){
        if(g[j][i]+g[i][k]<g[j][k]){
          g[j][k]=g[j][i]+g[i][k];
        }
      }
    }
  }
  ll ans=1000000100;
  for(int i=1;i<a.size();i++){
    for(int j=0;j<i;j++){
      ans=min(ans,g[1][a[i]]+g[a[i]][a[j]]+g[a[j]][1]);
    }
  }
  if(ans>=1000000100){
    ans=-1;
  }
  cout << ans << endl;
  return 0;
}
ABC022_Blue_Bird_ワーシャルフロイド_bit
===================================================
int x,y,k;
cin >> x >> y;
cin >> k;
if(y>=k){
  cout << x+k << endl;
  return 0;
}else if(y<k){
  cout << y+(x-(k-y)) << endl;
  return 0;
}
}
===================================================
string S;
cin >> S;
for(int i=0;i<S.size();i++){
  if(S[i]-'0'<11){
    cout << S[i];
  }else if(S[i]=='B'){
    cout << '8';
  }else if(S[i]=='O'){
    cout << '0';
  }else if(S[i]=='I'){
    cout << '1';
  }else if(S[i]=='D'){
    cout << '0';
  }else if (S[i]=='Z'){
    cout << '2';
  }else if(S[i]=='S'){
    cout << '5';
  }
}
cout << endl;
return 0;
===================================================
string d;
cin >> d;
if(d[0]=='S'){
  cout << 0 << endl;
  return 0;
}
char c=d[1];
switch(c){
  case 'o':
    cout << 5 << endl;
    break;
  case 'u':
    cout << 4 << endl;
    break;
  case 'e':
    cout << 3 << endl;
    break;
  case 'h':
    cout << 2 << endl;
    break;
  case 'r':
    cout << 1 << endl;
    break;
  default:
    break;
}
return 0;
}
===================================================
int N,M,A,B;
int c;
cin >> N >> M >> A >> B;
for(int i=1;i<=M;i++){
  if(N<=A)N+=B;
  cin >> c;
  N-=c;
  if(N<0){
    cout << i << endl;
    return 0;
  }
}
cout << "complete" << endl;
return 0;
}
===================================================
int  N;
cin >> N;
double ans=0;
for(int i=0;i<N;i++){
  int a,b;
  cin  >>  a >> b;
  ans+=a*b;
}
cout << floor(ans*1.05) << endl;
return 0;
}
===================================================
string S[3]={"TAKAHASHIKUN","Takahashikun","takahashikun"};
int N;
cin >> N;
string w;
int ans=0;
for(int i=0;i<N;i++){
  cin >> w;
  if(w.size()>=14)continue;
  for(int j=0;j<3;j++){
    bool flag=false;
    for(int k=0;k<12;k++){
      if(S[j][k]!= w[k])break;
      if(k==11){
        ans++;
        flag=true;
      }
    }
    if(flag)break;
  }
}
cout << ans << endl;
return 0;
}
===================================================
int E[12]={0},L[12]={0};
int B;
int n;
int cnt=8;
for(int i=0;i<=5;i++){
  cin >> n;
  E[n]++;
}
cin >> B;
bool flag=false;
for(int i=0;i<=5;i++){
  cin >> n;
  if(E[n]==1){
    cnt--;
  }else if(n==B)flag=true;
}
if(cnt==3 && flag)cnt--;
else if(cnt==2)cnt--;
else if(cnt>5) cnt=0;
cout << cnt << endl;
return 0;
}
===================================================
char X;
string s;
cin >> X >> s;
for(int i=0;i<s.size();i++){
  if(s[i]!=X){
    cout << s[i];
  }
}
cout << endl;
===================================================
cin >> N;
int dp[51];
for(int i=0;i<=6;i++){
  dp[i]=i*15;
}
for(int i=7;i<=10;i++){
  dp[i]=100;
}
if(N<=10){
  cout << dp[N] << endl;
  return 0;
}
for(int i=11;i<=N;i++){
  dp[i]=min(dp[i-1]+15,dp[i-10]+100);
}
cout << dp[N] << endl;
return 0;
}
===================================================
int T,N;
cin >> T >> N;
int a[110];
for(int i=1;i<=N;i++){
  cin >> a[i];
}
int M;
cin >> M;
int b[110];
for(int i=1;i<=M;i++){
  cin >> b[i];
}
if(N<M){
  cout << "no" << endl;
  return 0;
}
int k=1;
for(int i=1;i<=M;i++){
  while(1){
    if(a[k]<=b[i] && b[i]<=a[k]+T){
      k++;
      break;
    }else if(k==N){
      cout << "no" << endl;
      return 0;
    }else{
      k++;
    }
  }
}
cout << "yes" << endl;
return 0;
}
=============ABC111======================================
cin >> n;
map<int,int> ma,mb;
ll ans=0;
int t;
for(int i=1;i<=n;i++){
  cin >> t;
  if(i%2==1){
    ma[t]++;
  }else{
    mb[t]++;
  }
}
vector<pair<int,int>> mc,md;
for(auto k:ma){
  mc.push_back({k.second,k.first});
}
for(auto k:mb){
  md.push_back({k.second,k.first});
}
sort(mc.rbegin(),mc.rend());
sort(md.rbegin(),md.rend());
if(mc[0].second==md[0].second){
  int p=mc[1].first+md[0].first;
  int q=md[1].first+mc[0].first;
  if(p>q){
    ans=n-p;
  }else{
    ans=n-q;
  }
}else{
  ans=n-mc[0].first-md[0].first;
}
cout << ans << endl;
return 0;
}
===================================================
string S;
cin >> S;
ll ans=0;
ll cnt=1;
for(int i=0;i<=S.size();i++){
  if(i==S.size()){
    if(cnt)ans++;
    break;
  }
  if(S[i]=='0'){
    cnt=0;
  }
  if(S[i]=='*'){
    cnt*=1;
  }
  if(S[i]=='+'){
    if(cnt)ans++;
    else cnt=1;
  }
}
cout << ans << endl;
return 0;
}
===================================================
ll N;
cin >> N;
ll x[110],y[110],h[110];
for(int i=1;i<=N;i++){
  cin >> x[i] >> y[i] >> h[i];
}
ll H=0;
for(int ax=0;ax<=100;ax++){
  for(int ay=0;ay<=100;ay++){
    for(int i=1;i<=N;i++){
      if(h[i]!=0){
        H=h[i]+abs(x[i]-ax)+abs(y[i]-ay);
        break;
      }
    }
    for(int j=1;j<=N;j++){
      if(h[j]==max(å0LL,H-abs(x[j]-ax)-abs(y[j]-ay))){
        if(j==N){
          cout << ax << " " << ay << " " << H << endl;
          return 0;
        }
      }else{
        break;
      }
    }
  }
}
}
===================================================
cin >> N;
cin >> NG1 >> NG2 >> NG3;
int dp[310];
for(int i=0;i<311;i++){
  dp[i]=MOD;
}
dp[N]=0;
for(int i=N;i>=0;i--){
  if(i==NG1||i==NG2||i==NG3)continue;
  for(int j=1;j<=3;j++){
    dp[i-j]=min(dp[i]+1,dp[i-j]);
  }
}


if(dp[0]<=100) cout << "YES" << endl;
else cout << "NO" << endl;
return 0;
}
===================================================
void f(ll N,string s){
  if(N==0){
    cout << s << endl;
    return;
  }
  for(char c='a';c<='c';c++){
    f(N-1,s+c);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  ll x,y;
  cin >> N;
  f(N,"");
  return 0;
}
===================================================
  ll ans=0;
  ll N,M;
  cin >> N >> M;
  ll X,Y;
  cin >> X >> Y;

  vector<ll> a,b;
  ll t;
  for(int i=1;i<=N;i++){
    cin >> t;
    a.push_back(t);
  }
  for(int i=1;i<=M;i++){
    cin >> t;
    b.push_back(t);
  }

  ll time=0;
  int i=0,j=0;
  int point=0;
  while(true){
    if(point==0){
      auto it=lower_bound(a.begin(),a.end(),time);
      i=distance(a.begin(),it);
      if(i==N)break;
      time=a[i]+X;
      point =1;
    }else{
      auto it=lower_bound(b.begin(),b.end(),time);
      j=distance(b.begin(),it);
      if(j==M)break;
      time=b[j]+Y;
      ans++;
      point =0;
    }
  }

  cout << ans << endl;
  return 0;
}

===================================================
int N,M;
vector<pair<int,int>> City[100010];
cin >> N >> M;
int P,Y;
for(int i=1;i<=M;i++){
  cin >> P >> Y;
  City[P].push_back({Y,i});
}
pair<int,int> ans[100010];
for(int i=1;i<=N;i++){
  sort(City[i].begin(),City[i].end());
  for(int j=0;j<City[i].size();j++){
    ans[City[i][j].second]={i,j+1};
  }
}
for(int i=1;i<=M;i++){
  printf("%06d%06d\n", ans[i].first,ans[i].second);
}
return 0;
}

===================================================
int N;
cin >> N;
vector<pair<int,int>> a;
int t;
for(int i=1;i<=N;i++){
  cin >> t;
  a.push_back({t,i});
}
sort(a.begin(),a.end());
int ans[100010];
int v=a[0].first;
int cnt=0;
for(int i=0;i<N;i++){
  if(a[i].first>v){
    cnt++;
    v=a[i].first;
  }
  ans[a[i].second]=cnt;
}
for(int i=1;i<=N;i++){
  cout << ans[i] << endl;
}
return 0;
}
===================================================
int N;
cin >> N;
int a[N+10]={0};
map<int,int> mp;
for(int i=1;i<=N;i++){
  cin >> a[i];
  mp.insert(pair<int,int>(a[i],i));
}  å

sort(a,a+N+1,greater<int>());
for(int i=0;i<N;i++){
  cout << mp[a[i]] << endl;
}
return 0;
}
===================================================
ll N;
cin >> N;
ll a[100010];
for(int i=1;i<=N;i++){
  cin >> a[i];
}
ll cost[100010];
cost[1]=0;
cost[2]=abs(a[2]-a[1]);
for(int i=3;i<=N;i++){
  cost[i]=min(abs(a[i]-a[i-1])+cost[i-1],abs(a[i]-a[i-2])+cost[i-2]);
}
cout << cost[N] << endl;
return 0;
}

===================================================
string S;
cin >> S;
string P="WBWBWWBWBWBW";
int num;
for(int i=0;i<P.size();i++){
  int cnt=0;
  int j=0;
  while(cnt<20){
    if(S[cnt]==P[(i+j)%12]){
      cnt++;
      j++;
    }else{
      break;
    }
  }
  if(cnt==20){
    num=i;
    break;
  }
}
switch(num){
  case 0:
      cout << "Do" << endl;
      break;
  case 2:
      cout << "Re" << endl;
      break;
  case 4:
      cout << "Mi" << endl;
      break;
  case 5:
      cout << "Fa" << endl;
      break;
  case 7:
      cout << "So" << endl;
      break;
  case 9:
      cout << "La" << endl;
      break;
  case 11:
      cout << "Si" << endl;
      break;
  default:
      break;
}
return 0;
}

===================================================
int N;
cin >> N;
int a[100010];
int b[10]={0};
for(int i=1;i<=N;i++){
  cin >> a[i];
  if(a[i]%4==0){
    b[4]++;
  }else if(a[i]%2==0){
    b[2]++;
  }else{
    b[1]++;
  }
}
int t=b[1]-b[4];
bool flag=false;
if(t>1){
  cout << "No" << endl;
  return 0;
}else if(t==1){
  if(b[2]>0){
    cout << "No" << endl;
    return 0;
  }else{
    flag=true;
  }
}else{
  flag =true;
}

if(flag)cout << "Yes" << endl;
else cout << "No" << endl;
return 0;
}
===================================================
template <class T>
void move_position(std::vector<T>& v, std::size_t before, std::size_t after)
{
    T x = std::move(v[before]);
    v.erase(v.begin() + before);
    v.insert(v.begin() + after, std::move(x));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  ll a,b;
  a=(N/5)%6;
  b=N%5;
  vector<int> c;
  for(int i=a+1;i<a+1+6;i++){
    int cnt=i;
    if(cnt>6){
      cnt-=6;
    }
    c.push_back(cnt);
  }
  if(b!=0){
    move_position(c,0,b);
  }

  for(int x:c){
    cout << x;
  }
  cout << endl;
  return 0;
}
===================================================
ll N,D,K;
cin >> N >> D >>  K;
ll L[10010],R[10010];
for(int i=1;i<=D;i++){
  cin >> L[i] >> R[i];
}
for(int i=1;i<=K;i++){
  ll day=0;
  ll s,t;
  cin >> s >> t;
  while(s!=t){
    day++;
    if(L[day]<=s && s<=R[day]){
      if(s<t){
        s=min(R[day],t);
      }else{
        s=max(L[day],t);
      }
    }
  }
  cout << day << endl;
}
return 0;
}
===================================================
void f(int N, string s){
  if(N==0){
    cout << s << endl;
    return;
  }
  for(char c='a';c<='c';c++){
    f(N-1,s+c);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  f(N,"");
  return 0;
}
===================================================


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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll ans=0;
  ll N,M;
  cin >> N >> M;
  ll X,Y;
  cin >> X >> Y;

  ll a[100010],b[100010];
  for(int i=1;i<=N;i++){
    cin >> a[i];
  }
  for(int i=1;i<=M;i++){
    cin >> b[i];
  }

  ll time=0;
  int i=1,j=1;
  int state=0;
  while(i<=N && j<=M){
    if(state==0){
      for(i;i<=N;i++){
        if(time<=a[i]){
          time =a[i]+X;
          i++;
          state=1;
          break;
        }
      }
    }
    if(state==1){
      for(j;j<=M;j++){
        if(time<=b[j]){
          time =b[j]+Y;
          j++;
          state=0;
          ans++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
