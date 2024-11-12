class Node{

    int data;
    Node next;
    Node back;

    Node(int data,Node next,Node back){
        this.data=data;
        this.next=next;
        this.back=back;
    }
    
    Node(int data){
        this.data=data;
        this.next=null;
        this.back=null;
    }
} 

public class DLL {

    //print a Doubly LinkedList
    public static void printDll(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head=head.next;
        }
    }

    //Convert array into a  Doubly LinkedList
    public static Node convertArrToDll(int[] arr){
        Node head=new Node(arr[0]);
        Node prev=head;
        for(int i=1;i<arr.length;i++){
            Node temp=new Node(arr[i],null,prev);
            prev.next=temp;
            prev=temp; //prev=prev.next
        }
        return head;
    }

    //Deletion in Doubly LinkedList
    public static Node deleteHead(Node head){
        if(head==null || head.next==null) return null;
        Node prev=head;
        head=head.next;
        prev.next=null;
        head.back=null;
        return head;
    } 

    public static Node deleteTail(Node head){
        if(head==null || head.next==null) return null;
        Node temp=head;
        while(temp.next.next != null){
            temp=temp.next;
        }
        temp.next.back=null;
        temp.next=null;
        return head;
    }

    public static Node deleteKthNode(Node head,int k){
        if(head==null) return null;
        int count=0;
        Node temp=head;
        while(temp!=null){
            count++;
            if(count==k){
                break;
            }
            temp=temp.next;
        }
        Node prev = temp.back;
        Node front=temp.next;
        if(front==null && prev==null){
            return null;
        }
        else if(prev==null){
            return deleteHead(head);
        }
        else if(front==null){
            return deleteTail(head);
        }
        else{
            prev.next=front;
            front.back=prev;
            temp.next=null;
            temp.back=null;
            return head;
        } 
    }

    public static Node deleteKthValue(Node head,int value){
        if(head==null) return null;
        Node temp=head;
        while(temp!=null){
            if(temp.data==value){
                break;
            }
            temp=temp.next;
        }
        Node prev = temp.back;
        Node front=temp.next;
        if(front==null && prev==null){
            return null;
        }
        else if(prev==null){
            return deleteHead(head);
        }
        else if(front==null){
            return deleteTail(head);
        }
        else{
            prev.next=front;
            front.back=prev;
            temp.next=null;
            temp.back=null;
            return head;
        }
    }
    
    public static void deleteNode(Node temp){
        //Always (temp != head)
        Node prev =temp.back;
        Node front = temp.next;

        if(front== null){
            prev.next = temp.back = null;
            return;
        }

        prev.next=front;
        front.back=prev;
        temp.back = temp.next =null;
    }
    
    //Insertion in doubly Linked List
    public static Node insertBeforeHead(Node head,int val){
        Node newNode=new Node(val,head,null);
        head.back=newNode;
        return newNode;
    }
    
    public static Node insertAfterHead(Node head,int val){
        Node newNode=new Node(val,head.next,head);
        if(head.next != null) head.next.back=newNode;
        head.next=newNode;
        return head;
    }
    
    public static Node insertBeforeTail(Node head,int val){
        if(head.next == null){
            return insertBeforeHead(head, val);
        }
        Node temp=head;
        while(temp.next!= null){
            temp=temp.next;
        }
        Node prev = temp.back;
        Node newNode=new Node(val,temp,prev);
        prev.next = temp.back = newNode;
        return head; 
    }
    
    public static Node insertAfterTail(Node head,int val){
        Node temp=head;
        while(temp.next!= null){
            temp=temp.next;
        }
        Node newNode=new Node(val,null,temp);
        temp.next=newNode;
        return head;
    }
    
    public static Node insertBeforeKthNode(Node head,int k,int val){
        if(k==1){
            return insertBeforeHead(head, val);
        }
        int count=0;
        Node temp=head;
        while(temp != null){
            count++;
            if(count==k) break;
            temp=temp.next;
        }
        Node prev=temp.back;
        Node newNode=new Node(val,temp,prev);
        temp.back = prev.next = newNode;
        return head;
    }
    
    public static Node insertBeforeKthValue(Node head,int value,int data){
        if(head.data==value){
            return insertBeforeHead(head, data);
        }
        Node temp=head.next;
        while(temp != null){
            if(temp.data==value) break;
            temp=temp.next;
        }
        Node prev=temp.back;
        Node newNode=new Node(data,temp,prev);
        temp.back = prev.next = newNode;
        return head;
    }
    public static void main(String args[]){
        int[] a={1,2,3,4,5};
        Node head=convertArrToDll(a);
        head=insertBeforeKthValue(head, 2,10);
        printDll(head);
    }

}
