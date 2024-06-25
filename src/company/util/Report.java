package company.util;

public class Report<T> {
    private final String message;
    private final T data;

    public Report(String message, T data) {
        this.message = message;
        this.data = data;
    }
}
