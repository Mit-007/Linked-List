#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
         Node(int data1,Node* next1){
            data=data1;
            next=next1;
         }   
         Node(int data1){
            data=data1;
            next=nullptr;
         } 
};

Node* convertarr2LL(vector<int>& arr){
    Node* head= new Node(arr[0]);  
    Node* mover=head; 
    for (int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]); 
        mover->next=temp; 
        mover=mover->next;
    }
    return head;
}

void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertarr2LL(arr);
    print(head);
    return 0;
}
