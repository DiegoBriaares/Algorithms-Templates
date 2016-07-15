#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int bit[MAX][MAX];
void update(int x,int y,int val){
	int y1;
	while(x<MAX){
		y1=y;
		while(y1<MAX){
			bit[x][y1]+=val;
			y1+=(y1&-y1);
		}
		x+=(x&-x);
	}
}
int query(int x,int y){    //query(x1,y1,x2,y2) = query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
	int r=0;
	while(x>0){
		int y1=y;
		while(y1>0){
			r+=bit[x][y1];
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);

	}
