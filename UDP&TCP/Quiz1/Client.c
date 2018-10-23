//
//	Lebal Undefind
//
//  Lab 1_HW_Client.c
//	Version 2.2 
//	
//  Created by Waylon.Yuen on 24/9/2018
//	Last modified by Waylon.Yuen on 19/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//	操作：
//	優化：
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void) {
    
    struct sockaddr_in server;
    int sock,readSize;

    int getting[256];
    int totalNum[1];
    int DataCounter[2];

    char ipNum[15];
    int portNum[4];
    char buf[]="TCP TEST";

    /*通訊設定——建立通訊協定*/
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);

    /*輸入ip 和 port*/
    printf("Plz enter the ip number:\n");
    scanf("%s",ipNum);
    printf("Plz enter the port number:\n");
    scanf("%d",portNum);

    int i;
    int counter = 0;

    
    puts("\n\n");
    printf("Plz intput the data:\n");

    for(i=0; i<5; i++){

        scanf("%s",buf);

        sock = socket(PF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&server, sizeof(server));
        send(sock, buf, sizeof(buf), 0);
        printf("Send Message: %s \n",buf);
        counter = counter + 1;
    }   

    puts("\n\n");

    /*收到server排序後的結果 輸出*/
    printf("Sort:");
    for(i=0; i<5; i++){
        readSize = recv(sock, &getting[i], sizeof(getting[i]), 0);
        printf(" %d ", getting[i]);
    }
    
    puts("\n");

    /*接收totalNum*/
    readSize = recv(sock, &getting[6], sizeof(getting[6]), 0);
    printf("total: %d ", getting[6]);


    puts("\n\n");

}
