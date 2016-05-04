#include <bits/stdc++.h>
using namespace std;
#define MAX 262002
char base[MAX];
int n;
int p[200][MAX];
struct entry {
    int a,ba,x;
    bool operator <(const entry &b) const
        {
        if(a==b.a) return ba<b.ba;
        else return a<b.a;
        }
} v[MAX];
void suffixArray(){
	for(int i=0;i<n;i++){
		if(base[i]>='A'&&base[i]<='Z')p[0][i]=base[i]-'A';
		else p[0][i]=base[i]-'a'+26;
	}
	int uso=1;
	for(int exp=1;(exp>>1)<n;uso++,exp<<=1){
		for(int i=0;i<n;i++){
			v[i].a=p[uso-1][i];
			v[i].ba=i+exp<n?p[uso-1][i+exp]:-1;
			v[i].x=i;
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			p[uso][v[i].x]=i>0&&v[i].a==v[i-1].a&&v[i].ba==v[i-1].ba?p[uso][v[i-1].x]:i;
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>base;
		n=strlen(base);
		suffixArray();
		for(int i=0;i<n;i++)cout << v[i].x<<"\n";
	}
