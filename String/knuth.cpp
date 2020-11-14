#include<bits/stdc++.h>
using namespace std;

#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)

struct knuth
{
    string text, pattern;
    vector<int> LPS_Table;
    vector<int> patternFoundPosition;
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
    void KMP(string text, string pattern)
    {
        int i=0;
        int j=0;
        while(i < text.length())
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
            if(j == pattern.length())
            {
                patternFoundPosition.push_back(i - j);
                j = LPS_Table[j-1];
            }
        }
    }
    void printLPS()
    {
        cout << "LPS table: ";
        for (int i = 0; i < LPS_Table.size(); i++)
        {
            cout << LPS_Table[i] << ' ';
        }
        cout << endl;
    }
    void printPosition()
    {
        if(patternFoundPosition.size()){
            cout << "Pattern Occurs at: ";
            for (int i = 0; i < patternFoundPosition.size(); i++)
                cout << patternFoundPosition[i] << ' ';
            cout << endl;
        }
        else
            cout << "Not Found" << endl;
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
    kmp.KMP(kmp.text, kmp.pattern);
    kmp.printPosition();
    return 0;
}