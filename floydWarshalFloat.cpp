#include <bits/stdc++.h>
using namespace std;
int V, E, u, v, w, graph[200][200];
float p;
#define INF 10000000
void showgraph(int k){
    cout<<"D ( "<<k+1<<" )"<<endl;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            p = float(graph[i][j])/100;
            if(graph[i][j]!=INF)printf("%.2f ",p);
            else printf("**** ");
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
  freopen("floydWarshal2.txt", "r", stdin);
freopen("out.txt", "w", stdout);
  scanf("%d %d", &V, &E);

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      graph[i][j] = INF;
    graph[i][i] = 0;
  }
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    graph[u][v] = w;
    //graph[v][u] = w;
  }
  //showgraph(0);
  for (int k = 0; k < V; k++){
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    showgraph(k);
  }
  return 0;
}
