#include <stdio.h>
#include <iostream>

using namespace std;

int d[7][7];
int p[7][7];
int n = 7;

void floyd() {
    int i, j, k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j] = k;
                }
}

void printPath (int i, int j){
    int inter = p[i][j];
    if (d[i][j] > 900){
        printf("NA");
    }
    if (inter == -1){
        cout << char(i + 'A') << '-' << char(j + 'A');
    }
    else{
        printPath(i, inter);
        cout << ',';
        printPath(inter, j);
    }
}


void printMatrix() {
    int i, j;
    for ( i = 0; i < n; ++i){
        printf("\n");
        for(j=0;j<n;++j)
            printf(" %d ", d[i][j]);
    }
    printf("\n\n");
    for ( i = 0; i < n; ++i)
        for(j=0;j<n;++j)
            printf(" %d ", d[i][j]);


}

void print() {
    int i, j;
    for (i=0; i<7; ++i){
        cout << "from " << char(i+'A') << '\n';
        for (j=0; j<7; ++j){
            if (j != i){
                cout << "to " << char(j+'A') << ": ";
                if (d[i][j] < 900){
                        cout << "to " << char(j+'A');
                        cout << " " << d[i][j] << " via ";
                        printPath(i,j);
                        cout << '\n';
                }
                else
                    cout << "<UNREACHABLE>\n";
            }

        }

    }
}

int main(int argc, char *argv[]) {
    FILE *fin = fopen("dist.txt", "r");
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(fin, "%d", &d[i][j]);

    fclose(fin);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            p[i][j] = -1;
 
    floyd();
    print();

    fin = fopen("dist2.txt", "r");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(fin, "%d", &d[i][j]);

    fclose(fin);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            p[i][j] = -1;

    floyd();
    print();
    return 0;
}
