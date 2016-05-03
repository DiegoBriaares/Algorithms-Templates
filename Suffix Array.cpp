#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int suffix[MAX];
int cmp(pair<int,char *>a,pair<int,char *>b){
	return strcmp(a.second,b.second)<0?1:0;
}
void tree(char *base,int n){
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
		char *arr;
		cin>>arr;
		tree(arr,strlen(arr));
		for(int i=0;i<strlen(arr);i++)cout << suffix[i]<<"\n";
	}
