#include <iostream>
using namespace std;

class Team
{
  private:
    int score;
    int shotsOnGoal;
    string name;
  public:
    Team()
{
  score = 0; shotsOnGoal = 0; name = "DefaultName";
}
void setScore(int s) {score = s;}
void setShotsOnGoal(int sog) {shotsOnGoal = sog;}
void setName(string n) {name = n;}
int getScore() const {return score;}
int getShotsOnGoal() const {return shotsOnGoal;}
string getName() const {return name;}
};

class Scoreboard
{
  private:
    int min;
    int sec;
    int half;
    Team home; //object home is of data type team
    Team away; //object visitor is of data type team
  public:
    Scoreboard()
{
  min = 0; sec = 0; half = 1; home = Team(); away = Team();
}
void setHome(Team hSet) {home = hSet;}
void setAway(Team aSet) {away = aSet;}
void setMin(int m) {min = m;}
void setSec(int s) {sec = s;}
void setHalf(int h) {half = h;}
int getMin() const {return min;}
int getSec() const {return sec;}
int getHalf() const {return half;}
Team getHome() const {return home;}
Team getAway() const {return away;}
void showScoreboard(){
  cout << home.getName() << "\t\t" << away.getName() << endl;
  cout << "\t\t\t" << min << ":" << sec << endl;
  cout << home.getScore() << "\t\t\t" << "Goals" << "\t\t\t" << away.getScore() << endl;
  cout << "\t\t\tHalf: " << half << endl;
  cout << home.getShotsOnGoal() << "\t\t" << "Shots On Goal" << "\t\t" << away.getShotsOnGoal() << endl;
}
};

int main() {
  Scoreboard s;
  Team tOne;
  Team tTwo;
  char choice = '\0';
  string newName = "";
  int newScore = 0;
  int newSOG = 0;
  
  s.setHome(tOne);
  s.setAway(tTwo);

  do
  {
    s.showScoreboard();
    cout << "\nMenu" << endl;
    cout << "A. Update Home Team Name" << endl;
    cout << "B. Update Home Team Score" << endl;
    cout << "C. Update Home Team Shots On Goal" << endl;
    cout << "X. Exit" << endl;
    cout << "Choice ";
    cin >> choice;
    if(choice == 'a' || choice == 'A'){
      cout << "Enter a new name for the home team: ";
      cin >> newName;
      tOne.setName(newName);

    } else if(choice == 'b' || choice == 'B'){
      cout << "Enter a new score for the home team: ";
      cin >> newScore;
      tOne.setScore(newScore);
    } else if(choice == 'c' || choice == 'C'){
      cout << "Enter a new shots on goal for the home team: ";
      cin >> newSOG;
      tOne.setShotsOnGoal(newSOG);
    }


  s.setHome(tOne);
  s.setAway(tTwo);  
  cout << "\033[2J\033[1;1H";
  } while (choice != 'x' && choice != 'X');
  

  return 0;
}