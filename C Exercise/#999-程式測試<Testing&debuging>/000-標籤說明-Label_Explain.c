//
//#999-標籤說明<Label_Explain>.c
//
#include<stdio.h>

int main(){
    
    printf(
            " Label   Explain\n"
            "------------------------------------------\n"
            " Dxx-    DeBug\n"      //有錯誤,某種情況下會死機
            " Exx-    Error\n"      //無法編譯
            " Fxx-    finished\n"   //完成,可以run且暫時沒發現BUG
            " Txx-    Testing\n"    //零時檔案,等待調適
           );
    
    puts("\n\nEnd\n");
    
    return 0;
}
