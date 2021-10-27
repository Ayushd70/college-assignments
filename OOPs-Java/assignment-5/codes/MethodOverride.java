class Company
{
    void address()
    {
        System.out.println("Address Details");
    }
}
class Amazon extends Company
{
    void address()
    {
        System.out.println("AMAZON\nAddress:xyz Road,Chennai.");
        System.out.println("CEO: Andy Jassy");
    }
}
class Flipkart extends Company
{
    void address()
    {
        System.out.println("FLIPKART\nAddress:abc Road,New Delhi.");
        System.out.println("CEO: Kalyan Krishnamurthy");
    }
}
public class MethodOverride
{
    public static void main(String[] args)
    {
        Company obj1=new Company();
        Amazon obj2=new Amazon();
        Flipkart obj3=new Flipkart();
        obj1.address();
        obj2.address();
        obj3.address();
    }
}
