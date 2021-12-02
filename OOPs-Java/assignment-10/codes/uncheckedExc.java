public class uncheckedExc {
    public static void main(String[] args) {
        try {
            int a = 1;
            System.out.println(a / 0);
        } finally {
            System.out.println("Rest of the code");
        }
    }

}
