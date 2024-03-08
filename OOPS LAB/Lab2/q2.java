import java.io.IOException;
import java.util.*;
import java.lang.Math;

public class q2 extends IOException {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Size of array 1:- ");
        Integer n = sc.nextInt();

        System.out.println("Size of array 2:- ");
        Integer m = sc.nextInt();

        System.out.println("Elements of array 1:- ");
        int arr1[] = new int[n];
        for(int i=0; i<n; i++) {
            Integer num = sc.nextInt();
            arr1[i] = num;
        }

        System.out.println("Elements of array 2:- ");
        int arr2[] = new int[n];
        for(int i=0; i<n; i++) {
            Integer num = sc.nextInt();
            arr2[i] = num;
        }
        // System.out.println(" ");
        int num = Math.abs(n-m);
        if(num > 1) {
            System.out.println("Cant be done");
        }
        else {
            int ans[] = new int[n+m];

            int p1=0;
            int p2=0;

            if(n >= m) {
                for(int i=0; i<n+m; i++) {
                    if(i%2 == 0) {
                        ans[i] = arr1[p1];
                        p1++;
                    }
                    else {
                        ans[i] = arr2[p2];
                        p2++;
                    }
                }
            }
            else {
                for(int i=0; i<n+m; i++) {
                    if(i%2 == 0) {
                        ans[i] = arr2[p1];
                        p1++;
                    }
                    else {
                        ans[i] = arr1[p2];
                        p2++;
                    }
                }
            }

            System.out.println("Final Array:- ");
            for(int i=0; i<n+m; i++) {
                System.out.print(ans[i]+" ");
            }
        }




        // System.out.println("yes");
    }
}