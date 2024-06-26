package company.util;

public class Report<T, B> {
    private final String message;
    private final T reportedTo;
    private final B reportedBy;

    public Report(String message, T reportedTo, B reportedBy) {
        this.message = message;
        this.reportedTo = reportedTo;
        this.reportedBy = reportedBy;
    }
}
