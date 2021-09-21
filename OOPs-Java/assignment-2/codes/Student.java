import java.util.Scanner;

public class Student {
    private int id, year;
    private String name, department;

    public Student() {
    }

    public void insertInfo(int id, String name, String department, int year) {
        this.id = id;
        this.name = name;
        this.department = department;
        this.year = year;
    }

    public void displayInfo() {
        String fmt = "ID : %d , Name : %s, Department : %s, Year : %d";
        System.out.printf(fmt, id, name, department, year);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student s = new Student();
        s.insertInfo(sc.nextInt(), sc.next(), sc.next(), sc.nextInt());
        s.displayInfo();
    }
}