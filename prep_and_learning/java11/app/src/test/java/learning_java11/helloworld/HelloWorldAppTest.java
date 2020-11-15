package learning_java11.helloworld;

import helloworld.HelloWorldApp;
import org.junit.Test;
import static org.junit.Assert.*;
public class HelloWorldAppTest {

    static String customMessage = "Custom Greeting";
    static String customNullMessage = null;
    static String customEmptyString = null;

    @Test
    public void testDefaultConstructor() {
        var app = new HelloWorldApp();
        assertNotNull(app.getMessage());
    }

    @Test
    public void testNullOrEmptyMessage() {
        var appNullMessage = new HelloWorldApp(customNullMessage);
        assertEquals(HelloWorldApp.DEFAULT_MESSAGE, appNullMessage.getMessage());
        var appEmptyMessage = new HelloWorldApp(customEmptyString);
        assertEquals(HelloWorldApp.DEFAULT_MESSAGE, appNullMessage.getMessage());
    }

    @Test
    public void testParameterizedConstructor() {
        var app = new HelloWorldApp(customMessage);
        assertEquals(customMessage, app.getMessage());
    }
}
