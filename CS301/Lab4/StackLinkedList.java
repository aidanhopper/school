class Car{
   private String make;
   
   public Car(String make){
      this.make = make;
   }
   
   public String toString(){
      return make;
   }
}


class Node<T>{
   
   public T data;
   public Node<T> next;
   
   public Node(T data){
      this.data = data;
      this.next = null;
   }

}



public class StackLinkedList<T>{
   
   //Single field of type Node   
   //to represent the front of the stack
  public Node<T> head = null;

     
   //operation push()
      /*
      The push operation is equivalent to the inserting a node at 
      the head of the list.

      */
  public void push(T data) {
    Node<T> insertNode = new Node<T>(data);
    if (head != null) insertNode.next = head;
    head = insertNode;
  }

   
   
   //operation pop()
      /*
      Pop is equivalent to deleting the node at the front
      */
  public void pop(){
    return;
  }
   
   //operation peek()
      /*
      Peek is equivalent to the pop operation
      but instead of removing the node, simply return the data
      */
      
  public T peek(){
    return null;
  }
   
   //operation print()
      /*
      Walk through the list (stack) and print it out.
      */
  public void print(){
    return;
  }
   
   
   //main()
   public static void main(String[] args){
       /*
      Test cases have been set up to test the program. The stack will be 
      populated with different types.
      You can comment them out when while implementing the operations. 
      */
      
      StackLinkedList<Car> s1 = new StackLinkedList<Car>();
      s1.push(new Car("Honda"));
      s1.push(new Car("BMW")); 
      s1.print();
      
      System.out.println("top of the stack: "+ s1.peek());
      
      s1.pop();
      s1.print();
      
      s1.push(new Car("Mercedes"));
      s1.print();
      
      s1.pop();
      s1.pop();
      s1.pop();
      System.out.println("\n--------------------------------\n");
      
      
      StackLinkedList<Integer> s2 = new StackLinkedList<Integer>();
      s2.push(10);
      s2.push(20); 
      s2.print();
      
      System.out.println("top of the stack: "+ s2.peek());
      
      s2.pop();
      s2.print();
      
      s2.push(30);
      s2.print();
      
      s2.pop();
      s2.pop();
      s2.pop();
      System.out.println("\n--------------------------------\n");



      StackLinkedList<String> s3 = new StackLinkedList<String>();
      s3.push("cat");
      s3.push("dog"); 
      s3.print();
      
      System.out.println("top of the stack: "+ s3.peek());
      
      s3.pop();
      s3.print();
      
      s3.push("tiger");
      s3.print();
      
      s3.pop();
      s3.pop();
      s3.pop();
   }
   
}
