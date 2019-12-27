/*
 * C++ Program to Implement Knuth–Morris–Pratt Algorithm (KMP)
 */
#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

vector<int> fail;

void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether target string contains pattern 
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];     
    preKMP(pattern, f);     
    int i = 0;
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}

/*

int main()
{
    string tar = "san and linux training";
    string pat = "lin";
    if (KMP(pat, tar))
        cout<<"'"<<pat<<"' found in string '"<<tar<<"'"<<endl;
    else
        cout<<"'"<<pat<<"' not found in string '"<<tar<<"'"<<endl;
    pat = "sanfoundry";
    if (KMP(pat, tar))
        cout<<"'"<<pat<<"' found in string '"<<tar<<"'"<<endl;
    else
        cout<<"'"<<pat<<"' not found in string '"<<tar<<"'"<<endl;
    return 0;
}

*/

int f(string p, int idx) {
    int m = p.length();
    int j = 0; 
    
    for(int i = 1; i< m ; i++)
    { 
        while(j > 0 && p[i] != p[j]) 
            j = fail[j-1]; 
        if(p[i] == p[j]) 
            fail[i] = ++j;
    } 
    return -1; 
}

int _kmp(string T, string P) {
    int i = 0, j = 0;
    int n = T.length();
    int m = P.length();
    while(i<n) {
        if(P[j] = T[i]) { // match
            if(j=m-1)
                return (i-m+1);
            i++; j++;
        }
        else if(j>0) {
            f(P, j-1);
            j = fail[j-1];
        }
        else
            i++;    
    }
    return -1; // there is no substring of T matching P
}

int main() {

    string text;
    string pattern = "python";
    int m, p;

    printf("input your text : "); fflush(stdout);
    cin >> text;
    //printf("input your pattern : "); fflush(stdout);
    //cin >> pattern;

    m = text.length();
    p = pattern.length();

    fail.assign(m, 0); 

    if(_kmp(text, pattern) >= 0) {
        printf(" matching ! \n");
    }





    return 0;
}