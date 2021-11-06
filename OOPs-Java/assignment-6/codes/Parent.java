public class Parent {
    int x, y;

    public Parent(int a, int b) {
        x = a;
        y = b;
    }

    void show() {
        System.out.println("Value of x:" + x + "\nValue of y:" + y);
    }
}

class Child extends Parent {
    int z;

    Child(int a, int b, int c) {
        super(a, b);
        z = c;
    }

    void show() {
        System.out.println("Value of x:" + x + "\nValue of y:" + y + "\nValue of z:" + z);
    }

}

class Main {
    public static void main(String[] args) {
        Parent p = new Parent(10, 20);
        Child c = new Child(1, 2, 3);
        p.show();
        c.show();
    }
}
