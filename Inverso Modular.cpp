#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
#define MOD 1000000007
ll l,r;
string v;
ll h[52][MAX];
ll fact[MAX];
ll rfact[MAX];
ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1) * x % MOD;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % MOD;
    }
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		fact[0]=1LL;
		rfact[0]=1LL;
		for(int i=1;i<MAX;i++){
			fact[i]=fact[i-1]*i;
			fact[i]%=MOD;
			rfact[i] = power(fact[i], MOD - 2);
		}
		//Si tu resultado es P!/a_1!*a_2!*...a_n!, entonces imprimes rfact[a_1]*rfact[a_2]*...*rfact[a_n]*fact[P].
	}
