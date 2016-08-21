#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int n;
int raiz;
int nodos;
int v[MAX];
int izq[MAX],der[MAX],tree[MAX];
int new_node(int x){
	tree[nodos]=x;
	izq[nodos]=-1;
	der[nodos]=-1;
	return nodos++;
}
void insert(int nodo,int x){
	if(x<tree[nodo]){  //Pa la izquierda
		if(izq[nodo]==-1)izq[nodo]=new_node(x);
		else insert(izq[nodo],x);
	}
	else {   //Pa la derecha
		if(der[nodo]==-1)der[nodo]=new_node(x);
		else insert(der[nodo],x);	
	}
}
void preorden(int nodo){
	if(nodo==-1)return;
	cout << tree[nodo]<<" ";
	preorden(izq[nodo]);
	preorden(der[nodo]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		reverse(v,v+n);
		for(int i=0;i<n;i++){
			if(!i){
				raiz=new_node(v[i]);
			}
			else {
				insert(raiz,v[i]);
			}
		}
		preorden(raiz);
	}
