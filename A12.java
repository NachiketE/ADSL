import java.util.Scanner;

abstract class stack 
{
stack(){}
public final void function()
{
	int flag=0,op,data;
	Scanner obj= new Scanner(System.in);
	while(flag!=1)
	{
		System.out.println("\n1.Push the element \n2.Pop the element \n3.Display element at top \n4.Exit \n Enter your choice-:");
		op=obj.nextInt();
		switch(op)
		{
		case 1:
			
			push();
			break;
			
		case 2:
			data=pop();
			if(data!=0)
			{
				System.out.print(" is popped data!!");
			}
				
			break;
			
		case 3:
			data=top();
			if(data!=0)
			{
				System.out.print(" is Data at top!!");
			}
				
			break;
			
		case 4:
			flag=1;
			break;
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
	}
}
abstract protected void push();
abstract protected int pop();
abstract protected int top();
}

class Intstack extends stack
{
	 int[] stack=new int[50];
	 int top=-1;
	protected int pop()
	{
		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print(" '" +stack[top--] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	
	protected int top()
	{

		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.println("'" +stack[top] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	protected void push()
	{
		Scanner obj= new Scanner(System.in);
		int x=obj.nextInt();
		try
		{
			RuntimeException re= new RuntimeException("Overflow!!");
			if(top==6)
			{
				throw re;
			}
			else
			{
				stack[++top]=x;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
		}
	}

}


class Charstack extends stack
{
	int top=-1;
	 char[] stck=new char[50];
	protected int pop()
	{
		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print("'"+ stck[top--] +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	
	protected int top()
	{

		RuntimeException re= new RuntimeException("Underflow!!");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.print("'"+ stck[top]  +"'");
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
			return 0;
		}
	}
	
	protected void push()
	{
		Scanner obj= new Scanner(System.in);
		char x=obj.next().charAt(0);
		try
		{
			RuntimeException re= new RuntimeException("Overflow!!");
			if(top==49)
			{
				throw re;
			}
			else
			{
				stck[++top]=x;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught-: "+ret);
		}
	}

}


public class A12
{
	public static void main(String[] args)
	{
		
	System.out.println("-------------For Integer-----------");
	stack t= new Intstack();
	t.function();
	
	
	System.out.println("-------------For Characters-----------");
        stack t1=new Charstack();
	t1.function();
	
	}
}
/*
shreyas@shreyas:~/2416$ javac A12.java
shreyas@shreyas:~/2416$ java A12
-------------For Integer-----------

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
1
12

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
1
56

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
1
18

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
1
63

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
'63'
 is Data at top!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
2
 '63' is popped data!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
'18'
 is Data at top!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
2
 '18' is popped data!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
'56'
 is Data at top!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
2
 '56' is popped data!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
'12'
 is Data at top!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
2
 '12' is popped data!!
1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
Exception Caught-: java.lang.RuntimeException: Underflow!!

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
2
Exception Caught-: java.lang.RuntimeException: Underflow!!

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
3
Exception Caught-: java.lang.RuntimeException: Underflow!!

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
4
-------------For Characters-----------

1.Push the element 
2.Pop the element 
3.Display element at top 
4.Exit 
 Enter your choice-:
4
shreyas@shreyas:~/2416$ 
*/
