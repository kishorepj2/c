#include <stdio.h>
#include <conio.h>

int s[10], d, n, set[10], count = 0;
int flag = 0;

void display(int count) {
    printf("\t{");
    for (int i = 0; i < count; i++)
        printf("%d,", set[i]);
    printf("}\n");
}

void subset(int sum, int i) {
    if (sum == d) {
        flag = 1;
        display(count);
        return;
    }
    if (sum > d || i >= n)
        return;
    
    set[count++] = s[i];
    subset(sum + s[i], i + 1);
    count--;
    
    subset(sum, i + 1);
}

int main() {
    printf("ENTER THE NUMBER OF THE ELEMENTS IN THE SET : ");
    scanf("%d", &n);
    printf("ENTER THE SET OF VALUES : ");

    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    printf("ENTER THE SUM : ");
    scanf("%d", &d);

    printf("THE PROGRAM OUTPUT IS:\n");
    subset(0, 0);

    if (flag == 0)
        printf("There is no solution\n");

    return 0;
}
