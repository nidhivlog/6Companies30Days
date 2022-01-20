// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
            pair<int,int> res;
       res.first=-1;
       res.second=-1;
       
       if(k==1)
       {
           res.first=arr[0][0];
           res.second=arr[0][0];
           
           return res;
       }
       
       int diff=INT_MAX;
       
       //order of values in tuple is.
       //1.element.
       //2.index of array to which this element belongs.
       //3.index of the element in that array.
       
       multiset<tuple<int,int,int>> ms;
       
       for(int i=0;i<k;i++)
       {
           ms.insert(make_tuple(arr[i][0],i,0));
       }
       
       while(ms.size()==k)
       {
           auto temp1=*(ms.begin());
           
           ms.erase(ms.begin());
           
           int val1=get<0>(temp1);
           int arr_pos1=get<1>(temp1);
           int val_pos1=get<2>(temp1);
           
           auto temp2=*(ms.rbegin());
           
           int arr_pos2=get<1>(temp2);
           int val_pos2=get<2>(temp2);
           int val2=get<0>(temp2);
           
           if(diff > val2-val1)
           {
               diff=val2-val1;
               res.first=arr[arr_pos1][val_pos1];
               res.second=arr[arr_pos2][val_pos2];
           }
           
           val_pos1++;
           
           if(val_pos1<n)
           {
               ms.insert(make_tuple(arr[arr_pos1][val_pos1],arr_pos1,val_pos1));
           }
       }
       
       return res;
   }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends