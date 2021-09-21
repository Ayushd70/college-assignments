import java.util.Scanner;

public class Vehicle {
    private int speed, wheelNum;
    private double mileage, distance, fuelFilled;
    private String gearType;

    public Vehicle() {
    }

    public void insertInfo(int speed, int wheelNum, String gearType, double distance, double fuelFilled) {
        this.speed = speed;
        this.wheelNum = wheelNum;
        this.gearType = gearType;
        this.distance = distance;
        this.fuelFilled = fuelFilled;
    }

    public void calSpeed() {
        mileage = distance / fuelFilled;
    }

    public void displayInfo() {
        String fmt = "Speed : %d , Wheels : %s, Gear Type : %s, Mileage : %s";
        System.out.printf(fmt, speed, wheelNum, gearType, mileage);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Vehicle s = new Vehicle();
        s.insertInfo(sc.nextInt(), sc.nextInt(), sc.next(), sc.nextDouble(), sc.nextDouble());
        s.calSpeed();
        s.displayInfo();
    }
}
