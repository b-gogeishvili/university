package company.util;

public class Activity<T> {
    private final String message;
    private final T issuer;

    public Activity(String message, T issuer) {
        this.message = message;
        this.issuer = issuer;
    }
}
