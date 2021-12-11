class MyException extends Exception {
    public MyException(String s) {
        super(s);
    }
}

public class excepThrow {
    public static void main(String[] args) {
        try {
            throw new MyException("Exception!!");
        } catch (MyException e) {
            System.out.println("Exception Caught!!");
            System.out.println(e.getMessage());
        }
    }
}
