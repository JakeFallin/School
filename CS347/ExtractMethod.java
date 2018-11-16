/*
 *   Version 1
 *
 *   Name is "printAmountOwed" but method (1) prints and
 *   (2) calculates for (3) both current and prior orders.
 *
 *   
 */

void printTitle() {
    System.out.println("***********************");
    System.out.println("***  Customer owes  ***");
    System.out.println("***********************");
}

public void printInfo(String name, double amount) {
    System.out.println("name: " + _name);
    System.out.println("amount: "+ amount)

}

public double getOutstanding(Enumeration e) {
    double outstanding = 0.0;
    while (e.hasMoreElements()) {
         Order order = (Order) e.nextElement();
         outstanding += order.getAmount();
     }
    return outstanding;
}

void printAmountOwed(double balance) {

    printTitle();
    Enumeration e = _orders.elements();
    double outstanding = getOutstanding(e);
    double amt = balance + outstanding;
    printInfo(_name, amt);
}
