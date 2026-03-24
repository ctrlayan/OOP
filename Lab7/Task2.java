import java.util.Scanner;

public class Length {

    private int ft;
    private int in;

    // Default constructor
    public Length() {
        ft = 0;
        in = 0;
    }

    // Parameterized constructor
    public Length(int f, int i) {
        ft = f;
        in = i;
        adjust();
    }

    // Input method
    public void inputLength() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter feet: ");
        ft = sc.nextInt();

        System.out.print("Enter inches: ");
        in = sc.nextInt();

        adjust();
    }

    // Display method
    public void displayLength() {
        System.out.println(ft + " Ft " + in + " Inch");
    }

    // Addition
    public Length addLength(Length obj) {
        Length temp = new Length();
        temp.ft = this.ft + obj.ft;
        temp.in = this.in + obj.in;
        temp.adjust();
        return temp;
    }

    // Subtraction
    public Length subtractLength(Length obj) {
        Length temp = new Length();
        temp.ft = this.ft - obj.ft;
        temp.in = this.in - obj.in;

        if (temp.in < 0) {
            temp.ft -= 1;
            temp.in += 12;
        }

        temp.adjust();
        return temp;
    }

    // Normalize inches into feet
    private void adjust() {
        if (in >= 12) {
            ft += in / 12;
            in = in % 12;
        }
    }

    // Main method
    public static void main(String[] args) {

        System.out.println("Distance Calculator\n");

        Length l1 = new Length();
        Length l2 = new Length();

        System.out.println("Enter First Distance");
        l1.inputLength();

        System.out.println("\nEnter Second Distance");
        l2.inputLength();

        System.out.println("\nEntered Values:");
        System.out.print("First: ");
        l1.displayLength();
        System.out.print("Second: ");
        l2.displayLength();

        System.out.println("\nAfter Addition:");
        Length total = l1.addLength(l2);
        System.out.print("Result: ");
        total.displayLength();

        System.out.println("\nAfter Subtraction:");
        Length difference = l1.subtractLength(l2);
        System.out.print("Result: ");
        difference.displayLength();
    }
}