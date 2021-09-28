import java.util.Scanner;

class StudentFive {
    private int ID;
    private String name;

    StudentFive() {
        ID = 122;
        name = "STCET Student";
    }

    public void insertInfo() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Student ID  ");
        ID = sc.nextInt();
        System.out.println("Enter Student Name ");
        name = sc.next();


    }

    public void display() {
        System.out.println("Student Name : " + name);
        System.out.println("Student ID : " + ID);

    }

    public static void main(String[] args) {

        StudentFive[] students = new StudentFive[5];

        for (int i = 0; i < 5; i++) {
            students[i] = new StudentFive();
            students[i].insertInfo();

        }

        System.out.println("\nDetails of the Students are given below ");
        for (int i = 0; i < 5; i++) {
            students[i].display();

        }


    }
}