#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Linked List Node for Customer Information
struct CustomerDetails
{
    long long accountNumber;
    string name;
    string address;
    long long contact;
    CustomerDetails *next;

    CustomerDetails() : accountNumber(0), name(" "), address(" "), contact(0), next(nullptr)
    {
    }
};

// Hash Table for Efficient Account Management
class HashTable
{
private:
    unordered_map<long long, CustomerDetails *> table;

public:
    void insert(long long key, CustomerDetails *value)
    {
        table[key] = value;
    }

    CustomerDetails *retrieve(long long key)
    {
        return table[key];
    }
};

// Linked List for Account Management
class CustomerList
{
private:
    CustomerDetails *head;
    HashTable hashtable;

public:
    CustomerList() : head(nullptr)
    {
    }

    // Function to create a new customer account
    void createAccount()
    {
        CustomerDetails *newNode = new CustomerDetails;

        cout << "\n<============= Create Account here =============>\n\n";
        cout << "Enter Account No: ";
        cin >> newNode->accountNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, newNode->name);
        cout << "Enter Address: ";
        getline(cin, newNode->address);
        cout << "Enter Contact No: ";
        cin >> newNode->contact;

        // Add the new customer to the linked list
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        // Insert the customer into the hash table for efficient retrieval
        hashtable.insert(newNode->accountNumber, newNode);
    }

    // Function to display details of all customers
    void displayAllCustomers()
    {
        int count = 0;
        CustomerDetails *temp = head;

        cout << "\n<============ Customer Details ============>\n";
        cout << "\t[Display All Customers]\n";

        while (temp != nullptr)
        {
            count++;
            cout << "\n\n";
            cout << "Customer #[" << count << "]\n";
            cout << "\nAccount No.: " << temp->accountNumber;
            cout << "\nName: " << temp->name;
            cout << "\nContact No.: " << temp->contact;
            cout << "\nAddress: " << temp->address;

            temp = temp->next;
        }

        cout << endl;
        cout << "----------------------------------------------";
    }

    // Function to retrieve customer details by account number
    CustomerDetails *getCustomer(long long accNo)
    {
        return hashtable.retrieve(accNo);
    }
};

// Queue for Transaction History
class TransactionQueue
{
private:
    queue<string> transactionHistory;

public:
    // Function to enqueue a new transaction
    void enqueueTransaction(const string &transaction)
    {
        // Limiting to 10 transactions for efficiency
        if (transactionHistory.size() >= 10)
        {
            transactionHistory.pop();
        }
        transactionHistory.push(transaction);
    }

    // Function to display transaction history
    void displayTransactionHistory()
    {
        cout << "\n<============ Transaction History ============>\n";
        cout << "\t[Display Transaction History]\n";

        queue<string> tempQueue = transactionHistory;

        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }

        cout << "----------------------------------------------";
    }
};

// Binary Search Tree for Account Verification
struct Credentials
{
    long long accountNumber;
    string password;
    string name;
    long long contact;
    string address;

    Credentials *left;
    Credentials *right;

    Credentials() : accountNumber(0), password(" "), left(nullptr), right(nullptr)
    {
    }
};

class AccountVerification
{
public:
    Credentials *root;

    AccountVerification() : root(nullptr)
    {
    }

    // Function to insert new account credentials into the binary search tree
    void insert(Credentials *&node, long long accNo, const string &password, const string &name, long long contact, const string &address)
    {
        if (node == nullptr)
        {
            node = new Credentials;
            node->accountNumber = accNo;
            node->password = password;
            node->name = name;
            node->contact = contact;
            node->address = address;
        }
        else if (accNo < node->accountNumber)
        {
            insert(node->left, accNo, password, name, contact, address);
        }
        else if (accNo > node->accountNumber)
        {
            insert(node->right, accNo, password, name, contact, address);
        }
        // If accNo already exists, you might want to handle it accordingly (perhaps update the existing node).
    }

    // Function to search for account credentials in the binary search tree
    Credentials *search(Credentials *node, long long accNo)
    {
        if (node == nullptr || node->accountNumber == accNo)
        {
            return node;
        }

        if (accNo < node->accountNumber)
        {
            return search(node->left, accNo);
        }

        return search(node->right, accNo);
    }

    // Other functions for BST operations can be added as needed
};

int main()
{
    CustomerList customerList;
    TransactionQueue transactionQueue;
    AccountVerification accountVerification;

    int choice;

    // Main menu loop
    do
    {
        cout << "\n\n<============= Banking Management System =============>\n";
        cout << "\t[Main Menu]\n\n";
        cout << "1. Account Management System (Linked List, Hash Table)\n";
        cout << "2. Transaction History (Queue)\n";
        cout << "3. Account Verification (Binary Search Tree)\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
        {
            int accountManagementChoice;

            // Account Management System submenu
            do
            {
                cout << "\t[Account Management System]\n";
                cout << "1. Create Account\n";
                cout << "2. Display All Customers\n";
                cout << "3. Get Customer Details by Account No.\n";
                cout << "4. Back to Main Menu\n";
                cout << "\nEnter your choice: ";
                cin >> accountManagementChoice;
                cout << "\n";

                switch (accountManagementChoice)
                {
                case 1:
                {
                    customerList.createAccount();
                    break;
                }
                case 2:
                {
                    customerList.displayAllCustomers();
                    break;
                }
                case 3:
                {
                    long long accNo;
                    cout << "Enter Account No. to retrieve details: ";
                    cin >> accNo;
                    CustomerDetails *customer = customerList.getCustomer(accNo);
                    if (customer != nullptr)
                    {
                        cout << "\nCustomer Details for Account No. " << accNo << ":\n";
                        cout << "Name: " << customer->name << "\n";
                        cout << "Contact No.: " << customer->contact << "\n";
                        cout << "Address: " << customer->address << "\n";
                    }
                    else
                    {
                        cout << "\nCustomer not found for Account No. '" << accNo << "'!!\n";
                    }
                    break;
                }
                case 4:
                {
                    break; // Go back to the main menu
                }
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                }

            } while (accountManagementChoice != 4);
            break;
        }
        case 2:
        {
            int transactionHistoryChoice;

            // Transaction History submenu
            do
            {
                cout << "\t[Transaction History]\n";
                cout << "1. Enqueue Transaction\n";
                cout << "2. Display Transaction History\n";
                cout << "3. Back to Main Menu\n";
                cout << "\nEnter your choice: ";
                cin >> transactionHistoryChoice;
                cout << "\n";

                switch (transactionHistoryChoice)
                {
                case 1:
                {
                    string transaction;
                    cout << "Enter Transaction Details: ";
                    cin.ignore();
                    getline(cin, transaction);
                    transactionQueue.enqueueTransaction(transaction);
                    break;
                }
                case 2:
                {
                    transactionQueue.displayTransactionHistory();
                    break;
                }
                case 3:
                {
                    break; // Go back to the main menu
                }
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                }

            } while (transactionHistoryChoice != 3);
            break;
        }
        case 3:
        {
            int accountVerificationChoice;

            // Account Verification submenu
            do
            {
                cout << "\t[Account Verification]\n";
                cout << "1. Create Account Credentials\n";
                cout << "2. Login\n";
                cout << "3. Back to Main Menu\n";
                cout << "\nEnter your choice: ";
                cin >> accountVerificationChoice;
                cout << "\n";

                switch (accountVerificationChoice)
                {
                case 1:
                {
                    long long accNo;
                    string password, name, address;
                    long long contact;

                    cout << "\n<============= Create Account Credentials =============>\n\n";
                    cout << "Enter Account No: ";
                    cin >> accNo;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Address: ";
                    getline(cin, address);
                    cout << "Enter Contact No: ";
                    cin >> contact;
                    cout << "Set Password: ";
                    cin.ignore();
                    getline(cin, password);

                    accountVerification.insert(accountVerification.root, accNo, password, name, contact, address);
                    break;
                }
                case 2:
                {
                    long long accNo;
                    string password;
                    cout << "\t\t[Login]\n\n";
                    cout << "Enter Account No: ";
                    cin >> accNo;
                    cout << "Enter Password: ";
                    cin.ignore();
                    getline(cin, password);

                    Credentials *foundCustomer = accountVerification.search(accountVerification.root, accNo);
                    if (foundCustomer != nullptr && foundCustomer->password == password)
                    {
                        cout << "\nLogin Successful!\n";
                        cout << "Customer Details:\n";
                        cout << "Name: " << foundCustomer->name << "\n";
                        cout << "Contact No.: " << foundCustomer->contact << "\n";
                        cout << "Address: " << foundCustomer->address << "\n";
                    }
                    else
                    {
                        cout << "\nLogin Failed. Invalid Account No. or Password.\n";
                    }
                    break;
                }
                case 3:
                {
                    break; // Go back to the main menu
                }
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                }

            } while (accountVerificationChoice != 3);
            break;
        }
        case 4:
        {
            break; // Exit the program
        }
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
