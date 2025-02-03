package company.department;

import company.exceptions.*;
import company.people.*;
import company.project.*;

import java.util.ArrayList;

public class Team {
    private final String name;
    private final Manager manager;
    private final Department department;

    // Collections
    private final ArrayList<Employee> employees = new ArrayList<>();
    private final ArrayList<Project> projects = new ArrayList<>();

    public Team(String name, Manager manager, Department department) {
        this.name = name;
        this.manager = manager;
        this.department = department;
    }

    public String getName() {
        return name;
    }

    public Department getDepartment() {
        return department;
    }

    public void addEmployees(Employee employee) {
        employees.add(employee);
    }

    public void addEmployees(ArrayList<Employee> employees) {
        this.employees.addAll(employees);
    }

    public void removeEmployee(Employee employee) {
        employees.remove(employee);
    }

    public void addProjects(Project project) {
        projects.add(project);
    }

    public void addProjects(ArrayList<Project> projects) {
        this.projects.addAll(projects);
    }

    public void removeProjects(Project project) {
        projects.remove(project);
    }

    @Override
    public String toString() {
        return name;
    }
}
