#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Warshall's algorithm to find transitive closure
void warshall(int p[10][10], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
            }
        }
    }
}

int main() {
    int p[10][10] = {0}, n, e, u, v, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter the end vertices of edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        p[u][v] = 1;
    }

    printf("\nMatrix of input data:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    warshall(p, n);

    printf("\nTransitive closure:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}
