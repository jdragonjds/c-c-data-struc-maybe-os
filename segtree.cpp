/*some queries of following type:
Each query consists of three integers
1 A B : Update the Array at index A by value B
2 A B : if the subarray from index A to B (both inclusive) is
        1. Both increasing(Non-decreasing) and decreasing(Non-increasing) print -1
        2. Only increasing(Non-decreasing) print 0
        3. Only decreasing(Non-increasing) print 1
        4. Neither increasing nor decreasing print -1
example :
Input:
1
7
1 5 7 4 3 5 2
5
2 1 3
2 2 4
2 3 4
1 6 3
2 5 6
Output:
0
-1
1
-1


*/
#include <bits/stdc++.h>
using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }  


pair<pair<int,int>,int> constructSTUtil(int arr[], int ss, int se, pair<pair<int,int>,int> *st, int si) 
{  
    if (ss == se) 
    { 
        st[si] = {{arr[ss],arr[ss]},-9}; 
        return {{arr[ss],arr[ss]},-9}; 
    }  
    int mid = getMid(ss, se); int f,s;
    pair<pair<int,int>,int>  ul,ur,res;ul=constructSTUtil(arr, ss, mid, st, si*2+1);
    ur=constructSTUtil(arr, mid+1, se, st, si*2+2); 
    
    if(ul.second==ur.second){
        if(ul.second==1){
         if(ul.first.second>ur.first.first) {res.second=1;res.first={ul.first.first,ur.first.second };}
          else res.second=-1;   
        }
        if(ul.second==0){
          if(ul.first.second<ur.first.first){ res.second=0;res.first={ul.first.first,ur.first.second };}
          else res.second=-1;
        }
      if(ul.second==-9){
          if(ul.first.second<ur.first.first){ res={{ul.first.first,ur.first.second },0};}
          if(ul.first.second>ur.first.first) {res ={{ul.first.first,ur.first.second },1};}
          if(ul.first.second==ur.first.first)  res ={{-5,-5},-1};
        }  
    }
    if(ul.second!=ur.second){res={{-5,-5},-1};
     if(ur.second==-9){
         
      if(ul.second==1){
        if(ul.first.second>ur.first.first) {res.second=1;res.first={ul.first.first,ur.first.second };}
        }
        if(ul.second==0){
          if(ul.first.second<ur.first.first){ res.second=0;res.first={ul.first.first,ur.first.second };}
        }
        if(ul.second==-1) res={{-5,-5},-1};
      } 
      
    }
    
    
st[si]=res;
    return res; 
} 
 
pair<pair<int,int>,int> *constructST(int arr[], int n) 
{  
    int x = (int)(ceil(log2(n)));   
    int max_size = 2*(int)pow(2, x) - 1;   
    pair<pair<int,int>,int> *st =  (pair<pair<int,int>,int> *)malloc(sizeof(pair<pair<int,int>,int>)*max_size);  
    constructSTUtil(arr, 0, n-1, st, 0);  
    return st; 
} 
 
pair<pair<int,int>,int> getXorUtil(pair<pair<int,int>,int> *st, int ss, int se, int qs, int qe, int si) 
{  
    if (qs <= ss && qe >= se) 
        return st[si];  
    if (se < qs || ss > qe) 
        return {{-8,-8},-8};  
    int mid = getMid(ss, se); 
     
     pair<pair<int,int>,int>  ul,ur,res;ul=getXorUtil(st, ss, mid, qs, qe, 2*si+1);
    ur=getXorUtil(st, mid+1, se, qs, qe, 2*si+2); 
    
    if(ul.second==-8) 
        return ur;
    if(ur.second==-8) 
        return ul;
    
    
    if(ul.second==ur.second){
        if(ul.second==1){
         if(ul.first.second>ur.first.first) {res.second=1;res.first={ul.first.first,ur.first.second };}
          else res={{-5,-5},-1};   
        }
        if(ul.second==0){
          if(ul.first.second<ur.first.first){ res.second=0;res.first={ul.first.first,ur.first.second };}
          else res={{-5,-5},-1};
        }
      if(ul.second==-9){
          if(ul.first.second<ur.first.first){ res={{ul.first.first,ur.first.second },0};}
          if(ul.first.second>ur.first.first) {res ={{ul.first.first,ur.first.second },1};}
          if(ul.first.second==ur.first.first)  res ={{-5,-5},-1};
        }  
    }
    if(ul.second!=ur.second){res={{-5,-5},-1};
     if(ur.second==-9){
         
      if(ul.second==1){
        if(ul.first.second>ur.first.first) {res.second=1;res.first={ul.first.first,ur.first.second };}
        }
        if(ul.second==0){
          if(ul.first.second<ur.first.first){ res.second=0;res.first={ul.first.first,ur.first.second };}
        }
        if(ul.second==-1) res={{-5,-5},-1};
      } 
      
    }
    
      
  return res;       
}
  
 
int main(){
    int t, n, q , a, b, op, temp;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        vector<int> check;
        for(int i = 0; i < n; i++) cin>>arr[i];
        cin>>q;
pair<pair<int,int>,int> *st=constructST(arr,  n ); 
 
        while(q--){
         cin>>op>>a>>b;
        if(op==2)  cout<<getXorUtil(st, 0, n-1, a-1, b-1, 0).second<<endl;   
      
        if(op==1){
          arr[a-1]=b;free(st);
          st=constructST(arr,  n );  
        }  
        
        }
         
    }
    return 0;
}
