package sample.server;

import sample.protocal.HttpProtocal;

public class Application implements HttpProtocal {
    @Override
    public String get(String webSiteName){
        return "Hello " + webSiteName;
    }
}
