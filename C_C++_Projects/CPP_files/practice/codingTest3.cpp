#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;




typedef struct count {
    char c;
    int count;
} count;


int maxCount(vector<count> list) {
    int len = list.size();
    int max = 0;
    for(int j=0;j<len;j++) {
        if(max < list[j].count)
            max = list[j].count;
    }
    return max;    
}

int maxCount9(vector<count> list) {
    int len = list.size();
    int max = 0;
    for(int i=0;i<len;i++) {
        if(list[i].c == '9' && list[i].count > max) {
            max = list[i].count;
        }
    }
    return max;
}

int maxCount6(vector<count> list) {
int len = list.size();
    int max = 0;
    for(int i=0;i<len;i++) {
        if(list[i].c == '6' && list[i].count > max) {
            max = list[i].count;
        }
    }
    return max;
}


int main() {
    string roomNumber;
    int length, i, j;
    vector<count> cnt;
    
    cin >> roomNumber;

    length = roomNumber.length();
    cnt.assign(length, count());
    

    cout << roomNumber << endl << endl;

    for(i=0;i<length;i++) {
        cnt[i] = count{roomNumber[i], 1};
    }

    for(i=0;i<length;i++) {
        for(j=i+1;j<length;j++) {
            if(cnt[i].c == cnt[j].c) {
                cnt[i].count += 1;
            }
        }
    }

    for(i=0;i<length;i++) 
        printf("'%c' : %d\n", cnt[i].c, cnt[i].count); 

    int max9 = maxCount9(cnt);
    int max6 = maxCount6(cnt);
    int max96 = max9 + max6;

    for(i=0;i<length;i++) {
        if(cnt[i].c == '6' || cnt[i].c == '9') {
            cnt[i].count = max96;
            cnt[i].count = (cnt[i].count + 1) / 2;
        }
    }

    int max = maxCount(cnt);
    cout << "max : " << max << endl;


    return 0;
}