class student{
    public String name;
    public String s_id;
    static String college = "STCET";
    public student(String name,String s_id){
        this.name = name;
        this.s_id = s_id;
    }
    public static void show(){
        System.out.println("In Static method show");
        System.out.println("College : " + college);
    }
    public void display(){
        System.out.println("In non-static method display");
        System.out.println("Name: " + this.name);
        System.out.println("Student id: " + this.s_id);
    }
}
class Main1 {
    public static void main(String[] args) {
        student s1 = new student("Naruto", "ad11");
        student.show();
        s1.display();

    }
}
