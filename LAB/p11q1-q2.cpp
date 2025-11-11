#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX], visited[MAX];
int queueArr[MAX], front = -1, rear = -1;
int n; // number of vertices

void DFS(int vertex) {
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queueArr[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queueArr[front++];
}

void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    cout << "\nBreadth First Search: ";

    while (front <= rear) {
        int vertex = dequeue();
        cout << vertex << " ";

        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "Depth First Search: ";
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(start);

    BFS(start);

    return 0;
}
