#include <stdio.h>
#define space 0 //空白
#define white 1 //白棋
#define black 2 //黑棋

int chess[8][8]={ //棋盤
    {1,2,0,1,1,1,0,2},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,2,1,0,0,0},
    {0,0,0,1,2,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}};

int nowcolor = black;//將要落子的顏色 //黑先落子
int i,j; //迴圈用
int yes_or_no(int,int); //先定義函式

int main() {
    int newX, newY;
    int yesno = 0;
    scanf("%d%d",&newX,&newY);//掃描要落子的位置
    if (chess[newY][newX]==space)
        yesno = yes_or_no(newY, newX);//呼叫函式 檢查當下要落子的位置是否可行
    
    if (yesno==1){ 
        printf("可以落子");
    }    
    else{
        printf("不可落子");
    }
    return 0;
}

//檢測是否可以落子
int yes_or_no(int y,int x) {
    int Ltemp=0,Rtemp=0,Utemp=0,Dtemp=0;

    for(i=0; i<x-1; i++){ //由左到判斷點
        if (chess[y][i]==nowcolor) //目前位置是否為當前的落子顏色
            Ltemp=1;
        if (chess[y][i]==space) //目前位置是否有棋子 若沒有則要再重新判斷是否可落子
            Ltemp=0;
    }
    if(chess[y][x-1]==nowcolor) //若當前落子位置左邊一顆為當前落子顏色 則以左邊來看無法落子
        Ltemp=0;

    for(i=7; i<x+1; i--){ //由右到判斷點
        if (chess[y][i]==nowcolor)
            Rtemp=1;
        if (chess[y][i]==space)
            Rtemp=0;
    }
    if(chess[y][x+1]==nowcolor) 
        Rtemp=0;

    for(i=0; i<y-1; i++){ //由上到判斷點
        if (chess[i][x]==nowcolor) 
            Utemp=1;
        if (chess[i][x]==space) 
            Utemp=0;
    }
    if(chess[y-1][x]==nowcolor) 
        Utemp=0;
    

    for(i=7; i<y+1; i--){ //由下到判斷點
        if (chess[i][x]==nowcolor) 
            Dtemp=1;
        if (chess[i][x]==space) 
            Dtemp=0;
    }
    if(chess[y+1][x]==nowcolor) 
        Dtemp=0;

    if (Ltemp==0 && Rtemp==0 && Dtemp==0 && Utemp==0){ //
        return 0;
    }else{
        return 1; 
    }
    
}
//tempPos=i;//最後偵測到的當前顏色子的位置