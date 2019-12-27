#include<iostream>
#include<map>
#include<string>

using namespace std;

int maxCount(map<char, int> m) {
    int max = 0;
    for(auto e : m) {
        if( max < e.second )
            max = e.second;
    }
    return max;
}

int main() {
    multimap<char, int> count;
    map<char, int> num;
    string roomNumber;
    int len;
    int cnt[100];

    cin >> roomNumber;
    len = roomNumber.length();

    for(int i=0; i<len; i++) {
        count.insert(make_pair(roomNumber[i], 0));
        printf("the value of i : %d\n", i);
    }
    
    for(auto iter = count.begin(); iter != count.end(); ++iter) {
        //printf("%c : %d\n", (*iter).first, count.count((*iter).first));
        num.insert(make_pair((*iter).first, count.count((*iter).first) ));
    }
    
    int count9 = count.count('9');
    int count6 = count.count('6');
    num['6'] = num['9'] = (count9 + count6 + 1) / 2;

    int max = maxCount(num);
    
    printf("I need %d sets!\n", max);









    return 0;
}