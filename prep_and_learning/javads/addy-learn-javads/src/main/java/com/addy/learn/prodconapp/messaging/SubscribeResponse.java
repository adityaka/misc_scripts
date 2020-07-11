package com.addy.learn.prodconapp.messaging;

public class SubscribeResponse extends MessageBase{
    boolean success;

    @Override
    public byte[] marshal() {
        return new byte[0];
    }

    @Override
    public MessageBase unmarshal(byte[] buffer) {
        return null;
    }
}
