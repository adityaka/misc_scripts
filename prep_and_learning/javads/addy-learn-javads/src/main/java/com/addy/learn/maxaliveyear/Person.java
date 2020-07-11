package com.addy.learn.maxaliveyear;

import java.time.LocalDate;
import java.lang.IllegalArgumentException;

public class Person {
    private String name;
    private int yearOfBirth;
    private int yearOfDeath;

    public static int MAX_PERSON_AGE = 110;

    private boolean isValidYear(int year) {
        int currentYear = LocalDate.now().getYear();
        return year >= 1600 && year <= currentYear;
    }
    private boolean isValidBirthAndDeathYear(int birthYear, int deathYear){
        if (!isValidYear(birthYear) || !isValidYear(deathYear)){
            return false;
        }else if (deathYear - birthYear < 0){
            return false;
        } else {
            return deathYear - birthYear <= MAX_PERSON_AGE;
        }
    }
    public Person(String name, int yearOfBirth, int yearOfDeath) throws IllegalArgumentException  {

        if(!isValidBirthAndDeathYear(yearOfBirth, yearOfDeath)){
            throw new IllegalArgumentException("birth year and death year combination is invalid");
        }
        this.yearOfBirth = yearOfBirth;
        this.yearOfDeath = yearOfDeath;
        this.name = name;
    }
    public int getYearsAlive() {
        return yearOfDeath - yearOfBirth;
    }

    public int getYearOfBirth(){
        return yearOfBirth;
    }

    public int getYearOfDeath(){
        return yearOfDeath;
    }
    public String getName(){
        return name;
    }
    public boolean isPersonAlive(int year){
        return year >= yearOfBirth && year < yearOfDeath;
    }
}
