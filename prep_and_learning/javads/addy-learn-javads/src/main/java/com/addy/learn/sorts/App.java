package com.addy.learn.sorts;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class App {

    public static Integer[] scanArrayOfIntegers( String[] args, String delim) throws NumberFormatException {
        
        Scanner s = new Scanner(System.in);
        String[] strings = s.nextLine().split(delim);
        List<Integer> listOfNumbers = new ArrayList<>();
        for (String str : strings){
            listOfNumbers.add(Integer.parseInt(str));
        }
        return (Integer[])listOfNumbers.toArray();
    }

    public static void main(String[] args){
        
        try {     
            Integer[] listOfNumbers = scanArrayOfIntegers(args, ",");
            

        } catch (NumberFormatException e ) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

            
    }
}