#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int n;
int a[MAX][MAX];
int b[MAX][MAX];
int r[MAX][MAX];
void solve(int x,int y,int i,int j,int s){
	if(y==n){
		solve(x+1,0,0,0,0);
	}
	else if(x==n){
		return;
	}
	else if(i==n&&j==n){
		r[x][y]=s;
		solve(x,y+1,0,0,0);
	}
	else {
		int uso=(a[x][i]*b[y][j]);
		solve(x,y,i+1,j+1,s+uso);
	}
}
	int main (){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>b[i][j];
			}
		}
		solve(0,0,0,0,0);
		cout << "\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << r[j][i]<<" ";
			}
			cout << "\n";
		}
	}
