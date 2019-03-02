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
  string S;
  int N;
  cin >> S >> N;
  int l,r;
  for(int i=0;i<N;i++){
    cin >> l >> r;
    reverse(S.begin()+l-1,S.begin()+r);
  }
  for(int i=0;i<S.size();i++){
    cout << S[i];
  }
  cout  << endl;
  return 0;
}













=========================ABC007=================================

int N;
cin >> N;
int a=bitset<8>(N);
if(int bit=0;bit<
return 0;

=========================ABC007=================================
ll gcd(ll m, ll n){
  // 引数に０がある場合は０を返す
	if ( ( 0 == m ) && ( 0 == n ) )
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



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b,n;
  ll ans=0;
  cin >> a >> b >> n;
  ll k=lcm(a,b);
  while(n>ans){
    ans+=k;
  }
  cout << ans << endl;
  return 0;

}
=========================ABC007=================================
int N;
cin >> N;
cout << (N==100?"Perfect":N>=90?"Great":N>=60?"Good":"Bad") << end;
return 0;

=========================ABC001=================================
int s[3],t[3];
for(int i=0;i<3;i++){
  cin >> s[i];
}
memcpy(t, s, sizeof(s));
sort(t,t+3,greater<int>());
/*for(int i=0;i<3;i++){
  cout << t[i] << endl;
}*/
for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
    if(s[i]==t[j]){
      cout << j+1 << endl;
    }
  }
}
return 0;
}
