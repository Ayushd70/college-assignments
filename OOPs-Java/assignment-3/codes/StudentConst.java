public class StudentConst {
    private int id;
    private String name;

    public StudentConst() {
        this(122, "STCET student");
    }

    public StudentConst(int i, String s) {
        id = i;
        name = s;
    }

    public static void main(String[] args) {
        StudentConst student1 = new StudentConst();
        student1.id=122;
        student1.name="STCET Student";
        System.out.println(student1.id + " " + student1.name);
    }
}
