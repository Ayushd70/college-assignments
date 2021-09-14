import java.util.Scanner;
//class of student name, roll number, department.

public class StudentInfo {
    public static void main(String[] args) {
        String name, department;
        int roll;
        Scanner in = new Scanner(System.in);

        System.out.println("Enter Student Name");
        name = in.nextLine();

        System.out.println("Enter Department");
        department = in.nextLine();

        System.out.println("Enter Roll Number");
        roll = in.nextInt();

        System.out.println("Students Name is:" + name);
        System.out.println("Students Roll is:" + roll);
        System.out.println("Students Department is:" + department);

    }
}
