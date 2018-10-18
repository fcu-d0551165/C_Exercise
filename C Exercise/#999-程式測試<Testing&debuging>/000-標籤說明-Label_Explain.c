//
//#999-標籤說明<Label_Explain>.c
//
#include<stdio.h>

int main(){
    
    printf(
            " Label   Explain\n"
            " #Dxx-   DeBug\n"      //有錯誤&調適
            " #Exx-   Error\n"      //無法編譯
            " #Fxx-   finished\n"   //完成
            " #Txx-   Testing\n"    //測試&調適
           );
    
    puts("\n\nEnd\n");
    
    return 0;
}
