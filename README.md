# C++ E-commerce System

## Overview
This project is an implementation of an e-commerce system in C++ developed as part of the **Fawry Quantum Internship Challenge 3**.

## Features
- ✅ **Product Management**: Handle product inventory with expiry dates and stock levels
- ✅ **Shopping Cart**: Add products to cart with quantity validation
- ✅ **Customer Management**: Customer balance and payment processing
- ✅ **Shipping Service**: Calculate shipping fees based on product weight and shipping requirements
- ✅ **Checkout System**: Complete order processing with receipt generation
- ✅ **Error Handling**: Validates stock, expiry, and payment capabilities

## System Architecture

### Classes Overview

#### `Product`
- Manages product information (name, price, quantity, expiry, shipping requirements, weight)
- Validates product expiry status
- Tracks inventory levels

#### `CartItem`
- Links products with quantities in the shopping cart
- Maintains product references and selected quantities

#### `Cart`
- Manages collection of cart items
- Validates product availability and expiry before adding
- Calculates subtotal for all items
- Provides cart status checking

#### `Customer`
- Handles customer information and balance management
- Validates payment capability
- Processes payment transactions

#### `ShippingService`
- Calculates shipping fees based on product weight
- Generates detailed shipping notices for items requiring shipment
- Handles weight calculations and displays package information

## How to Build and Run

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- C++11 or later standard support

### Compilation Options

#### Option 1: Using g++ directly
```bash
g++ -std=c++11 -Wall -Wextra -o ecommerce ecommerce_system.cpp
```

#### Option 2: Using the provided Makefile
```bash
make
```

### Running the Program
```bash
./ecommerce
```

## Sample Output
The program demonstrates a complete checkout process with:

```
** Shipment notice **
2x Cheese        400g
1x TV        5000g
Total package weight 5.4kg

** Checkout receipt **
2x Cheese        200
1x TV        500
1x Scratch Card        50
----------------------
Subtotal         750
Shipping         30
Amount           780
Customer balance 220
```

## Code Features
- **Object-Oriented Design**: Clean class structure with proper encapsulation
- **Memory Management**: Proper pointer usage for cart items
- **Input Validation**: Comprehensive checks for stock, expiry, and payment
- **Modular Design**: Separated concerns for different system components
- **Error Handling**: Graceful handling of various error conditions

## Test Scenario
The program includes a test scenario with:
- **Customer**: John with $1000 initial balance
- **Products**:
  - Cheese: $100, 10 in stock, 5 days until expiry, 200g weight, requires shipping
  - TV: $500, 5 in stock, no expiry, 5000g weight, requires shipping
  - Scratch Card: $50, 20 in stock, no expiry, 0g weight, no shipping required

## Future Enhancements
- [ ] Dynamic memory management with vectors
- [ ] Database integration for persistent storage
- [ ] Multiple shipping options and rates
- [ ] Discount and coupon system
- [ ] User authentication and multiple customers
- [ ] Order history tracking

## Author
**Abdelhamid Khald**

## Challenge
Fawry Quantum Internship Challenge 3

---
*This project demonstrates proficiency in C++ programming, object-oriented design, and e-commerce system architecture.*