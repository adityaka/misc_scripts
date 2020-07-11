package com.addy.learn.serialtest.simpleobjects;

import java.text.ParseException;
import java.util.Scanner;

public class PersonBuilderFromConsole {
    private static Person person = null;
    private static Scanner s = new Scanner(System.in);

    private static void setPersonNameFromConsole(){
        while(true) {
            System.out.println("Enter the name (first middle last) >");
            String name = s.nextLine();
            String[] nameFields = name.split("\\s+");
            if (nameFields.length <= 1) {
                System.out.println("Please enter at least first and last name separated by spaces");
                continue;
            }

            if (nameFields.length > 3) {
                if (nameFields.length > 10) {
                    System.out.println("too long a middle name, please enter initials for middle name not separated by spaces");
                    continue;
                }
                StringBuilder sb = new StringBuilder();
                for (int i = 1; i < nameFields.length - 2; i++) {
                    sb.append(nameFields[i]);
                }

                person.setName(nameFields[0], sb.toString(), nameFields[nameFields.length - 1]);
                break;

            } else {
                person.setName(nameFields[0], nameFields[1], nameFields[2]);
                break;
            }
        }
    }

    private static void setPersonDobFromConsole(){
        while(true) {
            System.out.println("Enter DOB in  day/month/year format user '/' as separator > ");
            String dobString = s.nextLine();
            String[] dobFields = dobString.split("/");

            if (dobFields.length > 3) {
                System.out.println("Enter a valid date dd/mm/yyyy");
                continue;
            }

            try {
                person.setDob(Integer.parseInt(dobFields[2]),
                        Integer.parseInt(dobFields[1]),
                        Integer.parseInt(dobFields[0]));
                break;
            } catch (ParseException e) {
                System.out.println("Invalid date please enter eagain");
                e.printStackTrace();
                continue;
            }
        }
    }

    public static Person getPerson(){
        if (null == person) {
            person = new Person();
            setPersonNameFromConsole();
            setPersonDobFromConsole();
        }
        return person;
    }

}
