//#FM02-質數<Prime_Number>.c
#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int i;
    int flag = 0;
    int number;

    scanf("%d", &number);

    for(i=2; i<number; i++){
        if(number%i == 0){  //能被整除
            flag = 1;
            break;
        }
    }
    /*不能夠被整除*/
    if(flag == 0){
        printf("%d is a Prime number! \n", number);
    }
    else{
        printf("%d is not a Prime number! \n", number);
    }


    return 0;
}
