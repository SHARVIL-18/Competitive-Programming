public:
struct node{
    node* child[26];
    int size;
    vector<string> wend;
    node(){
        size = 0;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};
struct trie
{
node *root;
trie()
 {
root = new node;
 }

 void insert(string s){
    node * cur = root;
    for(int i = 0; i < s.length(); i++){
        int ind = s[i] - 'a';
        if(cur->child[ind] == NULL){
            cur->child[ind] = new node;
        }
        cur->size++;
        cur = cur-> child[ind];
    }
    cur->size++;
    cur->wend.push_back(s);
 }
int lcp(node *s){

// function to compute longest common prefix among atleast two strings inserted into child.

if(s == NULL) return 0;
int ans = 0;
for(int i = 0; i < 26; i++ ){
    if(s->child[i] != NULL){
        ans = max(ans, lcp(s->child[i]) + (s->child[i]->size > 1 ? 1 : 0));
    }
}
return ans; 
}

};