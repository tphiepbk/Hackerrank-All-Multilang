import java.util.Scanner;

public class MainClass {
    public static void main(String[] args) {
        Scanner inPut = new Scanner(System.in);
        int n = inPut.nextInt();
        ExtraLongFactorial obj = new ExtraLongFactorial();
        obj.extraLongFactorial(n);
    }
}