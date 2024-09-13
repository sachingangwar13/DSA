#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    public:
    Node(int data1 , Node *next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

void Print(Node *head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }
}

Node *convert2ll(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* move = head;

  for(int i=1 ; i< arr.size(); i++){
    Node* ok = new Node(arr[i]);
    move->next = ok;
    move = ok;
    
  }
  return head;

}

Node* remove(Node *head , int k){

    if(head==NULL)return head;
    if(k==1){
        Node *temp = head;
        head  = head -> next;
        free(temp);
        return head;
    }

    int cnt=0;
    Node *temp=head;
    Node *prev = NULL;

    while(temp != NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev -> next -> next;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n) ;
    for(int i=0 ; i<n; i++)cin>>arr[i];

    int k;
    cin>>k;

    Node *head = convert2ll(arr);
    head = remove(head ,k);
    Print(head);

    return 0;
}

