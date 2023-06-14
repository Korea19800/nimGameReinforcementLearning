#include <bits/stdc++.h>
using namespace std;

int nim[3][10];
vector<pair<int, int>> record; // recording computer's every move
// first int is move's row(number of taken stick) second is col(number of left stick)

int stick;

void game();
void com_move();
void user_move();
bool is_empty(std::ifstream &pFile) {
  return pFile.peek() == std::ifstream::traits_type::eof();
}

int main() {
  // reading file
  ifstream fp("saved.txt");
  if (fp) { // when file exists
    cout << "Loading from a previously saved file\n";
    for (int row = 0; row < 3; row++) {
      for (int column = 0; column < 10; column++) {
        fp >> nim[row][column];
      }
    }
  } else { // no file
    cout << "There is no file\n";
    nim[0][0] = 1; //(1,1)
    nim[1][1] = 1; //(2,2)
    nim[2][2] = 1; //(3,3)
  }
  cout << "Before game: \n\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      cout << nim[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
  game();
  cout << "After game: \n\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      cout << nim[i][j] << ' ';
    }
    cout << '\n';
  }
  ofstream ofp("saved.txt");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      ofp << nim[i][j] << ' ';
    }
    ofp << '\n';
  }
  return 0;
}

void game() {
  stick = 10; // stick is global variable
  // run a loop unless stick is bigger than 0
  while (stick > 0) {
    // computer moves first
    com_move();
    // after computer's move, if there is no more stick, then computer wins
    if (stick == 0) {
      cout << "computer player won. Game over\n" << endl;
      // updating our nim array
      for (int i = 0; i < record.size(); i++) {
        int row = record[i].first;
        int col = record[i].second;
        nim[row][col] += 1; // since computer won, +1
      }
      return;
    }

    // user moves after computer
    user_move();
    // after user's move, if ther is no more stick, then user wins
    if (stick == 0) {
      cout << "human player won. Game over\n" << endl;
      for (int i = 0; i < record.size(); i++) {
        int row = record[i].first;
        int col = record[i].second;
        nim[row][col] -= 1; // since human won, -1
      }
      return;
    }
  }
}

void com_move() {
  cout << "computer player's turn" << endl;
  int take = 1; // if there is a tie, computer takes 1 stick
  if (nim[1][stick - 1] > nim[0][stick - 1])
    take = 2; // compare row with taking 2 sticks
  if (nim[2][stick - 1] > nim[1][stick - 1])
    take = 3; // compare row with taking 3 sticks

  record.push_back({take - 1, stick - 1});

  stick -= take;
  cout << take << " stick(s) are taken by computer" << endl;
  cout << stick << " stick(s) are left\n" << endl;
}

void user_move() {
  // number of sticks to take
  int take;
  cout << "human player's turn" << endl;
  cout << "Enter the number of sticks you want to take: ";
  // let user to enter number of sticks to take
  cin >> take;

  /* a loop to prevent user to take more than the number of left sticks
  or more than 5 sticks or negative number of sticks */
  while (stick - take < 0 || take > 3 || take <= 0) {
    if (stick - take < 0)
      cout << "you cannot choose more than the number of left sticks." << endl;
    else if (take > 3)
      cout << "you cannot choose more than 3." << endl;
    else if (take <= 0)
      cout << "you cannot choose less than or equal to zero" << endl;
    cout << "Choose again" << endl;
    cin >> take;
  }

  cout << take << " stick(s) are taken by human" << endl;
  stick -= take;
  cout << stick << " stick(s) are left\n" << endl;
}

