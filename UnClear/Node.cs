using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//基底Node的產生方法

public class Map_Management : MonoBehaviour {

    [Header("Settings")]
    public GameObject Node; //Prefabs Node， Node實體的接口
    public GameObject Parent_Node;  //父類物件接口

    public float OffsetNodePos; //為每個Node建立一個等量差值，避免重疊
    static public int MapWidth = 5;     //*被Iterm腳本調用
    static public int MapHeight = 5;    //*被Iterm腳本調用
    static public GameObject[,] NodeArr;  //Node 陣列 *被Iterm腳本調用

    private void Start() {

        NodeArr = new GameObject[MapWidth, MapHeight];

        for(int y=0; y<MapHeight; y++) {
            for(int x=0; x<MapWidth; x++) {
                Vector2 NodePos = new Vector2(transform.position.x + OffsetNodePos * x, transform.position.y + OffsetNodePos * y);  //為每一個Node產生一個新座標，避免重疊。

                GameObject Child_Node = Instantiate(Node, NodePos, transform.rotation) as GameObject;   //將新產生的Node物件 賦予給Child物件
                Child_Node.transform.parent = Parent_Node.transform;    //將Child物件 歸類為 Parent_Node物件的 子物件

                NodeArr[x, y] = Child_Node; //將Child物件存放到NodeArr陣列中
                //Debug.Log("NodeArr["+ x + "," + y + "] :  " + NodeArr[x,y]);    //debug NodeArr陣列
            }
        }

    }

}
