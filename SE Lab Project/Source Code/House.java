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
public class House {
    
    int house_no;
    String model;
    String place;
    float fare;
    boolean isRented;
    
    Owner owner;
    
    House(int no,String mod,String plac,float far,boolean is,String nam,Long pho){
       house_no=no;
       model=mod;
       place=plac;
       fare=far;
       isRented=is;
       owner=new Owner(nam,pho);
    }
    
    void display(){
        System.out.println("\nHouse no : "+house_no);
        System.out.println("Model : "+model);
        System.out.println("Place : "+place);
        System.out.println("Fare : "+fare);
        System.out.println();
    }
    
}
