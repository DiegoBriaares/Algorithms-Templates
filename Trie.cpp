#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
struct nodo{
    int many;
    int cubeta[26];
};
nodo trie[MAX];
int n,q,m=1,l;
char palabra[MAX];
void meter(int l){
    int pos=1;
    for(int i=0; i<l; i++){
        int letra=(palabra[i]-'a');
        if(trie[pos].cubeta[letra]==0){
            trie[pos].cubeta[letra]=++m;
        }
        pos=trie[pos].cubeta[letra];
        trie[pos].many++;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>palabra;
        l=strlen(palabra);
        meter(l);
    }
}
