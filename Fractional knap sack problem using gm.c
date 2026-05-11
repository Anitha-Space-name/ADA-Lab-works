#include <stdio.h>

struct Item {
    float profit;
    float weight;
    float ratio;
};

int main() {
    int n, i, j;
    float m, sum = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight for each item:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &item[i].profit, &item[i].weight);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%f", &m);
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float x[n];
    for(i = 0; i < n; i++)
        x[i] = 0.0;

    float rem_cap = m;
    for(i = 0; i < n; i++) {
        if(item[i].weight > rem_cap)
            break;

        x[i] = 1.0;
        rem_cap = rem_cap - item[i].weight;
    }
    if(i < n)
        x[i] = rem_cap / item[i].weight;
    for(i = 0; i < n; i++)
        sum = sum + item[i].profit * x[i];

    printf("Maximum profit = %f\n", sum);

    return 0;
}
