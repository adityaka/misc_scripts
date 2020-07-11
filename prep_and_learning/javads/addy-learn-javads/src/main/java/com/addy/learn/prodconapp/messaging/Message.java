package com.addy.learn.prodconapp.messaging;

import java.io.Serializable;

public interface Message<Type> extends Serializable, Cloneable {
    Type get();
    void set(Type message);

}
