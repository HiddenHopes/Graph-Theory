#include<bits/stdc++.h>
using namespace std;

int node, edge;
int graph[20][20];

void initialize(){
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            graph[i][j]=0;
        }
    }
}

void graphprint(){
  //  printf("Graph:\n");
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            printf("%d ",graph[i][j]);
        }
       // printf("\n");
    }
}
void graphinput(){
    int x, y;
    for(int i = 1; i<=edge; i++){
        scanf("%d %d\n",&x, &y);
        graph[x][y] = 1;
    }
}

void underlyingGraph(){
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++){
            if(graph[i][j]==1) graph[j][i]=1;
        }
    }
}

int main(){
    freopen("underlying.txt","r",stdin);
    scanf("%d %d\n", &node, &edge);

    initialize();
    graphinput();
    graphprint();
    underlyingGraph();
    graphprint();
}

