#include <iostream>

using namespace std;

void enterTable(int, int[][100]);
void showTable(int, int[][100]);

void assignTask(int, int[][100], int[]);
int getMinTime(int, int[][100], int[], int);
void showResults(int[], int);
int findFirstIndex(int[], int);


void showResults2(int[], int);
void assignTaskOp2(int, int[][100], int[]);
int getMinTime2(int, int[][100], int[], int);

int main() {
  // b0: results[N]; Task [];
  int N;
  int results[100];
  int table[100][100];
  cout << "Nhap N ";
  cin >> N;
  enterTable(N, table);
  showTable(N, table);
  // assignTask(N, table, results);
  assignTaskOp2(N, table, results);
  // b1: nhap bang cong viec = nhap mang 2 chieu => function
  // op1: nguoi tim viec
  // b2: Xet hang => for
  // tim gia tri nho nhat => function call assignTask
  // khong xet nhung cot da chon
  // -> results = [5, 2, ....]
  // op2: viec tim nguoi
  //  .................
  // b3: xuat ket qua
  // showResults(results, N);
  showResults2(results, N);
  return 0;
}

/*
[0,0]5 6 4 7 2
[1,0]5 2 4 5 1
[2,0]4 5 4 6 3
[3,0]5 5 3 4 2
[4,0]3 3 5 2 5
*/
void enterTable(int N, int table[][100]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << "Nhap " << i << " " << j << " ";
      cin >> table[i][j];
    }
  }
}

void showTable(int N, int table[][100]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
}

void assignTask(int N, int table[][100], int results[]) {
  int task[N] = {0}; // danh sach task da lam (1) hay chua (0)
  for (int i = 0; i < N; i++) {
    // staff i th = row i th -> task -> min value -> function
    int t = getMinTime(i, table, task, N);
    task[t] = 1;
    results[i] = t;
  }
}

void showResults(int results[], int N) {
  for (int i = 0; i < N; i++) {
    cout << "Staff " << i + 1 << ": " << results[i] + 1 << endl;
  }
}

int getMinTime(int row, int table[][100], int task[], int N) {
  // find first index
  int minIndex = findFirstIndex(task, N);
  for (int j = 0; j < N; j++) {
    if (table[row][j] < table[row][minIndex] && task[j] == 0) {
      minIndex = j;
    }
  }
  return minIndex;
}

int findFirstIndex(int task[], int N) {
  for (int i = 0; i < N; i++) {
    if (task[i] == 0) {
      return i;
    }
  }
  return -1;
}

void assignTaskOp2(int N, int table[][100], int results[]) {
  // CODE HERE
  int task[N] = {0}; // danh sach task da lam (1) hay chua (0)
  for (int i = 0; i < N; i++) {
    int t = getMinTime2(i, table, task, N);
    task[t] = 1;
    results[i] = t;
  }
}
  
void showResults2(int results[], int N) {
  for (int i = 0; i < N; i++) {
    cout << "Task " << i + 1 << ": " << results[i] + 1 << endl;
  }
}
int getMinTime2(int column, int table[][100], int task[], int N) {
  // find first index
  int minIndex = findFirstIndex(task, N);
  for (int j = 0; j < N; j++) {
    if (table[j][column] < table[column][minIndex] && task[j] == 0) {
      minIndex = j;
    }
  }
  return minIndex;
}
