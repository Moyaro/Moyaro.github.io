#include<iostream>

using namespace std;
int main()
{
	int n,m,k,i,j,l;
	cin>>n>>m>>k;
	
	int a[102][102],b[102][102],c[102][102]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){	
			scanf("%d",&a[i][j]);}}
	for(i=1;i<=m;i++){
		for(j=1;j<=k;j++){
			scanf("%d",&b[i][j]);}}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			for(l=1;l<=m;l++){
				c[i][j]+=a[i][l]*b[l][j];}}}
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++)
			{printf("%d ",c[i][j]);}
		printf("\n");}
	return 0;
}
