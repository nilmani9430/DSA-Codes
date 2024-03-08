import java.io.IOException;
import java.util.*;
import java.lang.Math;

public class q4 extends IOException {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:- ");
        Integer n = sc.nextInt();

        int sum1=0, sum2=0;

        while(n != 0) {
            int num = n%10;
            if(num%2 != 0) {
                sum1 += num;
            }
            else {
                sum2 += num;
            }

            n = n/10;
        }

        System.out.print("Sum of even numbers:- " + sum2);
        System.out.println("");
        System.out.print("Sum of odd numbers:- " + sum1);
    }
}