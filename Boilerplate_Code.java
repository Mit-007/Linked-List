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
  
  public static void main(String[] args) {
        int[] a={1,2,3,4,5};
        Node head=convertarr2LL(a);
        head=insertBeforeValue(head,6,5);
        printLL(head);
    }
}
