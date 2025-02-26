package company.exceptions;

public class DeadlineExceeded extends Exception {
    public DeadlineExceeded() {
        super("Deadline exceeded");
    }
}
