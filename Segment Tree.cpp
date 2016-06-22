#include <bits/stdc++.h>
using namespace std;
#define MAX 202
int A[MAX];
int ST[MAX];
int tamn;
int tamst;
void build(int lo,int hi,int n){
	if(lo==hi){
		ST[n]=A[lo];
		return;
	}
	int mid=(lo+hi)/2;
	int left=n*2+1;
	int right=n*2+2;
	build(lo,mid,left);
	build(mid+1,hi,right);
	ST[n]=min(ST[left],ST[right]);
}
int query(int qlo,int qhi,int lo,int hi,int n){
	if(qlo<=lo&&qh>=hi){
		return ST[n];
	}
	if(qlo>hi||qhi<lo)
		return (1<<30); //el return es infinito
		int mid=(lo+hi)/2;
		int left=n*2+1;
		int right=n*2+2;
		return min(query(qlo,qhi,lo,mid,left),query(qlo,qhi,mid+1,hi,right));
}
void update(int i,int val){
	ST[tamst-tamn+i]=val; //actualiza hoja
	int n=tamst-tamn+i;
	while(n!=0){ //Mientras no sea raíz
		n=(n-1)/2; //padre
		int left=n*2+1;
		int right=n*2+2;
		ST[n]=min(ST[left],ST[right]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>tamn;
		tamst=tamn*2-1; //SI TAMN NO ES POTENCIA DE 2, HAGAMOSLO POTENCIA, Y RELLENEMOS LOS SIGUEINTES DE LA POTENCIA CON IFINITO
		build(0,tamn,0);
		query(a,b,0,tamn-1,0);
	}
