#include<bits/stdc++.h>
using namespace std;

int node, edge, t=0;
vector<vector<int> > graph(20);
vector<vector<int> > ugraph(20);

void graphprint(vector<vector<int> > graph){
    cout<<"underline Graph:\n";
    for(int i=1; i<=node; i++){
        cout<<i<<"-> ";
        for(int j=0; j<ugraph[i].size(); j++){
            cout<<ugraph[i][j]<<", ";
        }
        cout<<endl;
    }
}

void graphinput(){
    int x, y;
    cin>>node>>edge;
    for(int i = 1; i<=edge; i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
}

void underlyingGraph(){
    for(int i=1; i<=node; i++){
        for(int j=0; j<graph[i].size(); j++){
            int y = graph[i][j];
            ugraph[i].push_back(y);
            ugraph[y].push_back(i);
        }
    }
}

int main(){
    graphinput();
    underlyingGraph();
    graphprint();
}

