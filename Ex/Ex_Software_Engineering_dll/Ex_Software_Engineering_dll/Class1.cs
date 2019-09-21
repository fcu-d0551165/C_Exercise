using System;
using System.IO;
using System.Net;
using System.Text;

namespace Ex_Software_Engineering_dll {

    public class Util {
        
        private Random random;

        /// <summary>
        /// 隨機產生整數(範圍 = int：可設定上下界限)
        /// </summary>
        /// <param name="LowerBound">上限(包含最小隨機數)| 非空</param>
        /// <param name="UpperBound">下限(包含最大隨機數)| 非空</param>
        /// <returns>回傳int結果</returns>
        public int RandomNum(int LowerBound, int UpperBound) {
            random = new Random();
            int Num = random.Next(LowerBound, UpperBound);
            return Num;
        }

        /// <summary>
        /// 隨機產生字串KEY = password
        /// </summary>
        /// <param name="Length">Key長度</param>
        /// <param name="Reference">參考來源(內容參考來源)</param>
        /// <returns>回傳String or String[]</returns>
        public string RandomKey(int Length, char[] Reference) {

            string[] ArrayKEY = { "N/A" };

            if (Length <= 0) {
                ArrayKEY[0] = "Error";
                return ArrayKEY[0];
            }

            string KEY = string.Empty;
            random = new Random();
            for (int i = 0; i < Length; i++) {
                KEY += Reference[random.Next(62)].ToString();
            }

            //轉換成非陣列String

            ArrayKEY[0] = KEY;
            string Key = ArrayKEY[0];

            return Key;
        }

        /// <summary>
        /// 文件讀寫
        /// </summary>
        /// <param name="srcPath">文件路徑</param>
        /// <param name="Save_Byte">需寫入的內容 | 非寫入模式 可空null</param>
        /// <param name="DataSize">內容長度</param>
        /// <param name="fileMode">文件處理模式</param>
        /// <param name="fileAccess">文件處理方法</param>
        /// <param name="Offset">讀寫偏差值</param>
        /// <param name="ReadPosition">讀寫起點</param>
        /// <returns>回傳讀取到的資料(寫入資料則沒有回傳值)</returns>
        public byte[] FileSet(string srcPath, byte[] Save_Byte, int DataSize, FileMode fileMode, FileAccess fileAccess, int Offset, long ReadPosition) {

            byte[] data_Byte = new byte[DataSize];   //創建容器

            if (Save_Byte != null) data_Byte = Save_Byte;

            if (File.Exists(srcPath)) {
                using (FileStream fileStream = new FileStream(srcPath, fileMode, fileAccess)) {
                    fileStream.Position = ReadPosition;
                    if (fileAccess == FileAccess.Read) fileStream.Read(data_Byte, Offset, data_Byte.Length);
                    if (fileAccess == FileAccess.Write) fileStream.Write(data_Byte, Offset, data_Byte.Length);
                }
            } else Console.WriteLine($"#  Warning: Cannot found the Path\t Info [Path: {srcPath} ]");
            return data_Byte;
        }


    }

    public class Setup {

        public char[] constant = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };

        public char[] GetKey { get; set; }

        public virtual void Key() {

        }

        public void SetKey(char[] Key) => GetKey = Key;
        

    }

    public class ToByte {

        public byte[] String(string[] Data) {

            //計算MsgBody的長度
            int DataBodyLenght = 0;

            for (int i = 0; i < Data.Length; i++) {
                if (Data[i] == "")
                    break;
                DataBodyLenght += Encoding.UTF8.GetBytes(Data[i]).Length;   //計算每個字串組中的長度總和 e.g: string[3] Data = {"Hello", "Welcome", "Hi"}; 分別為： 5 + 7 + 2 = DataBodyLenght;
            }

            //定義封包體的字節數組
            byte[] data_Byte = new byte[DataBodyLenght + (Data.Length * 4)];    //保留每個字串組前4Bytes，以保存每組的字串長度。

            //紀錄存入消息體數組的字節數目前的索引位置
            int TempIndex = 0;
            for (int i = 0; i < Data.Length; i++) {

                //單個消息，單個字串組
                byte[] Temp_Bytes = Encoding.UTF8.GetBytes(Data[i]); //將第i個字串組取出

                BitConverter.GetBytes(IPAddress.HostToNetworkOrder(Temp_Bytes.Length)).CopyTo(data_Byte, TempIndex);    //計算第i個字組長度存放到TempIndex中
                TempIndex += 4; //右邊往左邊存， 1個int = 4bytes
                Temp_Bytes.CopyTo(data_Byte, TempIndex);    //存入
                TempIndex += Temp_Bytes.Length; //加上字串組長度，索引至新位置；準備存第二組字串組。
            }
            return data_Byte;
        }
    }
    
}

