import java.io.IOException;
import java.util.*;

public class q1 extends IOException {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Income:- ");
        Integer salary = sc.nextInt();

        Integer incomeTax=0;

        if(salary<=50000) {
            incomeTax=0;
        }
        else if(salary>50000 && salary<=60000) {
            incomeTax = ((salary-50000)*10)/100;
        }
        else if(salary>60000 && salary<=150000) {
            incomeTax = ((salary-60000)*20)/100;
        }
        else {
            incomeTax = ((salary-150000)*30)/100;
        }

        System.out.println("Your Income Tax:- ");
        System.out.println(incomeTax);
    }
}