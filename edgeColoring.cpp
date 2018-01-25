#include<bits/stdc++.h>
using namespace std;
int node, edge, m;
int graph[20][20];
int n[20][20];

bool isSafe(int u, int v, int c){
    for(int i=1; i<=node; i++){
        if(graph[u][i]==1 && c== n[i]){
            return false;
        }
    }
    return true;
}
void graphColor(int u, int v){

    for(int c=1; c<=m; c++){
        if(isSafe(u,v,c)){
            n[u][v] = c;
            n[v][u] = c;
            if((V+1)<=edge)
                graphColor(u+1);
            else {
                //for(int j=1; j<=node; j++) cout<<n[j]<<" ";
                return;
            }

        }
    }

}

void graphshow(){
    for(int i=1; i<=node; i++){
        for(int j=1; j<=node; j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    freopen("graphColoring.txt", "r", stdin);
    cin>>node>>edge;
    int x,y;
    memset(graph,0,sizeof(graph));
    memset(n,0,sizeof(n));
    for(int i=1; i<=edge; i++){
        cin>>x>>y;
        graph[x][y]=graph[y][x]=1;
    }
    for(int i=1; i<=node; i++){
        graph[i][i]=1;
    }
graphshow();
    m = 4;
    graphColor(1,2);
    for(int i=1; i<=node; i++)
        for(int j=1; j<=node; j++)
            cout<<"edge"<<i<<"---"<<j<<" color : "<<n[i][j]<<"\n";
    return 0;
}
