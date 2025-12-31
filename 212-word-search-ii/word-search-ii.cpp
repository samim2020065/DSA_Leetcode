struct Node{
    Node* links[26]={NULL};
    bool flag=false;
    string word="";
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(string &w){
        flag=true;
        word=w;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setEnd(word);
    }
};
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,Node* node,vector<string>&ans){
        char ch=board[i][j];
        if(ch=='#'||!node->containsKey(ch)){
            return;
        }
        node=node->get(ch);
        if(node->isEnd()){
            ans.push_back(node->word);
            node->flag=false;
        }
        board[i][j]='#';
        int n=board.size(),m=board[0].size();
        if(i>0){
            dfs(i-1,j,board,node,ans);
        }
        if(j>0){
            dfs(i,j-1,board,node,ans);
        }
        if(i<n-1){
            dfs(i+1,j,board,node,ans);
        }
        if(j<m-1){
            dfs(i,j+1,board,node,ans);
        }
        board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tri;
        for(string word:words){
            tri.insert(word);
        }
        vector<string>ans;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,board,tri.root,ans);
            }
        }
        return ans;
    }
};