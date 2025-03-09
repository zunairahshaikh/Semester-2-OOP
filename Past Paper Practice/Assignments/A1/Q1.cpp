/*FAST has many sports enthusiasts, and to encourage their growth, the university wants to implement a mentorship program. In this program, mentors guide learners (students),
but each mentor has a limited capacity to manage a fixed number of learners. The university sports mentorship system involves two main roles: mentors and learners (students).

The Student class has data members such as studentID, name, age, sportsInterests[], and mentorAssigned. A student can register for mentorship under a mentor by calling the
registerForMentorship(Mentor m) method. The student can also view the mentor’s details and update their sports interests through viewMentorDetails() and updateSportsInterest(Sport s)
methods, respectively.

The Mentor class, on the other hand, has data members like mentorID, name, sportsExpertise[], maxLearners, and assignedLearners[]. The maxLearners attribute specifies the
maximum number of learners the mentor can handle. The mentor can assign learners using the assignLearner(Student s) method, as long as they have available capacity.
If a learner needs to be removed, the removeLearner(Student s) method can be used. The mentor can also view their list of assigned learners by calling viewLearners() and provide
guidance using the provideGuidance() method.

The Sport class defines the sports offered for mentorship. It includes attributes like sportID, name, description, and requiredSkills[].
The mentor can add new skills required for a specific sport using the addSkill(Skill s) method, and they can also remove skills from the list using removeSkill(Skills).

The Skill class defines the various skills related to each sport, including data members like skillID, skillName, and description. This class provides methods such as showSkillDetails()
to display the skill details and updateSkillDescription(String newDescription) to update a skill’s description.

In this system, each mentor has a limited capacity to handle learners. For example, a mentor named Ali who specializes in Tennis can only mentor up to three students at a time.
When a student like Saad, who is interested in Tennis, registers for mentorship, Ali can assign him as a mentee if there is space. If Ali already has three learners, Saad cannot be
assigned until a slot becomes available. If Saad later decides to stop the mentorship, Ali can remove them, freeing up space for a new student. The system allows mentors to guide
students on their sports skills, providing training and advice to improve their performance.*/

#include <iostream>
using namespace std;

class Mentor;
class Skill;
class Sport;

class Student {
    string studentID;
    string Name;
    int Age;
    Sport** sportsInterests;
    int numInterests;
    Mentor* mentorAssigned;

public:
    Student(string id, string name, int age,  int ni, Mentor* men): studentID(id), Name(name), Age(age), numInterests(ni), mentorAssigned(nullptr) {
        sportsInterests = new Sport*[numInterests];
        for (int i = 0; i < numInterests; i++) {
            sportsInterests[i];
        }
    }

    ~Student() {
        delete[] sportsInterests;
    }

    void registerForMentorship(Mentor* m);
    void viewMentorDetails() const;

    void updateSportsInterest(Sport* s){
        if(numInterests < 5){ //assuming a student can learn 5 sports at a time
            sportsInterests[numInterests] = s;
            numInterests++;
        }
    }

    string getName() const {
        return Name;
    }
};

class Mentor {
    string mentorID;
    string Name;
    string* sportsExpertise;
    int numExpertise;
    int maxLearners;
    Student** assignedLearners;
    int learnerCount;

public:
    Mentor(string id, string name, string* se, int max, int numExp) : mentorID(id), Name(name), numExpertise(numExp), maxLearners(max), learnerCount(0) {
        assignedLearners = new Student*[maxLearners];
        sportsExpertise = new string[numExpertise];
        for (int i = 0; i < numExpertise; i++) {
            sportsExpertise[i] = se[i];
        }
    }

    ~Mentor() {
        delete[] sportsExpertise;
        delete[] assignedLearners;
    }

    bool assignLearner(Student* s) {
        if (learnerCount < maxLearners) {
            assignedLearners[learnerCount++] = s;
            cout << "Student added successfully!" << endl;
            return true;
        } else {
            cout << "Maximum number of students reached." << endl;
            return false;
        }
    }

    void removeLearner(Student* s) {
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i] == s) {
                for (int j = i; j < learnerCount - 1; j++) 
                    assignedLearners[j] = assignedLearners[j + 1];
                learnerCount--;
                cout << "Student removed successfully" << endl;
                break;
            }
        }
    }

    void viewLearners() const {
        cout << "Mentor: " << Name << "'s Learners:\n";
        for (int i = 0; i < learnerCount; i++) 
            cout << assignedLearners[i]->getName() << endl;
    }

    string getName() const {
        return Name;
    }
};


void Student::registerForMentorship(Mentor* m) {
    if (m->assignLearner(this)) {
        mentorAssigned = m;
        cout << Name << " registered under mentor " << m->getName() << endl;
    } else {
        cout << "Mentor " << m->getName() << " has no available slots.\n";
    }
}

void Student::viewMentorDetails() const {
    if (mentorAssigned) {
        cout << "Mentor assigned: " << mentorAssigned->getName() << endl;
    } else {
        cout << "No mentor assigned.\n";
    }
}

class Sport {
    string sportID;
    string Name;
    string description;
    Skill** requiredSkills;
    int skillCount;

public:
    Sport(string id, string name, string desc) : sportID(id), Name(name), description(desc), skillCount(0) {
        requiredSkills = new Skill*[10]; // assuming max skills are 10
    }

    ~Sport() {
        delete[] requiredSkills;
    }
};

class Skill {
    string skillID;
    string Name;
    string description;

public:
    Skill(string id, string name, string desc) : skillID(id), Name(name), description(desc) {}

    void showSkillDetails() {
        cout << "Skill: " << Name << " - " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
        cout << "New description for skill " << Name << ": " << description << endl;
    }
};


int main() {

    cout <<"Zuniarh Aziz Shaikh 24k-0986" << endl;

    cout << endl;
    
    Sport football("S001", "Football", "A team sport played with a ball.");
    Sport basketball("S002", "Basketball", "A fast-paced game with hoops.");
    
    
    Skill dribbling("SK001", "Dribbling", "Control the ball while moving.");
    Skill shooting("SK002", "Shooting", "Accurate shot towards the goal.");
    
    string mentorExpertise1[] = {"Football", "Basketball"};
    
    Mentor mentor1("M001", "Ali", mentorExpertise1, 3, 2);
    
    Student student1("ST001", "Saad", 18, 0, nullptr);
    Student student2("ST002", "Bisma", 19, 0, nullptr);
    
    student1.registerForMentorship(&mentor1);
    student2.registerForMentorship(&mentor1);
    
    student1.viewMentorDetails();
    student2.viewMentorDetails();
    
    mentor1.viewLearners();
    
    student1.updateSportsInterest(&football);
    student1.updateSportsInterest(&basketball);
    
    student2.updateSportsInterest(&football);
    
    mentor1.removeLearner(&student1);
    
    mentor1.viewLearners();
    
    return 0;
}
