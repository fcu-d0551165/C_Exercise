#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int get;

    scanf("%d", &get);

    if(get%2 != 0){
        printf("%d is a odd number. \n", get);
    }
    else{
        printf("%d is not a odd number. \n", get);
    }

    puts("end of run\n\n");

    return 0;
}
