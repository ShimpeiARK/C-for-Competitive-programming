

===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
===================================================
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> P;

int used[101];
int unenable[101];
int link[101][101];
int n,g,e;

bool dfs(int s){
	if(s==n) return 1;
	used[s]=1;
	for(int i=0;i<=n;i++){
		if(used[i]) continue;
		if(link[s][i]!=0 && !unenable[i] && dfs(i)){
			if(link[s][i]==1){
				link[i][s]=-1;
				link[s][i]=0;
			}else{
				link[i][s]=1;
				link[s][i]=0;
			}
			used[s]=0;
			return 1;
		}//else if(link[s][i]!=0) unenable[i]=1;
	}
	used[s]=0;
	return 0;
}

int main(){
	cin >> n >> g >> e;
	for(int i=0;i<g;i++){
		int p;
		cin >> p;
		link[p][n]=1;
	}
	for(int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		link[a][b]=1;
		link[b][a]=1;
	}

	int ans=0;
	while(dfs(0)) {
		ans++;
		for(int i=0;i<=n;i++) unenable[i]=0;
	}
	cout << ans << endl;
}
//ABC_010_MinCut_MaxFlow
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
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N_MAX=1010;
  ll M_MAX=2010;
  ll N,M;

  cin >> N >> M;
  ll a[M_MAX],b[M_MAX],c[M_MAX];
  for(int i=0;i<M;i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i]=-c[i];
  }
  ll dist[N_MAX];
  const ll INFA =1LL<<50;
  for(int i=0;i<N_MAX;i++){
    dist[i]=INFA;
  }
  dist[0]=0;

  for(int i=0;i<N-1;i++){
    for(int j=0;j<M;j++){
      if(dist[a[j]]==INFA)continue;
      if(dist[b[j]]>dist[a[j]]+c[j]){
        dist[b[j]]=dist[a[j]]+c[j];
      }
    }
  }

  ll ans=dist[N-1];

  for(int i=0;i<N-1;i++){
    for(int j=0;j<M;j++){
      if(dist[a[j]]==INFA)continue;
      if(dist[b[j]]>dist[a[j]]+c[j]){
        dist[b[j]]=dist[a[j]]+c[j];
      }
    }
  }
  if(ans!=dist[N-1]){
    cout << "inf" << endl;
  }else{
    cout << -ans << endl;
  }
  return 0;
}


// ABC_061_Bellman-Ford
===================================================

ios::sync_with_stdio(false);
cin.tie(NULL);
int N,K;
cin >> N >> K;
string S;
int a[27]={0};

cin >> S;
for(int i=0;i<N;i++){
  a[S[i]-'a']++;
}

string T="";
for(int i=0;i<N;i++){
  for(int j=0;j<26;j++){
    if(a[j]==0)continue;
    a[j]--;
    int sum=N;
    for(int k=0;k<i;k++){
      if(T[k]==S[k])sum--;
    }
    if(S[i]-'a'==j)sum--;
    int b[27]={0};
    for(int k=i+1;k<N;k++){
      b[S[k]-'a']++;
    }
    for(int k=0;k<26;k++){
      sum-=min(b[k],a[k]);
    }
    if(sum<=K){
      char x='a'+j;
      T+=x;
      break;
    }
    a[j]++;
  }
}
cout << T << endl;
return 0;
}

//ABC_009_辞書順列
===================================================

int N,M;
bool visited[100100];
int dp[100100]={0};
vector<int> G[100100],v;

void dfs(int s){
  visited[s]=1;
  for(int i=0;i<G[s].size();i++){
    if(!visited[G[s][i]]){
      dfs(G[s][i]);
    }
  }
  v.push_back(s);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  int x,y;
  for(int i=0;i<M;i++){
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
  }

  for(int i=0;i<N;i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  reverse(v.begin(),v.end());

  int ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<G[v[i]].size();j++){
      dp[G[v[i]][j]]=max(dp[G[v[i]][j]],dp[v[i]]+1);
    }
    ans=max(ans,dp[v[i]]);
  }
  cout << ans << endl;
  return 0;
}

ABC_Educational_DP_G__DAG

===================================================
int N,M;
vector<P> G[400];
int dst[400];
const int INFA=30000000;

int dijkstra(int s){

  priority_queue<P> q;
  q.push({0,s});

  fill(dst,dst+N,INFA);
  dst[s]=0;

  while(!q.empty()){
    P p=q.top();
    q.pop();
    int v=p.second;
    for(auto e:G[v]){
      if(dst[e.first]>dst[v]+e.second){
        dst[e.first]=dst[v]+e.second;
        q.push({dst[e.first],e.first});
      }
    }
  }
  int time=0;
  for(int i=0;i<N;i++){
    if(dst[i]==INFA)continue;
    else time=max(time,dst[i]);
  }
  return time==0?INF:time;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  int a,b,t;
  for(int i=0;i<M;i++){
    cin >> a >> b >> t;
    a--;
    b--;
    G[a].push_back({b,t});
    G[b].push_back({a,t});
  }
  int ans=INFA;
  for(int i=0;i<N;i++){
    ans=min(ans,dijkstra(i));
  }
  cout << ans << endl;
  return 0;
}

//ABC012_避けられない運命
===================================================
int N,M;
int ans=0;
int f[20][20]={0};

void dfs(vector<int> v,int k){
  if(k==N){
    for(int i=0;i<v.size();i++){
      for(int j=i+1;j<v.size();j++){
        if(f[v[i]][v[j]]!=1){
          return;
        }
      }
    }
    ans=max(ans,(int)v.size());
  }else{
    dfs(v,k+1);
    v.push_back(k);
    dfs(v,k+1);
  }
  //return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  int x,y;
  for(int i=0;i<M;i++){
    cin >> x >> y;
    x--;
    y--;
    f[x][y]=f[y][x]=1;
  }
  vector<int> v;
  int k=0;
  dfs(v,k);
  cout << ans << endl;
  return 0;
}

//ABC_002_派閥(DFS)
