class staticDemo {
    static int a;
    static int b;

    static {
        a = 10;
        System.out.println("Static block 1");
    }

    static {
        b = 5 * a;
        System.out.println("Static block 2 & value of b is : " + b);
    }

    public static void member(int val) {
        System.out.println("Value of a is : " + a);
        System.out.println("Value of argument : " + val);
    }
}

class stat {
    public static void main(String[] args) {
        staticDemo.member(30);
    }
}