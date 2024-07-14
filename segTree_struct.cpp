struct SegTree{

// BEWARE : 

// RANGE MAX QUERY SUPPORTED
 
// NUMBERS ASSUMED TO BE POSITIVE !!(CHANGE DEAD CASE RETURN VALUE FOR NEGATIVE)


    public : 
    vector<int> arr;
    vector<int> t;

    SegTree(int n){
        arr.resize(n);
        t.resize(4*n);
    }
    
void build(int index,int l,int r){
      if(l==r){
        t[index]  = arr[l];//Leaf condition
        return;
      }
  int mid = (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);
  t[index] = max(t[2*index],t[2*index + 1]); //Any required FUNCTION INSTEAD OF ADDITON (eg MAX)
}

void update(int index,int l,int r,int pos,int val){
    if(pos<l||pos>r)return;
    if(l==r){
        t[index] = val;
        arr[l] = val;
        return;
    }
    int mid = (l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = max(t[2*index], t[2*index+1]); // function change


}
int query(int index,int l,int r,int lq,int rq){
    if(l>rq || lq>r){return 0;} // least number change if negative numbers are allowed
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid = (l+r)/2;
    return max(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq)); // Function change
}









}