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







===================================================
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
D. 派閥
===================================================

ll gcd(ll m, ll n){
  // 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;

	// ユークリッドの方法
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd

ll lcm( ll m, ll n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm

// a x + b y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y) {
  int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
int invMod(int a, int m) {
  int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;
  else                         return 0; // unsolvable
}


ll N,M;
cin >> N >> M;
string S,T;
ll ans=lcm(N,M);
cin >> S >> T;
for(int i=0;i<gcd(N,M);i++){
  if(S[i*ans/M]!=T[i*ans/N]){
    cout << -1 << endl;
    return 0;
  }
}

cout << ans << endl;
return 0;
}
	A. Two Abbreviations

===================================================
int N;
cin >> N;
int ame[2410]={0};
int S,E;
char c;
for(int i=0;i<N;i++){
  cin >> S >> c >> E;
  int a=(S/100*100)+(S%100/5*5);
  int b=(E/100*100)+((E%100+4)/5*5);
  if(b%100==60){
    b+=40;
  }
  ame[a]++;
  ame[b+1]--;
}
for(int i=1;i<2404;i++){
  ame[i]=ame[i-1]+ame[i];
}
bool flag=false;
for(int i=0;i<2404;i++){
  /*if(i!=0){
    ame[i]+=ame[i-1];
  }*/
  if(flag==false && ame[i]>0){
    cout << setfill('0') << setw(4) << i << '-';
    flag =true;
  }
  if(flag==true && ame[i]==0){
    cout << setfill('0') << setw(4) << i-1 <<endl;
    flag=false;
  }
}
return 0;
}
D. 感雨時刻の整理

===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
int H,W;
int N;
cin >> H >> W >> N;

int a[10010]={0};
for(int i=1;i<=N;i++){
  cin >> a[i];
}

int dq[110][110]={0};
int k=1;
for(int i=1;i<=H;i++){
  for(int j=1;j<=W;j++){
    if(a[k]==0){
      k++;
    }
    dq[i][j]=k;
    a[k]--;
  }
}
for(int i=1;i<=H;i++){
  for(int j=1;j<=W;j++){
    if(i%2==1){
      cout << dq[i][j];
    }else{
      cout << dq[i][W-j+1];
    }
    if(j!=W){
      cout << " ";
    }else{
      cout << endl;
    }
  }
}

return 0;
}
//ABC69
D. Grid Coloring


===================================================
int N;
string S;
cin >> N >> S;
string ans=S;
int l=0,r=0;
for(int i=0;i<N;i++){
  if(S[i]=='('){
    l++;
  }else{
    if(l>0){
      l--;
      continue;
    }else{
      ans= '('+ans;
    }
  }
}
if(l>0){
  while(l!=0){
    l--;
    ans=ans+')';
  }
}
cout << ans << endl;
return 0;
}

//ABC64
D. Insertion
===================================================
int N;
cin >> N;
int A[100010]={0};
int x;
int ans=0;
int b=0;
for(int i=0;i<N;i++){
  cin >> x;
  A[x]++;
  b=max(x,b);
}
int t=0;
for(int i=0;i<=b;i++){
  if(A[i]>=1){
    ans++;
  }else if(A[i]==0){
    continue;
  }
  if(A[i]%2==0){
    t++;
  }
}
cout << ans-(t%2) << endl;
return 0;
}

	D. Card Eater
