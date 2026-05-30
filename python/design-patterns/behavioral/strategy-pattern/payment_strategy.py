from abc import ABC, abstractmethod


class PaymentStrategy(ABC):
    """
    This is the interface of the strategy that we will be making different payment strategies out of
    """

    @abstractmethod
    def pay(self, amount: int) -> None:
        pass
