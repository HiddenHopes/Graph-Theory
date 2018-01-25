#include<bits/stdc++.h>
using namespace std;


#define MAX 40
#define INF 1000000000

int res[MAX][MAX], mf, f, s, t;                          // global variables
vector<int> p;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] = res[p[v]][v] -  f; res[v][p[v]] += f; }       // update
}

int main() {
  int vertex, edge;

  freopen("maxFlow.txt", "r", stdin);

  scanf("%d %d %d %d", &vertex, &edge, &s, &t);

  memset(res, 0, sizeof res);
  int x,y,w;
  for (int i = 0; i < edge; i++) {
      scanf("%d %d %d",&x, &y, &w);
      res[x][y] = w;
  }

  mf = 0;                                              // mf stands for max_flow
  while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
    f = 0;
    // run BFS, compare with the original BFS shown in Section 4.2.2
    vector<int> dist(MAX, INF);
    dist[s] = 0;
    queue<int> q; q.push(s);
    p.assign(MAX, -1);           // record the BFS spanning tree, from s to t!
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;      // immediately stop BFS if we already reach sink t
      for (int v = 0; v < MAX; v++){                 // note: this part is slow
        if (res[u][v] > 0 && dist[v] == INF){
          dist[v] = dist[u] + 1;  // level 1 kore bariye dey
          q.push(v);
          p[v] = u;
          }
      }
    }
    augment(t, INF);     // find the min edge weight `f' along this path, if any
    if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
    mf += f;                 // we can still send a flow, increase the max flow!
  }

  printf("%d\n", mf);                              // this is the max flow value

  return 0;
}
