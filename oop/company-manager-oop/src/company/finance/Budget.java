package company.finance;

import company.*;

public class Budget {
    private final String name;
    private final int balance;
    private final int currency;

    public Budget(String name, int balance, int currency, Company company) {
        this.name = name;
        this.balance = balance;
        this.currency = currency;
        company.setBudget(this);
    }

    public String getName() {
        return name;
    }

    public int getBalance() {
        return balance;
    }

    public int getCurrency() {
        return currency;
    }
}
