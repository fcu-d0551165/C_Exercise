#include<stdio.h>

int main(){
    int i=1;
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
            if(ans > base){
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