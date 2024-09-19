#include <bits/stdc++.h>
using namespace std;

    int priorityy(char ch){
        
        if( ch == '^')return 3;
        else if (ch == '/' || ch == '*')return 2;
        else if(ch == '+' || ch == '-')
        {
            return 1;
        }
        
        return -1;
    }
    
    string infixToPostfix(string s) {
        
        int n = s.size();
        stack<int> st;
        
        string ans="";
        int i=0;
        
        while(i<n){
            
            if((s[i]<='Z'&& s[i]>='A') || 
                (s[i]>='a' && s[i] <='z') || 
                (s[i]>='0' && s[i]<='9')){
                
                ans += s[i];
            }
            
            else if(s[i]=='('){
                st.push(s[i]);
            }
            
            else if( s[i] == ')'){
                
                while(!st.empty() && st.top() != '('){
                    ans+= st.top();
                    st.pop();
                }
                
                st.pop();
            }
            
            else{
                
                while( !st.empty() && priorityy(s[i]) <= priorityy(st.top())){
                    ans += st.top();
                    st.pop();
                }
                
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
    }

int main() {

    string exp;
    cin >> exp;
    cout << infixToPostfix(exp) << endl;

    return 0;
}

// } Driver Code Ends