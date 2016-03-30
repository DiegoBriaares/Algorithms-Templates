#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int BIT[MAX];
void add(int i,int val){
	while(i<=MAX){
		BIT[i]+=val;
		i+=(i&-i);
	}
}
int query(int i){
	int suma=0;
	while(i>0){
		suma+=BIT[i];
		i-=(i&-i);
	}
	return suma;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
				
	}
