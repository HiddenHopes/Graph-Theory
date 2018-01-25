#include<stdio.h>
int a[20][20],x[20],n,e,m;
void next(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1; j<=n; j++)
            if(a[k][j]!=0&&x[k]==x[j])
                break;
        if(j==n+1)
            return;
    }
}
void mcolor(int k)
{
    int j;
    while(1)
    {
        next(k);
        if(x[k]==0)
            return;
        if(k==n)
        {
            printf("\n");
            for(j=1; j<=n; j++)
                printf("%2d",x[j]);
        }
        else
            mcolor(k+1);
    }
}
int main()
{
    freopen("graphColoring.txt", "r", stdin);
    int i,u,v;
    //printf("\n\n Enter how many colors : ");
    scanf("%d",&m);
   // printf("\n\n Enter how many nodes :");
    scanf("%d",&n);
   // printf("\n\n Enter how many edges :");
    scanf("%d",&e);
    for(i=1; i<=e; i++)
    {
        scanf("%d %d",&u,&v);
        a[u][v]=a[v][u]=1;
    }
    mcolor(1);
    printf("\n\n");
    return 0;
}
