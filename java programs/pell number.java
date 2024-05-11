class pellNumber{
    public static void main(String[] args){
        int a=0,b=1,n;
        System.out.print(a+","+b);
        for(int i=0;i<18;i++){
               System.out.print(","+(2*b+a));
               n=2*b+a;
               a=b;b=n;
        }
    }
}