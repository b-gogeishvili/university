package company.finance;

public class Income {
    private final int monthlyAmount;
    private final int yearlyAmount;

    public Income(int monthlyAmount) {
        this.monthlyAmount = monthlyAmount;
        this.yearlyAmount = monthlyAmount * 12;
    }

    public int getMonthlyAmount() {
        return this.monthlyAmount;
    }

    public int getYearlyAmount() {
        return this.yearlyAmount;
    }
}
