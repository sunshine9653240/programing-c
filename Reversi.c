#include <stdio.h>
#define SPACE 0 //空白
#define WHITE 1 //白棋
#define BLACK 2 //黑棋

//----------------------------------------------------------------未完成巢狀迴圈

int chess[8][8]={ //棋盤
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,2,1,0,0,0},
    {0,0,0,1,2,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}};

int Ltemp=0,Rtemp=0,Utemp=0,Dtemp=0,LUtemp=0,LDtemp=0,RUtemp=0,RDtemp=0;
int yes_or_no(int,int); //先定義函式
int scanboard();
void reverse(int,int);
void printchess();
int nowcolor=0;

int main() {
    int i=0;
    while(scanboard()){
        printchess();

        for(i=1;i<3;i++){
            if (i==WHITE){
                printf("白子可下 : ");
                nowcolor = WHITE;
            }
            else if (i==BLACK){
                printf("\n黑子可下 : ");
                nowcolor = BLACK;
            }

            for(int j=0;j<8;j++){
                for(int k=0;k<8;k++){
                    if(chess[k][j]!=0)
                        continue;
                    if(yes_or_no(k,j)!=0)
                        printf("(%d,%d)",j,k);
                }
            }
        }

        int newX, newY;
        int yesno = 0;
        scanf("%d%d",&newX,&newY);//掃描要落子的位置
        scanf("%d",&nowcolor);//掃描顏色

        if (newX>7||newX<0||newY>7||newY<0){
            printf("不可落子");
            return 0;
        }

        if (chess[newY][newX]==SPACE){
            printf("空白\n");
        }
        else if (chess[newY][newX]==BLACK){
            printf("黑\n");
        }
        else{ 
            printf("白\n");
        }
        
        yesno = yes_or_no(newY, newX);//呼叫函式 檢查當下要落子的位置是否可行
        if (yesno == 1){
            printf("可以落子 要落子嗎(1 or 0):");
            reverse(newY, newX);
        }
    }
    return 0;
}
//
//
//檢測是否可以落子
int yes_or_no(int y,int x) {
    
    int i; //迴圈用
    i=0;
    while(1){
        i++;
        if (x-i<0||chess[y][x-i]==SPACE)
            break;
        if (chess[y][x-i]==nowcolor)
            Ltemp=1;
    }
    if(chess[y][x-1]==nowcolor) //若當前落子位置左邊一顆為當前落子顏色 則以左邊來看無法落子
        Ltemp=0;

    i=0;
    while(1){
        i++;
        if (x+i>7||chess[y][x+i]==SPACE)
            break;
        if (chess[y][x+i]==nowcolor)
            Rtemp=1;
    }
    if(chess[y][x+1]==nowcolor) 
        Rtemp=0;

    i=0;
    while(1){//上
        i++;
        if (y-i<0||chess[y-i][x]==SPACE)
            break;
        if (chess[y-i][x]==nowcolor)
            Utemp=1;
    }
    if(chess[y-1][x]==nowcolor) 
        Utemp=0; 
    
    i=0;
    while(1){//下
        i++;
        if (y+i>7||chess[y+i][x]==SPACE)
            break;
        if (chess[y+i][x]==nowcolor)
            Dtemp=1;
    }
    if(chess[y+1][x]==nowcolor) 
        Dtemp=0;

    i=0;
    while(1){
        i++;
        if (x+i>7||y+i>7||chess[y+i][x+i]==SPACE)
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
        if (x+i>7||y-i<0||chess[y-i][x+i]==SPACE)
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
        if (x-i<0||y+i>7||chess[y+i][x-i]==SPACE)
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
        if (x-i<0||y-i<0||chess[y-i][x-i]==SPACE)
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

void reverse(int y,int x){
    int i=0;
    if (Ltemp=1){
        while(1){
            i++;
            if (chess[y][x-i]==nowcolor)
                break;
            if (chess[y][x-i]!=nowcolor)
                chess[y][x-i]=nowcolor%2+1;
        }
    }
    if (Rtemp=1){
        while(1){
            i++;
            if (chess[y][x+i]==nowcolor)
                break;
            if (chess[y][x+i]!=nowcolor)
                chess[y][x+i]=nowcolor%2+1;
        }
    }
    if (Utemp=1){
        while(1){
            i++;
            if (chess[y-i][x]==nowcolor)
                break;
            if (chess[y-i][x]!=nowcolor)
                chess[y-i][x]=nowcolor%2+1;
        }
    }
    if (Dtemp=1){
        while(1){
            i++;
            if (chess[y+i][x]==nowcolor)
                break;
            if (chess[y+i][x]!=nowcolor)
                chess[y+i][x]=nowcolor%2+1;
        }
    }
    if (RDtemp=1){
        while(1){
            i++;
            if (chess[y+i][x+i]==nowcolor)
                break;
            if (chess[y+i][x+i]!=nowcolor)
                chess[y+i][x+i]=nowcolor%2+1;
        }
    }
    if (RUtemp=1){
        while(1){
            i++;
            if (chess[y-i][x+i]==nowcolor)
                break;
            if (chess[y-i][x+i]!=nowcolor)
                chess[y-i][x+i]=nowcolor%2+1;
        }
    }
    if (LDtemp=1){
        while(1){
            i++;
            if (chess[y+i][x-i]==nowcolor)
                break;
            if (chess[y+i][x-i]!=nowcolor)
                chess[y+i][x-i]=nowcolor%2+1;
        }
    }
    if (LUtemp=1){
        while(1){
            i++;
            if (chess[y-i][x-i]==nowcolor)
                break;
            if (chess[y-i][x-i]!=nowcolor)
                chess[y-i][x-i]=nowcolor%2+1;
        }
    }
    printchess();
}

void printchess(){
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%d ",chess[i][j]);
        }
        printf("\n");
    }
}

int scanboard(){
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (chess[i][j]==0)
                return 1;
        }
    }
    return 0;
}