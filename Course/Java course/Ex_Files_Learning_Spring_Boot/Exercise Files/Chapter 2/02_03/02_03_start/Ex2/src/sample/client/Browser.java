package sample.client;

import sample.protocal.HttpProtocal;
import sample.server.Application;

public class Browser {
    public static void main(String[] args){
        HttpProtocal protocal = new Application();
        System.out.println(protocal.get("Google"));
    }
}
