//
//  Lab 1_HW_Server.c
//
//  001-字元與字串-Char_And_String.c
//  Version 2.0
//	
//  Created by Waylon.Yuen on 24/9/2018.
//  Last modified by Waylon.Yuen on 24/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：
//  操作：X
//  原理：X
//  優化：X
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

void swap(int *A, int *B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Max(int maxmum[]){

    int i;
    int hold = 0;

    for(i=0; i<5; i++){
        if(maxmum[i] > hold){
            hold = maxmum[i];
        }
    }
    return hold;
}

int Min(int minmum[]){

    int i;
    int hold = 9999999999;

    for(i=0; i<5; i++){
        if(minmum[i] < hold){
            hold = minmum[i];
        }
    }
    return hold;
}

int Mid(int midmum[]){

    int i,j;
    int temp;

    /*排序——小至大*/
    for(i=0; i<5-1; i++){
        for(j=0; j<j-i-1; j++){
            if(midmum[j]>midmum[j+1]){
                temp = midmum[j+1];
                midmum[j+1] = midmum[j];
                midmum[j] = temp;
            }
        }
    }
    return 0;
}

int main(void) {
    
    struct sockaddr_in server, client;
    int sock, csock, readSize, addressSize;
    char buf[256];
    
    /*通訊設定——建立通訊協定*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    bind(sock, (struct sockaddr*)&server, sizeof(server));
    listen(sock,5);
    
    int i,j;
    int hold[5];
    int getData[256];

    /*接收資料總數*/
    int size[1];
    addressSize = sizeof(client);
    csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
    readSize = recv(csock, size, sizeof(size), 0);
    printf("\n\nRead data Size: %d \n\n", size[0]);

    /*接收資料內容*/
    printf("Get Data\n"
           "----------------------------\n");
    for(i=0; i<size[0]; i++){
        addressSize = sizeof(client);
        csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
        readSize = recv(csock, &getData[i], sizeof(getData[i]), 0);
        printf("Read Message: %d \n", getData[i]);
    }puts("End\n\n");

//Functions:server功能----------------------------------------------

    /*冒泡排序法_Bubble Sort*/
    int temp;
    for(i=0; i<size[0]-1; i++){  
        for(j=0; j<size[0]-i-1; j++){ 
            if(getData[j] < getData[j+1]){// "<" 和 ">" 決定排序是：由大到小"<" or 由小到到大">"
                /*交換_SWAP*/
                swap(&getData[j], &getData[j+1]);
            }
        }
    }

    /*累加值*/
    int totalNum = 0;
    for(i=0; i<size[0]; i++){
        totalNum = totalNum + getData[i];
    }
//End of Functions--------------------------------------------------

    /*Sort Array 回傳*/
    printf("Send Data\n"
           "----------------------------\n");
    for(i=0; i<size[0]; i++){
        send(csock, &getData[i], sizeof(getData[i]), 0);
        printf("sendBack Msg %d \n", getData[i]);
    }puts("End\n\n");
    
    /*Sum of numbers 回傳*/
    printf("Send Sum of number\n"
           "----------------------------\n");
    send(csock, &totalNum, sizeof(totalNum), 0);
    printf("sendBack TobalNum: %d\n", totalNum);
    puts("End\n\n");

    close(csock);
    close(sock);
}

