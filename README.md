# Supermarket Billing System

A terminal-based retail invoice management application built in C++. This application serves as an interactive CLI (Command Line Interface) tool designed to manage customer orders dynamically, compute itemized receipts, handle real-time item updates, and apply manual discount schemas.

---

## 🚀 Features

* **Dynamic Product Addition:** Instantly add items to a dynamic digital cart along with custom quantities and individual pricing values.
* **Formatted Digital Receipts:** Automatically calculates individual subtotals and displays your cart layout using aligned rows, courtesy of the `<iomanip>` library.
* **Dynamic Percentage Discounts:** Seamlessly adjust the final bill by inputting a manual discount percentage during the invoice processing stage.
* **Total Session Control:** Modify mismatched item details, completely wipe out old buyer lists for fresh customers, or safely delete individual products.

---

## 🛠️ Technical Concepts Explored

* **Data Aggregation (`struct`):** Combines related variables under a unique identifier blueprint to model product entries seamlessly (`Name`, `quatity`, `price`, `total`).
* **Dynamic Sequences (`std::vector`):** Utilizes linear dynamic storage to hold arbitrary item totals without dealing with hard-coded limitations.
* **Vector Iterators & Safe Removal:** Employs iterator-based traversals to targets items cleanly, preventing unexpected crashes or memory leaks during runtime cart modification.
* **Output Spacing Control (`<iomanip>`):** Generates cleanly padded billing layouts utilizing specific text padding rules (`std::left`, `std::setw`).

---

## 🎮 Interface Options

```text
 ||............. SELECT OPTION .............||
 ||                                         ||
 ||            1. ADD ITEM                  ||
 ||            2. PRINT BILL                ||
 ||            3. EDIT ORDER                ||
 ||            4. RESET LIST                ||
 ||            5. DELETE PRODUCT            ||
 ||            0. Exit                      ||
 ||.........................................||
