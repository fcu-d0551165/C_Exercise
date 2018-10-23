#include<stdio.h>
#include<stdlib.h>

int main(){


    int counter[6]={0};
    int i;

    /* 6000 次的統計循環*/
    for(i=1; i<=6000; ++i){ //先++，再做內容
        int dice = rand()%6 + 1; //隨機數範圍 1～6

        /*判斷骰子號碼&統計*/
        switch(dice){
            case 1: counter[0]++; break;
            case 2: counter[1]++; break;
            case 3: counter[2]++; break;
            case 4: counter[3]++; break;
            case 5: counter[4]++; break;
            case 6: counter[5]++; break;
        }
    }

    /*Output*/
    printf("1: %d\n", counter[0]);
    printf("2: %d\n", counter[1]);
    printf("3: %d\n", counter[2]);
    printf("4: %d\n", counter[3]);
    printf("5: %d\n", counter[4]);
    printf("6: %d\n", counter[5]);

    return 0;
}