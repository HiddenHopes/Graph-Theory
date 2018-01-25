#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(20);
vector<vector<int> > igraph(20);
stack<int>st;

int color[20];

void dfs1(int u){
    color[u] = 1;
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if(color[v]==-1){
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    cout<<u+1<<" ";
    color[u] = 1;
    for(int i=0; i<igraph[u].size(); i++){
        int v = igraph[u][i];
        if(color[v]==-1){
            dfs2(v);
        }
    }
}

int main(){
    int vertex, edge;
    freopen("stronglyConnected.txt", "r", stdin);
    //graph.assign(vertex, vector<int>());
    //igraph.assign(vertex, vector<int>());
    cin>>vertex>>edge;
    int x,y;
    for(int i=1; i<=edge; i++){
        cin>>x>>y;
        //cout<<x<<" "<<y<<endl;
        graph[x-1].push_back(y-1);
        igraph[y-1].push_back(x-1);
    }
    memset(color,-1,sizeof(color));

    for(int i=0; i<vertex; i++){
        if(color[i]==-1)
            dfs1(i);
    }

    memset(color,-1,sizeof(color));
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(color[u]==-1){
            cout<<"SCC: ";
            dfs2(u);
            cout<<endl;
        }
    }

    return 0;
}
