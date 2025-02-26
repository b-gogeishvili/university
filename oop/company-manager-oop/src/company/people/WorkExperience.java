package company.people;

import company.department.*;

public class WorkExperience {
    private final String companyName;
    private final int yearSpent;
    private Position position;

    public WorkExperience(String companyName, int yearSpent) {
        this.companyName = companyName;
        this.yearSpent = yearSpent;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public String getCompanyName() {
        return companyName;
    }

    public int getYearSpent() {
        return yearSpent;
    }

    public Position getPosition() {
        return position;
    }
}
