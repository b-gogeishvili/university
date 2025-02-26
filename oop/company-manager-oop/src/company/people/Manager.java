package company.people;

import company.department.*;
import company.finance.*;

public class Manager extends Person {
    private Team team;
    private Income income;

    public Manager(String name, int age, Income income) {
        super(name, age);
        this.income = income;
    }

    @Override
    public void goToWork() {

    }

    @Override
    public void goHome() {

    }

    @Override
    public void raiseIncome() {

    }

    @Override
    public void report() {

    }

    @Override
    public void createReport() {

    }

    public void assignToTeam(Team team) {
        this.team = team;
    }
}
