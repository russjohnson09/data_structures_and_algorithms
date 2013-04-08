//http://compprog.wordpress.com/2007/11/15/all-sources-shortest-path-the-floyd-warshall-algorithm/
#include <stdio.h>
 
int n; /* Then number of nodes */
int dist[16][16]; /* dist[i][j] is the length of the edge between i and j if
            it exists, or 0 if it does not */
 
void printDist() {
    int i, j;
    printf("    ");
    for (i = 0; i < n; ++i)
        printf("%4c", 'A' + i);
    printf("\n");
    for (i = 0; i < n; ++i) {
        printf("%4c", 'A' + i);
        for (j = 0; j < n; ++j)
            printf("%4d", dist[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
/*
    floyd_warshall()
 
    after calling this function dist[i][j] will the the minimum distance
    between i and j if it exists (i.e. if there's a path between i and j)
    or 0, otherwise
*/
void floyd_warshall() {
    int i, j, k;
    for (k = 0; k < n; ++k) {
        printDist();
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                /* If i and j are different nodes and if
                    the paths between i and k and between
                    k and j exist, do */
                if ((dist[i][k] * dist[k][j] != 0) && (i != j))
                    /* See if you can't get a shorter path
                        between i and j by interspacing
                        k somewhere along the current
                        path */
                    if ((dist[i][k] + dist[k][j] < dist[i][j]) ||
                        (dist[i][j] == 0))
                        dist[i][j] = dist[i][k] + dist[k][j];
    }
    printDist();
}
 
int main(int argc, char *argv[]) {
    FILE *fin = fopen("dist.txt", "r");
    fscanf(fin, "%d", &n);
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(fin, "%d", &dist[i][j]);
    fclose(fin);
 
    floyd_warshall();
 
    return 0;
}
