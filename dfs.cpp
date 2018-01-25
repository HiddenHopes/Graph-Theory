#include<bits/stdc++.h>
using namespace std;

int node, edge, t=0;
int d[20], f[20];
int graph[20][20];
int color[20], parent[20];

void graphprint(){
    printf("Graph:\n");
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void graphinput(){
    int x, y;
    freopen("in.txt","r",stdin);
    scanf("%d %d\n", &node, &edge);
    for(int i = 1; i<=edge; i++){
        scanf("%d %d\n",&x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
}
void dfs(int u){
    color[u] = -1;    //  -1 mane u node er color chhai color
    t = t + 1;       // t =
    d[u] = t;       //     discover time

    for(int i = 1; i<=node; i++){
         if(graph[u][i]==1 && color[i]==0) { // graph[u][i]==1 mane u theke i connection ache
            parent[i] = u;
            dfs(i);
        }
    }
    color[u] = 1;     // u node er kaj sesh. u er color 1 mane black dhorchi.
    t = t + 1;       // t =
    f[u] = t;        //     finish time
}
int main(){
    memset(color,0,sizeof(color));
    memset(parent,0,sizeof(parent));
    memset(graph,0,sizeof(graph));

    graphinput();
    graphprint();

    for(int k=1; k<=node; k++)
        if(color[k]==0) dfs(k);     // assume starting node 1

    for(int i=1; i<=node; i++){
        printf("node %d starts at %d and finishes at %d\n",i, d[i], f[i]);
    }
}

