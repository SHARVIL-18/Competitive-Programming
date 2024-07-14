ll sub_hash1(ll i,ll j){
    if(i==0)return hash1[j];
    else{
        return (hash1[j] - (hash1[i-1]*ppow[j-i+1])%B + B)%B;
    }
}
 

   cin>>str>>arr>>k;
    n = str.size();
    hash1[0] = str[0];
    ppow[0] = 1;
    un.resize(n+1);
    // un1.resize(n+1);
    for (int i = 1; i < n; i++)
    {
        hash1[i]=  (hash1[i-1]*A + str[i])%B;
        ppow[i] = (A*ppow[i-1])%B;
    }