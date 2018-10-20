#include<stdio.h> 

int main(){

    int i,j,k;
    int level = 5;	
    char request; 
    
    scanf("%d %c", &level, &request);

    switch(request){
        case 'A':
            //triangle |>:printf====================================================
            for(i=0; i<level; i++){		
                for(j=0; j<=i; j++){
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        case 'B': 
            //triangle |>:printf====================================================
            for(i=0;i<=level;i++){		
                for(j=i;j<level;j++){
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        case 'C': 
            //triangle |>:printf====================================================
            for(i=0;i<level;i++){
                for(k=0;k<=i;k++){
                    printf(" ");	
                }	
                for(j=i;j<level;j++){
                    printf("*");		
                }
                printf("\n");
            }
            break;

        case 'D': 
            //triangle |>:printf====================================================
            for(i=0;i<level;i++){	
                for(k=i;k<level;k++){
                    printf(" ");	
                    }	
                for(j=0;j<=i;j++){		
                    printf("*");
                }	
                printf("\n");	
            }
            break;

        default: 
            printf("\nPlz input the correct options\n");
            break;    
    }

    puts("End...\n\n");

	return 0;			
}
		

	

