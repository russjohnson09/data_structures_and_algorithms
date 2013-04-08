/*C PROGRAM TO IMPLEMENT ALL PAIR SHORTEST PATH USING FLOYDS ALGORITHM
 
INPUT: N VALUE FOR NUMBER OF VERTICES
 
OUTPUT: ADJACENCY MATRIX
SHORTEST DISTANCE MATRIX
*/
 
#include<stdio.h>
#include<stdlib.h>
 
void AdjacencyMatrix(int a[][100],int n){ //To generate adjacency matrix for given nodes
 
int i,j;
for(i = 0;i < n; i++)
{
for(j = 0;j <= n; j++)
{
a[i][j] = 0;
}
 
}
 
for(i = 1; i < n; i++)
{
for(j=0;j<i;j++)
{
a[i][j] = rand()%10;
a[j][i] = 99;
}
}
}
 
 
int min(int a,int b){
 
if(a < b)
return a;
else
return b;
}
 
void floyds(int a[][100],int n){
 
int i,j,k;
for(k = 0;k < n ; k++)
{
for(i = 0;i < n; i++)
{
for(j = 0;j < n ; j++)
{
a[i][j] = min (a[i][j], a[i][k] + a[k][j] );
}
}
}
 
}
 
int main()
{
int a[100][100],n,i,j;
 
FILE *fp = fopen("floyds.dot","w"); /* FOR DIGRAPH */
 
fprintf(fp,"digraph A {\n"); /* WRITE TO FILE */
 
printf("Enter the vertices of the digraph\n");
scanf("%d",&n);
 
AdjacencyMatrix(a,n);
 
printf("\t\tAdjacency Matrix of the graph\n"); /* PRINT ADJACENCY MATRIX */
for(i = 0;i < n; i++)
{
for(j = 0;j < n; j++)
{
printf("\t%d",a[i][j]);
if(a[i][j] != 0)
{
fprintf(fp,"%d -> %d\n",i,j);
}
}
printf("\n");
}
 
floyds(a,n);
 
printf("\n Shortest distance matrix\n"); /*PRINT SHORTEST DISTANCE MATRIX*/
for(i = 0;i < n; i++)
{
for(j = 0;j < n; j++)
{
printf("\t%d",a[i][j]);
}
printf("\n");
}
 
fprintf(fp,"}\n\n");
 
fclose(fp);
 
return 0;
}
