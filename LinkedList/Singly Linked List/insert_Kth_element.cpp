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

Node* insertK(Node *head , int k , int data){

    if(k==1){
        Node *temp = new Node(data);
        temp->next = head;
        head= temp;
        return head;
    }

    int cnt =0 ;
    Node *temp = head;

    while(temp!=NULL){
        cnt++;

        if(cnt==k-1){
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        temp = temp->next;
    }

    return head;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n) ;
    for(int i=0 ; i<n; i++) cin>>arr[i];

    int k;
    cin>>k;

    Node *head = convert2ll(arr);
    head = insertK(head ,k,100);
    Print(head);

    return 0;
}

