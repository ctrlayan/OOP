import java.util.Scanner;

public class CalculatorApp {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Basic Calculator");

        System.out.print("Enter first value: ");
        double first = input.nextDouble();

        System.out.print("Enter second value: ");
        double second = input.nextDouble();

        System.out.println("\nSelect Operation:");
        System.out.println("1 -> Add");
        System.out.println("2 -> Subtract");
        System.out.println("3 -> Multiply");
        System.out.println("4 -> Divide");
        System.out.print("Your choice: ");
        int option = input.nextInt();

        double answer = 0;
        boolean isValid = true;

        if (option == 1) {
            answer = first + second;
            System.out.println("\nOutput:");
            System.out.println(first + " + " + second + " = " + answer);

        } else if (option == 2) {
            answer = first - second;
            System.out.println("\nOutput:");
            System.out.println(first + " - " + second + " = " + answer);

        } else if (option == 3) {
            answer = first * second;
            System.out.println("\nOutput:");
            System.out.println(first + " * " + second + " = " + answer);

        } else if (option == 4) {
            if (second == 0) {
                System.out.println("\nError:");
                System.out.println("Division by zero is not allowed.");
                isValid = false;
            } else {
                answer = first / second;
                System.out.println("\nOutput:");
                System.out.println(first + " / " + second + " = " + answer);
            }

        } else {
            System.out.println("\nError:");
            System.out.println("Wrong option selected.");
            isValid = false;
        }

        if (isValid) {
            System.out.println("=============");
        }

        input.close();
    }
}