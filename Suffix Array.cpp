#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int suffix[MAX];
char base[MAX];
int n;
int cmp(pair<int,char *>a,pair<int,char *>b){
	return strcmp(a.second,b.second)<0?1:0;
}
void tree(){
	pair<int,char *>v[MAX];
	for(int i=0;i<n;i++){
		v[i].first=i;
		v[i].second=(base+i);
	}
	sort(v,v+n,cmp);
	for(int i=0;i<n;i++){
		suffix[i]=v[i].first;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>base;
		n=strlen(base);
		tree();
		for(int i=0;i<n;i++)cout << suffix[i]<<"\n";
	}
