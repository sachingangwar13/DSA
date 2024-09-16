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
int i = 0;
Node *reverseLL(Node *head){

    Node *temp = head;
    Node * prev = NULL;

    while(temp != NULL){

        Node *front = temp -> next;
        temp -> next= prev;
        prev=temp;
        temp = front;
    }
    return prev;

}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n) ;
    for(int i=0 ; i<n; i++) cin>>arr[i];


    Node *head = convert2ll(arr);
    head = reverseLL(head );
    Print(head);

    return 0;
}

