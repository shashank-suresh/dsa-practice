from payment_strategy import PaymentStrategy


class UPIStrategy(PaymentStrategy):
    def pay(self, amount: int):
        print(f"Successfully paid {amount} through UPI!")
