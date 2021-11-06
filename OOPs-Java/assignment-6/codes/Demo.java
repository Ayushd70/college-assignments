class Demo {
    static int my_count = 2;

    public void increment() {
        my_count++;
    }

    public static void main(String[] args) {
        Demo o1 = new Demo();
        Demo o2 = new Demo();
        o1.increment();
        o2.increment();
        System.out.println("The count of first object is " + my_count);
        System.out.println("The count of second object is " + my_count);
    }
}
