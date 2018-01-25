#include<stdio.h>
int node, edge;
struct graph
{
    int u,v,w,select;
} x[30];

int n1,n2,rootn1,rootn2,mincost,parent[20];
void graphinput()
{
    int a,b,z;
    scanf("%d %d",&node, &edge);
    for(int i=1; i<=edge; i++)
    {
        scanf("%d %d %d",&a, &b, &z);
        x[i].u = a;
        x[i].v = b;
        x[i].w = z;
    }
}
void sort()
{
    struct graph temp;

    for(int i=1; i<=edge; i++)
    {
        for(int j=i; j<edge; j++)
        {
            if(x[j].w > x[j+1].w)
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
}

int main()
{
    int c=0;
    freopen("kruskal.txt", "r", stdin);
    graphinput();
    sort();
    printf("\n\t\tMinimal spanning tree is : ");
    for(int i=1; i<=edge; i++)
    {
        if(c==edge)
            break;
        n1=x[i].u;
        n2=x[i].v;
        while(n1>0||n2>0)
        {
            if(n1>0)
            {
                rootn1=n1;
                n1=parent[n1];
            }
            else
            {
                rootn2=n2;
                n2=parent[n2];
            }
        }
        if(rootn1!=rootn2)
        {
            parent[rootn2]=rootn1;
            x[i].select=1;
            printf("\n\t\t\t%d->%d=%d",x[i].u, x[i].v, x[i].w);
            mincost+=x[i].w;
            c++;
        }
    }
    printf("\n\t\tMinimum cost =%d",mincost);
    return(0);
}
