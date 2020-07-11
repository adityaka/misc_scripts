package com.addy.learn.serialtest.objecthierarchy;

public class HelloMessageResponse extends  MessageBase{
    private static final long serialVersionUID = 1L;
    
     boolean accpted = false;

     public boolean getAcceptance(){
         return accpted;
     }

     public void helloAccepted() {
         accpted = true;
     }


}
