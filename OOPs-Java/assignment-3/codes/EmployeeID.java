import java.util.Scanner;

class EmployeeID {
    private int EID;
    private String Ename;
    private String Dept;

    EmployeeID(int Eid, String ename, String dept) {
        EID = Eid;
        Ename = ename;
        Dept = dept;

    }

    public void getInfo() {
    }

    public void displayInfo() {
        System.out.println("Employee Name : " + Ename);
        System.out.println("Employee ID : " + EID);
        System.out.println("Employee Dept : " + Dept);

    }


}

class Employees {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        EmployeeID[] Emp = new EmployeeID[5];

        for (int i = 0; i < 5; i++) {
            int Eid;
            String Ename, Dept;
            System.out.println("Enter Employee ID  ");
            Eid = sc.nextInt();
            System.out.println("Enter Employee Name ");
            Ename = sc.next();

            System.out.println("Enter Employee Department (Choose from IT,Sales,Accounts,HR)  ");
            Dept = sc.next();
            Emp[i] = new EmployeeID(Eid, Ename, Dept);

        }


        System.out.println("\nDetails of the employees given below");

        for (int i = 0; i < 5; i++) {
            Emp[i].displayInfo();
        }

    }

}