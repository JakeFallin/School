public class Customer {
    private double _price;
    private double _cost;
    private double _tax;

    public Customer(double cost, double tax) {
        _cost = cost;
        _tax = tax;
    }

    public double getPrice() {
        return _price;
    }
    public double getCost() {
        return _cost;
    }
    public double getTax() {
        return _tax;
    }

    public double totalDue() {
        double cost = getPrice() * getCost();
        double tax = cost * getTax();
        return cost + tax;
    }
}

class Individual extends Customer {
    private final double COST = 1.0;
    private final double TAX = .035;
    public Individual() {
        super(COST, TAX);
    }
}

class Business extends Customer {
    private final double COST = .9;
    private final double TAX = .07;
    public Business() {
        super(COST, TAX);
    }
}
