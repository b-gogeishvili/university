import company.*;
import company.department.*;
import company.finance.Income;
import company.people.*;
public class Main {
    public static void main(String[] args) {
        Company company = new Company(
                "eToro",
                2009,
                "Financial Company",
                new Director("Yonni Assia", 23)
        );

        Department department = new Department(
                "Technology",
                "Technological solutions and design",
                new Director("Tuval Chomut", 30),
                company
        );

        Manager manager = new Manager(
                "Giga Kovaliovi",
                25,
                new Income(30)
        );

        Team team = new Team("Dealing", manager, department);
        manager.assignToTeam(team);

        Position position = new Position(
                "Software Developer",
                new Income(15),
                new WorkExperience("Unilab", 1)
        );

        Employee employee1 = new Employee(
                "Besik Gogeishvili",
                19,
                position,
                department,
                team,
                manager
        );

    }
}

