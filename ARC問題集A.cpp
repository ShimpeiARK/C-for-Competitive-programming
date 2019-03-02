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

}









===============================================
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
  int N;
  cin >> N;
  int t[10];
  int cost=0;
  for(int i=0;i<N;i++){
    cin >> t[i];
    cost+=t[i];
  }

  for(int i=0;i<(1<<N);i++){
    int one=0,two=0;
    for(int j=0;j<N;j++){
      if(i& 1<<j){
        one+=t[j];
      }else{
        two+=t[j];
      }
    }
    cost=min(cost,max(one,two));
  }
  cout << cost << endl;
  return 0;
}
===============================================
===============================================
===============================================

  pair<int,int> r[110],b[110];
  bool flag[110];
  int N;
  cin >> N;
  int p,q;

  for(int i=0;i<N;i++){
    cin >> p >> q;
    r[i]=make_pair(p,q);
    flag[i]=true;
  }
  for(int i=0;i<N;i++){
    cin >> p >> q;
    b[i]=make_pair(p,q);
  }
  sort(b,b+N);

  int ans=0;
  for(int i=0;i<N;i++){
    int k=10000;
    for(int j=0;j<N;j++){
      if(!flag[j]) {
        continue;
      }
      if(r[j].first<b[i].first && r[j].second<b[i].second){
        if(k==10000 || r[k].second < r[j].second){
          k=j;
        }
      }
    }
    if(k!=10000){
      flag[k]=false;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
===============================================
ll H,W;
cin >> H >> W;
ll a,b,c;
ll ans=INF;
for(int i=1;i<H;i++){
  a=i*W;
  b=(H-i)/2*W;
  c=(H-i-(H-i)/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
}
for(int i=1;i<H;i++){
  a=i*W;
  b=W/2*(H-i);
  c=(W-W/2)*(H-i);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
}
int t;
t=H;
H=W;
W=t;
for(int i=1;i<H;i++){
  a=i*W;
  b=(H-i)/2*W;
  c=(H-i-(H-i)/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
}
for(int i=1;i<H;i++){
  a=i*W;
  b=W/2*(H-i);
  c=(W-W/2)*(H-i);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
}
cout << ans << endl;
return 0;
}
===============================================
double x,y,r;
double a,b,c,d;
cin >> x >> y >> r;
cin >> a >> b >> c >> d;
if(y+r<=d && y-r>=b && x+r<=c && x-r>=a){
  cout << "NO";
}else{
  cout << "YES";
}
cout << endl;
double dis=pow(abs(a-x),2)+pow(abs(b-y),2);
r=pow(r,2);
if(dis>r){
  cout << "YES" << endl;
  return 0;
}
dis=pow(abs(c-x),2)+pow(abs(b-y),2);
if(dis>r){
  cout << "YES" << endl;
  return 0;
}
dis=pow(abs(c-x),2)+pow(abs(d-y),2);
if(dis>r){
  cout << "YES" << endl;
  return 0;
}
dis=pow(abs(a-x),2)+pow(abs(d-y),2);
if(dis>r){
  cout << "YES" << endl;
  return 0;
}
cout << "NO" << endl;
return 0;
}
===============================================
int N,M;
cin >> N >> M;
pair<int,int> p[100010];
for(int i=0;i<N;i++){
  p[i]=make_pair(-1,i+1);
}
for(int i=0;i<M;i++){
  int a;
  cin >> a;
  p[a-1].first=i;
}
sort(p,p+N);
reverse(p,p+N);
for(int i=0;i<N;i++){
  if(p[i].first!=-1){
    cout << p[i].second << endl;
  }
}
sort(p,p+N);
for(int i=0;i<N;i++){
  if(p[i].first==-1){
    cout << p[i].second << endl;
  }
}
return 0;
}
===============================================

int N;
cin >> N;
int n=N/9+1;
int cnt=N%9;
int t=1;
int ans=0;
while(n>0){
  n--;
  ans+=t;
  t*=10;
}
cout << ans*cnt << endl;
return 0;
===============================================
int m,n,N;
cin >> m >> n >> N;
ll ans=0;
int a=0,b=N;
int c=0;
while((a+b)>m){
  ans+=b;
  a+=(b)%m;
  if(a>=m){
    a-=m;
    c=n;
  }
  b=(b+a)/m*n+c;
  c=0;
}
cout << ans+b << endl;
return 0;
}
===============================================
vector<int> t;
int k;
for(int i=1;i<=N;i++){
  cin >> k;
  t.push_back(k);
}
if(N==1){
  cout << t[0] << endl;
}else if(N==2){
  cout << max(t[0],t[1])<< endl;
}else if(N==3){
  cout << max(t[2],t[1]+t[0]) << endl;
}else{
  int sa=1000;
  do{
    if(sa>abs(t[0]+t[1]-t[2]-t[3])){
      sa=abs(t[0]+t[1]-t[2]-t[3]);
      ans=max(t[0]+t[1],t[2]+t[3]);
    }else if(sa>abs(t[3]-t[0]-t[1]-t[2])){
      sa=abs(t[3]-t[0]-t[1]-t[2]);
      ans=max(t[3],t[0]+t[1]+t[2]);
    }
  }while(next_permutation(t.begin(),t.end()));
  cout << ans << endl;
}
return 0;
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
===============================================
int A,B;
cin >> A >> B;
int ans=-1000;
for(int i=0;i<3;i++){
  string A_str=to_string(A);
  A_str[i]='9';
  int new_A=stoi(A_str);
  ans=max(ans,new_A-B);
}
for(int j=0;j<3;j++){
  string B_str=to_string(B);
  if(j==0){
    B_str[j]='1';
  }else{
    B_str[j]='0';
  }
  int new_B=stoi(B_str);
  ans=max(ans,A-new_B);
}
cout << ans << endl;
return 0;
}
===============================================
int A,B;
cin >> A >> B;
int ans=A-B;
int a=999-A;
int b=B-100;
if(a>=b){
  if(a>=100){
    a=(a/100)*100;
  }else if(a>=10){
    a=(a/10)*10;
  }
cout << ans+a << endl;
}else{
  if(b>=100){
    b=(b/100)*100;
  }else if(b>=10){
    b=(b/10)*10;
  }
cout << ans-b << endl;
}
return 0;
}
===============================================
double n,k;
cin >> n >> k;
cout << (ceil((n-1)/2.0)>=k?"YES":"NO") << endl;
===============================================
int m,n,N;
cin >> m >> n >> N;
int ans=0;
int old=0,new1=N;
while(new1>0){
  ans+=new1;
  old+=new1;
  new1=0;
  new1=old/m*n;
  old%=m;
  //cout << old << " " << new1<<endl;
}
cout << ans << endl;
return 0;
===============================================
double N,A,B;
cin >> N >> A >> B;
double ave=0,t,ma=0,mb=10000000001;
for(int i=0;i<N;i++){
  cin >> t;
  ave+=t;
  ma=max(ma,t);
  mb=min(mb,t);
}
ave/=N;
double sa=ma-mb;
if(mb==ma){
  cout << -1 << endl;
  return 0;
}
double P=B/sa;
double Q=A-ave*B/sa;
cout << fixed << setprecision(15) << P << ' ';
cout << fixed << setprecision(15) << Q << endl;
return 0;
===============================================
int N;
cin >> N;
if(N<=9){
  cout << N << endl;
  return 0;
}
int a=N/9;
int b=N%9;
int ans=0;
while(a>=0){
    ans+=pow(10,a);
    a--;
}
if(b==0){
  cout << ans/10*9 << endl;
}else{
  cout << ans*b << endl;
}
return 0;
===============================================
int n;
cin >> n;
int ans=n*(n+1)/2;
if(IsPrime(ans))cout << "WANWAN" << endl;
else cout << "BOWWOW" << endl;
return 0;
}
===============================================
int L,R;
cin >> L >> R;
int ans=0;
int l[110]={0},r[110]={0};
int a;
for(int i=1;i<=L;i++){
  cin >> a;
  l[a]++;
}
for(int i=1;i<=R;i++){
  cin >> a;
  if(l[a]>0){
    l[a]--;
    ans++;
  }
}
cout << ans << endl;
return 0;
}
===============================================
int  A[6][6]={0};
for(int i=1;i<=4;i++){
  for(int j=1;j<=4;j++){
    cin >> A[i][j];
  }
}
for(int i=1;i<=4;i++){
  for(int j=1;j<=4;j++){
    if(A[i][j]==A[i][j-1]||A[i][j]==A[i][j+1]){
      cout << "CONTINUE" << endl;
      return 0;
    }
    if(A[i][j]==A[i-1][j]||A[i][j]==A[i+1][j]){
      cout << "CONTINUE" << endl;
      return 0;
    }
  }
}
cout << "GAMEOVER" << endl;
return 0;
}
===============================================
int N;
cin >> N;
cout << '1';
for(int i=1;i<=N;i++){
  if(i==N){
    cout << '7';
    break;
  }
  cout << '0';
}
cout << endl;
return 0;
===============================================
string S;
cin >> S;
string ans="";
for(int i=0;i<S.size();i++){
  if(S[i]-'0'<10)ans+=S[i];
}
cout << ans << endl;
return 0;
===============================================
double L,X,Y,S,D;
cin >> L >> X >> Y >> S >> D;
double d1=D-S,d2=(L-D)+S;
if(S>D){
  d1=L-S+D;
  d2=S-D;
}
double ans;
if(X<Y){
  ans = min(d1/(X+Y),d2/(Y-X));
}else{
  ans=d1/(X+Y);
}
cout << fixed << setprecision(12) << ans << endl;
return 0;
}
===============================================
ll A,B,K,L;
cin >> A >> B >> K >> L;
ll ans=0;
if(K<=L){
  ans=min(A*K,B);
  cout << ans << endl;
  return 0;
}
ans=min(K/L*B+K%L*A,K/L*B+B);
cout << ans << endl;
return 0;
===============================================
char C,c;
cin >> C >> c;
c=c-32;
cout << (C==c?"Yes":"No") << endl;
return 0;
===============================================
ll A,B;
cin >> A >> B;
ll ans=B-A;
if(A<0&& B>0)ans--;
cout << ans << endl;
===============================================
int N,L;
cin >> N >> L;
string S;
cin >> S;
int cnt=1;
int ans=0;
for(int i=0;i<S.size();i++){
  if(S[i]=='+')cnt++;
  else if(S[i]=='-')cnt--;

  if(cnt>L){
    ans++;
    cnt=1;
  }
}
===============================================
string S;
int cnt=0;
while(cin >> S){
  if(cnt){
    cout << " ";
  }
  cnt++;
  if(S[0]=='A')cout << 'A';
  else if(S[0]=='L')cout << '<';
  else if(S[0]=='R')cout << '>';
}
cout << endl;
return 0;
===============================================
ll cnt=0;
for(int i=0;i<N;i++){
  cin >> S;
  for(int j=0;j<N;j++){
    if(S[j]=='R')cnt++;
    else if(S[j]=='B')cnt--;
  }
}
cout << (cnt==0?"DRAW":cnt>0?"TAKAHASHI":"AOKI") << endl;
return 0;
===============================================
string s;
cin >> s;
int n=s.size();
for(int i=0;i<n/2;i++){
  if(s[i]==s[n-1-i] ||s[i]=='*' ||s[n-1-i]=='*')continue;
  else cout << "NO" << endl;return 0;
}
cout << "YES" << endl;
return 0;
===============================================
ll N;
cin >> N;
double a,b,c,d,e;
double ans=0.0;
for(int i=0;i<N;i++){
  cin >> a >> b >> c >> d >> e;
  ans=max(ans,a+b+c+d+e*110.0/900.0);
}
cout << fixed << setprecision(10) << ans << endl;
return 0;
===============================================
ll A,K;
cin >> A >> K;
ll sum=A;
ll cnt=0;
if(K==0){
  cout << 2000000000000-A << endl;
  return 0;
}
while(sum<2*pow(10,12)){
  sum=(1+K*(sum)+sum);
  cnt++;
}
cout << cnt << endl;
return 0;
