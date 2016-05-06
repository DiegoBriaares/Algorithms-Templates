#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define P 9001
#define ll long long 
int hash(string v){
	ll r=0;
	for(int i=0;i<v.size();i++){
		r*=P;
		r+=(ll)(v[i]);
		r%=MOD;
	}
	return r;
}
int roll(string query,string base){
	ll hash1=hash(query),hash2=0,pot=1;
	for(int i=0;i<query.size();i++){
		pot=(pot*P)%MOD;
	}
	for(int i=0;i<base.size();i++){
		hash2*=P;
		hash2+=base[i];
		hash2%=MOD;
		if(hash2<0)hash2+=MOD;
		if(i>=query.size()){
			hash2-=pot*base[i-query.size()]%MOD;
			if(hash2<0)hash2+=MOD;
		}
		if(i>=query.size()-1&&hash1==hash2)return i-(query.size()-1);
	}
	return -1;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		string a,b;
		cin>>a>>b;
		int r=roll(b,a);
		(r!=-1?cout << "Encontrado en: "<<r<<"\n":cout <<"No encontrado\n");
	}
