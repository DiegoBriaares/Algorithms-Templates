#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int m[MAX][MAX],n,c,ac=(1<<30),memo[MAX][MAX];
vector<int>r;
int dp(int i,int j){
	if(i>n||j>c||i<1)return (1<<30);
	if(j==c)return memo[i][j]=m[i][j];
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=(m[i][j]+min(dp(i-1,j+1),min(dp(i,j+1),dp(i+1,j+1))));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=c;j++){
				cin>>m[i][j];
			}
		}
		int uso=(1<<30),uso3;
		for(int i=1;i<=n;i++){
			vector<int>lol;
			memset(memo,0,sizeof(memo));
			uso3=dp(i,1);
			if(uso3<uso){
				uso=uso3;
				lol.push_back(i);
				int s=m[i][1],i2=i;
				for(int j=2;j<=c;j++){
					if(uso3-s==memo[i2-1][j]&&i2-1>=1)s+=m[--i2][j];
					else if(uso3-s==memo[i2][j]&&i2<=n)s+=m[i2][j];
					else s+=m[++i2][j];
					lol.push_back(i2);
				}
				r=lol;
			}
		}
		cout << uso <<"\n";
		for(int k=0;k<r.size();k++)cout << r[k]<<" ";
		cout << "\n";
	}
