package com.addy.learn;

import com.qubole.qds.sdk.java.client.DefaultQdsConfiguration;
import com.qubole.qds.sdk.java.client.QdsClient;
import com.qubole.qds.sdk.java.client.QdsClientFactory;
import com.qubole.qds.sdk.java.client.QdsConfiguration;
import com.qubole.qds.sdk.java.entities.Command;
import org.apache.commons.cli.*;

public class MainApp {


    public static Options cliOptions = new Options();

    public static void commandShell(QdsClient client){

    }

    public static void help(){

    }

    public static void main(String[] args){
        cliOptions.addOption("h","help",false,"Help Menu");
        cliOptions.addOption("e","endpoint",true,"Qubole URI which will be used as a target to fire the commands defaults to https://api.qubole.com");
        cliOptions.addOption("t","token",true,"Token for access");
        cliOptions.addOption("v","version",true,"API Version defaults to 1.2");

        CommandLineParser parser = new DefaultParser();
        CommandLine arguments = null;

        try {
            arguments = parser.parse(cliOptions,args);
        } catch (ParseException e) {
            //TODO : Add exception handling code piece here later
            e.printStackTrace();
        }

        String endpoint = "https://api.qubole.com";
        String version = "1.2";
        String token = null;

        if(arguments.hasOption("h") || arguments.hasOption("help")){
            help();
        }else if(arguments.hasOption("t") || arguments.hasOption("token")){
            token = arguments.getOptionValue("token");
        }else if (arguments.hasOption("e") || arguments.hasOption("endpoint")){
            endpoint = arguments.getOptionValue("endpoint");
        }else if(arguments.hasOption("v") || arguments.hasOption("verson")){
            version = arguments.getOptionValue("version");
        }else{
            System.out.println("Ignoring unknown option");
        }

        if (token == null){
            System.out.println("Token is a mandatory argument");
            help();
            System.exit(-1);
        }

        QdsClient client = QdsClientFactory.newClient(new DefaultQdsConfiguration(endpoint,token));
        commandShell(client);


    }
}
