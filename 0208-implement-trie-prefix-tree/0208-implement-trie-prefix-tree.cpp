struct Node{
    vector<Node*> children;
    bool eow=false;
    Node(){
        children.resize(26);
        for(auto&i:children) i=nullptr;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* p=root;
        for(int i{};i<word.length();i++){
            if(p->children[word[i]-'a']==nullptr){
                p->children[word[i]-'a']=new Node();
            }
            p=p->children[word[i]-'a'];
        }
        p->eow=true;
    }
    
    bool search(string word) {
        Node* p=root;
        for(int i{};i<word.length();i++){
            if(p->children[word[i]-'a']==nullptr){
                return false;
            }
            p=p->children[word[i]-'a'];
        }
        if(p->eow) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* p=root;
        for(int i{};i<prefix.length();i++){
            if(p->children[prefix[i]-'a']==nullptr){
                return false;
            }
            p=p->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */