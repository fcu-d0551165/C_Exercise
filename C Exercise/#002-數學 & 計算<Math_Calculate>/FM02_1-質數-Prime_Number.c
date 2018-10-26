//
//	Lebal #002-數學 & 計算<Math_Calculate>
//
//  FM02_1-質數-Prime_Number.c
//	Version 1.3 
//	
//  Created by Waylon.Yuen on 18/10/2018.
//	Last modified by Waylon.Yuen on 26/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：輸入整數，判斷其是否為質數。
//	操作：輸入一整數，範圍是int標準。
//	優化：1、判斷n個整數是否為質數，以EOF結束程序。
//       2、限制輸入類型，int以外類型需給予警告標語。
//
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
