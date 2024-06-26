package company;

import company.people.*;
import company.department.*;
import company.service.*;
import company.finance.*;
import company.util.*;

import java.util.ArrayList;
import java.util.concurrent.BlockingDeque;

public class Company {
    // Basic Information
    private final String name;
    private final int yearFounded;
    private final String shortDescription;
    private final Director founder;

    // Collections !!! Should be added upon creation
    private final ArrayList<Employee> employees = new ArrayList<>();
    private final ArrayList<Department> departments = new ArrayList<>();
    private final ArrayList<Service> services = new ArrayList<>();
    private final ArrayList<Resource> resources = new ArrayList<>();

    // Financial Information
    private Revenue revenue;
    private Budget budget;


    // Company

    public Company(String name, int yearFounded, String shortDescription, Director founder) {
        this.name = name;
        this.yearFounded = yearFounded;
        this.shortDescription = shortDescription;
        this.founder = founder;
    }

    public void getCompanyInfo() {
        System.out.println(
            "Name: " + this.name + ", " +
            "Founded by " + this.founder + ", " +
            "Founded in " + this.yearFounded + ", " +
            "About: " + this.shortDescription
        );
    }

    public Director getCompanyFounder() {
        return this.founder;
    }


    // Employee

    public int getEmployeeCount() {
        return this.employees.size();
    }

    public void addEmployee(Employee employee) {
        this.employees.add(employee);
    }

    public void addEmployee(ArrayList<Employee> employee) {
        this.employees.addAll(employee);
    }

    public ArrayList<Employee> getCompanyEmployees() {
        return this.employees;
    }


    // Department

    public void addDepartment(Department department) {
        this.departments.add(department);
    }

    public void displayCompanyDepartments () {
        for (Department department : departments) {
            System.out.println(department);
        }
    }


    // Services

    public void addService(Service service) {
        this.services.add(service);
    }

    public void displayCompanyServices() {
        for (Service service : services) {
            System.out.println(service);
        }
    }

    public ArrayList<Service> getCompanyServices() {
        return this.services;
    }


    // Revenue

    public void setRevenue(Revenue revenue) {
        this.revenue = revenue;
    }

    public void displayCompanyRevenue() {
        System.out.println("Display Company revenue: " + this.revenue);
    }

    public void setBudget(Budget budget) {
        this.budget = budget;
    }

    public Budget getCompanyBudget() {
        return this.budget;
    }

    public void displayCompanyBudget() {
        System.out.println("Display Company budget: " + this.budget);
    }


    // Resource

    public void addResource(Resource resource) {
        this.resources.add(resource);
    }

    public void addResource(ArrayList<Resource> resource) {
        this.resources.addAll(resource);
    }

    public ArrayList<Resource> getCompanyResources() {
        return this.resources;
    }

    public void displayCompanyResources() {
        for (Resource resource : resources) {
            System.out.println(resource);
        }
    }
}
