package com.addy.learn.prodconapp.messaging;

public class MessageBase implements Message<MessageBase> {

    private MessageBase message;

    @Override
    public synchronized MessageBase get() {
        return message;
    }

    @Override
    public synchronized  void set(MessageBase message) {
        this.message = message;
    }

}