#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node(int data1,Node* next1,Node* back1){
            data=data1;
            next=next1;
            back=back1;
        }   
        Node(int data1){
            data=data1;
            next=nullptr;
            back=nullptr;
        }    
};
Node* convertArr2DLL(vector<int>& arr){
    Node* head= new Node(arr[0]);  
    Node* mover=head; 
    for (int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]); 
        mover->next=temp; 
        mover=mover->next;
    }
    return head;
}
void printDLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2DLL(arr);   
    printDLL(head);
    return 0;
}
