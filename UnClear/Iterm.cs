using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Iterm : MonoBehaviour {

    public float distanceOffset;

    float distance;
    float Layerdistance = 6f;

    private Vector3 objPosition;
    private GameObject GridT;

    public GameObject[,] Node;
    private int MapWidth;
    private int MapHeight;

    private void Start() {
        Node = Map_Management.NodeArr;
        MapWidth = Map_Management.MapWidth;
        MapHeight = Map_Management.MapHeight;
    }

    private void OnMouseDrag() {
        Vector3 mPos = new Vector3(Input.mousePosition.x , Input.mousePosition.y , Layerdistance);
        objPosition = Camera.main.ScreenToWorldPoint(mPos);
        transform.position = objPosition;   //實時移動效果
    }

    private void OnMouseUp() {
        int MiniX = 0;
        int MiniY = 0;
        float HoldMini = 100;

        /*遍歷計算Iterm與哪個Node最近*/
        for (int y = 0; y < MapHeight; y++) {
            for (int x = 0; x < MapWidth; x++) {

                Vector2 miniDistance = Node[x, y].transform.position;
                distance = Vector3.Distance(objPosition, miniDistance);
                if (distance < HoldMini) {
                    HoldMini = distance;
                    MiniX = x;
                    MiniY = y;
                }

            }
        }

        //Debug.Log("Mini Distance is Node[" + MiniX + "," + MiniY + "]");

        if (HoldMini < 4.2f) {
            transform.position = new Vector3(Node[MiniX, MiniY].transform.position.x, Node[MiniX, MiniY].transform.position.y, -1 * Layerdistance);
        }

    }
}