/*Your task is to create a football game simulation where two teams, each with a robot player,attempt to move a ball towards a predefined goal. The game determines the winner based
on which team reaches the goal in the fewest number of hits.

The Robot class represents a robot and should have two key attributes: name, which holds the name of the robot as a string, and hits, which keeps track of the number of hits made
by the robot. The class must include a method hitBall(int &ballX, int &ballY, const string &direction). This method will update the ball’s position based on the direction given
by the robot (either up, down, left, or right), and it will also increment the robot’s hit count each time the ball is hit.

For ball position on the field specify by x and y, representing the ball's current position on the field. The class should provide methods such as getX() and getY() to return
the current x and y coordinates of the ball, respectively. Additionally, the method move(int dx, int dy) will update the ball’s position based on the movement made by the robot,
and the method getPosition() will return the ball's position as a tuple (x, y) format.

Goal's position on the field designed by x and y, which define the coordinates of the goal (set to (3, 3) for this assignment. isGoalReached(int ballX, int ballY), which will check whether the ball's
position matches the goal’s coordinates.

The Team class represents a football team, which consists of robot player. The team has a teamName attribute to store the name of the team and a robot attribute that holds
a pointer to a mRobot object, which represents the player.

The Game class manages the entire game flow. It holds two Team objects (teamOne and teamTwo), a Ball object, and a Goal object. The class includes the method startGame(),
which starts the game, letting each team play its turn. The play(Team *team) method simulates the game for a given team, moving the ball towards the goal and counting
the number of hits made by the robot. After both teams have played, the declareWinner() method compares the number of hits made by each robot and declares the team with the
fewer hits as the winner.

you are required to design and implement a C++ program that simulates a simple football game. The program should follow Object-Oriented Programming (OOP) principles,
particularly focusing on "Has-A" relationship*/


#include <iostream>
#include <string>
using namespace std;

class Robot{
    string name;
    int hits;

    public:
        Robot(string n) : name(n), hits(0){}

        ~Robot(){}

        void hitBall(int &ballX, int &ballY, const string &direction){
            hits++;
            if(direction == "left")
                ballX--;
            else if(direction == "right")
                ballX++;
            else if(direction == "up")
                ballY++;
            else if(direction == "down")
                ballY--;
        }

        int getHits(){
            return hits;
        }
};

struct ballPos{    //struct for returning tuple in getPosition method
    int x, y;
};

class BallPosittion{
    int xPos;
    int yPos;

    public:
        BallPosittion() : xPos(0), yPos(0){}

        ~BallPosittion(){}

        int getX(){
            return xPos;
        }

        int getY(){
            return yPos;
        }

        void move(int dx, int dy){
            xPos += dx;
            yPos += dy;
        }

        ballPos getPosition() const{
            return {xPos, yPos};
        }

        void resetX(){
            xPos = 0;
        }

        void resetY(){
            yPos = 0;
        }
};

class Team{
    string teamName;
    Robot *mRobot;

    public:
        Team(string n, Robot *r) : teamName(n), mRobot(r){}

        ~Team(){
            delete mRobot;
        }

        string getTeamName(){
            return teamName;
        }

        Robot* getRobot(){
            return mRobot;
        }

};

class Goal{
    int goalX, goalY;

    public:
        Goal() : goalX(3), goalY(3) {}

        ~Goal(){}

        bool isGoalReached(int &ballX, int &ballY){
            if(ballX == goalX && ballY == goalY)
                return true;
            else
                return false;
        }
};

class Game{
    Team *teamOne, *teamTwo;
    BallPosittion *ball;
    Goal *goal;

    public:
        Game(Team* to, Team* tt) : teamOne(to), teamTwo(tt){
            ball = new BallPosittion();
            goal = new Goal();
        }

        ~Game(){
            delete goal;
            delete ball;
            delete teamTwo;
            delete teamOne;
        }

        int play(Team* team){   //int b/c it returns num hits by one team ka robot
            string dir;
            int ballX,ballY;
            ballPos currBallPos;

            cout << "Team " << team->getTeamName() << endl;
            while(true){
                cout << "Enter direction to hit the ball in: ";
                cin >> dir;

                currBallPos = ball->getPosition();
                ballX = currBallPos.x;
                ballY = currBallPos.y;

                team->getRobot()->hitBall(ballX,ballY,dir);
                ball->move(ballX - ball->getX(), ballY - ball->getY());

                if(goal->isGoalReached(ballX, ballY)){
                    ball-> resetX();
                    ball-> resetY();
                    cout << endl;
                    return team->getRobot()->getHits();
                }

            }
        }

        void declareWinner(int t1Hits, int t2Hits){
            if(t1Hits < t2Hits)
                cout << teamOne->getTeamName() << " wins by " << teamTwo->getRobot()->getHits() - teamOne->getRobot()->getHits() << " hits!" << endl;
            else if(t1Hits > t2Hits)
                cout << teamTwo->getTeamName() << " wins by " << teamOne->getRobot()->getHits() - teamTwo->getRobot()->getHits() << " hits!" << endl;
            else
                cout << "Its a tie! " << endl;
        }

       void startGame(){
            int score1, score2;

            score1 = play(teamOne);
            score2 = play(teamTwo);

            declareWinner(score1, score2);
       }

};

int main(){

    cout <<"Zuniarh Aziz Shaikh 24k-0986" << endl;

    cout << endl;
    
   Robot* r1 = new Robot("MbappeBot");
    Robot* r2 = new Robot("MSalahBot");
    Team* t1 = new Team("RealMadrid", r1);
    Team* t2 = new Team("FCBarcelona", r2);

    cout << "Let the game begin!" << endl;
    cout << endl;
    Game game(t1, t2);
    game.startGame();

    return 0;

}
