class Shape {
    double a, b, c;

    void calculateAreaTri(double x, double y) {
        a = (x * y) / 2;
    }

    void calculateAreaRec(float x, float y) {

        b = x * y;
    }

    void calculateAreaCir(double r) {

        c = 3.14 * r * r;
    }

    void display() {
        System.out.println("Area of the scalene triangle: " + a + " sq units");
        System.out.println("Area of the rectangle: " + b + " sq units");
        System.out.println("Area of the circle: " + c + " sq units");
    }

    public static void main(String[] args) {
        Shape obj = new Shape();

        obj.calculateAreaTri(5, 6);
        obj.calculateAreaRec(10, 22);
        obj.calculateAreaCir(6.1);
        obj.display();
    }
}