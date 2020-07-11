package com.addy.learn.serialtest.simpleobjects;

import java.io.Serializable;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.Period;

public class Person implements Serializable {
    private static final long serialVersionUID = 1L;
    
    private String fname;
    private String mname;
    private String lname;
    private LocalDate dob;

    public String getName() {
        StringBuilder sb = new StringBuilder();
        sb.append(fname).append(" ").append(mname).append(" ").append(lname);
        return sb.toString();
    }

    public void setName(String first, String middle, String last) {
        fname  = first;
        mname = middle;
        lname = last;
    }

    public void setDob(int year, int month, int day) throws ParseException {
        dob = LocalDate.of(year, month, day);

    }

    public int getAge(){
       return Math.abs(Period.between(LocalDate.now(), dob).getYears());
    }

}
