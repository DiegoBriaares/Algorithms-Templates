#include <bits/stdc++.h>
using namespace std;
#define MAX 102
string res;
int n1,n2,n3;
string v1,v2,q;
int memo[MAX][MAX][MAX];
int dp(int i,int j,int k){
	if(k==n3)return -(1<<30);
	if(i==n1||j==n2){
		return 0;
	}
	if(memo[i][j][k])return memo[i][j][k];
	memo[i][j][k]=max(dp(i,j+1,k),dp(i+1,j,k));
		if(v1[i]==v2[j]){
			if(v1[i]!=q[k])memo[i][j][k]=max(memo[i][j][k],1+dp(i+1,j+1,0));
			else memo[i][j][k]=max(memo[i][j][k],1+dp(i+1,j+1,k+1));
		}
	return memo[i][j][k];
}
void print(){
    int i=0,j=0,k=0;
    int a=memo[i+1][j][k];
    int b=memo[i][j+1][k];
    while(i<n1&&j<n2){
    	a=memo[i+1][j][k];
		b=memo[i][j+1][k];
        if(v1[i]==v2[j]){
            if(q[k]!=v1[i]){
            	if(memo[i+1][j+1][0]+1>max(a,b)){
            		cout << v1[i];
            		i++;
            		j++;
            		k=0;
				}
				else {
					if(a>b){
        				i++;
					}
        			else {
        				j++;
					}
				}
			}
			else {
				if(k+1<n3){
					if(memo[i+1][j+1][k+1]+1>max(a,b)){
						cout << v1[i];
            			i++;
            			j++;
            			k++;
					}
					else {
						if(a>b){
        					i++;
						}
        				else {
        					j++;
						}
					}
				}
				else {
					if(a>b){
        				i++;
					}
        			else {
        				j++;
					}
				}	
			}
        }
        else {
        	if(a>b){
        		i++;
			}
        	else {
        		j++;
			}
		}
    }
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v1;
		cin>>v2;
		cin>>q;
		n1=v1.size();
		n2=v2.size();
		n3=q.size();
		int r=dp(0,0,0);
		if(r<=0){
			cout << "0\n";
			return 0;
		}
		print();
	}
