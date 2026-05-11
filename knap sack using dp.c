#include<stdio.h>

struct Item{
    int weight;
    int profit;
    };

int max(int a,int b){
    return(a>b)?a:b;
    }

int main(){
    int n,W;
    printf("Enter number of items:");
    scanf("%d",&n);

    struct Item items[n];
    printf("Enter weight and profit for each item:\n");
    for(int i=0;i<n;i++){
        printf("Item %d (weight profit):",i+1);
        scanf("%d%d",&items[i].weight,&items[i].profit);
    }

    printf("Enter knapsack capacity:");
    scanf("%d",&W);

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(items[i-1].weight<=j)
                dp[i][j] = max(dp[i-1][j],items[i-1].profit + dp[i-1][j - items[i-1].weight]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    printf("\n Maximum Profit=%d\n",dp[n][W]);
    return 0;
}
