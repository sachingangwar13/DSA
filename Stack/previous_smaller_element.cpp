#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n) {
    
    stack<int> st;
    vector<int>ans(n);

    for(int i=0 ; i< n;i++){
        
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        
        if(!st.empty()){
            ans[i] = st.top();
        }
        else{
            ans[i]=-1;
        }
        
        st.push(arr[i]);
    }
    
    return ans;
}

int main() {

    int n;
    cin >> n;
    int arr[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> b;
    b = Smallestonleft(arr, n);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << endl;

    return 0;
}



