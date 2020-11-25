/*
    * fft and inverse fft
    * multiply two polynomials in O(nlogn) time
    * source:
        1. https://cp-algorithms.com/algebra/fft.html
        2. https://codeforces.com/blog/entry/43499
        3. https://codeforces.com/blog/entry/66400
        4. https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
*/

#include<bits/stdc++.h>
using namespace std;

#define     PI              acos(-1)

using cd = complex<double>;

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


/* for multiplying two big numbers. */
string multiplyTwoNumber(string s1, string s2)
{
    vector<int> a, b;
    for(auto i : s1)
        a.push_back(i - '0');
    for(auto i : s2)
        b.push_back(i - '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> result = multiply(a, b);
    int carry = 0;
    for (int i = 0; i < result.size(); i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    reverse(result.begin(), result.end());
    bool zero = true;
    string ans = "";
    for(auto i : result)
    {
        if(i == 0 && zero)
            continue;
        zero = false;
        ans += (i + '0');
    }
    if(zero)
        ans = "0";
    return ans;
}

int main()
{
    vector<int> fx = {1,1,1};  // f(x) = 1 + x + x^2
    vector<int> gx = {1,3};    // g(x) = 1+3x

    vector<int> res = multiply(fx,gx);

    for(int i=0; i<res.size(); i++)
    	if(res[i])
            cout << res[i] << "x^" << i << " "; // h(x) = 1+ 4x + 4x^2 + 3x^3
    cout<<endl;

    cout << multiplyTwoNumber("845", "9849") << endl; // 8322405
    return 0;
}
