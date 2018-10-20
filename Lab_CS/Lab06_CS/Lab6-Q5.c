#include<stdio.h>

int main(){
    int i=0;
    int base, number, times;
    int ans;

    scanf("%d %d %d", &base, &number, &times);

    if(base <= times){
        ans = number * times;
    }
    else{
        while(1){
            ans = base/times;
            ans = (ans+i)*times;
            if(ans >= base){
                i=1;
                while(i != number){
                    ans+=times;
                    i++;
                }
                break;
            }
            i++;
        }
    }

    printf("%d", ans);

    return 0;
}