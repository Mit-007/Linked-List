import java.util.*;

class Node{
    int data;
    Node next;

    Node(int data,Node next){
        this.data=data;
        this.next=next;
    }

    Node(int data){
        this.data=data;
        this.next=null;
    }
}

public class LL {
    private static void printLL(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head=head.next;
        }
    }

    private static Node convertarr2LL(int[] arr){
        Node head= new Node(arr[0]);
        Node mover=head;
        for (int i=1;i<arr.length;i++){
            Node temp= new Node(arr[i]);
            mover.next=temp;
            mover=mover.next;
        }
        return head;
    }

    private static Node deleteHead(Node head){
        head=head.next;
        return head;
    }

    private static Node deleteTail(Node head){
        if(head==null || head.next==null) return null;
        Node temp=head;
        while(temp.next.next != null){
            temp=temp.next;
        }
        temp.next=null;
        return head;
    }

    private static Node deleteKnode(Node head,int k){
        if(head == null) return head;//  also return null
        if(k == 1){
            head=head.next;
            return head;
        }
        int cnt=0;
        Node temp=head,prev=null;
        while (temp != null) {
            cnt++;
            if(cnt == k){
                prev.next=prev.next.next; // also written as (prev.next=temp.next)
                break;
            }
            prev=temp;
            temp=temp.next;
        } 
        return head;
    }
    
    private static Node deleteKvalue(Node head,int val){
        if(head==null) return head ; 
        if(head.data==val) {
            head=head.next;
            return head;
        }
        Node temp=head,prev=null;
        while(temp != null){
            if(temp.data==val){
                prev.next=prev.next.next;
                break;
            }
            prev=temp;
            temp=temp.next;
        }
        return head;
    }
    
    private static Node insertHead(Node head,int val){
        return new Node(val,head);
    }

    private static Node insertLast(Node head,int val){
        if(head == null) return new Node(val);
        Node temp=head;
        while(temp.next != null){
            temp = temp.next;
        }
        Node newNode=new Node(val);
        temp.next=newNode;
        return head;
    }

    private static Node insertKthPosition(Node head,int val,int k){
        if(head == null) {
            if(k==1) return new Node(val);
            else return null;
        }
        if(k==1){
            return new Node(val,head);
        }
        int cnt=0;
        Node temp=head;
        while(temp != null){
            cnt++;
            if(cnt == k-1){
                Node newNode=new Node(val,temp.next);
                temp.next=newNode;
                break;
            }
            temp = temp.next;
        }
        return head;
    }

    private static Node insertBeforeValue(Node head,int data,int value){
        if(head==null) return null;
        if(head.data==value) return new Node(data,head);
        Node temp=head;
        while(temp != null){
            if(temp.next.data==value){
                Node newNode=new Node(data,temp.next);
                temp.next=newNode;
                break;
            }
            temp=temp.next;
        }
        return head;
    }

    public static void main(String[] args) {
        int[] a={1,2,3,4,5};
        Node head=convertarr2LL(a);
        head=insertBeforeValue(head,6,5);
        printLL(head);
    }
}
