#include<bits/stdc++.h>
using namespace std;
int node, edge, m;
vector<vector<int> > graph(20);
int n[20];
bool isSafe(int k, int c){
    for(int i=0; i<graph[k].size(); i++){
        int u = graph[k][i];
        if( c == n[u]){
            return false;
        }
    }
    return true;
}
void graphColor(int k){
    for(int c=1; c<=m; c++){
        if(isSafe(k,c)){
            n[k] = c;
            if((k+1)<node)
                graphColor(k+1);
            else {
                //for(int j=1; j<=node; j++) cout<<n[j]<<" ";
                return;
            }

        }
    }

}

void graphshow(){
    for(int i=0; i<node; i++){
        cout<<i<<" ->  ";
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<<", ";
        cout<<"\n";
    }
}
int main(){
    freopen("graphColoring2.txt", "r", stdin);
    cin>>node>>edge;
    memset(n,0,sizeof(n));
    int x,y;
    for(int j=1; j<=edge; j++){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    for(int j=0; j<node; j++){
        graph[j].push_back(j);
    }
    graphshow();
    m = 3;
    graphColor(0);
    for(int j=0; j<node; j++) cout<<"Node"<<j<<" color : "<<n[j]<<"\n";
    return 0;
}
