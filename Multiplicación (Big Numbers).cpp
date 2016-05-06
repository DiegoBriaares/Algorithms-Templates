ll go(ll x, ll y){
	ll r=0;
	for (;y;y/=2){
		if ((y&1))
			r=(r+x)%MOD;
		x=(x+x)%MOD;
	}
	return r;
}
