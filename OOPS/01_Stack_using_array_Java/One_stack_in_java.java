

import java.util.Scanner;

class Stack{
    int top;
    int size;
    int arr[];

    Stack(int size)
    {
        this.size = size;
        arr = new int[size];
        top =-1;
    }

    void push(int value)
    {
        if(top==size-1) 
        {
            System.out.println("Stack overflot");
            return;
        }

        arr[++top] = value;
        System.out.println(value +"pushed into stack");
    }

    void pop()
    {
        if(top==-1)
        {
            System.out.println("Stack underflow");
            return; 
        }

        System.out.println(arr[top--]+"popped form stack");
    }

    void peek()
    {
        if(top==-1) 
        {
            System.out.println("stack empty");
            return;
        }
        System.out.println("Top element:" +arr[top]);
    }

    void display()
    {
        if(top==-1)
        {
            System.out.println("Stack is empty");
            return ;
        }

        System.out.println("Stack elements:");
        for(int i= top; i>=0;i--) System.out.println(arr[i]);
    }

}

public class One_stack_in_java {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter stack size: ");
        int size = sc.nextInt();

        Stack stack = new Stack(size);

        while (true) {
            System.out.println("\n--- STACK MENU ---");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");

            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    int value = sc.nextInt();
                    stack.push(value);
                    break;

                case 2:
                    stack.pop();
                    break;

                case 3:
                    stack.peek();
                    break;

                case 4:
                    stack.display();
                    break;

                case 5:
                    System.out.println("Program terminated.");
                    sc.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}

    
