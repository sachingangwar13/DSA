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

Node *removeK(Node *head, int k){

    if(head==NULL || head->next == NULL) return NULL;
    Node *temp = head;
    if(k==1){
        
        head = head->next;
        head->back = nullptr;
        free(temp);
        return head;
    }

    int cnt=0;

    while(temp != NULL){
        cnt++;
        if(cnt==k)break;
        temp = temp ->next;
    }

    if(temp->next ==NULL){
        Node *pre = temp->back;
        pre->next = 0;
        free(temp);
        return head;
    }
    
    Node *pre = temp->back;
    Node *front = temp->next;

    pre-> next = front;
    front-> back = pre;
    free(temp);
    return head;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)cin>>arr[i];

    Node *head = convert2Dll(arr);

    int k;
    cin>>k;
    head = removeK(head ,k);

    printl(head);

    return 0;
}

