// Aidan Hopper
// Lab 3
// 10/19/2021

import java.io.*; 

// Java program to implement 
// a Singly Linked List 
public class linkedlist { 

	Node head; // head of list 

	// Linked list Node. 
	// This inner class is made static 
	// so that main() can access it 
	static class Node { 

		int data; 
		Node next; 

		// Constructor 
		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 

	// **************INSERTION************** 
        /**
         * The insertion method
         * @param insertNode the node to be inserted
         * @return retuns the list with newly inserted node
        **/
	// Method to insert a new node 
	public static linkedlist insert(linkedlist list, int data) 
	{    
                
		// Create a new node with given data 
                Node insertNode = new Node(data);
		// then make the new node as head 
                if (list.head == null) {  
                  list.head = insertNode;
                  return list;
                } 
                
                Node node = list.head;
                while (node.next != null) {
                  node = node.next;
                }
                node.next = insertNode;
                
		// Return the list by head
                
                return list;
	} 

	// **************TRAVERSAL************** 
        /**
         * prints out list nodes
         * @param node temp variable to traverse through list
         * @return nothing
        **/
	// Method to print the linkedlist. 
	public static void printList(linkedlist list) 
	{ 
	        Node node = list.head;
                while (node != null) {
                  System.out.print(node.data + ", ");
                  node = node.next;
                }
                System.out.println();
        }

	// **************DELETION BY KEY************** 
        /**
         * deletes by key
         * @param node temp var used to traverse through the list
         * @return returns list without specified key
         **/
	// Method to delete a node in the linkedlist by KEY 
	public static linkedlist deleteByKey(linkedlist list, int key) 
	{ 
		// Store head node 

		// 
		// CASE 1: 
		// If head node itself holds the key to be deleted 
                if (list.head.data == key) {
                  list.head = list.head.next;
                  System.out.println(key + " found and deleted"); 
                  return list;
                }


		// Return the updated List 

		// 
		// CASE 2: 
		// If the key is somewhere other than at head 
		// 
                Node node = list.head;
                while (node.next != null) {
                  if (node.next.data == key){
                    node.next = node.next.next;
                    System.out.println(key + " found and deleted");
                    return list;
                  }
                  node = node.next;
                }

		// CASE 3: The key is not present 
                System.out.println(key + " is not in list");
                return list;
	} 

	// **************DELETION AT A POSITION************** 
        /**
         * deletes node at specified index
         * @param node temp var to traverse through the list
         * @return returns list without node at specified index
         **/
	// Method to delete a node in the linkedlist by POSITION 
	public static linkedlist deleteAtPosition(linkedlist list, int index) 
	{ 
		// Store head node 

		// 
		// CASE 1: 
		// If index is 0, then head node itself is to be deleted 
                if (index == 0) {
		  System.out.println(index + " position element deleted"); 
                  list.head = list.head.next;
                  return list;
                }
			// Display the message 

			// Return the updated List 

		// 
		// CASE 2: 
		// If the index is greater than 0 but less than the size of linkedlist 
                Node node = list.head.next;
                int i = 1;
		while(node != null){
                  if (i+1 == index) {
                    System.out.println(index + " position element deleted"); 
                    node.next = node.next.next;
                    return list;    
                  }
                  node = node.next;
                  i++;
                }
                System.out.println(index + " position out of bounds");
                return list;
	} 

        /**
         * removes duplicate values in list
         * @param temp temp var used to traverse through the list
         * @return returns list without duplicate values
         **/
        private static linkedlist removeDuplicates(linkedlist list)
        {
	      Node temp = list.head;  
	      while(temp.next != null) {
                if (temp.data == temp.next.data) temp.next = temp.next.next;
                else temp = temp.next;
              }
	      return list;
        }

	// **************MAIN METHOD************** 

	// method to create a Singly linked list with n nodes 
	public static void main(String[] args) 
	{ 
		/* Start with the empty list. */
		linkedlist list = new linkedlist(); 

		// 
		// ******INSERTION****** 
		// 

		// Insert the values 
		list = insert(list, 1); 
		list = insert(list, 2); 
		list = insert(list, 3); 
		list = insert(list, 4); 
		list = insert(list, 5); 
		list = insert(list, 6); 
		list = insert(list, 7); 
		list = insert(list, 8); 

		// Print the linkedlist 
		printList(list); 

		// 
		// ******DELETION BY KEY****** 
		// 

		// Delete node with value 1 
		// In this case the key is ***at head*** 
		deleteByKey(list, 1); 

		// Print the linkedlist 
		printList(list); 

		// Delete node with value 4 
		// In this case the key is present ***in the middle*** 
		deleteByKey(list, 4); 

		// Print the linkedlist 
		printList(list); 

		// Delete node with value 10 
		// In this case the key is ***not present*** 
		deleteByKey(list, 10); 

		// Print the linkedlist 
		printList(list); 

		// 
		// ******DELETION AT POSITION****** 
		// 

		// Delete node at position 0 
		// In this case the key is ***at head*** 
		deleteAtPosition(list, 0); 

		// Print the linkedlist 
		printList(list); 

		// Delete node at position 2 
		// In this case the key is present ***in the middle*** 
		deleteAtPosition(list, 2); 

		// Print the linkedlist 
		printList(list); 

		// Delete node at position 10 
		// In this case the key is ***not present*** 
		deleteAtPosition(list, 10); 

		// Print the linkedlist 
		printList(list); 
                
                // Build a list with duplicates
                linkedlist duplicates = new linkedlist();
                duplicates = insert(duplicates, 1);
                duplicates = insert(duplicates, 1);
                duplicates = insert(duplicates, 1);
                duplicates = insert(duplicates, 2);
                duplicates = insert(duplicates, 3);
                duplicates = insert(duplicates, 3);
                duplicates = insert(duplicates, 4);
                // Print list with duplicates
                printList(duplicates);
                // Remove duplicates
                duplicates = removeDuplicates(duplicates);
                // Print list without duplicates
                printList(duplicates);
	} 
} 
