#include <stdio.h>
#define SPACE 0 //空白
#define WHITE 1 //白棋
#define BLACK 2 //黑棋

//----------------------------------------------------------------未完成與電腦下 目前是自己跟自己下

int chess[8][8]={ //棋盤
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}};

int Ltemp=0,Rtemp=0,Utemp=0,Dtemp=0,LUtemp=0,LDtemp=0,RUtemp=0,RDtemp=0;
int total=0,maxX=0,maxY=0; //紀錄可翻幾顆子 電腦下棋用 
int newX, newY;
int ai_or_user=1;//user 1 ai 0
//先定義函式
int yes_or_no(int,int,int); 
int scanboard(int);
void reverse(int,int,int);
void printchess();
void AIturn(int);
void wherecan(int);

int main() {
    int i=0;
    int yesno = 0;
    int nowcolor=0;
    printf("要落子的顏色(1=白,2=黑):");
    scanf("%d",&nowcolor);//掃描顏色
    int firstcolor = nowcolor;
    while(scanboard(nowcolor)){
        printchess();
        
        if (ai_or_user==1){//是誰在下棋
            wherecan(nowcolor);//檢查何處可落子 讀入落子位置
            yesno = yes_or_no(newY, newX, nowcolor);//呼叫函式 檢查當下要落子的位置是否可行
            if (yesno == 1){
                printf("可以落子 要落子嗎(1 or 0):");
                scanf("%d",&yesno);
                if(yesno == 1){
                    reverse(newY, newX, nowcolor);//翻轉 
                    nowcolor=nowcolor%2+1;
                }
            }
            ai_or_user = 0;

        }else if (ai_or_user==0){
            AIturn(nowcolor);
            nowcolor=nowcolor%2+1;
            ai_or_user = 1;
        }
        
    }
    printchess();//結束時的棋盤
    int user=0, ai=0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (chess[i][j]==firstcolor)
                user++;
            if (chess[i][j]==firstcolor%2+1) 
                ai++;
        }
    }
    if(ai>user)
        printf("你輸了，輸%d子",ai-user);
    if(ai<user)
        printf("你贏了，贏%d子",user-ai);
    if(ai==user)
        printf("此局平手");

    return 0;
}


int yes_or_no(int y,int x,int nowcolor) {//檢測是否可以落子
    //printf("yes_or_no(%d,%d,%d)\n", y,x,nowcolor);
    Ltemp=0,Rtemp=0,Utemp=0,Dtemp=0,LUtemp=0,LDtemp=0,RUtemp=0,RDtemp=0;
    int i; //迴圈用
    i=0;
    
    while(1){//左
        i++;
        if (x-i<0||chess[y][x-i]==SPACE){
            Ltemp=0;break;}
        if (chess[y][x-i]==(nowcolor)){
            break;}
        if (chess[y][x-i]==nowcolor%2+1){
            Ltemp++;}
    }
    if(chess[y][x-1]==nowcolor||chess[y][x-1]==SPACE) //若當前落子位置左邊一顆為當前落子顏色或空白 則以左邊來看無法落子
        Ltemp=0;
    
    i=0;
    while(1){//右
        i++;
        if (x+i>7||chess[y][x+i]==SPACE){
            Rtemp=0;break;}
        if (chess[y][x+i]==nowcolor)
            break;
        if (chess[y][x+i]==nowcolor%2+1)
            Rtemp++;
    }
    if(chess[y][x+1]==nowcolor||chess[y][x+1]==SPACE) 
        Rtemp=0;

    i=0;
    while(1){//上
        i++;
        if (y-i<0||chess[y-i][x]==SPACE){
            Utemp=0;break;}
        if (chess[y-i][x]==nowcolor)
            break;
        if (chess[y-i][x]==nowcolor%2+1)
            Utemp++;
    }
    if(chess[y-1][x]==nowcolor||chess[y-1][x]==SPACE) 
        Utemp=0; 
    
    i=0;
    while(1){//下
        i++;
        if (y+i>7||chess[y+i][x]==SPACE){
            Dtemp=0;break;}
        if (chess[y+i][x]==nowcolor)
            break;
        if (chess[y+i][x]==nowcolor%2+1)
            Dtemp++;
    }
    if(chess[y+1][x]==nowcolor||chess[y+1][x]==SPACE) 
        Dtemp=0;

    i=0;
    while(1){//右下
        i++;
        if (x+i>7||y+i>7||chess[y+i][x+i]==SPACE){
            RDtemp=0;break;}
        if (chess[y+i][x+i]==nowcolor)
            break;
        if (chess[y+i][x+i]==nowcolor%2+1){
            RDtemp++;
        }
    }
    if(chess[y+1][x+1]==nowcolor||chess[y+1][x+1]==SPACE) 
        RDtemp=0;
    
    i=0;
    while(1){//右上
        i++;
        if (x+i>7||y-i<0||chess[y-i][x+i]==SPACE){
            RUtemp=0;break;}
        if (chess[y-i][x+i]==nowcolor)
            break;
        if (chess[y-i][x+i]==nowcolor%2+1){
            RUtemp++;
        }
    }
    if(chess[y-1][x+1]==nowcolor||chess[y-1][x+1]==SPACE) 
        RUtemp=0;
    
    i=0;
    while(1){//左下
        i++;
        if (x-i<0||y+i>7||chess[y+i][x-i]==SPACE){
            LDtemp=0;break;}
        if (chess[y+i][x-i]==nowcolor)
            break;
        if (chess[y+i][x-i]==nowcolor%2+1){
            LDtemp++;
        }
    }
    if(chess[y+1][x-1]==nowcolor||chess[y+1][x-1]==SPACE) 
        LDtemp=0;
    
    i=0;
    while(1){//左上
        i++;
        if (x-i<0||y-i<0||chess[y-i][x-i]==SPACE){
            LUtemp=0;break;}
        if (chess[y-i][x-i]==nowcolor)
            break;
        if (chess[y-i][x-i]==nowcolor%2+1){
            LUtemp++;
        }
    }
    if(chess[y-1][x-1]==nowcolor||chess[y-1][x-1]==SPACE) 
        LUtemp=0;
    
    if (total<Ltemp+Rtemp+Utemp+Dtemp+LUtemp+LDtemp+RUtemp+RDtemp){
        total=Ltemp+Rtemp+Utemp+Dtemp+LUtemp+LDtemp+RUtemp+RDtemp;
        maxX=x,maxY=y;
    }
    if (Ltemp+Rtemp+Utemp+Dtemp+LUtemp+LDtemp+RUtemp+RDtemp==0){
        return 0;
    }else{
        return 1;
    }
    
}

void reverse(int y,int x,int nowcolor){//翻轉棋子
    int i=0;
    chess[y][x]=nowcolor;
    yes_or_no(y,x,nowcolor);
    if (Ltemp!=0){
        while(1){
            i++;
            if (chess[y][x-i]==nowcolor)
                break;
            if (chess[y][x-i]!=nowcolor)
                chess[y][x-i]=nowcolor;
        }
    }
    i = 0;
    if (Rtemp!=0){
        while(1){
            i++;
            if (chess[y][x+i]==nowcolor)
                break;
            if (chess[y][x+i]!=nowcolor)
                chess[y][x+i]=nowcolor;
        }
    }
    i = 0;
    if (Utemp!=0){
        while(1){
            i++;
            if (chess[y-i][x]==nowcolor)
                break;
            if (chess[y-i][x]!=nowcolor)
                chess[y-i][x]=nowcolor;
        }
    }
    i = 0;
    if (Dtemp!=0){
        while(1){
            i++;
            if (chess[y+i][x]==nowcolor)
                break;
            if (chess[y+i][x]!=nowcolor)
                chess[y+i][x]=nowcolor;
        }
    }
    i = 0;
    if (RDtemp!=0){
        while(1){
            i++;
            if (chess[y+i][x+i]==nowcolor)
                break;
            if (chess[y+i][x+i]!=nowcolor)
                chess[y+i][x+i]=nowcolor;
        }
    }
    i = 0;
    if (RUtemp!=0){
        while(1){
            i++;
            if (chess[y-i][x+i]==nowcolor)
                break;
            if (chess[y-i][x+i]!=nowcolor)
                chess[y-i][x+i]=nowcolor;
        }
    }
    i = 0;
    if (LDtemp!=0){
        while(1){
            i++;
            if (chess[y+i][x-i]==nowcolor)
                break;
            if (chess[y+i][x-i]!=nowcolor)
                chess[y+i][x-i]=nowcolor;
        }
    }
    i = 0;
    if (LUtemp!=0){
        while(1){
            i++;
            if (chess[y-i][x-i]==nowcolor)
                break;
            if (chess[y-i][x-i]!=nowcolor)
                chess[y-i][x-i]=nowcolor;
        }
    }
}

void printchess(){//印出棋盤
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%d ",chess[i][j]);
        }
        printf("\n");
    }
}

int scanboard(int nowcolor){//檢查棋盤是否還有可落子的地方
    for (int i=1; i<3; i++) {
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                if(chess[k][j]!=0)
                    continue;
                if(yes_or_no(k,j,i)!=0){
                    if (i!=nowcolor)
                        ai_or_user= !ai_or_user;
                    return 1;
                }
            }
        }
    }
    return 0;
}


void wherecan(int nowcolor){//印出白子黑子可下位置 並讀入落子位置
    for(int i=1;i<3;i++){
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
                if(yes_or_no(k,j,nowcolor)!=0)
                    printf("(%d,%d)",j,k);
            }
        }
    }
    printf("\n換您落子了 請落子(x,y):");
    scanf("%d%d",&newX,&newY);//掃描要落子的位置

    if (newX>7||newX<0||newY>7||newY<0){
        printf("\n不可落子");
        return;
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
}

void AIturn(int nowcolor){//電腦下 未完成
    maxX=0,maxY=0,total=0;
    for(int j=0;j<8;j++){
        for(int k=0;k<8;k++){
            if(chess[k][j]!=0)
                continue;
            if(yes_or_no(k,j,nowcolor)!=0)
                printf("(%d,%d)",j,k);
        }
    }
    reverse(maxY,maxX,nowcolor);
    printf("電腦下(%d,%d),翻轉了%d個子\n",maxX,maxY,total);
    
}
