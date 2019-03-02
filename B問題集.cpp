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
  int a=N/5;
  int b=N%5;
  a%=6;
  deque<int> c;
  for(int i=1;i<=6;i++){
    if(a>i) c.push_back(i);
    else c.push_front(i);
  }
  for(int i=0;i<b;i++){
    swap(c[i],c[i+1]);
  }
  for(int i=0;i<=5;i++){
    cout << c[i];
  }
  cout << endl;
  return 0;
}

=========================ABC007=================================
=========================ABC007=================================
=========================ABC007=================================
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
  int n=pow(N,0.5)+1;
  int h,w;
  int ans=100000000;
  for(int h=1;h<n;h++){
    w=N/h;
    ans=min(ans,abs(w-h)+(N-h*w));
  }
  cout << ans << endl;
  return 0;
}
=========================ABC001=================================
double m;
cin >> m;
ll ans=0;
if(m<100){
  cout << "00" << endl;
}else if(100<=m && m<1000){
  m/=100;
  cout << '0' << m << endl;
}else if(1000<=m && m <=5000){
  cout << m/100 << endl;
}else if(6000<=m && m<=30000){
  m=m/1000+50;
  cout << m << endl;
}else if (35000<=m && m <=70000){
  m=(m/1000-30)/5+80;
  cout << m << endl;
}else if (70000<m){
  cout << 89 << endl;
}else{
  return 0;
}
return 0;
}
