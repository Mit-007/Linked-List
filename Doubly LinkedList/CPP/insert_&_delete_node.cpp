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

//convert arr to doubly linkrd list
Node* convertArr2DLL(vector<int>& arr){
    Node* head= new Node(arr[0]);  
    Node* prev=head; 
    for (int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev); 
        prev->next=temp; 
        prev=temp;
    }
    return head;
}

//print DLL
void printDLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

//deletion in doubly linkrd list
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL ||head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    temp->back=NULL;
    prev->next=NULL;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head,int k){
    if(head==NULL) return NULL;
    Node* temp=head;
    int count=0;
    while(temp!= NULL){
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    Node* front=temp->next;
    Node* prev=temp->back;
    if(front==NULL && prev==NULL){
        delete temp; //delete head
        return NULL;
    }
    else if(prev ==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    else{
        front->back=prev;
        prev->next=front;
        temp->next=NULL;
        temp->back=NULL;
        delete temp;
        return head;
    }
}

Node* deleteKthValue(Node* head,int value){
    if(head==NULL) return NULL;
    Node* temp=head;
    while(temp!= NULL){
        if(temp->data==value){
            break;
        }
        temp=temp->next;
    }
    Node* front=temp->next;
    Node* prev=temp->back;
    if(front==NULL && prev==NULL){
        delete temp; //delete head
        return NULL;
    }
    else if(prev ==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    else{
        front->back=prev;
        prev->next=front;
        temp->next=NULL;
        temp->back=NULL;
        delete temp;
        return head;
    }
}

void deleteNode(Node* temp){
    //Always (temp!=head)
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next = temp->back =NULL;
        delete temp;
        return;
    }

    prev->next=front;
    front->back=prev;
    temp->back = temp->next =NULL;
    delete temp;
}

//insertion in Doubly Linked List
Node* insertBeforeHead(Node* head,int val){
        Node* newNode=new Node(val,head,NULL);
        head->back=newNode;
        return newNode;
    }

Node* insertAfterHead(Node* head,int val){
    Node* newNode=new Node(val,head->next,head);
    if(head->next != NULL) head->next->back=newNode;
    head->next=newNode;
    return head;
}

Node* insertBeforeTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next = temp->back = newNode;
    return head; 
}

Node* insertAfterTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val,NULL,temp);
    temp->next=newNode;
    return head;
}

Node* insertBeforeKthNode(Node* head,int k,int val){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp = head;
    int count=0;
    while(temp!= NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next = temp->back = newNode;
    return head;
}

Node* insertBeforeKthValue(Node* head,int value,int data){
    if(head->data == value) return insertBeforeHead(head,data);
    Node* temp = head->next;
    while(temp!= NULL){
        if(temp->data== value) break;
        temp = temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(data,temp,prev);
    prev->next = temp->back = newNode;
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2DLL(arr); 
    head=insertBeforeKthValue(head,2,2525);  
    printDLL(head);
    return 0;
}
