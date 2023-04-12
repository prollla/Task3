#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>

template<typename T>
class DirectedGraph {
public:
    DirectedGraph() {}
    ~DirectedGraph() {}

    void addVertex(const T& v) {
        if (!hasVertex(v)) {
            vertices.push_back(v);
            adjList[v] = std::vector<T>();
        }
    }

    void addEdge(const T& from, const T& to) {
        if (!hasVertex(from) || !hasVertex(to)) {
            std::cerr << "Error: vertex not found!" << std::endl;
            return;
        }
        adjList[from].push_back(to);
    }

    bool hasVertex(const T& v) const {
        return adjList.find(v) != adjList.end();
    }

    void printVertices() const {
        std::cout << "Vertices: ";
        for (const auto& v : vertices) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    void printEdges() const {
        std::cout << "Edges: " << std::endl;
        for (const auto& p : adjList) {
            const T& from = p.first;
            const std::vector<T>& to = p.second;
            for (const auto& t : to) {
                std::cout << from << " -> " << t << std::endl;
            }
        }
    }

private:
    std::vector<T> vertices;
    std::unordered_map<T, std::vector<T>> adjList;
};
int main() {
    DirectedGraph<int> intGraph;
    intGraph.addVertex(1);
    intGraph.addVertex(2);
    intGraph.addVertex(3);
    intGraph.addEdge(1, 2);
    intGraph.addEdge(2, 3);
    intGraph.addEdge(3, 1);
    intGraph.printVertices();
    intGraph.printEdges();

    DirectedGraph<std::string> strGraph;
    strGraph.addVertex("hello");
    strGraph.addVertex("world");
    strGraph.addEdge("hello", "world");
    strGraph.printVertices();
    strGraph.printEdges();

    return 0;
}
