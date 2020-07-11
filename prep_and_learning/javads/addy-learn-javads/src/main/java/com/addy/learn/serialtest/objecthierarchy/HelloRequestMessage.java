package com.addy.learn.serialtest.objecthierarchy;

import java.util.UUID;

public class HelloRequestMessage extends  MessageBase{
    private static final long serialVersionUID = 1L;
    private UUID clientID;

    public UUID getClient() {
        return clientID;
    }

    public void setClientId(){
        clientID = UUID.randomUUID();
    }
}
