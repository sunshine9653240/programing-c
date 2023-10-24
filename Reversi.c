#include <stdio.h>
#define space 0 //空白
#define white 1 //白棋
#define black 2 //黑棋

//----------------------------------------------------------------未完成巢狀迴圈

int chess[8][8]={ //棋盤
    {1,2,0,2,1,1,0,2},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,2,1,0,0,0},
    {0,0,0,1,2,0,0,0},
    {0,0,2,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}};

int nowcolor = black;//將要落子的顏色 //黑先落子
int i; //迴圈用
int yes_or_no(int,int); //先定義函式

int main() {
    int newX, newY;
    int yesno = 0;
    scanf("%d%d",&newX,&newY);//掃描要落子的位置
    scanf("%d",&nowcolor);//掃描顏色

    if (newX>7||newX<0||newY>7||newY<0){
        printf("不可落子");
        return 0;
    }

    if (chess[newY][newX]==space){
        yesno = yes_or_no(newY, newX);//呼叫函式 檢查當下要落子的位置是否可行
        printf("空白\n");
    }
    else if (chess[newY][newX]==black){
        printf("黑\n");
    }
    else{ 
        printf("白\n");
    }

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
    int Ltemp=0,Rtemp=0,Utemp=0,Dtemp=0,LUtemp=0,LDtemp=0,RUtemp=0,RDtemp=0;

    i=0;
    while(1){
        i++;
        if (x-i<0||chess[y][x-1]==space)
            break;
        if (chess[y][x-i]==nowcolor)
            Ltemp=1;
    }
    if(chess[y][x-1]==nowcolor) //若當前落子位置左邊一顆為當前落子顏色 則以左邊來看無法落子
        Ltemp=0;

    i=0;
    while(1){
        i++;
        if (x+i>7||chess[y][x+1]==space)
            break;
        if (chess[y][x+i]==nowcolor)
            Ltemp=1;
    }
    if(chess[y][x+1]==nowcolor) 
        Rtemp=0;

    i=0;
    while(1){//上
        i++;
        if (y-i<0||chess[y-i][x]==space)
            break;
        if (chess[y-i][x]==nowcolor)
            Ltemp=1;
    }
    if(chess[y-1][x]==nowcolor) 
        Utemp=0; 
    
    i=0;
    while(1){//下
        i++;
        if (y+i>7||chess[y+i][x]==space)
            break;
        if (chess[y+i][x]==nowcolor)
            Ltemp=1;
    }
    if(chess[y+1][x]==nowcolor) 
        Dtemp=0;

    i=0;
    while(1){
        i++;
        if (x+i>7||y+i>7||chess[y+i][x+1]==space)
            break;
        if (chess[y+i][x+i]==nowcolor){
            RDtemp=1;
            break;
        }
    }
    if(chess[y+1][x+1]==nowcolor) 
        RDtemp=0;
    
    i=0;
    while(1){
        i++;
        if (x+i>7||y-i<0||chess[y-i][x+1]==space)
            break;
        if (chess[y-i][x+i]==nowcolor){
            RUtemp=1;
            break;
        }
    }
    if(chess[y-1][x+1]==nowcolor) 
        RUtemp=0;
    
    i=0;
    while(1){
        i++;
        if (x-i<0||y+i>7||chess[y+i][x-1]==space)
            break;
        if (chess[y+i][x-i]==nowcolor){
            LDtemp=1;
            break;
        }
    }
    if(chess[y+1][x-1]==nowcolor) 
        LDtemp=0;
    
    i=0;
    while(1){
        i++;
        if (x-i<0||y-i<0||chess[y-i][x-1]==space)
            break;
        if (chess[y-i][x-i]==nowcolor){
            LUtemp=1;
            break;
        }
    }
    if(chess[y-1][x-1]==nowcolor) 
        LUtemp=0;
    


    if (Ltemp+Rtemp+Utemp+Dtemp+LUtemp+LDtemp+RUtemp+RDtemp==0){
        return 0;
    }else{
        return 1; 
    }
    
}
