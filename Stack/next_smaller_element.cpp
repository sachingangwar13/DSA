#include <bits/stdc++.h> 
using namespace std; 

    vector<int> next_smaller(vector<int> arr, int n) 
    { 
        stack<int> st;
        vector<int> ans(n);
        for(int i =n-1 ; i>=0 ; i--){
            
            while(!st.empty() && st.top()>= arr[i]){
                st.pop();
            }
            
            if(!st.empty()) ans[i]=st.top();
            
            else{
                ans[i]=-1;
            }
            st.push(arr[i]);
        }
        return ans;
    } 

int main() 
{ 
    int n;
    cin>>n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>array[i];
    }
    
    vector<int> result = next_smaller(array,n);
    for (int i = 0; i < n; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<"\n";

	return 0; 
}


// } Driver Code Ends