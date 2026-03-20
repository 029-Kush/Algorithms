/* Floyd’s algorithm */
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int cost[MAX][MAX];
int n;
main( )
{
int i,j,k,c,x,y;
int max_edges,origin,destin;
printf("Enter number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
cost[i][j]=999999; // initialize all entries in cost[][] to 0
}
max_edges=n*(n-1);
for(i=1;i<=max_edges;i++)
{
printf("Enter edge %d( 0 0 to quit ) : ",i);
scanf("%d %d",&origin,&destin);
if((origin==0) && (destin==0))
break;
if( origin > n || destin > n || origin<=0 || destin<=0)
{
    printf("Invalid edge!\n");
i--;
}
else
{
 printf("\n enter the cost\n");
 scanf("%d",&c); // only for a valid edge, read its cost ‘c’ and store it in the appropriate
cost[origin][destin]=c; // index of cost[ ][ ]
}
}
//display
printf("\nInitial Cost Matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%6d ",cost[i][j]);
printf("\n");
}
for(i=1;i<=n;i++) //‘i’ index generates the 4 iterations needed to individually explore routes via
{ // ‘j’ index generates the row number of the matrices
 for(j=1;j<=n;j++)
 {
 for(k=1;k<=n;k++) // ‘k’ index generates the 4 columns that are to be processed in each row
 {
 if(cost[j][k]>cost[j][i]+cost[i][k])
 { //if the route via vertex ‘i’ is shorter, update the cost of that route in the cost matrix
 cost[j][k]=cost[j][i]+cost[i][k];

 }
 }
 }
}
printf("\nFinal Cost Matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%6d",cost[i][j]);
printf("\n");
}
return 0;
}