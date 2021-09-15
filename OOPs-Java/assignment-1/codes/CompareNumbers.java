import java.util.Scanner;

class CompareNumbers {
    public static void main(String[] args) {
        double a, b, c;
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the first number");
        a = in.nextInt();

        System.out.println("Enter the second number");
        b = in.nextInt();

        System.out.println("Enter the third number");
        c = in.nextInt();

        if (a >= b && a >= c)
            System.out.println(a + " is the largest number");

        else if (b >= a && b >= c)
            System.out.println(b + " is the largest number");

        else
            System.out.println(c + " is the largest number");
    }
}