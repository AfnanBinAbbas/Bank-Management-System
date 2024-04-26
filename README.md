# Account Management System

This program implements an account management system using various data structures for efficient organization and retrieval of customer information, transaction history, and account verification. Below are the key components of the system:

## 1. Account Management (Linked List, Hash Table)

- Implements a linked list to manage customer information.
- Each node in the linked list represents a customer, storing essential details such as account number, name, address, and contact information.
- Provides a menu for adding new customers and opening new accounts.
- Utilizes a hash table to efficiently manage customer accounts.
- Defines a mapping mechanism within the hash table to link account numbers to corresponding customer information, ensuring quick and efficient retrieval.

## 2. Transaction History (Queue)

- Implements a queue to maintain a transaction history for each account.
- Offers functionalities for deposit, withdrawal, and fund transfer.
- Allows Enqueueing new transactions and Dequeueing older transactions, ensuring efficient management of transaction history with a limited size.

## 3. Account Verification (Binary Search Tree)

- Utilizes a binary search tree for efficient verification of account details during login or transactions.
- The binary search tree structure enables quick determination of whether an account exists and facilitates retrieval of its associated information.

### Usage

1. Compile the program using a C++ compiler.
2. Run the executable file generated after compilation.
3. Follow the menu options to add new customers, open accounts, perform transactions, and verify accounts.

### Implementation Details

- The program is written in C++.
- The linked list, hash table, queue, and binary search tree are implemented using standard C++ data structures and algorithms.
- Error handling and edge cases are considered to ensure the robustness and reliability of the system.

### Contributors
- Afnan Bin Abbas

### License

Refer to License.txt attached
.