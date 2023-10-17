#include <stdio.h>

int main(){
    int x = 1, y = 1;
    for(int i = 1; i <= 81; i ++){
        printf("%d x %d = %2d", x, y, x * y);
        if(i % 27 == 0){
            x ++;
            y = 1;
            printf("\n\n");
        }
        else if(i % 3 == 0){
            x = x - 2;
            y ++;
            printf("\n");
        }
        else{
            x ++;
            printf("  ");
        }
    }
    return 0;
}