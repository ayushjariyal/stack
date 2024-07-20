import java.util.*;

public class StackGenerics<Item> {
    private Node first = null;

    private class Node {
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public void push (Item item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
    }

    public Item pop() {
        Item item = first.item;
        first = first.next;
        return item;
    }

    public void printStack() {
        Node current = first;
        System.out.println("Items in the stack: ");
        while (current != null) {
            System.out.println(current.item);
            current = current.next;
        }
    }

    public static void main(String[] args) {
        StackGenerics<String> stack = new StackGenerics<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a string to push(or type 'pop' to pop, 'exit' to exit): ");
            String input = scanner.nextLine();

            if (input.equals("exit")) {
                break;
            }
            else if (input.equals("pop")) {
                if (stack.isEmpty()) {
                    System.out.println("Stack is Empty.");
                }
                else {
                    String item = stack.pop();
                    System.out.println("Item Popped: " + item);
                }
            }
            else {
                stack.push(input);
                System.out.println("Item Pushed: " + input);
            }
        }

        stack.printStack();
        scanner.close();
    }
}
