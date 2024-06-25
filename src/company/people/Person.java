package company.people;

import company.finance.*;

public abstract class Person {
    private final String name;
    private final int age;
    protected Income income;
    private WorkExperience workExperience;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void setIncome(Income income) {
        this.income = income;
    }

    public Income getIncome() {
        return this.income;
    }

    public void setWorkExperience(WorkExperience workExperience) {
        this.workExperience = workExperience;
    }

    public WorkExperience getWorkExperience() {
        return workExperience;
    }

    public abstract void goToWork();
    public abstract void goHome();

    public abstract void raiseIncome();

    public abstract void report();
    public abstract void createReport();
}
