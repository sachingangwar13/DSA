#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node *next;
    Node *back;

    public:
    Node(int data1 , Node *next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

void printl(Node* head){
    Node *temp = head;

    while( head != NULL ){
        temp= head;
        cout << head -> data<<" ";
        head = head->next;
    }
    cout << endl;
    // while(temp){
    //     cout<< temp->data <<" ";
    //     temp = temp->back;
    // }
}

Node *convert2Dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i],nullptr , prev);
        prev -> next = temp;

        prev = temp;
    }

    return head;
}

Node *removeH(Node *head){

    if(head==NULL || head->next == NULL) return NULL;

    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    free(temp);
    return head;
}

int main(){
    vector<int> arr = {2,4,6,8,4,6};
    Node *head = convert2Dll(arr);

    printl(head);

    head = removeH(head);
    printl(head);

    return 0;
}

