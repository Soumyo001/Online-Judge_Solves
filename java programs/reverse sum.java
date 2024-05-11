import java.util.Scanner;
class Sum{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int i,sum=0;
        i=input.nextInt();
        input.close();
        while(i!=0){
            sum=(sum*10)+(i%10);
            i/=10;
        }
        System.out.println(sum);
    }
}