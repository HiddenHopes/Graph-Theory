#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(20);
vector<vector<int> > igraph(20);
stack<int>st;
int color[20];
int cnt;
bool flag;

void dfs1(int u){
    cnt++;
    color[u] = 1;
    for(int i=0; i<graph[u].size(); i++){   // 0 er sathe kon node connected graph[0][0]= 1
        int v = graph[u][i];   // v = 1
        if(color[v]==-1){  // not visited kina check mane -1 value kina
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    cnt++;
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

    cin>>vertex>>edge;
    int x,y;
    for(int i=1; i<=edge; i++){
        cin>>x>>y;
        graph[x-1].push_back(y-1);    // graph[x][y]=1
        igraph[y-1].push_back(x-1);
    }

    memset(color,-1,sizeof(color)); // for(i=0; i<20; i++) color[i] = 0
    flag = true;
    cnt = 0;
    dfs1(0);    // first dfs.  here we started from node 1 mane 0

    if(cnt<vertex) flag = false;

    memset(color,-1,sizeof(color));

    if(flag)
      while(!st.empty()){
        int u = st.top();
        st.pop();
        if(color[u]==-1){
            cnt = 0;
            dfs2(u); // second dfs
            if(cnt<vertex) {flag = false; break;}
        }
    }
    if(flag) cout<<"Strongly Connected\n";
    else cout<<"Not Strongly Connected\n";

    return 0;
}
