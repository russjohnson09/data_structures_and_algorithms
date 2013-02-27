#include <stdio.h>

int main(){
    
    int value;
    int i;

    int j,k;

    scanf("%d", &i);
    int matrix[i][i];

    for (j = 0; j<i;j++)
        for (k=0;k<i;k++){
            scanf("%d",&value);
            matrix[j][k] = value;
        }

    for (j = 0; j<i;j++){
        for (k=0;k<i;k++)
            printf("%d ",matrix[j][k]);
        printf("\n");
    }

}
