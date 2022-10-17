#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> jugs;        // define structure data for jugs
void BFS(int a, int b, int target); // define BFS(Breadth-First Search) function
void printresult(map<jugs, jugs> node,
                 jugs currentNode); // define function print results

int main() {

  int a;
  int b;
  int target;
  /// viet ham nhap a,b, target tu ban phim
  // CODE HERE
  cout << "Nhap a limit: ";
  cin >> a;
  cout << "Nhap b limit: ";
  cin >> b;
  cout << "Nhap target: ";
  cin >> target;
  BFS(a, b, target);
  return 0;
}
void printresult(map<jugs, jugs> node, jugs currentNode) {
  if (currentNode.first == 0 && currentNode.second == 0) {
    cout << 0 << " " << 0 << endl;
    return;
  }
  printresult(node, node[currentNode]);
  cout << currentNode.first << " " << currentNode.second << endl;
}

void BFS(int a, int b, int target) {
  map<jugs, int> isChecked; // kiem tra cac node da duyet: 1 da duyet, 0 chua
                            // duyet (default = 0)
  bool isSolvable = false;  // ton tai ket qua
  map<jugs, jugs> node;     // Graph
  queue<jugs> q;            // Queue de duyet cay bang BFS

  q.push(make_pair(0, 0)); // Bat dau duyet cay cho ket qua vao hanh doi
  while (!q.empty()) {
    jugs currentNode = q.front();    // lay phan tu dau tien
    q.pop();                         // xoa phan tu dau tien khoi hang doi
    if (isChecked[currentNode] == 1) // node da duyet thi pass
      continue;
    isChecked[{currentNode.first, currentNode.second}] = 1; // da duyet

    if (currentNode.first == target || currentNode.second == target) {
      isSolvable = true;

      // CODE HERE
      if (currentNode.first == target && currentNode.second != 0) {
        node[{currentNode.first, 0}] = currentNode;
        currentNode.second = 0;
      }

      if (currentNode.second == target && currentNode.second != 0) {
        node[{0, currentNode.second}] = currentNode;
        currentNode.first = 0;
      }
      printresult(node, currentNode);
      return;
    }
    // ======= Operation =====
    // ## Fill
    // fill into jug 1
    if (isChecked[{a, currentNode.second}] != 1) {
      q.push({a, currentNode.second});
      node[{a, currentNode.second}] = currentNode; // Set father
    }

    // fill into jug 2
    // CODE HERE
    if (isChecked[{currentNode.first, b}] != 1) {
      q.push({currentNode.first, b});
      node[{currentNode.first, b}] = currentNode;
    }
    // ## Transfer of water
    int d = b - currentNode.second; // from jug 1 to jug 2
    if (currentNode.first >= d) {
      int c = currentNode.first - d; // transfer a little
      if (isChecked[{c, b}] != 1) {
        q.push({c, b});
        node[{c, b}] = currentNode;
      }
    } else {
      int c = currentNode.first + currentNode.second;
      if (isChecked[{0, c}] != 1) { /// transfer all
        q.push({0, c});
        node[{0, c}] = currentNode;
      }
    }

    // from jug 2 to j1
    // CODE HERE
    int d2 = a - currentNode.first; // from jug 2 to jug 1
    if (currentNode.second >= d2) {
      int c2 = currentNode.second - d2; // transfer a little
      if (isChecked[{a, c2}] != 1) {
        q.push({a, c2});
        node[{a, c2}] = currentNode;
      }
    } else {
      int c2 = currentNode.first + currentNode.second;
      if (isChecked[{c2, 0}] != 1) { /// transfer all
        q.push({c2, 0});
        node[{c2, 0}] = currentNode;
      }
    }

    if (isChecked[{currentNode.first, 0}] != 1) {
      q.push({currentNode.first, 0});
      node[{currentNode.first, 0}] = currentNode;
    }

    if (isChecked[{0, currentNode.second}] != 1) {
      q.push({0, currentNode.second});
      node[{0, currentNode.second}] = currentNode;
    }
  }
  if (!isSolvable)
    cout << "No solution";
}

