ll solve(ll a,ll k){
    int r=(a/p)%10;
    if(r==k){
        return (a%p)+1+(a/(p*10))*p;
    }
    if(r<k){
        return (a/(p*10))*p;
    }
    return (a/(p*10)+1)*p;
}
ll give(ll mid,int idx){   //mid = N, idx = digito.
	cont=0;
			p=1;
			while(p<mid){
        		cont+=solve(mid,idx);
        		p*=10;
    		}
    		return cont;
}
