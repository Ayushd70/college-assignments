abstract class Bank {
    String b_name;
    String br_name;
    String ifsc;

    public void display(String y, String x, String z) {
        b_name = y;
        br_name = x;
        ifsc = z;
        System.out.println("Bank name is " + y);
        System.out.println("Branch name is " + x);
        System.out.println("IFSC Code is " + z);
    }

    abstract void getroi();
}

class SBI extends Bank {
    void getroi() {
        double amt = 50000 + ((50000 * 6) / 100);
        System.out.println("Amount in SBI is " + amt);
    }
}

class PNB extends Bank {
    void getroi() {
        double amt = 50000 + ((50000 * 7) / 100);
        System.out.println("Amount in PNB is " + amt);
    }
}

class AXIS extends Bank {
    void getroi() {
        double amt = 50000 + ((50000 * 8) / 100);
        System.out.println("Amount in AXIS is " + amt);
    }
}

class HDFC extends Bank {
    void getroi() {
        double amt = 50000 + ((50000 * 9) / 100);
        System.out.println("Amount in HDFC is " + amt);
    }
}

class abstraction2 {
    public static void main(String[] args) {
        Bank b1 = new SBI();
        Bank b2 = new PNB();
        Bank b3 = new AXIS();
        Bank b4 = new HDFC();
        b1.display("SBI", "Shyambazar", "SBIN0002054");
        b2.display("PNB", "Shyambazar", "PUNB0011720");
        b3.display("AXIS", "Shyambazar", "UTIB0000284");
        b4.display("HDFC", "Shyambazar", "BARB0DUMDUM");
        Bank b5 = new SBI();
        Bank b6 = new PNB();
        Bank b7 = new AXIS();
        Bank b8 = new HDFC();
        b5.getroi();
        b6.getroi();
        b7.getroi();
        b8.getroi();
        System.out.println("HDFC bank should be chosen for the person's FD as the rate of interest is 9%");
    }
}