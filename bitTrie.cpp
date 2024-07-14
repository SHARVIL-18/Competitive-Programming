struct node{
    node *child[2];
    int sz = 0;
    node(){
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie{
    node * root();
    trie(){
        root = new node();
    }

void insert(int n){
    node * cur = root;
    for(int i = LN - 1; i >= 0; --i){
        cur->cnt ++;
        int b = (n >> i) & 1;
        if(cur->child[x] == NULL){
            cur->child[x] = new node;
        }
        cur = cur->child[x];
    }
    cur->cnt ++; 
}
void delete(int n){
    node * cur = root;
    for(int i = LN - 1; i >= 0; --i){
        cur->cnt --;
        int b = (n >> i) & 1;
        if(cur->child[x] == NULL){
            cur->child[x] = new node;
        }
        cur = cur->child[x];
    }
    cur->cnt --; 
}
}


