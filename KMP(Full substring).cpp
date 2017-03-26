#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
string v,q;
int KMP[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v>>q;
		for(int i=1,j=0;i<q.size();){
			if(q[i]==q[j]){
				KMP[i]=j+1;
				j++;
				i++;
			}
			else if(j) {
				j=KMP[j-1];
			}
			else {
				KMP[i]=0;
				i++;
			}
		}
		for(int i=0,j=0;i<v.size()&&j<q.size();){
			if(v[i]==q[j])i++,j++;
			else if(j){
				j=KMP[j-1];
			}
			else i++;
			if(j==q.size()){
				cout << "ESTA\n";
				return 0;
			}
		}
		cout << "NO ESTA\n";
	}
