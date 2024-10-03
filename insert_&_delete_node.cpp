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

Node* deleteHead(Node* head){
    Node* temp=head;
    head=head->next;
    delete(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next =nullptr;
    return head;
}

Node* deleteKnode(Node* head,int k){
    if(head == nullptr) return head;
    if(k == 1){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteKvalue(Node* head,int val){
    if(head==NULL) return head ; 
        if(head->data==val) {
            head=head->next;
            return head;
        }
        Node* temp=head;
        Node* prev=NULL;
        while(temp != NULL){
            if(temp->data==val){
                prev->next=prev->next->next;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
}

Node* insertHead(Node* head,int val){
    return new Node(val,head);
}

Node* insertLast(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node*  temp=head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head; 
}

Node* insertKthPosition(Node* head,int val,int k){
        if(head == NULL) {
            if(k==1) return new Node(val);
            else return NULL;
        }
        if(k==1){
            return new Node(val,head);
        }
        int cnt=0;
        Node* temp=head;
        while(temp != NULL){
            cnt++;
            if(cnt == k-1){
                Node* newNode=new Node(val,temp->next);
                temp->next=newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

Node* insertBeforeValue(Node* head,int data,int value){
        if(head==NULL) return NULL;
        if(head->data==value) return new Node(data,head);
        Node* temp=head;
        while(temp != NULL){
            if(temp->next->data==value){
                Node* newNode=new Node(data,temp->next);
                temp->next=newNode;
                break;
            }
            temp=temp->next;
        }
        return head;
    }

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertarr2LL(arr);
    head=insertBeforeValue(head,6,3);    
    print(head);
    return 0;
}
