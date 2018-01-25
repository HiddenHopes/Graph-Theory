#include<bits/stdc++.h>
using namespace std;

int node, edge;
int graph[20][20];
int color[20], parent[20];
queue<int> Q;

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
void bfs(int start){
    Q.push(start);   // Q []
    parent[start] = 0;
    color[start] = -1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        printf("queue pop %d\n",u);
        for(int i = 1; i<=node; i++){
            if(graph[u][i]==1 && color[i]==0) {
                Q.push(i);
                printf("queue push %d\n",i);
                parent[i] = u;
                color[i] = -1;
            }
        }
        color[u] = 1;
    }

}
int main(){
    memset(color,0,sizeof(color));
    memset(parent,0,sizeof(parent));
    memset(graph,0,sizeof(graph));

    graphinput();
    graphprint();

    for(int k=1; k<=node; k++)
        if(color[k]==0) bfs(k);
}

