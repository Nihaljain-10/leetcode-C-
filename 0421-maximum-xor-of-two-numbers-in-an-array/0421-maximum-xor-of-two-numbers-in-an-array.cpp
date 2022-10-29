


struct Node{
    Node* link[2];
    bool isContain(int bit){
        return (link[bit]!=NULL);
    }
    void put(int bit,Node* node){
        link[bit]= node;
    }
    Node* get(int bit){
        return link[bit];
    }

};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void Insert(int num){
       Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->isContain(bit)){
                node->put(bit,new Node());
            }
            node =node->get(bit);
        }
    }
    int getmax(int num){
         Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->isContain(1-bit)){
                maxi=maxi|(1<<i);
                node =node->get(1-bit);
            }else{
                node =node->get(bit);
            }
        }
        return maxi;
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it:nums){
            trie.Insert(it);
        }
        int ans=0;
        for(auto &it:nums){
            ans=max(ans,trie.getmax(it));
        }
        return ans;
    }
};