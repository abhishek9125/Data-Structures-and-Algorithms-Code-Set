#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>;

class Graph{

    public:
        unordered_map<T, list<T>> adj;

        void addEdge(T u, T v, bool direction) {
            adj[u].push_back(v);
            if(!direction) {
                adj[v].push_back(u);
            }
        }

        void printAdj() {
            for(auto i: adj) {
                cout << i.first << " : ";
                for(auto j : i.second) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
 
};

int main() {
    cout<<"Hello World!";
}
