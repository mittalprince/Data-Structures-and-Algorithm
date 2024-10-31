package service;

public class HTTPService {
    private static HTTPService instance;
    private HTTPService() {
    }
    public static synchronized HTTPService getInstance() {
        if (instance == null) {
            instance = new HTTPService();
        }
        return instance;
    }
}
