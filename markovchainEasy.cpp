#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("markovchain.txt","r",stdin);
    float s0, s1, a,b,c,d;
    float temp0, temp1;
    scanf("%f %f\n", &s0,&s1);

    scanf("%f %f %f %f\n", &a, &b, &c, &d);

    while(1){
        temp0 = s0*a + s1*c;
        temp1 = s0*b + s1*d;
        if(fabs(s0-temp0)<.001) break;
        s0 = temp0;
        s1 = temp1;
        printf("%10.2f %10.2f\n",s0,s1);
    }
    return 0;
}

