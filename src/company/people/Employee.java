package company.people;

import company.department.Department;
import company.department.Position;
import company.department.Team;
import company.project.*;
import company.util.*;

import java.util.ArrayList;

public class Employee extends Person {
    private final Position position;
    private final Department department;
    private final Team team;
    private final Manager manager;

    // Collections
    private final ArrayList<Report<Employee>> workLog = new ArrayList<>();
    private final ArrayList<Project> projectsAssigned = new ArrayList<>();
    private final ArrayList<Task> toDoList = new ArrayList<>();

    public Employee(String name, int age, Position position, Department department, Team team, Manager manager) {
        super(name, age);
        this.position = position;
        this.department = department;
        this.team = team;
        this.manager = manager;
    }

    @Override
    public void goToWork() {
        // create report to go to work
    }

    @Override
    public void goHome() {
        // create report to go home
    }

    @Override
    public void raiseIncome() {
        // add money to income counter
    }

    @Override
    public void report() {
        // new Report(message, issuer, destination...);
    }

    @Override
    public void createReport() {
        // 23.03.2024 - Went to work
        // 25.03.2024 - Worked on T Project
        // 25.03.2024 - Did some tasks: added x lines of code, refactored, worked on db...
    }

    public void getPromotion() {
        // raise income, change position,
    }

    public void workOnProject() {
        // brainstorm, design...
    }

    public void doTasks() {
        // tasks: added x lines of code, refactored, worked on db...
    }
}
