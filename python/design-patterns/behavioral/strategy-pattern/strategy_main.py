from cc_strategy import CreditCardStrategy
from context import Context
from upi_strategy import UPIStrategy

if __name__ == "__main__":
    client: Context = Context(UPIStrategy())
    client.pay(100)

    client.payment_mode = CreditCardStrategy()
    client.pay(1000)
