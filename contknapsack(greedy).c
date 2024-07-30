#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    return (ratio2 > ratio1) - (ratio2 < ratio1);
}

void discreteKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    printf("Total value obtained in discrete Knapsack: %.2f\n", totalValue);
}

void continuousKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; ++i) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    printf("Total value obtained in continuous Knapsack: %.2f\n", totalValue);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    discreteKnapsack(items, n, capacity);
    continuousKnapsack(items, n, capacity);

    return 0;
}
