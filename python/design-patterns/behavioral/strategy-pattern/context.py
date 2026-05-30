from payment_strategy import PaymentStrategy


class Context:
    def __init__(self, method: PaymentStrategy) -> None:
        self._payment_mode = method

    @property
    def payment_mode(self) -> PaymentStrategy:
        return self._payment_mode

    @payment_mode.setter
    def payment_mode(self, method: PaymentStrategy) -> None:
        self._payment_mode = method

    def pay(self, amount: int) -> None:
        if not self._payment_mode:
            print("Please select a payment method!")

        self._payment_mode.pay(amount)
