abstract class Employee {
    int emp_id;
    String emp_name;
    String emp_doj;

    public void getinfo(int y, String x, String z) {
        emp_id = y;
        emp_name = x;
        emp_doj = z;
        System.out.println("Employee id is " + y);
        System.out.println("Employee name is " + x);
        System.out.println("Employee joining data is " + z);
    }

    abstract void getsal();
}

class Manager extends Employee {
    void getsal() {
        int p1 = 65000 + ((65000 * 99) / 100);
        System.out.println("Salary is" + p1);
    }
}

class Salesman extends Employee {
    void getsal() {
        int p1 = 15000 + ((15000 * 85) / 100);
        System.out.println("Salary is" + p1);
    }
}

class abstraction {
    public static void main(String[] args) {
        Employee e1 = new Salesman();
        Employee e2 = new Manager();
        e1.getinfo(1, "Mr. X", "16.11.21");
        e2.getinfo(2, "Mr. Y", "15.11.21");
        Employee e = new Manager();
        Employee ep = new Salesman();
        e.getsal();
        ep.getsal();
    }
}
