#include<iostream> 
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int arr_t[1000];
int limitMoney[1000];
int arr[1000];

void merge(int left, int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j])
            arr_t[k++] = arr[i++];
        else
            arr_t[k++] = arr[j++];
    }

    int r = ((i > mid) ? j : i);

    while(k<=right)
        arr_t[k++] = arr[r++];

    for(int idx=left;idx<=right;idx++) 
        arr[idx] = arr_t[idx];
    
}

void merge_sort(int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, right);
    }
    return;
}

void calcBudget(int budget, int n) {
    int b = budget;
    int i;
    int temp;
    for(i=0; i<n; i++) {
        b = b-(arr[i]);
        temp = n-i;
        temp = temp - 1;
        if(temp <= 0) return;

        limitMoney[i] = b/temp;
    }
    return;
}

int maxLimit(int n, int& max) {
    int idx = 0;
    max = 0;
    for(int i=0;i<n;i++) {
        if(max < limitMoney[i]) {
            max = limitMoney[i];
            idx = i;
        }
    }
    return idx;
}


int main() {
    int budget, teams;
    int limitMoney_ans;
    int sum = 0;
    int i,j;


    scanf("%d %d", &budget, &teams);
    
    for(int k=0; k<teams; k++) {
        arr_t[k] = 0;
        limitMoney[k] = 0;
        arr[k] = 0;
    }

    cout << endl << "input request money!" << endl;
    for(i=0;i<teams;i++) {
        int money;
        scanf("%d", &money);
        arr[i] = money;
        sum += arr[i];
    }
    cout << "complete input!" << endl; 
    cout << endl;
    for(i=0;i<teams;i++) {
        printf("%d, ", arr[i]);
    }
    cout << endl;


    merge_sort(0, teams-1);


    cout << endl;
    for(i=0;i<teams;i++) {
        printf("%d, ", arr[i]);
    }
    cout << endl;

    calcBudget(budget, teams);
    int max = 0;
    int maxIdx = maxLimit(teams, max);
    // for(i=0;i<teams;i++) {
    //     printf("(%d: %d), ", i, limitMoney[i]);
    // }

    printf("(On the basis of sorted state) Except for the first %d teams, give the others %d won.\n", (maxIdx + 1), max);










    return 0;
}