//                      1. Account Management System(Linked List, Hash Table)
// // 1. Create a program to implement a linked list for managing customer information.
// 2. Define each node in the linked list to represent a customer, storing essential details like
// account number, name, address, and contact information. Create a menu for adding
// new customers and opening new accounts.
// 3. Utilize a hash table to efficiently manage customer accounts.
// 4. Define a mapping mechanism within the hash table to link account numbers to corresponding customer information, ensuring quick and efficient retrieval.
//                      2. Transaction History (Queue)
// 1. Implement a queue for maintaining a transaction history for each account, offering deposit, withdrawal, and fund transfer functionalities.
// 2. Implement functionality to Enqueue new transactions and Dequeue older transactions,
// ensuring the transaction history is limited and efficiently managed.
//                      3. Account Verification (Binary Search Tree)
// 1. Create a binary search tree for efficient verification of account details during login or
// transactions.
// 2. Explain how this binary search tree structure can be employed to quickly determine if
// an account exists and retrieve its associated information.
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
template <typename G>
class Graph
{
public:
    unordered_map<G, list<G>> adj;
    void addEdge(G u, G v, bool direction)
    {
        // create an edge from u to v
        adj[u].push_back(v);
    }
    // direction==>1 == directed
    // direction==>0 == undirected
    if (direction == 0)
    {
        adj[v].push_back(u);
    }
    void displayGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << "->";
            }
            cout << endl;
        }
    }
};
int main()
{

    int n, m;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    cout << "Enter the no. of edges: ";
    cin >> m;
    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.displayGraph();
    return 0;
}