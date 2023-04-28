#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX // Khai báo giá trị vô cùng lớn

// Hàm tìm đường đi ngắn nhất từ đỉnh s đến các đỉnh còn lại trên đồ thị
void dijkstra(vector<vector<pair<int, int>>>& graph, int s)
{
    int n = graph.size();

    // Tạo một mảng đánh dấu để lưu trạng thái của các đỉnh
    vector<bool> visited(n, false);

    // Tạo một mảng để lưu trọng số của đường đi ngắn nhất tạm thời từ đỉnh s đến các đỉnh còn lại
    vector<int> dist(n, INF);

    // Khởi tạo đường đi ngắn nhất từ đỉnh s đến chính nó bằng 0
    dist[s] = 0;

    // Duyệt qua tất cả các đỉnh trên đồ thị
    for (int i = 0; i < n - 1; i++) {

        // Tìm đỉnh v chưa được xét và có đường đi ngắn nhất tạm thời nhỏ nhất
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }

        // Đánh dấu đỉnh v đã được xét
        visited[v] = true;

        // Cập nhật đường đi ngắn nhất tạm thời của các đỉnh kế tiếp của v
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
            }
        }
    }

    // In ra đường đi ngắn nhất từ đỉnh s đến các đỉnh còn lại
    for (int i = 0; i < n; i++) {
        cout << "Đường đi ngắn nhất từ " << s << " đến " << i << " là: ";
        if (dist[i] == INF) {
            cout << "Không có đường đi" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main()
{
    int n = 5; // số lượng đỉnh trên đồ thị
    vector<vector<pair<int, int>>> graph(n);

    // Thêm các cạnh trên đồ thị
    graph[0].push_back(make_pair<int, int>(1, 2));
    graph[0].push_back(make_pair<int, int>(2, 4));
    graph[1].push_back(make_pair<int, int>(2, 1));
    graph[1].push_back(make_pair<int, int>(3, 5));
    graph[2].push_back(make_pair<int, int>(3, 1));
    graph[2].push_back(make_pair<int, int>(4, 3));
    graph[3].push_back(make_pair<int, int>(4, 2));
    graph[3].push_back(make_pair<int, int>(0, 6));
    graph[4].push_back(make_pair<int, int>(3, 1));

   dijkstra(graph, 0);

   return 0;
}
