#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int number[10],v,n,m,ans;
int g[5][5];
int place(int row, int col){
   int k;
   for(k=1;k<row;k++){
     if(number[k]==col) return 0;
   }
   return 1;
}
void permutation (int v, int n){     // girl v er jonno kon boy seta ber korbe ey function
    int i;
    if (v==n+1){     // jokhon girl er sonkha(v) mot girls er sonkha(n) theke 1 beshi hobe. mane v==n+1 hobe tokhn number array print
	for (i=1; i<=n; i++)
        printf("girl %d would marry boy %d\n",i,number[i]); // girl i marry number[i]
	printf ("\n\n") ;
	return;
    }

	for(i=1;i<=m;i++)
	    if(g[v][i]==1&&place(v,i)){  // two checks: girls v boy i k chine kina ar girl v ke boy i deoa jabe kina.
	    number [v]=i;   // girl v will get boy i
	    permutation(v+1,n); // call same function for next girl (v+1)
	}
}

int main(){
    int x;
    freopen("marriage.txt","r",stdin);
    scanf("%d %d",&n, &m);  // n girls and  m boys
    /*input*/
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&x);
            g[i][j]=x;      // girl i boy j ke chine kina. chinle graph[i][j]=x=1 ar na chinle graph[i][j]=x=0
        }
    }

    permutation(1,n); // girl 1 er jonno kon boy seta ber korar jonno ey funtion k call korche. n mane number of girls.

    return 0;
}
