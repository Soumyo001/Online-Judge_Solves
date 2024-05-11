package com.mycompany.arraylist;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class ArrayList {
    public static void main(String[] args) {
        //ArrayList and LinkedList
        Scanner sc=new Scanner(System.in);
        ArrayList<String>list1=new ArrayList<String>();
        list1.add("Hi");
        list1.add("Soumyo");
        list1.add("Sadman");
        list1.add(0, "Java");
        list1.add(1, "Says");
        list1.set(1,"ABC");
        list1.set(2,"XYZ");
        //list1.remove(2);
        //list1.clear();
        System.out.println(list1.size());
        System.out.println(list1);
        /*String[] s1=new String[10];
        for(int i=0;i<10;i++){
            String s=sc.nextLine();
            s1[i]=new String(s);
        }*/
        ArrayList<Integer>list2=new ArrayList<>();
        list2.add(Integer.SIZE);
        list2.add(5);
        list2.add(0, 45);
        list2.set(0, Double.SIZE);
        list2.add(0,55);
        //list2.remove(2);
        System.out.println(list2.size());
        System.out.println(list2);
        LinkedList<String>list3=new LinkedList<String>();
        list3.add("Hi");
        list3.add("Soumyo");
        list3.add("Sadman");
        list3.add(0,"Java");
        list3.add(1,"Says");
        list3.add(5,"input");
        list3.add(6,"output");
        list3.set(5,"ABC");
        list3.set(6,"XYZ");
        System.out.println(list3.size());
        System.out.println(list3);
        list3.remove(2);
        System.out.println(list3);
        //list3.clear();
        //System.out.println(list3);
        Object [] arr=list2.toArray();
        System.out.println(arr[0]);
        //HashSet
        System.out.println("For Hash set");
        HashSet<Integer>set1=new HashSet<>();
        set1.addAll(list2);
        System.out.println(set1);
        set1.add(100);
        System.out.println(set1);
        Object[]arr1=set1.toArray();
        System.out.println(arr1[3]);
        HashSet<Integer>set2=new HashSet<Integer>();
        set2.add(500);
        set2.add(2400);
        set2.add(600);
        System.out.println(set2);
        System.out.println(set2.hashCode());
        Object[] arr3=set2.toArray();
        System.out.println(arr3[0]);
        //Queue
        Queue<String> q1=new LinkedList<>();
        System.out.println("For Queue");
        q1.addAll(list3);
        q1.addAll(list1);
        System.out.println(q1);
        Queue<Integer> q2=new LinkedList<>();
        q2.addAll(set2);
        System.out.println(q2);
        System.out.println(q2.peek());
        System.out.println(q2);
    }
}
