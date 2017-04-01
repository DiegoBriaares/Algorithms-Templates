#include <bits/stdc++.h>
using namespace std;
#define MAX 122
int n;
int v[MAX];
int memo[MAX][MAX*40];
int primes_mask[MAX];
int primes[MAX];
int p;
vector<int>res;
bool vi[MAX][MAX*40];
bool mcd(vector<int>v2){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j&&__gcd(v2[i],v2[j])>1)return false;
		}
	}
	return true;
}
bool is_prime(int x){
	int i=sqrt(x);
	while(i>1){
		if(x%i==0)return false;
		i--;
	}
	return true;
}
void get_primes(){
	for(int i=2;p<=40;i++){
		if(is_prime(i))primes[p++]=i;
	}
}
int euclides(int x){
	int m=0;
		for(int i=0;i<p;i++){
			if(x%primes[i]==0){
				m|=(1<<i);  //Prendo el bit que representa que el primo divide a x.
			}
			while(x>0&&x%primes[i]==0){
				x/=primes[i];
			}
		}
		return m;
	}
int dp(int i,int m){
	if(vi[i][m])return memo[i][m];
	vi[i][m]=true;
	if(i<=0)return memo[i][m]=0;
	memo[i][m]=(1<<30);
	for(int j=1;j<40;j++){
			if(!(m & primes_mask[j])){  //Verifico que el primo no se ha usado antes en alguna factorización.
				memo[i][m]=min(memo[i][m],dp(i-1,m|primes_mask[j])+abs(j-v[i-1]));  //Busco la mejor configuración.
			}
	}
	return memo[i][m];
}
bool ok;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);   
		get_primes();
		for(int i=1;i<40;i++){  //Obtengo la mascara de los primos que usa cada posible pila.
			primes_mask[i]=euclides(i);
		}
		while(cin>>n){               
			if(!n)return 0;
			memset(vi,false,sizeof(vi));
			res.clear();
			ok=false;
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			int r=dp(n,0),m=0;
			//cout << r<<"\n";
			for(int i=n;i;i--){
				for(int j=1;j<40;j++){
					if(!(m&primes_mask[j])){
						if(memo[i][m]==memo[i-1][(m|primes_mask[j])]+abs(j-v[i-1])){
							m|=(primes_mask[j]);
							res.push_back(j);
							break;
						}
					}
				}
			}
			for(int i=res.size()-1;i>=0;i--){
				cout << res[i]<<" ";
			}
			cout << "\n";
		}
	}
