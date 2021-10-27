class Dev {
    void code() {
        System.out.println("Coding..");
    }
}

class Develop extends Dev {
    void develop() {
        System.out.println("Developing..");
    }
}

class Build extends Dev {
    void build() {
        System.out.println("Building..");
    }
}

public class Hierarchical {
    public static void main(String[] args) {
        Develop d = new Develop();
        d.develop();
        d.code();
        Build c = new Build();
        c.build();
        c.code();
    }
}
