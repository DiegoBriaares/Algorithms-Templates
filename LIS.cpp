#include<stdio.h>
#include<string.h>
void lis(int str[],int n)
{
	int len[n],prev[n],i,j,max=-1,k,b[n],a=0;
	for(i=0;i<n;i++){
		len[i]=1;
		prev[i]=-1;
	}
	for(i=1;i<n;i++)
	for(j=0;j<i;j++){
		if(str[i]>str[j]&& len[i]<(len[j]+1)){
			len[i]=len[j]+1;
			prev[i]=j;
 
		}
	}
	for(i=0;i<n;i++)
		if(len[i]>max)
		{	max=len[i]; k=i;}
	b[a]=str[k];
	for(i=prev[k];i>=0;i=prev[k])
		{b[++a]=str[i];k=i;}
	for(i=max-1;i>=0;i--)
		printf("%d ",b[i]);
}
main()
{
    int str[]={5,9,4};
    lis(str,sizeof(str)/4);
    return 0;
}
