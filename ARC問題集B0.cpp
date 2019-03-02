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
  double N,A,B;
  cin >> N >> A >> B;
  double t;
  double s=0;
  double sa=0;
  double sb=INF;
  for(int i=0;i<N;i++){
    cin >> t;
    s+=t;
    sa=max(sa,t);
    sb=min(sb,t);
  }
  t=sa-sb;
  double P=B/t;
  if(t==0){
    cout << -1 << endl;
    return 0;
  }
  double Q=A-s*B/t/N;
  cout << fixed << setprecision(10) << P << " " << Q << endl;
  return 0;
}



===============================================
int A,B;
cin >> A >> B;
int ans =dfs(abs(A-B),0);
cout << ans << endl;
return 0;

int dfs(int a,int cnt){
  if(cnt>40) return 40;
  if(a==0)return cnt;
  if(abs(a)>10) dfs(abs(10-a),cnt++);
  return min({dfs(abs(1-a),cnt++),dfs(abs(5-a),cnt++),dfs(abs(10-a),cnt)});
}

===============================================
int M[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
int D[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int y){
    if(!(y%400)) return true;
    if(!(y%100)) return false;
    if(!(y%4)) return true;
    return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int y,m,d;
 scanf("%d/%d/%d",&y,&m,&d);

  if(check){
    D[2]=29;
  }
  for(int i=m;i<=12;i++){
    int flag=1;
    for(int j=1;j<=31;j++){
      if(i==m && flag==1){
        j=d;
        flag=0;
      }
      if(!(y%(i*j))){
        printf("%4d/%02d/%02d\n",y,i,j);
        return 0;
      }
    }
  }
  cout << y+1 << "/" << "01" << "/" << "01" << endl;
  return 0;
}
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
===============================================
===============================================
===============================================
===============================================

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

bool simiPrime(int num){
  if(num%2==0 || num%5==0 ||num%3==0) return false;
  else return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  if(N==1){
    cout << "Not Prime" << endl;
    return 0;
  }
  if(IsPrime(N)){
    cout << "Prime" << endl;
  }else if(simiPrime(N)){
    cout << "Prime" << endl;
  }else{
    cout << "Not Prime" << endl;
  }
  return 0;
}
===============================================
int N;
cin >> N;
int ans=0;
int t;
for(int i=1;i<=N;i++){
  cin >> t;
  if(t>80)continue;
  else ans+=(80-t);
}
cout << ans << endl;
return 0;
===============================================
int ans=0;
int N,M,L;
vector<int> v;
cin >> N >> M >> L;
for(int i=0;i<3;i++){
  int t;
  cin >> t;
  v.push_back(t);
}
sort(v.begin(),v.end());
do{
  ans=max(ans,(N/v[0])*(M/v[1])*(L/v[2]));
}while(next_permutation(v.begin(),v.end()));
cout << ans << endl;
return 0;
