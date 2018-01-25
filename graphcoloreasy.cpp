#include<bits/stdc++.h>
using namespace std;
int node, edge, m;
int graph[20][20];
int n[20];
bool isSafe(int k, int c){
    for(int i=1; i<=node; i++){
        if(graph[k][i]==1 && c== n[i]){
            return false;
        }
    }
    return true;
}
void graphColor(int k){
    for(int c=1; c<=m; c++){
        if(isSafe(k,c)){
            n[k] = c;
            if((k+1)<=node)
                graphColor(k+1);
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
    freopen("graphColoring2.txt", "r", stdin);
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
    m = 3;
    graphColor(1);
    for(int j=1; j<=node; j++) cout<<"Node"<<j<<" color : "<<n[j]<<"\n";
    return 0;
}
