from payment_strategy import PaymentStrategy


class CreditCardStrategy(PaymentStrategy):
    def pay(self, amount: int):
        print(f"Successfully paid {amount} through credit card!")
