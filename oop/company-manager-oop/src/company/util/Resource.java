package company.util;

import company.Company;

public class Resource {
    private final String name;
    private final String issueDate;
    private final boolean isAvailable;

    public Resource(String name, String issueDate, boolean isAvailable, Company company) {
        this.name = name;
        this.issueDate = issueDate;
        this.isAvailable = isAvailable;
        company.addResource(this);
    }
}
