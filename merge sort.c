#include <stdio.h>

struct Array {
    int a[50];
    int n;
};

void merge(struct Array *arr, int l, int m, int h) {
    int i=l, j=m+1, k=l, b[50];

    while(i<=m && j<=h) {
        if(arr->a[i] < arr->a[j])
            b[k++] = arr->a[i++];
        else
            b[k++] = arr->a[j++];
    }

    while(i<=m) b[k++] = arr->a[i++];
    while(j<=h) b[k++] = arr->a[j++];

    for(i=l;i<=h;i++)
        arr->a[i] = b[i];
}

void mergesort(struct Array *arr, int l, int h) {
    if(l<h) {
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int main() {
    struct Array arr;
    int i;

    printf("Enter number of elements: ");
    scanf("%d",&arr.n);

    printf("Enter elements:\n");
    for(i=0;i<arr.n;i++)
        scanf("%d",&arr.a[i]);

    mergesort(&arr,0,arr.n-1);

    printf("Sorted array:\n");
    for(i=0;i<arr.n;i++)
        printf("%d ",arr.a[i]);

    return 0;
}
