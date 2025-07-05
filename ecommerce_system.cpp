#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    int quantity;
    int expiry_days;
    bool needs_shipping;
    double weight;

    Product(string n, double p, int q, int exp, bool ship, double w) {
        name = n;
        price = p;
        quantity = q;
        expiry_days = exp;
        needs_shipping = ship;
        weight = w;
    }

    bool isExpired() {
        return expiry_days <= 0;
    }
};

class CartItem {
public:
    Product* product;
    int quantity;

    CartItem(Product* p, int q) {
        product = p;
        quantity = q;
    }
};

class Cart {
public:
    CartItem* items[100];
    int item_count;

    Cart() {
        item_count = 0;
    }

    void add(Product* product, int quantity) {
        if (product->quantity >= quantity && !product->isExpired()) {
            items[item_count] = new CartItem(product, quantity);
            item_count++;
            product->quantity -= quantity;
        }
    }

    double getSubtotal() {
        double total = 0;
        for (int i = 0; i < item_count; i++) {
            total += items[i]->product->price * items[i]->quantity;
        }
        return total;
    }

    bool isEmpty() {
        return item_count == 0;
    }
};

class Customer {
public:
    string name;
    double balance;

    Customer(string n, double b) {
        name = n;
        balance = b;
    }

    bool canPay(double amount) {
        return balance >= amount;
    }

    void pay(double amount) {
        balance -= amount;
    }
};

class ShippingService {
public:
    double calculateShippingFee(Cart* cart) {
        double total_weight = 0;
        int shipping_items = 0;

        for (int i = 0; i < cart->item_count; i++) {
            if (cart->items[i]->product->needs_shipping) {
                total_weight += cart->items[i]->product->weight * cart->items[i]->quantity;
                shipping_items++;
            }
        }

        if (shipping_items == 0) return 0;

        cout << "** Shipment notice **" << endl;
        for (int i = 0; i < cart->item_count; i++) {
            if (cart->items[i]->product->needs_shipping) {
                cout << cart->items[i]->quantity << "x " << cart->items[i]->product->name;
                cout << "        " << cart->items[i]->product->weight * cart->items[i]->quantity << "g" << endl;
            }
        }
        cout << "Total package weight " << total_weight / 1000.0 << "kg" << endl;
        cout << endl;

        return 30.0;
    }
};

void checkout(Customer* customer, Cart* cart) {
    if (cart->isEmpty()) {
        cout << "Error: Cart is empty" << endl;
        return;
    }

    for (int i = 0; i < cart->item_count; i++) {
        if (cart->items[i]->product->quantity < 0) {
            cout << "Error: Product out of stock" << endl;
            return;
        }
        if (cart->items[i]->product->isExpired()) {
            cout << "Error: Product expired" << endl;
            return;
        }
    }

    double subtotal = cart->getSubtotal();
    ShippingService shipping;
    double shipping_fee = shipping.calculateShippingFee(cart);
    double total = subtotal + shipping_fee;

    if (!customer->canPay(total)) {
        cout << "Error: Insufficient balance" << endl;
        return;
    }

    customer->pay(total);

    cout << "** Checkout receipt **" << endl;
    for (int i = 0; i < cart->item_count; i++) {
        cout << cart->items[i]->quantity << "x " << cart->items[i]->product->name;
        cout << "        " << cart->items[i]->product->price * cart->items[i]->quantity << endl;
    }
    cout << "----------------------" << endl;
    cout << "Subtotal         " << subtotal << endl;
    cout << "Shipping         " << shipping_fee << endl;
    cout << "Amount           " << total << endl;
    cout << "Customer balance " << customer->balance << endl;
}

int main() {
    Customer customer("John", 1000.0);

    Product cheese("Cheese", 100.0, 10, 5, true, 200.0);
    Product tv("TV", 500.0, 5, -1, true, 5000.0);
    Product scratchCard("Scratch Card", 50.0, 20, -1, false, 0.0);

    Cart cart;

    cart.add(&cheese, 2);
    cart.add(&tv, 1);
    cart.add(&scratchCard, 1);

    checkout(&customer, &cart);

    return 0;
}