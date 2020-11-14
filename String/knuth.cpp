#include<bits/stdc++.h>
using namespace std;

#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)

struct knuth
{
    string text, pattern;
    vector<int> LPS_Table;
    knuth(string txt, string ptrn)
    {
        text = txt;
        pattern = ptrn;
        LPS_Table.resize(pattern.length());
        calculateLPS(pattern);
    }
    void calculateLPS(string s)
    {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int j = LPS_Table[i-1];
            while (j > 0 && s[i] != s[j])
                j = LPS_Table[j-1];
            if (s[i] == s[j])
                j++;
            LPS_Table[i] = j;
        }
    }
    bool KMP(string text, string pattern)
    {
        int i=0;
        int j=0;
        while(i < text.length() && j < pattern.length())
        {
            if(text[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0) j = LPS_Table[j-1];
                else i++;
            }
        }
        if(j == pattern.length())
            return true;
        return false;
    }
    void printLPS()
    {
        for (int i = 0; i < LPS_Table.size(); i++)
        {
            cout << LPS_Table[i] << ' ';
        }
        cout << endl;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    string text, pattern;
    cin >> text >> pattern;
    knuth kmp(text, pattern);
    kmp.printLPS();
    cout << kmp.KMP(kmp.text, kmp.pattern);
    return 0;
}