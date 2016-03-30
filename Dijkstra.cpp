#include <bits/stdc++.h>
using namespace std;
#define peso first
#define next second
#define MAX 200
#define edge pair<int,int>
vector <edge> E[MAX];
int z[MAX];
void dijkstra(int v){
	priority_queue<edge>q;
	edge a,b;
	a.peso=0;
	a.next=v;
	q.push(a);
	while(!q.empty()){
		a=q.top();
		q.pop();
		while(z[a.next]&&!q.empty()){
			a=q.top();
			q.pop();
			if(z[a.next]&&q.empty())return a.peso;
		}
		z[a.next]=a.peso;
		//opcional here:
		if(a.next==final)return a.peso;
		for(int i=0;i<E[a.next].size();i++){
			b.next=E[a.next][i].next;
			b.peso=a.peso-E[a.next][i].peso;
			if(!z[b.next]){
				q.push(b);
			}
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
	}
