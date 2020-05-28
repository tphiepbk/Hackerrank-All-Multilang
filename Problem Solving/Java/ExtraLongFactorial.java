import java.math.BigInteger;

public class ExtraLongFactorial {

    public void extraLongFactorial(int n) {
        BigInteger res = new BigInteger("1");
        for (int i = n ; i >= 1 ; i--) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        System.out.println(res);
    } 
}