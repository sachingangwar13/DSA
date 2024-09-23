link - https://leetcode.com/problems/sum-of-subarray-minimums/


class Solution {
public:

    int MOD = 1e9+7;
    vector<int> next_smallest_element(vector<int> arr, int n) 
    { 
        stack<int> st;

        vector<int> ans(n);

        for(int i =n-1 ; i>=0 ; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()) ans[i]=st.top();
            
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    } 

    vector<int> previous_smallest(vector<int> arr, int n) 
    {
        stack<int> st;
        
        vector<int>ans(n);

        for(int i=0 ; i< n;i++){
            
            while(!st.empty() && arr[st.top()] > arr[i]){

                st.pop();

            }
            
            if(!st.empty()){

                ans[i] = st.top();

            }

            else{

                ans[i] = -1;

            }
            
            st.push(i);
        }
    
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> nse = next_smallest_element(arr,n);

        vector<int> pse = previous_smallest(arr,n);

       int total = 0;

        for(int i = 0 ; i<n ;i++)
        {

            int left = i - pse[i];
            int right = nse[i]-i;

            total = (total + (right * left * 1LL * arr[i]) % MOD) % MOD;
        }

        return total;

    }
};