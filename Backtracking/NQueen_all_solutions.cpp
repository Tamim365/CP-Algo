#include<bits/stdc++.h>
using namespace std;
 
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     MEM(a, b)       memset(a, (b), sizeof(a))

const int MAXN = 107;

struct NQueen_all
{
    vector<vector<bool>> board;
    int N, cnt;
    NQueen_all(int size)
    {
        N = size;
        cnt = 0;
        vector<bool> v(N, false);
        board.resize(N, v);
    }
    void printSolution()
    {
        solve(0);
        cout << "Total No of solutions: " << cnt << endl;
    }
    bool check(int x, int y)
    {
        for (int i = x; i >= 0; i--) if(board[i][y]) return false;
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) if(board[i][j]) return false;
        for (int i = x, j = y; i >= 0 && j < N; i--, j++) if(board[i][j]) return false;
        return true;
    }
    void solve(int i)
    {
        if(i == N)
        {
            cnt++;
            printBoard();
            return;
        }
    
        for (int j = 0; j < N; j++)
        {
            if(check(i, j))
            {
                board[i][j] = true;
                solve(i + 1);
                board[i][j] = false;
            }
        }
    }
    void printBoard()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << (int)board[i][j] << ' ';
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
};


int main() {
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    fast;
    int N;
    cin >> N;
    NQueen_all nq(N);
    nq.printSolution();
    return 0;
}