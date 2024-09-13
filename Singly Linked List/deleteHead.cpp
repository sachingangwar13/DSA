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

Node* deleteH(Node *head){
    if(head == NULL)return head;
    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
    
}

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

int main(){
    vector<int> arr = {2,4,6,8,4,6};
    Node *head = convert2ll(arr);

    head = deleteH(head);
    Print(head);

    return 0;
}

