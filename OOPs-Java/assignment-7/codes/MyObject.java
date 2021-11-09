class MyObject {
    public static int counter = 0;

    MyObject() {
        counter = counter + 1;
    }
}

class Main3 {
    public static void main(String[] args) {
        MyObject Object1 = new MyObject();
        MyObject Object2 = new MyObject();
        MyObject Object3 = new MyObject();
        MyObject Object4 = new MyObject();
        MyObject Object5 = new MyObject();

        System.out.println("Value of Counter for Object 1: " + Object1.counter);
        System.out.println("Value of Counter for MyObject: " + MyObject.counter);
    }
}

