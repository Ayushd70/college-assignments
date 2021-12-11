public class tryCatchExcep {
    int a;

    public tryCatchExcep(int a) {
        this.a = a;
    }

    public int add() {
        a = a + 10;
        try {
            a = a + 10;
            try {
                a = a * 10;
                throw new Exception();
            } catch (Exception e) {
                a = a - 10;
            }
        } catch (Exception e) {
            a = a - 10;
        } finally {
            System.out.println("Finally block..");
        }
        return a;
    }

    public static void main(String[] args) {
        tryCatchExcep ob = new tryCatchExcep(10);
        int result = ob.add();
        System.out.println("Result=" + result);
    }
}
