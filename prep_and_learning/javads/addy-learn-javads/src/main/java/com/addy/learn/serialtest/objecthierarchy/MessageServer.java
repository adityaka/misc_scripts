package com.addy.learn.serialtest.objecthierarchy;


import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.SocketAddress;

public class MessageServer {
    public static int DEFAULT_SERVER_PORT = 59876;
    public static String DEFAULT_LISTENING_HOST = "localhost";
    public static SocketAddress DEFAULT_ADDRESS = InetSocketAddress.createUnresolved(DEFAULT_LISTENING_HOST, DEFAULT_SERVER_PORT);

    private ServerSocket s;

    public MessageServer() throws IOException {
        s = new ServerSocket();
        s.bind(DEFAULT_ADDRESS);
    }

    public MessageServer(SocketAddress address ) throws IOException {
        s = new ServerSocket();
        s.bind(address);
    }

    public void startServer() {
        while(true) {
           
        }
    }

}
