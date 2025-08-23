#include <stdio.h>

int lower (int arr[], int n, int taget){
    int left = 0, right = n;
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    while (left < right){
        if (arr[mid] < taget) left = mid + 1;
        else right = mid;
    }
    return left;
}

int upper (int arr[], int n, int taget){
    int left = 0, right = n;
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    while (left < right){
        if (arr[mid] <= taget) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main()
{
    int n, taget; scanf("%d%d", &n, &taget);
    int arr[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    lower(arr, n, taget);
    upper(arr, n, taget);
    
    int count = upper - lower;
    
    printf("%d", count);

    return 0;
}
