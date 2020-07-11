package com.addy.learn.serialtest.objecthierarchy;

import java.io.Serializable;
import java.util.UUID;

public class MessageBase implements Serializable, Cloneable {
    private static final long serialVersionUID = 1L;
    private UUID messageId = UUID.randomUUID();

    public UUID getId() {
        return messageId;
    }

}
