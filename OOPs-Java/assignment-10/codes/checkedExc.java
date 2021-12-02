import java.io.FileInputStream;
import java.io.IOException;

public class checkedExc {
    public static void main(String[] args) throws IOException {
        FileInputStream checkedExc = new FileInputStream("/Desktop/checked.txt");
        /*this file does not exist in the location
        This constructor FileInputStream
        throws FileNotFoundException which
        is a checked Exception*/
    }

}
