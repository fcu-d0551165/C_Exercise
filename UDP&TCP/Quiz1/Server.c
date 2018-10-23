//
//  Lab 1_HW_Server.c
//  Server
//
//  Created by Waylon.Yuen on 24/9/2018.
//  Copyright © 2018年 Oracragron. All rights reserved.
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
    int getting[256];
    int totalNum[1];
    int DataCounter[2];
    int maxValue;
    int minValue;
    int midValue;

    /*接收資料總數*/
    int size[1];
    addressSize = sizeof(client);
    csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
    readSize = recv(csock, size, sizeof(size), 0);
    printf("Read Size: %d \n", size[0]);

    /*接收資料內容*/
    for(i=0; i<size[0]; i++){
        addressSize = sizeof(client);
        csock = accept(sock, (struct sockaddr*)&server, &addressSize);
        
        readSize = recv(csock, &getting[i], sizeof(getting[i]), 0);
        printf("Read Message: %d \n", getting[i]);
    }

    /*排序——大到小*/
    /*冒泡排序法_Bubble Sort*/
    int temp;
    for(i=0; i<size[0]-1; i++){  
        for(j=0; j<size[0]-i-1; j++){ 
            if(getting[j] < getting[j+1]){
                /*交換_SWAP*/
                swap(&getting[j], &getting[j+1]);
            }
        }
    }

    /*累加值*/
    int counter = 0;
    for(i=0; i<size[0]; i++){
        counter = counter + getting[i];
    }
    totalNum[0] = counter;


    /*回傳*/
    for(i=0; i<size[0]; i++){
        send(csock, &getting[i], sizeof(getting[i]), 0);
    }

     puts("\n\n");

    /*output testing*/
    for(i=0; i<size[0]; i++){
        printf(" %d \n", getting[i]);
    }
    
    /*totalNum 回傳*/
    send(csock, &totalNum[0], sizeof(totalNum[0]), 0);


    close(csock);
    close(sock);
}

