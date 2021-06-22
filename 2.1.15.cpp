#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> read_matrix(int n, int m) {
    vector<vector<int>> matrix;
    vector<int> tmp;
    int num;
    for (int i = 0; i < n; i++) {
        tmp.clear();
        for (int j = 0; j < m; j++) {
            cin >> num;
            tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }
    return matrix;
}

void print_matrix(vector<vector<int>> matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<vector<int>> sort(vector<vector<int>> matrix, int n, int m) {
    vector<int> max;
    int tmp;
    int min_i;

    for (int i = 0; i < n; i++) {
        tmp = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] > tmp) {
                tmp = matrix[i][j];
            }
        }
        max.push_back(tmp);
    }

    for (int i = 0; i < n - 1; i++) {
        min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (max[j] < max[min_i]) {
                min_i = j;
            }
        }
        swap(max[min_i], max[i]);
        swap(matrix[min_i], matrix[i]);
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix;
    int n, m;

    cin >> n >> m;

    matrix = read_matrix(n ,m);

    matrix = sort(matrix, n, m);

    print_matrix(matrix, n, m);

    return 0;
}