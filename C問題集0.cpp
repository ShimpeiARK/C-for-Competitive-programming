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

ll N,K;
ll s[100010];
ll ans=0;

ll dfs(ll a,ll b, ll c){
  if(a==N+1)return c;
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> s[i];
  }
  ans=dfs(0,0,0);
  cout << ans << endl;
  return 0;
}



=================================================
=================================================
=================================================
=================================================
=================================================
=================================================
=================================================
=================================================

=================================================

ll N,M;
cin >> N >> M;
ll P[M+1]={0};
ll Y[M+1]={0};
for(int i=1;i<=M;i++){
  cin >> P >> Y;
}
ll Z[]=Y;
sort(Z.begin(),Z.end());
cout << ans << endl;
return 0;
}

=================================================
int X,Y;
cin >> X >> Y;

int ans=0;
cout << X+Y/2 << endl;
return 0;
}
=================================================
ll N,K,a[1000010]={0};
cin >> N >> K;
ll ans=0;
for(int i=1;i<=N;i++){
  cin >> a[i];
  if(i<=K){
    ans+=a[i];
  }
}
ll sum=ans;
for(int i=2;i<=N-K+1;i++){
  ans=ans-a[i-1]+a[i-1+K];
  sum+=ans;
}
cout << ans << endl;
return 0;
}
=================================================

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N,K,a[1000010]={0};
  cin >> N >> K;
  ll ans=0;
  for(int i=1;i<=N;i++){
    cin >> a[i];
    if(i<=K){
      ans+=a[i];
    }
  }
  ll sum=ans;
  for(int i=2;i<=N-K+1;i++){
    ans=ans-a[i-1]+a[i-1+K];
    sum+=ans;
  }
  cout << sum << endl;
  return 0;
}

=================================================
ll R,C,K;
cin >> R >> C >> K;
ll N;
cin >> N;
ll r[100010]={0};
ll c[100010]={0};
ll a[100010]={0};
ll b[100010]={0};
ll H[100010]={0};
ll W[100010]={0};
ll ans=0;
for(int i=1;i<=N;i++){
  cin >> r[i] >> c[i];
  a[r[i]]++;
  b[c[i]]++;
}
for(int i=1;i<=R;i++){
  H[a[i]]++;
}
for(int i=1;i<=C;i++){
  W[b[i]]++;
}

for(int i=0;i<=K;i++){
  ans+=H[i]*W[K-i];
}

for(int i=1;i<=N;i++){
  if(a[r[i]]+b[c[i]]==K){
    ans--;
  }
  if(a[r[i]]+b[c[i]]==K+1){
    ans++;
  }
}
cout << ans << endl;
return 0;
}
=================================================
int N;
cin >> N;
set<int> S;
int a;
for(int i=0;i<N;i++){
  cin >> a;
  while(a%2==0){
    a/=2;
  }
  S.insert(a);
}
cout << S.size() << endl;
/*for(int x:S){
  cout << x << endl;
}*/
return 0;
}
=================================================
ll N,M;
cin >> N >> M;
ll ans=0;
ll C[100010]={0};
ll l,r,s,a;
for(int i=1;i<=N;i++){
  cin >> l >> r >> s;
  C[l]+=s;
  C[r+1]-=s;
  a+=s;
}
ll b=INF;
for(int i=1;i<=M;i++){
  C[i]+=C[i-1];
  b=min(b,C[i]);
}
cout << a-b << endl;
return 0;
}
=================================================
float ans;
ll N;
cin >> N;
int sum=0;
for(int i=1;i<=9;i++){
  for(int j=1;j<=9;j++){
    sum+=i*j;
  }
}
N-=sum;
N=abs(N);
for(int i=1;i<=9;i++){
  if(i*(N/i)==N && (N/i)<=9){
    cout << i << " " << "x" << " " << N/i << endl;;
  }
}
return 0;
}
