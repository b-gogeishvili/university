package company.service;

import company.department.*;
import company.exceptions.*;
import company.finance.*;
import company.people.*;
import company.util.*;

import java.util.ArrayList;

public abstract class Service {
    private final String name;
    private final String description;
    private final Director director;
    private final Department department;
    private final Income income;
    private final Budget budget;

    // Collections
    private final ArrayList<Resource> resources;

    public Service(String name, String description, Department department, Income income) throws OutOfResources {
        this.name = name;
        this.description = description;
        this.director = department.getDirector();
        this.department = department;
        this.income = income;
        this.budget = department.getCompany().getCompanyBudget();
        this.resources = department.getCompany().getCompanyResources();

        if (this.resources.isEmpty()) {
            throw new OutOfResources();
        }
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public Department getDepartment() {
        return department;
    }

    public Income getIncome() {
        return income;
    }

    public Budget getBudget() {
        return budget;
    }

    public Director getDirector() {
        return director;
    }

    public abstract void createProjects();
    public abstract void assignTeam();
}
