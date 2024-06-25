package company.department;

import company.interfaces.*;
import company.people.*;
import company.service.*;

import java.util.ArrayList;

public class Department implements DepartmentInterface {
    private final String name;
    private final String departmentDescription;
    private final Director director;

    // Collections
    private final ArrayList<Team> teams = new ArrayList<>();
    private final ArrayList<Employee> employees = new ArrayList<>();
    private final ArrayList<Service> services = new ArrayList<>();

    public Department(String name, String departmentDescription, Director director) {
        this.name = name;
        this.departmentDescription = departmentDescription;
        this.director = director;
    }

    public void displayDepartmentInfo() {
        System.out.println(
                "Name: " + name);
    }

    @Override
    public void addTeams(Team team) {
        this.teams.add(team);
    }

    @Override
    public void addTeams(ArrayList<Team> teams) {
        this.teams.addAll(teams);
    }

    @Override
    public void addEmployees(Employee employee) {
        this.employees.add(employee);
    }

    @Override
    public void addEmployees(ArrayList<Employee> employees) {
        this.employees.addAll(employees);
    }

    @Override
    public void addServices(Service service) {
        this.services.add(service);
    }

    @Override
    public void addServices(ArrayList<Service> services) {
        this.services.addAll(services);
    }

}
