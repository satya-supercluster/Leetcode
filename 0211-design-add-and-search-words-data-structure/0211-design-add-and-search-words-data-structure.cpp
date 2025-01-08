int trie[150'000][26] = {0};
bool is_word[150'000] = {0};
int sz = 1;

class WordDictionary {
public:
    WordDictionary() {
        sz = 1;
        memset(trie, 0, sizeof trie);
        memset(is_word, 0, sizeof is_word);
    }
    
    void addWord(string_view word) {
        int idx = 0;
        for(char c: word) {
            if(trie[idx][c - 'a'] == 0) {
                trie[idx][c - 'a'] = sz++;
            }
            idx = trie[idx][c - 'a'];
        }
        is_word[idx] = true;
    }
    
    bool search(string_view word) {
        return searx(word, 0);
    }
private:
    bool searx(string_view word, int idx) {
        int n = word.size();
        for(int i = 0; i < n; ++i) {
            if(word[i] == '.') {
                for(int j = 0; j < 26; ++j) {
                    if(trie[idx][j] && searx(word.substr(i + 1), trie[idx][j])) {
                        return true;
                    }
                }
                return false;
            }
            if(trie[idx][word[i] - 'a'] == 0) return false;
            idx = trie[idx][word[i] - 'a'];
        }
        return is_word[idx];
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */