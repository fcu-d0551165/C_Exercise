#include <stdio.h>

int main(void){

    int i;
    int j;
    int BigNumber = -1;
    int Arr[10] = {1,4,7,8,1,3,5,6,0};

    for(i=0; i<10; i++){
        if(BigNumber < Arr[i]){
            BigNumber = Arr[i];
            j = i;
        }
    }

    printf("Big number: %d : Arr[%d]", BigNumber, j);

    return 0;
}