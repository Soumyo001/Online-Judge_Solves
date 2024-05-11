package com.mycompany.dstringdemo;
public class Main {
    public static void main(String[]args){
        msg m = null;ArrayString2D a=null;
        int [][]newArr={{1,2,3},{2,3,4,5,6,7},{5,6,7}};
        String[][]names={{"ini","mini","mainiii","mooo"},{"you","are","the","best"}};
        m=new msg("messege from msg",a);
        a=new ArrayString2D(newArr,names,"messege from array",m);
        a.print();
        System.out.println(a.sumArr(newArr));
        int [][]c=a.getArr();
        for(int i=0;i<a.getArr().length;i++){
            for(int j=0;j<c[i].length;j++){
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }
        try{
        m.msg();
        a.msg();
        m.showmsg();
        a.showmsg();
        }catch(Exception e){
            e.printStackTrace();
        }
   }
}
