/*
    * insert O(n), search O(n)
    * end mark returns the number of prefix which is a string previosly inserted into the trie
*/

struct TrieNode{
	int next[32], end = 0;
	int& operator[] (int i) {
		return next[i];
	}
};

struct Trie{
	vector<TrieNode> root = {TrieNode()};
	void add(string s) {
		int cur = 0;
		for(char ch : s){
			int c = ch - 'a';
			if(!root[cur][c]){
				root[cur][c] = root.size();
				root.push_back(TrieNode());
			}
			cur = root[cur][c];
			root[cur].end++;
		}
	}
	int search(string s) {
		int cur = 0;
		for(char ch : s) {
			int c = ch - 'a';
			cur = root[cur][c];
			if(!cur)
				return 0;
		}
		return root[cur].end;
	}
};

signed main() {
	int n; cin >> n;
    Trie tr;
	while(n--) {
		string a, b; cin >> a >> b;
        if(a == "add") tr.add(b);
		else cout << tr.search(b) << endl;
	}
	return 0;
}