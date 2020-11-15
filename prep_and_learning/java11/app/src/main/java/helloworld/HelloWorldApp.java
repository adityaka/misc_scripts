package helloworld;

import java.io.Console;

public class HelloWorldApp {
    public static final String DEFAULT_MESSAGE = "Hello World";
    private String message = HelloWorldApp.DEFAULT_MESSAGE;
    public String getMessage() {
        return message;
    }
    public HelloWorldApp() {

    }
    public HelloWorldApp(String message) {
        if (message != null && message.length() > 0) {
            this.message = message;
        }
    }

    public String toString() {
        return message;
    }

    public void displayMessage() {
        System.out.println(message);
    }
}
