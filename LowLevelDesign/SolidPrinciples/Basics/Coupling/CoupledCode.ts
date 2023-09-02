class Payment {
    amount: number;
  
    constructor(amount: number) {
      this.amount = amount;
    }
  
    processPayment(): void {
      console.log(`Processing payment of $${this.amount}`);
      // Code for actual payment processing would be here
    }
  }

  class Order {
    orderNumber: string;
    totalAmount: number;
    payment: Payment; // Order is directly dependent on Payment
  
    constructor(orderNumber: string, totalAmount: number, payment: Payment) {
      this.orderNumber = orderNumber;
      this.totalAmount = totalAmount;
      this.payment = payment;
    }
  
    checkout(): void {
      console.log(`Order ${this.orderNumber} is being checked out.`);
      this.payment.processPayment(); // Order directly calls Payment's method
      console.log(`Order ${this.orderNumber} has been successfully checked out.`);
    }
  }
  
  // Usage
  const payment = new Payment(100);
  const order = new Order("12345", 100, payment);
  order.checkout();