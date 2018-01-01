/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package javaapplication1;

/**
 *
 * @author Venkat
 */
public class Owner {
    
    String name;
    
    Long phone_no;
    Owner(String nam,Long pho){
        name=nam;
        phone_no=pho;
    }
    
    void display(){
        System.out.println("Name : "+name);
        System.out.println("Phone no : "+phone_no);
        System.out.println();
    }
    
}
