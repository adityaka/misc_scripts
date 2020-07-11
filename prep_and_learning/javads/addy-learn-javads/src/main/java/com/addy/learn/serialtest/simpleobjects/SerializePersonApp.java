package com.addy.learn.serialtest.simpleobjects;
/**
 * This is a simple example serialization and deserialization
 * to a file and back to the object
 */
import java.io.*;

public class SerializePersonApp {
    public static void main(String[] args) throws IOException, ClassNotFoundException {

        Person p = PersonBuilderFromConsole.getPerson();
        FileOutputStream fos = new FileOutputStream(new File("person.ser"));
        ObjectOutput oo = new ObjectOutputStream(fos);
        oo.writeObject(p);
        oo.close();
        FileInputStream fis = new FileInputStream(new File("person.ser"));
        ObjectInput oi = new ObjectInputStream(fis);
        Person p1 = (Person) oi.readObject();
        System.out.println("Person After deserialization is " + p1.getName() + " who is " + p1.getAge() + " years old");
      }
}
