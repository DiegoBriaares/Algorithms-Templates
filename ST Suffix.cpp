#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,q;
ll v[MAX];
struct node {
	ll sum;
	ll prefix;
	ll suffix;
	ll max;
};
node ST[MAX];
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo].sum=v[in];
		ST[nodo].prefix=v[in];
		ST[nodo].suffix=v[in];
		ST[nodo].max=v[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo].sum=ST[left].sum+ST[right].sum;
	ST[nodo].prefix=max(ST[left].prefix,ST[left].sum+ST[right].prefix);
	ST[nodo].suffix=max(ST[right].suffix,ST[right].sum+ST[left].suffix);
	ST[nodo].max=max(ST[nodo].prefix,max(ST[nodo].suffix,max(ST[left].max,max(ST[right].max,ST[left].suffix+ST[right].prefix))));
}
node query(int a,int b,int in,int fin,int nodo){
	node res;
	res.sum=res.prefix=res.suffix=res.max=-(1<<30);
	if(a<=in&&fin<=b){  //Total Overlap
		return ST[nodo];
	}
	if(a>fin||b<in){  //No Overlap
		return res;
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int lefti=(nodo*2)+1;
	int righti=(nodo*2)+2;
	if(a>mid)return query(a,b,mid+1,fin,righti);
	if(b<=mid)return query(a,b,in,mid,lefti);
	node left=query(a,b,in,mid,lefti);
	node right=query(a,b,mid+1,fin,righti);
	res.sum=left.sum+right.sum;
	res.prefix=max(left.prefix,left.sum+right.prefix);
	res.suffix=max(right.suffix,right.sum+left.suffix);
	res.max=max(res.prefix,max(res.suffix,max(left.max,max(right.max,left.suffix+right.prefix))));
	return res;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,n-1,0);
		cin>>q;
		ll a,b;
		while(q--){
			cin>>a>>b;
			a--;
			b--;
			cout << query(a,b,0,n-1,0).max<<"\n";
		}
	}
