ll go(ll x, ll y){
	ll r = 0;

	for (; y; y /= 2){
		if (y % 2)
			r = (r + x) % m;
		x = (x + x) % m;
	}

	return r;
}
