package company.interfaces;

import company.department.*;
import company.people.*;
import company.service.*;

import java.util.ArrayList;

public interface DepartmentInterface {
    public void addTeams(ArrayList<Team> teams);
    public void addTeams(Team team);

    public void addEmployees(Employee employee);
    public void addEmployees(ArrayList<Employee> employees);

    public void addServices(Service service);
    public void addServices(ArrayList<Service> services);
}
