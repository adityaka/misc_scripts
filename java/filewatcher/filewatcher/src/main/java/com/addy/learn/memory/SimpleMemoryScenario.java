package com.addy.learn.memory;

/**
 * Created by adityak on 7/5/17.
 */

import java.util.HashMap;
public class SimpleMemoryScenario {

    public static HashMap<String,String> map1;

    public static void main(String[] args){
        int i = 1;
        while(true){
            map1.put(Integer.toString(i),"Kapur");
            i++;
        }


    }
}
