import java.util.*;

public class A13 {
	Scanner obj= new Scanner(System.in);
	void main_func()
	{
		int op,flag=0;
		while(flag!=1)
		{
			System.out.println("\n1.Linked List \n2.Stack \n3.Priority Queue \n4.Dequeue \n5.HashSet \n6.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			Linked();
			break;
			
		case 2:
			Stack();
			break;
			
		case 3:
			Queue();
			break;
			
		case 4:
			Dequeue();
			break;
			
		case 5:
			HashSet();
			break;
			
		case 6:
			flag=1;
			return;
			
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
		}
	}
	
	public void Linked()
	{
		LinkedList<Integer> l= new LinkedList<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add Last \n3.Remove First \n4.Remove Last \n5.Display whole list \n6.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addFirst(data);
			break;
			
		case 2:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addLast(data);
			break;
			
		case 3:
			l.removeFirst();
			break;
			
		case 4:
			l.removeLast();
			break;
			
		case 5:
			System.out.println("Contents of Linked List are-: "+l);
			break;
			
		case 6:
			flag=1;
			break;
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
		}

		//main_func();
	}
	
	public void Stack()
	{
		Stack<Integer> st=new Stack<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Push \n2.Pop \n3.Display Top \n4.IsEmpty \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			st.push(data);
			break;
			
		case 2:
			System.out.println("Data popped from stack is-: " +st.pop());
			break;
			
		case 3:
			System.out.println("Data at top of stack is-: " +st.peek());
			break;
			
		case 4:
			if(st.isEmpty())
			{
				System.out.println("Stack is Empty!!");
			}
			else
			{
				System.out.println("Stack is not empty!!");
			}
			break;
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void Queue()
	{
		PriorityQueue<Integer> pq= new PriorityQueue<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add Data \n2.Pop \n3.Display head \n4.size \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in Priority Queue-: ");
			data=obj.nextInt();
			pq.add(data);
			break;
			
		case 2:
			System.out.println("Data popped from Priority Queue is-: " +pq.poll());
			break;
			
		case 3:
			System.out.println("Data at top of Priority Queue is-: " +pq.peek());
			break;
			
		case 4:
			System.out.println("Size of Priority Queue is-: " +pq.size());
			break;
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void Dequeue()
	{
		ArrayDeque<Integer> dq= new ArrayDeque<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add last \n3.Display head \n4.Display Tail \n5.Remove First \n6.Remove Last \n7.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in Deque-: ");
			data=obj.nextInt();
			dq.addFirst(data);
			break;
			
		case 2:
			System.out.println("Enter data to be added in Deque-: ");
			data=obj.nextInt();
			dq.addLast(data);
			break;
			
		case 3:
			System.out.println("Element at first position is-:  "+dq.peekFirst());
			break;
			
		case 4:
			System.out.println("Element at last position is-:  "+dq.peekLast());
			break;
			
		case 5:
			System.out.println("Data removed from front is-: " +dq.pollFirst());
			break;
			
		case 6:
			System.out.println("Data removed from Last is-: " +dq.pollLast());
			break;
			
		case 7:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public void HashSet()
	{
		HashSet<Integer> hs= new HashSet<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add element \n2.Remove element \n3.Display whole \n4.size\n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in HashSet-: ");
			data=obj.nextInt();
			hs.add(data);
			break;
			
		case 2:
			System.out.println("Enter data to be removed from Deque-: ");
			data=obj.nextInt();
			hs.remove(data);
			break;
			
		case 3:
			System.out.println("Elements in whole Hashset are-:  "+hs);
			break;
			
		case 4:
			System.out.println("Size of HashSet is-:  "+hs.size());
			break;
			
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		//main_func();
	}
	
	public static void main(String[] args)
	{
		A13 d= new A13();
		d.main_func();
	}
}
/*
shreyas@shreyas:~/2416$ javac A13.java
shreyas@shreyas:~/2416$ java A13

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
1

1.Add First 
2.Add Last 
3.Remove First 
4.Remove Last 
5.Display whole list 
6.Exit
1
Enter data to be added in list-: 
3

1.Add First 
2.Add Last 
3.Remove First 
4.Remove Last 
5.Display whole list 
6.Exit

6

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
2

1.Push 
2.Pop 
3.Display Top 
4.IsEmpty 
5.Exit
1
Enter data to be added in list-: 
56

1.Push 
2.Pop 
3.Display Top 
4.IsEmpty 
5.Exit
1
Enter data to be added in list-: 
45

1.Push 
2.Pop 
3.Display Top 
4.IsEmpty 
5.Exit
3
Data at top of stack is-: 45

1.Push 
2.Pop 
3.Display Top 
4.IsEmpty 
5.Exit
4
Stack is not empty!!

1.Push 
2.Pop 
3.Display Top 
4.IsEmpty 
5.Exit
5

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
3

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
2
Data popped from Priority Queue is-: null

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
1
Enter data to be added in Priority Queue-: 
6

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
1
Enter data to be added in Priority Queue-: 
4

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
3
Data at top of Priority Queue is-: 4

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
4
Size of Priority Queue is-: 2

1.Add Data 
2.Pop 
3.Display head 
4.size 
5.Exit
5

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
4

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
2
Enter data to be added in Deque-: 
78

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
2
Enter data to be added in Deque-: 
98

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
3
Element at first position is-:  78

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
4
Element at last position is-:  98

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
5
Data removed from front is-: 78

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
6
Data removed from Last is-: 98

1.Add First 
2.Add last 
3.Display head 
4.Display Tail 
5.Remove First 
6.Remove Last 
7.Exit
7

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
5

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
1
Enter data to be added in HashSet-: 
12

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
1
Enter data to be added in HashSet-: 
34

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
1
Enter data to be added in HashSet-: 
56

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
2
Enter data to be removed from Deque-: 
23

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
3
Elements in whole Hashset are-:  [34, 56, 12]

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
4
Size of HashSet is-:  3

1.Add element 
2.Remove element 
3.Display whole 
4.size
5.Exit
5

1.Linked List 
2.Stack 
3.Priority Queue 
4.Dequeue 
5.HashSet 
6.Exit
6
shreyas@shreyas:~/2416$ 
*/
