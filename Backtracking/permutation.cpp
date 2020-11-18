/*
    * Generates all permutation of a string (from i to j)
*/
void permutation(string s, int i, int j)
{
    if(i==j)
        cout << s << endl;
    else
    {
        for (int k = i; k <= j; k++)
        {
            swap(s[k], s[j]);
            permutation(s, i + 1, j);
            swap(s[k], s[j]);
        }
    }
}
/*
    * STL next_permutation
*/
void permutation(string s)
{
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

