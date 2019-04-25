// 編號：19-0425N0v1L1_Array-Exercise_For.c

// 程式類別：C語言
// 基礎題：陣列練習 ( 難度 ** )
// 題目：陣列-地圖編碼

// 時間：NULL ( 不限 )	//最佳 1s內
// 內存大小：128MB

// 1、創建一個10*10的整數型二維陣列。 e.g: int Map[10][10];
// 2、初始化Map陣列的內容（初始化為 0 ）
// 3、寫一個福程式輸出Map的內容，並且每輸出10個就換一行。
//      e.g: Map[10][10]:
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
//                  0 0 0 0 0 0 0 0 0 0
// 4、將Map最外圍的內容通過陣列運算改為 1。 e.g: if(x==0){Map[x][y] = 1; }
//      *只能夠通過陣列運算修改內容，不能夠針對性陣列編號修改。
//          陣列運算修改：例如： if(x==0){Map[x][y] = 1; }
//          陣列編號修改：例如： Map[0][0] = 1; 、 Map[0][1] = 1; 、 ...... 
// 5、輸出經過第四點運算的結果。
//      e.g: Map[10][10]:
//                  1 1 1 1 1 1 1 1 1 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 0 0 0 0 0 0 0 0 1
//                  1 1 1 1 1 1 1 1 1 1    
//
// 延伸挑戰
// 1、通過input來決定Map的大小
// 2、除邊框內容為 1, 內部的內容隨機產生1 或 0
//      e.g: Map[10][10]:
//                  1 1 1 1 1 1 1 1 1 1
//                  1 1 1 0 0 1 1 1 1 1
//                  1 0 0 1 0 0 0 0 0 1
//                  1 0 1 0 1 0 1 1 0 1
//                  1 1 1 0 0 0 0 1 1 1
//                  1 0 1 0 1 0 0 0 1 1
//                  1 0 1 1 0 1 0 0 0 1
//                  1 1 0 1 0 1 1 0 0 1
//                  1 0 0 0 1 0 1 0 1 1
//                  1 1 1 1 1 1 1 1 1 1      