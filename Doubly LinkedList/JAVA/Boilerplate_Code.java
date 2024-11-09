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

    public static void main(String args[]){
        int[] a={1,2,3,4,5};
        Node head=convertArrToDll(a);
        printDll(head);
    }

}
