#include<stdio.h>
int n, e, graph[20][20];
int degree(int node){
    int deg = 0;
    for(int i=1; i<=n; i++){
	if(graph[node][i]==1) deg = deg + 1;
    }
    return deg;
}

int isNull(){
    int null = 1;
    for(int i=1; i<=n; i++){
	if(degree(i)==0) continue;
	else{null = 0;break;}
    }
    return null;
}
int isComplete(){
    int comp = 1;
    for(int i=1; i<=n; i++){
	if(n-1==degree(i)) continue;
	else{comp = 0; break;}
    }
    return comp;
}

int isCycle(){
    int cyc = 1;
    for(int i=1; i<=n; i++){
	if(degree(i)==2) continue;
	else{cyc = 0; break;}
    }
    return cyc;
}

int isWheel(){
    int whl = 1, f = 0;
    for(int i=1; i<=n; i++){
	if(degree(i)==n-1) f = 1;
	else if(degree(i)>=3) continue;
	else{whl = 0; break;}

    }
    return whl&f;
}
int main(){
   // freopen("in.txt","r", stdin);
    int k = 1, a, b, i, j;
    while(scanf("%d %d", &n, &e)==2){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
            graph[i][j]=0;
            }
        }
        for(i=1; i<=e; i++){
            scanf("%d %d",&a, &b);
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

	printf("Graph #%d:\n",k++);
	if (isNull()) printf("Null graph\n");
	if(isComplete()) printf("Complete graph\n");
	if(isCycle()) printf("Cycle graph\n");
	if(isWheel()) printf("Wheel\n");
	printf("\n");
    }
    return 0;
}

