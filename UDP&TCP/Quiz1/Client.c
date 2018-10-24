//
//  Lab 1_HW_Client.c
//
//  001-字元與字串-Char_And_String.c
//  Version 2
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

int i;

int main(void) {
    
    struct sockaddr_in server;
    int sock,readSize;

    /*輸入ip 和 port*/
    char ipNum[15];
    int portNum;
    printf("Plz enter the ip number:\n");
    scanf("%s",ipNum);
    printf("Plz enter the port number:\n");
    scanf("%d", &portNum);

    /*通訊設定——建立通訊協定*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(ipNum);
    server.sin_port = htons(portNum);


    
    int counter = 0;
    int getting[256];
    int buf[256];
    
    puts("\n\n");
    printf("Plz intput the data:\n");

    
    int holding[1];
    while(scanf("%d", holding) != EOF){
        buf[counter] = holding[0];
        counter++;
    }   

    /*發送資料總數*/
    int size[1];
    size[0] = counter;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    send(sock, size, sizeof(size), 0);
    printf("Send Size: %d \n",size[0]);

    puts("\n\n");

    // for(i=0; i<size[0]; i++){
    //     printf("buf: %d \n", buf[i]);
    // }

    /*發送資料*/
    for(i=0; i<size[0]; i++){
        sock = socket(PF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&server, sizeof(server));

        send(sock, &buf[i], sizeof(buf[i]), 0);
        printf("Send Message: %d \n", buf[i]);
    }

    puts("\n\n");

    /*收到server排序後的結果 輸出*/
    printf("Sort:");
    for(i=0; i<size[0]; i++){
        readSize = recv(sock, &getting[i], sizeof(getting[i]), 0);
        printf(" %d ", getting[i]);
    }
    
    puts("\n");

    /*接收totalNum*/
    readSize = recv(sock, &getting[6], sizeof(getting[6]), 0);
    printf("total: %d ", getting[6]);


    puts("\n\n");

}
