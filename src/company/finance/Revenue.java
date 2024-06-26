package company.finance;

import company.Company;
import company.service.*;

public class Revenue {
    private int totalRevenue;

    public Revenue(Company company) {
        for (Service service : company.getCompanyServices()) {
            this.totalRevenue += service.getIncome().getMonthlyAmount();
        }
        company.setRevenue(this);
    }

    public int getTotalRevenue() {
        return totalRevenue;
    }
}
