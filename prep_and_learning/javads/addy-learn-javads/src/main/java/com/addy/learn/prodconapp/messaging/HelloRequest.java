package com.addy.learn.prodconapp.messaging;

import java.util.UUID;

public class HelloRequest extends  MessageBase{

    @Override
    public byte[] marshal() {
        return new byte[0];
    }

    @Override
    public MessageBase unmarshal(byte[] buffer) {
        return null;
    }
}
