struct Node{
  Node* links[26];
    bool flag = false;
    
    bool isPresent(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void markEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};
class Trie {
private: Node* root; 
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};