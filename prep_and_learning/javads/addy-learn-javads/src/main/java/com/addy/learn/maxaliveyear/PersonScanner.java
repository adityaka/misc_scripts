package com.addy.learn.maxaliveyear;

import java.text.ParseException;
import java.util.Scanner;

public class PersonScanner {

    public static Person getFromConsole() throws  IllegalArgumentException {
        Scanner s = new Scanner(System.in);
        String personDetails = s.nextLine();
        String[] personFields = personDetails.split("\\s+");
        if (personFields.length != 3) {
            throw new IllegalArgumentException("Person details needs <name birthYear deathYear>");
        }
        try {
            Person p = new Person(personFields[0], Integer.parseInt(personFields[1]), Integer.parseInt(personFields[2]));
            return p;
        }  catch (NumberFormatException nfe){
            nfe.printStackTrace();
            throw new IllegalArgumentException("Year of birth and death should be integers");
        }catch (IllegalArgumentException iae){
            iae.printStackTrace();
            throw iae;
        }
    }
}
