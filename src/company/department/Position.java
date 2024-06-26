package company.department;

import company.finance.*;
import company.people.*;

public class Position {
    private final String name;
    private final Income baseSalary;
    private final WorkExperience requiredWorkExperience;

    public Position(String name, Income salary, WorkExperience requiredWorkExperience) {
        this.name = name;
        this.baseSalary = salary;
        this.requiredWorkExperience = requiredWorkExperience;
    }

    public String getName() {
        return name;
    }

    public Income getBaseSalary() {
        return baseSalary;
    }

    public WorkExperience getRequiredWorkExperience() {
        return requiredWorkExperience;
    }
}
