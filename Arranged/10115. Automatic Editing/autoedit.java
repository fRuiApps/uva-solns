import java.util.*;

public class autoedit {

    public static void main(String[] args) {

     Scanner in=new Scanner(System.in);

     String s,p;

     String[] rules=new String[30];

     int i,j,n;

     while(true) {

     s=in.nextLine();

     n=Integer.parseInt(s);

     if(n==0) break;

     for(i=0;i<n;i++) {

         rules[2*i]=in.nextLine();

         rules[2*i+1]=in.nextLine();

     }

     p=in.nextLine();

     for(i=0;i<n;i++) {

         while(p.indexOf(rules[2*i])>=0) {

             p=p.replaceFirst(rules[2*i],rules[2*i+1]);

             }

     }

     System.out.println(p);

     }

    }


}
