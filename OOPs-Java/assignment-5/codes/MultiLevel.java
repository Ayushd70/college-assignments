class Animal {
    void eat() {
        System.out.println("eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("barking...");
    }
}

class Puppy extends Dog {
    void weep() {
        System.out.println("weeping...");
    }
}

class MultiLevel {
    public static void main(String[] args) {
        Puppy d = new Puppy();
        d.weep();
        d.bark();
        d.eat();
    }
}
