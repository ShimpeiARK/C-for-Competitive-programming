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
  cin >> N;
  ll a[3010];
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  ll dp[3010][3010];
  for(int i=0;i<N;i++){
    dp[i][i]=0;
  }
  for(int len=1;len<=N;len++){
    for(int i=0;i+len<=N;i++){
      int j=i+len;
      if((N-len)%2==0){
        dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
      }else{
        dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
      }
    }
  }
  cout << dp[0][N] << endl;
  return 0;
}

===========================================
=============================================
============================================
int N,K;
cin >> N >> K;
int N_MAX=110;
int K_MAX=110000;
int a[N_MAX];
bool dp[K_MAX];
for(int i=0;i<K_MAX;i++){
  dp[i]=false;
}
for(int i=0;i<N;i++){
  cin >> a[i];
}
for(int i=0;i<=K;i++){
  for(int j=0;j<N;j++){
    if(i-a[j]>=0){
      dp[i]=dp[i]|!dp[i-a[j]];
    }
  }
}
if(dp[K]) cout << "First" << endl;
else cout << "Second" << endl;
return 0;
}
============================================
ll H,W;
ll a[1010][1010];
ll dp[1010][1010];
bool used[1010][1010];

ll solve(ll s,ll t){
  if(s==H && t==W) return 1;
  if(s>H || t>W) return 0;
  if(a[s][t]==-1) return dp[s][t]=0;
  if(used[s][t]) return dp[s][t];
  used[s][t]=true;
  dp[s][t]=(solve(s+1,t)%MOD+solve(s,t+1)%MOD)%MOD;
  return dp[s][t];
}
  cin >> H >> W;
  char c;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      dp[i][j]=0;
      cin >> c;
      if(c=='.'){
        a[i][j]=1;
      }else{
        a[i][j]=-1;
      }
    }
  }
  dp[1][1]=1;
  ll ans=solve(1,1)%MOD;
  cout << ans%MOD << endl;
  return 0;
}



============================================
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

const ll N_MAX=3010;
ll a[N_MAX];
ll dp[N_MAX][N_MAX][3];

ll solve(int p,int q,int r){
  if(dp[p][q][r]!=-1) return dp[p][q][r];
  if(p>q) return 0;
  if(r){
    dp[p][q][r]=max(solve(p+1,q,0)+a[p],solve(p,q-1,0)+a[q]);
  }else if(r==0){
    dp[p][q][r]=min(solve(p+1,q,1)-a[p],solve(p,q-1,1)-a[q]);
  }
  return dp[p][q][r];

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;

  //ll k;
  for(int i=1;i<=N;i++){
    cin >> a[i];
    //a.push_back(k);
  }

  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<N_MAX;j++){
      dp[i][j][0]=dp[i][j][1]=-1;
    }
  }
  //1が太郎
  cout << solve(1,N) << endl;
  return 0;
}

============================================
const ll N_MAX=110;
const ll K_MAX=100100;
ll a[N_MAX];
ll dp[N_MAX][K_MAX];
ll N;

ll solve(int p,int q){
  if(p>N && q==0){
    return dp[N+1][0];
  }else if(p>N && q>0){
    return 0;
  }
  for(int i=0;i<=a[p];i++){
    dp[p][q-i]*=solve(p+1,q-i);
  }
  ll cnt=0;
  for(int i=0;i<=a[p];i++){
    cnt+=dp[p][q-i];
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll K;
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> a[i];
  }
  ll ans=0;
  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<K_MAX;j++){
      dp[i][j]=0;
    }
  }
  dp[N+1][0]=1;
  cout << solve(1,K) << endl;
  return 0;
}
============================================
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
  int N_MAX=100010;
  bool dp[N_MAX];
  int a[N_MAX];
  for(int i=0;i<=N_MAX;i++){
    dp[i]=false;
  }
  dp[0]=false;
  for(int i=1;i<=N;i++){
    cin >> a[i];
    dp[a[i]]=true;
  }
  for(int i=1;i<=K;i++){
    for(int j=1;j<=N;j++){
        dp[i]=true;
      }else{

      }
    }
  }
  if(dp[K])cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}
============================================
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
//#define INF (1<<29)

const long long INF=1LL<<60;

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N,W;
  cin >> N >> W;
  ll N_MAX=110;
  ll V_MAX=100100;
  ll weight[N_MAX],value[N_MAX];
  for(int i=0;i<N;i++){
    cin >> weight[i] >> value[i];
  }

  ll dp[N_MAX][V_MAX];
  for(ll i=0;i<=N_MAX;i++){
    for(ll j=0;j<=V_MAX;j++){
        dp[i][j]=INF;
    }
  }
  dp[0][0]=0;

  /*for(int i=0;i<N;i++){
    for(int j=0;j<V_MAX;j++){
      if(j-v[i]<0){
        dp[i+1][j]=dp[i][j];
      }else{
        dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
      }
    }
  }*/
  for (int i = 0; i < N; ++i) {
         for (int sum_v = 0; sum_v < V_MAX; ++sum_v) {

             // i 番目の品物を選ぶ場合
             if (sum_v - value[i] >= 0) chmin(dp[i+1][sum_v], dp[i][sum_v - value[i]] + weight[i]);

             // i 番目の品物を選ばない場合
             chmin(dp[i+1][sum_v], dp[i][sum_v]);
         }
  }

  ll ans=0;
  for(int i=0;i<V_MAX;i++){
    if(dp[N][i]<=W) ans=i;
    //else break;
  }

  /*for(ll j=V_MAX;j>=0;j--){
    if(dp[N][j]<=W){
      if(j<=ans)break;
      ans=max(j,ans);
    }
  }*/
  cout << ans << endl;
  return 0;
}




============================================
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

ll N,M;
vector<int> g[100100];
ll dp[100100];
bool used[100100];

ll dfs(ll s){
  if(used[s]) return dp[s];
  used[s]=true;
  ll ret=0;
  for(auto t:g[s]){
    ret=max(ret,dfs(t)+1);
  }

  return dp[s]=ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  ll x,y;
  for(int i=0;i<M;i++){
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
  }

  for(int i=0;i<100100;i++){
    used[i]=false;
    dp[i]=0;
  }

  ll ans=0;
  for(int i=0;i<N;i++){
    ans=max(ans,dfs(i));
  }
  cout << ans << endl;
  return 0;
}

============================================
 vector<int> P;
  int k;
  for(int i=0;i<N;i++){
    cin >> k;
    P.push_back;
  }
  vector<*int> Low;
  Low=lower_bound(P.begin(),P.end(),5);
  int a=(Low-P.begin());
  cout << a << endl;
  return 0;
}

============================================
const ll N_MAX=3010;
ll a[N_MAX];
ll dp[N_MAX][N_MAX][3];

ll solve(int p,int q,int r){
  if(dp[p][q][r]!=-1) return dp[p][q][r];
  if(p>q) return 0;
  if(r){
    dp[p][q][r]=max(solve(p+1,q,0)+a[p],solve(p,q-1,0)+a[q]);
  }else if(r==0){
    dp[p][q][r]=min(solve(p+1,q,1)-a[p],solve(p,q-1,1)-a[q]);
  }
  return dp[p][q][r];

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;

  //ll k;
  for(int i=1;i<=N;i++){
    cin >> a[i];
    //a.push_back(k);
  }

  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<N_MAX;j++){
      dp[i][j][0]=dp[i][j][1]=-1;
    }
  }
  //1が太郎
  cout << solve(1,N,1) << endl;
  return 0;
}

============================================
int N;
cin >> N;
int n=(N+1)/2;
int N_MAX=3010;
double p[3010];
for(int i=0;i<N;i++){
  cin >> p[i];
}

double dp[N_MAX][N_MAX]={0};
/*for(int i=0;i<N_MAX;i++){
  dp[i][0];
}*/
dp[0][0]=1.0;

for(int i=0;i<N;i++){
  for(int j=0;j<=i;j++){
    dp[i+1][j+1]+=dp[i][j]*p[i];
    dp[i+1][j]+=dp[i][j]*(1.0-p[i]);
  }
}
double ans=0.0;
for(int i=n;i<=N;i++){
  ans+=dp[N][i];
}
cout << fixed << setprecision(10) << ans << endl;
return 0;
}
============================================
//int size=1010;
int a[1010][1010];

int H,W;
ll dp[1010][1010];
bool used[1010][1010];

int dfs(int s,int t){
  if(s==H && t==W){
    return 1;
  }
  //if(s<1||t<1) return 0;
  /*if(a[s][t]==0){
    dp[s][t]=0;
    return 0;
  }*/
  if(used[s][t]) return dp[s][t];
  used[s][t]=true;
  ll p=0,q=0;
  //int ret=0;
  if(s<H+1 && a[s+1][t]==1){
    p=dfs(s+1,t);
  }
  if(t<W+1 && a[s][t+1]==1){
    q=dfs(s,t+1);
  }
  dp[s][t]=(p+q)%MOD;
  return dp[s][t];
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> H >> W;

  char k;

  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin >> k;
      if(k=='#'){
        a[i][j]=0;
        dp[i][j]=0;
      }else{
        a[i][j]=1;
        /*if(i==1 || j==1){
          dp[i][j]=1;
        }*/
      }
    }
  }
  dp[1][1]=1;
  ll ans=dfs(1,1);

  cout << ans%MOD << endl;
  return 0;
}





if(s+1>H || t>W)return 0;
else{
  dp[s+1][t]=dfs(s+1,t);
}
if(s>H || t+1>W)return 0;
else{
  dp[s][t+1]=dfs(s,t+1);
}

ret=max(dfs(s+1,t)*dp[s][t],dfs(s,t+1)+1);
return dp[s][t]=ret;
============================================
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

const int N_MAX=100100;
vector<int> g[N_MAX];
int dp[N_MAX];
int N,M;
bool used[N_MAX];

int dfs(int s){
  if(used[s]) return dp[s];
  used[s]=true;
  int ret=0;
  for(auto t:g[s]){
    ret=max(ret,dfs(t)+1);
  }
  return dp[s]=ret;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  int x[N_MAX],y[N_MAX];
  for(int i=0;i<N_MAX;i++){
    used[i]=false;
  }

  /*for(int i=0;i<N_MAX;i++){
    for(int j=0;j<N_MAX;j++){
      x[i][j]=0;
      //if(i==j)x[i][j]==1;
    }
  }*/


  for(int i=0;i<N_MAX;i++){
    dp[i]=0;
  }
  //int x,y;
  for(int i=0;i<M;i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    g[x[i]].push_back(y[i]);
  }

  int ans=0;
  for(int i=0;i<N;i++){
    ans=max(ans,dfs(i));
  }
  cout << ans << endl;
  return 0;
}

============================================
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
  ll N,W;
  cin >> N >> W;
  ll N_MAX=110;
  ll V_MAX=100100;
  ll w[N_MAX],v[N_MAX];
  for(int i=0;i<N;i++){
    cin >> w[i] >> v[i];
  }
  ll weight_MAX=1000000111;
  ll dp[N_MAX][V_MAX];
  for(int i=0;i<N_MAX;i++){
    for(int j=0;j<=V_MAX;j++){
       dp[i][j]=weight_MAX;
    }
  }
  //for(int j=0;j<=100000;j++){
    dp[0][0]=0;
  //}
  for(int i=0;i<N;i++){
    for(int j=0;j<V_MAX;j++){
      if(dp[i][j]>weight_MAX){
        dp[i][j]=weight_MAX;
        continue;
      }
      if(j-v[i]<0)dp[i+1][j]=min(dp[i][j],dp[i][0]+w[i]);
      else dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
    }
  }
  ll ans=0;
  /*for(int i=0;i<V_MAX;i++){
    if(dp[N][i]<=W) ans=i;
  }*/

  for(ll j=V_MAX;j>=0;j--){
    if(dp[N][j]<=W){
      if(j<=ans)break;
      ans=max(j,ans);
    }
  }
  cout << ans << endl;
  return 0;
}
============================================
string s,t;
cin >> s;
cin >> t;
int p=s.size();
int q=t.size();
int dp[3010][3010];

/*for(int i=0;i<=p;i++){
  for(int j=0;j<=q;j++){
    dp[i][j]=0;
  }
}*/

for(int i=0;i<p;i++){
  for(int j=0;j<q;j++){
    if(s[i]==t[j]){
      dp[i+1][j+1]=dp[i][j]+1;
    }else{
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
    }
  }
}
vector<char> ans;
while(p>0 && q>0){
  if(s[p-1]==t[q-1]){
    ans.push_back(s[p-1]);
    p--,q--;
  }else{
    if(dp[p-1][q]>dp[p][q-1]){
      p--;
    }else{
      q--;
    }
  }
}
reverse(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++){
  cout << ans[i];
}
cout << endl;
return 0;
}
============================================

============================================
int a[100100][5]={0};
for(int i=1;i<=N;i++){
  cin >> a[i][0] >> a[i][1] >> a[i][2];
}
ll dp[100100][5]={0};
for(int i=0;i<=2;i++){
  dp[1][i]=a[1][i];
}
for(int i=1;i<=N;i++){
  for(int j=0;j<=2;j++){
    dp[i+1][j]=max(dp[i][(j+1)%3]+a[i+1][j],dp[i][(j+2)%3]+a[i+1][j]);
  }
  //cout << max({dp[i][0],dp[i][1],dp[i][2]}) << endl;
}
ll ans=max({dp[N][0],dp[N][1],dp[N][2]});
cout << ans << endl;
return 0;
}
============================================
ll ans=0;
ll N,K;
cin >> N >> K;
ll N_MAX=100110;
ll h[N_MAX];
for(int i=1;i<=N;i++){
  cin >> h[i];
}
ll dp[N_MAX];
for(int i=1;i<=N;i++){
  dp[i]=1000000030;
}
dp[1]=0;
//dp[2]=abs(h[1]-h[2]);
for(int i=1;i<N;i++){
  for(int j=1;j<=K;j++){
    if(i+j>N+1)continue;
    dp[i+j]=min(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
  }
}
cout << dp[N] << endl;
return 0;
}
