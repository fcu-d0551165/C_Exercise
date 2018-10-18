#include<stdio.h>

int A[128];
int BublleSort(int size);

int main(int argc, char const *argv[]){
    
    int i=0;
    float median;
    int number;

    while(scanf("%d", &number) != EOF){
        A[i] = number;
        i++;
    }

    number = i;
    BublleSort(i);
    
    /*Output the Array*/
    for(i=0; i<number; i++){
        printf("%d ", A[i]);
    }

    puts("\n\n");
    printf("number of enter: %d \n\n", number);

    /*Median*/
    int mid = number/2;

    if(number%2 == 0){
        median = (A[mid-1]+A[mid]);
        median/=2;
    }
    else{
        median = A[mid];
    }
    printf("Medain : %.2f \n", median);

    return 0;
}

int BublleSort(int size){

    int i,j;
    int temp;

    /*冒泡排序法_Bubble Sort*/
    for(i=0; i<size-1; i++){  
        for(j=0; j<size-i-1; j++){ 
            if(A[j] > A[j+1])
            {
                /*交換_SWAP*/
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return 0;
}
