#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
#define P 9001
#define MOD 1000000007
int n;
string res;
struct HashTable {
	char v[MAX];
	ll hash[MAX];
};
ll pows[MAX];
HashTable a,b;
void mod(ll &aux){
	aux%=MOD;
	aux+=MOD;
	aux%=MOD;
}
void init(){
	pows[0]=1;
	for(int i=1;i<=n;i++){
		pows[i]=pows[i-1]*P;
		mod(pows[i]);
	}
}
ll hashing(int l,int r,int c){
	ll aux;
	if(!c){
		aux= (a.hash[r]-a.hash[l-1]);
		mod(aux);
	}
	else {
		aux= (b.hash[r]-b.hash[l-1]);
		mod(aux);
	}
	return aux;
}
bool binary(int idx1,int idx2){
	int k=-1;
	for(int l=0,m,r=min(n-idx1-1,n-idx2-1);l<=r;){
		m=(l+r)/2;
		ll h1=hashing(idx1,idx1+m,0);
		ll h2=hashing(idx2,idx2+m,1);
		if(idx1>idx2){
			h1*=pows[idx1-idx2];
			mod(h1);
		}
		else{
			h2*=pows[idx2-idx1];
			mod(h2);
		}
		if(h1!=h2){
			r=m-1;
			k=m;
		}
		else l=m+1;
	}
	if(k==-1)return idx1<=idx2;
	return a.v[idx1+k]<=b.v[idx2+k];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		init();
		for(int i=0;i<n;i++){
			cin>>a.v[i];
		}
		for(int i=0;i<n;i++){
			b.v[i]=a.v[(n-1)-i];
		}
		for(int i=0,j=n-1;i<n;i++,j--){
			if(i){
				a.hash[i]=a.hash[i-1];
				b.hash[i]=b.hash[i-1];
			}
			a.hash[i]+=a.v[i]*pows[j];
			mod(a.hash[i]);
			b.hash[i]+=b.v[i]*pows[j];
			mod(b.hash[i]);
		}
		for(int idx1=0,idx2=0;idx1+idx2<n;){
			if(binary(idx1,idx2)){  //Entonces a es menor a b.
				res+=a.v[idx1++];
			}
			else {   //Entonces b es menor a a.
				res+=b.v[idx2++];
			}
		}
		for(int i=0;i<n;i++){
			cout << res[i];
			if((i+1)%80==0)cout << "\n";
		}
	}
