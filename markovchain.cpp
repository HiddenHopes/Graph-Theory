#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("markovchain.txt","r",stdin);
    float s[2],a[2][2];
    float temp1, temp2;
    scanf("%f %f\n", &s[0],&s[1]);

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            scanf("%f\n", &a[i][j]);
        }
    }


    while(1){
        temp1 = s[0]*a[0][0] + s[1]*a[1][0];
        temp2 = s[0]*a[0][1] + s[1]*a[1][1];
if(fabs(s[0]-temp1)<.001) break;
        s[0] = temp1;
        s[1] = temp2;
        printf("%10.2f %10.2f\n",s[0],s[1]);
    }
    return 0;
}

