public class MobileDemo {
    public static void main(String[] args){
        Mobile ob1=new Mobile("Windows","Wn10",10015);
        System.out.println(ob1.maker);
        System.out.println(ob1.os);System.out.println(ob1.modelNumber);
        Mobile ob2=new Mobile();
        ob2.maker="Windows";ob2.os="Win11";ob2.modelNumber=10016;
        System.out.println(ob2.maker);
        System.out.println(ob2.os);System.out.println(ob2.modelNumber);
        Mobile ob3=new Mobile();
        ob3.print("Win11","Windows",10055);
        System.out.println(ob3.maker);
        System.out.println(ob3.os);System.out.println(ob3.modelNumber);
    }
}
