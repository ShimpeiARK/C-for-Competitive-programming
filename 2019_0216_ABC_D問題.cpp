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
  int N,A,B,C;
  cin >> N >> A >> B >> C;
  vector<int> l;
  int t;
  for(int i=0;i<N;i++){
    cin  >> t;
    l.push_back(t);
  }
  sort(l.begin(),l.end());
  int ans=10000;
  for(int bit= (1<<N) ;bit--;){
    int cnt=0;
    int count=0;
    for(int i=0;i<N;i++){
      if(bit >> i & 1){
        cnt+=l[i];
        count++;
      }
    }
    ans=min(ans,abs(A+B+C-cnt)+max(0,(count-2)*10));
  }
  cout << ans << endl;
  return 0;
}


  sum=10000;
  int id;
  if(flag_A){
  for(int i=0;i<l.size();i++){
    if(sum>abs(l[i]-A)){
      sum=min(sum,abs(l[i]-A));
      id=i;
    }
  }
  if(sum<=10){
    v.erase(l.begin(),l.begin()+id);
    ans+=sum;
  }else{

  }
  }
  if(flag_B){
  }
  if(flag_C){

  }


  int dp[1010];
  for(int i=0;i<1010;i++){
    for(int j=0;j<3010;j++){
     dp[i][j]=10000;
   }
  }
  dp[0][A+B+C]=-20;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=l[i];j++){
      if(j-l[i]>=0){
        dp[i+1][j]=min(dp[i][j],dp[i][j-l[i]]+10);
      }
    }
  }
  for(int i=0;i<=A+B+C;i++){
    ans=min(ans,dp[N][i]+abs()

ABC_117_bit_1LL<<i


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
===========================================

===========================================

===========================================
ll A,B,Q;
cin >> A >> B >> Q;
vector<ll> s;
vector<ll> t;
ll ans;
for(int i=0;i<A;i++){
  cin >> s[i];
}
for(int i=0;i<B;i++){
  cin >> t[i];
}
for(int i=0;i<Q;i++){
  ll x;
  cin >> x;
  if(x<t[0]){
    if(x<s[0]){
      ans=max(abs(t[0]-x),abs(s[0]-x));
      cout << ans << endl;
      continue;
    }else{

    }
  }
  auto Iter1 = lower_bound(s.begin(),s.end(),x);
  auto Iter2 = lower_bound(t.begin(),t.end(),x);
  if(Iter1==0){
    ll a=INF;
  }else{
    ll a=x-s[Iter1-s.begin()-1];
  }
  if(*Iter1==A-1){
    ll b=INF;
  }else{
    ll b=s[Iter1-s.begin()]-x;
  }
  if(*Iter2==0){
    ll c=INF;
  }else{
    ll c=x-t[Iter1-t.begin()-1];
  }
  if(*Iter2==B-1){
    ll d=INF;
  }else{
    ll d=t[Iter1-t.begin()]-x;
  }
  ans=min(a,b)+min(c,d);
  if(a>c && ans>a){
    ans=min(ans,a);
  }if(c>a && ans>c){
    ans=min(ans,c);
  }if(b>d && ans>b){
    ans=min(ans,b);
  }if(d>b && ans>d){
    ans=min(ans,d);
  }
  cout << ans << endl;
}
return 0;
}
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
===========================================
int N;
cin >> N;
double x;
string u;
double ans_JPY=0;
double ans_BTC=0;
for(int i=0;i<N;i++){
  cin >> x >> u;
  if(u=="JPY"){
    ans_JPY+=x;
  }else if(u=="BTC"){
    ans_BTC+=x;
  }
}
ans_BTC*=380000.0;
cout << ans_JPY+ans_BTC << endl;
return 0;
===========================================
string S;
cin >> S;
bool flag=false;
if(S[5]=='1'){
  flag=true;
}
if(S[6]-'0'>=5){
  flag=true;
}

if(flag){
  cout << "TBD" << endl;
}else{
  cout << "Heisei" << endl;
}
return 0;
}
===========================================
ll num[10]={2,5,5,4,5,6,3,7,6};
string dp[11000];
const string MINUS_INF = "-";

void chmax(string &a, string b){
  if(a==MINUS_INF) a=b;
  else if(a.size()<b.size())a=b;
  else if(a.size()==b.size()){
    if(a<b)a=b;
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
  }
  for(int i=0;i<11000;i++){
    dp[i]=MINUS_INF;
  }
  dp[0]="";
  for(int i=0;i<=N;i++){
    if(dp[i]==MINUS_INF)continue;
    for(auto a:A){
      chmax(dp[i+num[a-1]],dp[i]+char('0'+a));
    }
  }
  cout << dp[N] << endl;
  /*string a="122";
  string b="21";
  if(a<b){
    cout << b<< endl;
  }else{
    cout << a << endl;
  }*/
  return 0;
}


===========================================
int T[10];
for(int i=0;i<6;i++){
  cin >> T[i];
}
int N;
cin >> N;
int p[N];
int now_T=T[0];
int index=0;
int ans=0;
for(int i=0;i<N;i++){
  cin >> p[i];
  if(now_T==p[i]){
    continue;
  }else if(index%2==0 && T[(index+1)%6]==p[i]){
    ans+=2;
    now_T=T[(index+1)%6];
    index=(index+1)%6;
  }else if(index%2==1 && T[(index-1+6)%6]==p[i]){
    ans+=2;
    now_T=T[(index-1+6)%6];
    index=(index-1+6)%6;
  }else{
    for(int j=1;j<=6;j++){
      if(T[(index+j)%6]==p[i]){
        ans++;
        now_T=p[i];
        index=(index+j)%6;
        break;
      }
    }
  }
}
cout << ans << endl;
return 0;
}
//Paiza_S一人すごろく
===========================================
ll ans;
ll x,y;
ll A,B;
cin >> A >> B;
if(B%A==0){
  cout << A+B << endl;
}else{
  cout << B-A << endl;
}
return 0;
}
===========================================
int N,M;
cin >> N >> M;
int C[40]={0};
for(int i=1;i<=N;i++){
  int K;
  cin >> K;
  for(int j=0;j<K;j++){
    int A;
    cin >> A;
    C[A]++;
  }
}
int ans=0;
for(int i=0;i<40;i++){
  if(C[i]==N){
    ans++;
  }
}
cout << ans << endl;
return 0;
}
===========================================

ll gcd(ll a,ll b){
  return b? gcd(b,a%b):a;
}
/*ll gcd(ll m, ll n){
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
}//gcd*/

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
  ll N;
  cin >> N;
  ll A[1001000];
  ll t;
  for(int i=0;i<N;i++){
    cin >> t;
    A[i]=t;
  }
  sort(A,A+N);
  ll ans=A[0];
  for(int i=1;i<N;i++){
    ans=gcd(ans,A[i]);
    if(ans==1LL)break;
  }
  cout << ans << endl;
  return 0;
}
