package com.addy.learn.prodconapp.messaging;

public class HelloResponse extends MessageBase {
    @Override
    public byte[] marshal() {
        return new byte[0];
    }

    @Override
    public MessageBase unmarshal(byte[] buffer) {
        return null;
    }
}
