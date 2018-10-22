//
//  Lebal 
//
//  000-標籤說明-Label_Explain.c
//  Version 1.0
//	
//  Created by Waylon.Yuen on 16/10/2018.
//  Last modified by Waylon.Yuen on 22/10/2018
//  Copyright © 2018年 Oracragron. All rights reserved.
//
//  說明：X
//  操作：X
//  原理：X
//  優化：X
//

#include<stdio.h>

int main(){
    
    printf(
            " Main Label(Condition) Explain\n"
            "------------------------------------------\n"
            " D   & _Self_Lebal-    DeBug\n"
            /* #可編譯 
                1、未定義行為
                2、資料溢位
                3、輸出資料有誤
                4、不符合預期的行為
                */

            " Err & _Self_Lebal-    Error\n"
            /* #不可編譯
                1、編譯器報錯（檢查C標準：C89、C99 ⋯⋯）
                */

            " F   & _Self_Lebal-    finished\n"
            /* #完成品
                1、暫時沒發現重大的BUG
                2、可持續優化
                3、已知BUG ——> 在可控範圍內且可透過優化解決
                */

            " UnF & _Self_Lebal-    Unfinished\n"
            /* #待完成
                1、未達到預期進度
                2、缺少重要Functions
                */

            " T   & _Self_Lebal-    Testing\n"
            /* #測試
                1、零時檔案
                2、等待調適
                3、Function文檔
                */
            
            " Opt & _Self_Lebal-    Optimizationg\n"
            /* #最佳化 —— ”需優化“標籤
                1、等待優化
                */

           );

    puts("\n");

    printf(
            " Self Label Explain:\n\n"
            " ‘Main_Lebal_’ & ‘#xxx-SSxx-name’\n"
            "---------------------------------------------------------\n"
            " Explain: Condition_#Theme-’Subject&number‘-nameCH-nameEn.Type\n"
            " Example: Opt_002-000-平均值-Average.c\n"
            /* 範例：狀態_主題-‘範疇&編號’-中文名稱-英文名稱.格式
                1、缺省結果：
                    #狀態_‘範疇&編號‘-英文名稱.格式
                */
           );       
    
    puts("\n\nEnd\n");
    
    return 0;
}
