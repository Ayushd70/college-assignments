class Parents {
    public static void showInfo(){
        System.out.println("This is parent");
    }
}
/**
 * Childs extends Parents
 */
class Childs extends Parents {
    public static void showInfo(){
        System.out.println("This is child");
    }
}

class parent {
    public static void main(String[] args) {
        // When a method is overridden & both are static, then we say method in the super class is hidden by the method in the subclass
        Childs.showInfo();
        Childs.showInfo();

        // It is considered as compile time polymorphism
        Parents.showInfo();
    }
}