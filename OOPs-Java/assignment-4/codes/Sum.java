import java.util.Scanner;

public class Sum {
    int sumn;

    public Sum() {
        System.out.println("Bucket is empty");
    }

    public Sum(int n1, int n2) {
        this.sumn = n1 + n2;
    }

    public Sum(int n1, int n2, int n3) {
        this.sumn = n1 + n2 + n3;
    }

    public int getSumn() {
        return this.sumn;
    }

    public static void main(String[] args) {
        int n1, n2, n3;
        new Sum(); //Constructor with no arg
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers");
        n1 = sc.nextInt();
        n2 = sc.nextInt();
        System.out.println(new Sum(n1, n2).getSumn()); // two args
        System.out.println("Enter three nums");
        n1 = sc.nextInt();
        n2 = sc.nextInt();
        n3 = sc.nextInt();
        System.out.println(new Sum(n1, n2, n3).getSumn()); //three args
    }
}
