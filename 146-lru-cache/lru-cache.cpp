class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int val){
            key=k;
            value=val;
            prev=next=NULL;
        }
    };
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);
    int cap;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* node){
        Node* afterHead=head->next;
        node->next=afterHead;
        node->prev=head;
        head->next=node;
        afterHead->prev=node;
    }
    void deleteNode(Node* node){
        Node* delNext=node->next;
        Node* delPrev=node->prev;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    int get(int key) {
        if(mp.count(key)){
            Node* node=mp[key];
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key]=head->next;
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node=mp[key];
            mp.erase(key);
            deleteNode(node);
            
        }
        else{
            if(mp.size()==cap){
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */