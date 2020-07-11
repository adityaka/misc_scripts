package com.addy.learn.sorts;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class MergeSort<T> {
    List<T> list; 
    public MergeSort(T[] listOfNumbers) {
        list = new ArrayList<>(Arrays<T>.asList(listOfNumbers));
    }
    
}