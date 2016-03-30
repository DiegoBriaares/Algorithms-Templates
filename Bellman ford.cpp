#include <bits/stdc++.h>
using namespace std;
#define edge pair<pair<int,int>,int>
#define peso second
#define x first.first
#define y first.second
#define MAX 200
vector<edge>E;
int dp[MAX];
void init(){
	for(int i=0;i<MAX;i++){
		dp[i]=(1<<31);
	}
	dp[1]=0; //inicio
}
void solve(){
	for(int i=0;i<E.size();i++){
		dp[E[i].y]=min(dp[E[i].x]+E[i].peso,dp[E[i].y]);
	}
}
int main (){
	
}
