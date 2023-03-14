#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
char corner1 = 201, corner2 = 187, corner3 = 200, corner4 = 188, line = 205, side = 186, bullet = 254, arrow1 = 175, arrow2 = 174;

class Node {
public:
    double idNumber;
    string fName;
    int mm;
    int dd;
    int yy;
    string address;
    string gender;
    string dProgram;
    int yLevel;
    Node* next;
    Node* previous;

    Node() {
        mm = 0;
        dd = 0;
        yy = 0;
        yLevel = 0;
        address = "";
        gender = "";
        dProgram = "";
        fName = "";
        next = nullptr;
        previous = nullptr;
    }
};

class StudentRecord {

public:
    Node* head;

    StudentRecord() {
        head = nullptr;
    }
    StudentRecord(Node* n) {
        head = n;
    }

    // 1. CHeck if node exists using key value

    Node* nodeExists(int k) {
        Node* temp = NULL;
        Node* ptr = head;

        while (ptr != NULL) {
            if (ptr->idNumber == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    Node* nodeExists_name(string k) {
        Node* temp = NULL;
        Node* ptr = head;

        while (ptr != NULL) {
            if (ptr->fName == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    // 2. Append a node to the list

    void appendNode(Node* n) {
        if (nodeExists(n->idNumber) != NULL) {
            cout << "Node Already exists with key value : " << n->idNumber << ". Append another node with different Key value" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "Node Appended as Head Node" << endl;
            }
            else {
                Node* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    // 5. Delete node by unique key. Basically De-Link not delete
    void deleteNodeByKey(double k) {
        Node* ptr = nodeExists(k);
        if (ptr == nullptr) {
            cout << "Student ID with this number: " << k << " doesn't exist, please try again" << endl;
        }
        else {

            if (head->idNumber == k) {
                head = head->next;
                cout << "Student ID with number: " << k << " is officially deleted" << endl;
            }
            else {
                Node* nextNode = ptr->next;
                Node* prevNode = ptr->previous;
                // deleting at the end
                if (nextNode == nullptr) {

                    prevNode->next = nullptr;
                    cout << "Student ID with number: " << k << " is officially deleted" << endl;
                }

                //deleting in between
                else {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Student ID with number: " << k << " is officially deleted" << endl;

                }
            }
        }
    }

    // 6th update node
    void updateNodeByKey(int k, int d) {

        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            // ptr -> data  = d;
            cout << "Node Data Updated Successfully" << endl;
        }
        else {
            cout << "Node Doesn't exist with key value : " << k << endl;
        }

    }

    // 7th printing
    void printList() {
        if (head == nullptr) {
            cout << "No Nodes in Doubly Linked List";
        }
        else {
            cout << endl << "List of all student records\n";
            Node* temp = head;

            while (temp != nullptr) {
                cout << "Student ID Number:" << '\t' << fixed << setprecision(0) << temp->idNumber << endl;
                cout << "Full Name:" << '\t' << temp->fName << endl;
                cout << "Birthday:" << '\t' << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
                cout << "Address:" << '\t' << temp->address << endl;
                cout << "Gender:" << '\t' << temp->gender << endl;
                cout << "Degree Program:" << '\t' << temp->dProgram << endl;
                cout << "Year Level: " << '\t' <<   temp->yLevel << endl;
                cout << endl << endl;
                temp = temp->next;
            }
        }

    };


    int listCount() {
        int count = NULL;
        if (head == nullptr) {
            return 0;
        }
        else {
            Node* temp = head;
            while (temp != nullptr) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    };

    int* collectRecord_int(string name) {
        int size = listCount();
        int* year_lvl = new int[size];

        Node* temp = head;
        int i = 0;
        while (temp != nullptr) {
            year_lvl[i] = temp->yLevel;
            i++;
            temp = temp->next;
        }
       
        return year_lvl;
    };
 


    string* collectRecord(string name) {
        int size = listCount();
        string* fname = new string[size];
        string* address = new string[size];
        string* gender = new string[size];
        string* degprog = new string[size];
        Node* temp = head;
        int i = 0;
        if (temp == nullptr) {
            return nullptr;
        }
        else {
            while (temp != nullptr) {
                fname[i] = temp->fName;
                address[i] = temp->address;
                gender[i] = temp->gender;
                degprog[i] = temp->dProgram;
                i++;
                temp = temp->next;
            }
        };
        if (name == "Name") {
            return fname;
        }
        else if (name == "Address") {
            return address;
        }
        else if (name == "Gender") {
            return gender;
        }
        else if (name == "Degree Program") {
            return degprog;
        }else{
            return nullptr;
        }
    };

    void searchRecord(int id) {
        Node* temp = nodeExists(id);
        if (temp != nullptr) {
            cout << "Student ID Number:" << '\t' << fixed << setprecision(0) << temp->idNumber << endl;
            cout << "Full Name:" << '\t' << temp->fName << endl;
            cout << "Birthday:" << '\t' << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
            cout << "Address:" << '\t' << temp->address << endl;
            cout << "Gender:" << '\t' << temp->gender << endl;
            cout << "Degree Program:" << '\t' << temp->dProgram << endl;
            cout << "Year Level: " << '\t' << temp->yLevel << endl;
        }
        else {
            cout << "Student ID number: " << id << " doesn't exist\n";
        }
    };

    void searchRecord(string name) {
        Node* temp = nodeExists_name(name);

        if (temp != nullptr) {
            cout << "Student ID Number:" << '\t' << fixed << setprecision(0) << temp->idNumber << endl;
            cout << "Full Name:" << '\t' << temp->fName << endl;
            cout << "Birthday:" << '\t' << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
            cout << "Address:" << '\t' << temp->address << endl;
            cout << "Gender:" << '\t' << temp->gender << endl;
            cout << "Degree Program:" << '\t' << temp->dProgram << endl;
            cout << "Year Level: " << '\t' << temp->yLevel << endl;
        }
        else {
            cout << "Student Name: " << name << " doesn't exist\n";
        }
    };

    void specificRecord(string name) {
        system("cls");
        Node* temp = head;
        if (name == "Name" || name == "Gender" || name == "Address" || name == "Degree Program") {
            cout << "ID Number: " << name << '\n';
            string* values;
            values = collectRecord(name);
            int i = 0;
            while (temp != nullptr) {
                cout << temp->idNumber << '\t' << values[i] << endl;
                i++;
                temp = temp->next;
            }

        }
        else if (name == "Year Level") {
            cout << "ID Number: " << "Year Level:\n";
            int* values;
            values = collectRecord_int(name);
            int i = 0;
            while (temp != nullptr) {
                cout << temp->idNumber << '\t' << values[i] << endl;
                i++;
                temp = temp->next;
            }
        }
        else {
            cout << "ID Number: " << "Year Level:'\n'";
            while (temp != nullptr) {
                cout << temp->idNumber << '\t' << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
                temp = temp->next;
            }
        }

    };
};

Node* makeStudent(Node* n1);
void searchRecord(StudentRecord obj);
void deleteRecord(StudentRecord obj);
void displayAllRecords(StudentRecord obj);
void displaySpecificRecord(StudentRecord obj);
void pause();
bool checkID(double num);
bool checkBDAY(int dd, int mm, int yy);
bool checkGENDER(string gender);
bool checkYRLVL(int yrlvl);

int main() {

    StudentRecord obj;
    int option;
    do {
        system("cls"); system("Color 0E");
        cout << corner1 << setfill(line) << setw(32) << arrow1 << "HOME" << arrow2 << setw(35) << corner2;
        cout << endl << side << "\t\t\t\t\t\t\t\t\t" << side << endl;
        cout << side << "\t\tWELCOME TO GROUP XYZ STUDENT INFORMATION SYSTEM\t\t\t" << side << endl;
        cout << side << "\t\t\t\t\t\t\t\t\t" << side << endl;
        cout << corner3 << setw(72) << corner4 << endl;
        cout << setfill(' ');
        cout << endl << setw(13) << arrow1 << "- What do you want to do? -" << arrow2 << endl << endl;
        cout << setfill(line) << line << setw(72) << line << endl << endl;
        cout << setfill(' ');
        cout << setw(27) << arrow1 << "-[1] Add New Record.-" << arrow2 << endl;
        cout << setw(27) << arrow1 << "-[2] Search Record.-" << arrow2 << endl;
        cout << setw(27) << arrow1 << "-[3] Display ALl Records.-" << arrow2 << endl << endl;
        cout << setw(27) << arrow1 << "-[4] Display Specific Record.-" << arrow2 << endl;
        cout << setw(27) << arrow1 << "-[5] Delete Record.-" << arrow2 << endl;
        cout << setw(27) << arrow1 << "-[6] Exit.-" << arrow2 << endl << endl;
        cin >> option;
        Node* n1 = new Node();
        //Node n1;

        switch (option) {
        case 0:
            break;
        case 1:
            obj.appendNode(makeStudent(n1));
            break;

        case 2:
            searchRecord(obj);
            break;

        case 3:
            displayAllRecords(obj);
            break;
        case 4:
            displaySpecificRecord(obj);
            break;
        case 5:
            deleteRecord(obj);
            break;
        case 6:
            exit(EXIT_SUCCESS);
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
};


void displaySpecificRecord(StudentRecord obj) {
    system("cls");
    int option;
    cout << setw(27) << arrow1 << "Choose what record to display" << arrow2 << endl;
    cout << setw(27) << arrow1 << "-[1] Name-" << arrow2 << endl;
    cout << setw(27) << arrow1 << "-[2] Birthday-" << arrow2 << endl;
    cout << setw(27) << arrow1 << "-[3] Gender-" << arrow2 << endl << endl;
    cout << setw(27) << arrow1 << "-[4] Address-" << arrow2 << endl;
    cout << setw(27) << arrow1 << "-[5] Degree Program-" << arrow2 << endl;
    cout << setw(27) << arrow1 << "-[6] Year Level-" << arrow2 << endl << endl;
    cin >> option;

    switch (option) {
    case 1:
        obj.specificRecord("Name");
        pause();
        break;
    case 2:
        obj.specificRecord("Birthday");
        pause();
        break;
    case 3:
        obj.specificRecord("Gender");
        pause();
        break;
    case 4:
        obj.specificRecord("Address");
        pause();
        break;
    case 5:
        obj.specificRecord("Degree Program");
        pause();
        break;
    case 6:
        obj.specificRecord("Year Level");
        pause();
        break;
    default:
        cout << "Invalid input";
    }
};



    void displayAllRecords(StudentRecord obj) {
        system("cls");
        obj.printList();
        pause();
        return;
    };

    void searchRecord(StudentRecord obj) {
        int user_option; string name; double idNumber;
        cout << "Search for record using\n [1] Student ID number.\n [2] Student Name.\n " << endl;
        cin >> user_option;
        if (user_option == 1) {
            cout << "Enter Student ID number";
            cin >> idNumber;
            obj.searchRecord(idNumber);
        }
        else if (user_option == 2) {
            cout << "Enter Student Name";
            cin >> name;
            obj.searchRecord(name);
        }
        else {
            cout << "wrong input, try again";
            return;
        }

        pause();
        return;
    };

    void deleteRecord(StudentRecord obj) {
        system("cls");
        double idNumber;
        cout << "Delete Node By Student id number \nEnter the student id number to be deleted: " << endl;
        cin >> idNumber;
        obj.deleteNodeByKey(idNumber);
        return;
    };

Node* makeStudent(Node* n1) {
    double idNumber;
    string fname, address, gender, dProgram;
    int mm, dd, yy, yLevel;

            system("cls");
            cout << "Append Node Operation \nEnter Student & data of the Node to be Appended" << endl;

            while (true) {
                cout << setw(27) << arrow1 << "Enter Student ID Number: " << arrow2 << endl;
                cin >> idNumber;
                if (checkID(idNumber) == false) {
                    cout << "Invalid Student Number, must consist of 7 digit number, please try again\n";
                    pause();
                }
                else {
                    break;
                }
            }

            cin.ignore();
            cout << setw(27) << arrow1 << "Enter Full Name: " << arrow2 << endl;
            getline(cin, fname);

            cout << setw(27) << arrow1 << "Enter Address: " << arrow2 << endl;
            getline(cin, address);
            
            while (true) {
                cout << setw(27) << arrow1 << "Enter Birthday: " << arrow2 << endl;
                cin >> dd >> mm >> yy;
                if (checkBDAY(dd, mm, yy) == false) {
                    cout << "Invalid Birthday format, use dd/mm/yyyy, please try again\n";
                    pause();
                }
                else {
                    break;
                }
            }

            while (true) {
                cin.ignore();
                cout << setw(27) << arrow1 << "Enter Gender: " << arrow2 << endl;
                getline(cin, gender);
                if (checkGENDER(gender) == false) {
                    cout << "Invalid Input, please try again";
                    pause();
                }
                else {
                    break;
                }
            }
            cout << setw(27) << arrow1 << "Enter Degree Program: " << arrow2 << endl;
            getline(cin, dProgram);

            while (true) {
                cout << setw(27) << arrow1 << "Enter Year Level: " << arrow2 << endl;
                cin >> yLevel;
                if (checkYRLVL(yLevel) == false) {
                    cout << "Invalid Input, please try again";
                    pause();
                }
                else {
                    break;
                }
            }
        
            n1->idNumber = idNumber;
            n1->fName = fname;
            n1->address = address;
            n1->dd = dd;
            n1->mm = mm;
            n1->gender = gender;
            n1->yLevel = yLevel;
            n1->yy = yy;
            n1->dProgram = dProgram;

    return n1;
}

bool checkID(double num) {
    string id;
    stringstream ss;
    ss << num;
    ss >> id;
    int size = id.length();
    if (size < 7) {
        return false;
    }
    else {
        return true;
    }
};

bool checkBDAY(int dd, int mm, int yy) {
    string day, month, year;
    stringstream ss;
    ss << dd;
    ss >> day;
    ss.clear();
    ss << mm;
    ss >> month;
    ss.clear();
    ss << yy;
    ss >> year;

    if ((day.length() >= 1 && day.length() <= 2) && (month.length() >= 1 && month.length() <= 2) && (year.length() == 4) && (yy < 2023)) {
        return true;
    }
    else {
        return false;
    }

};

bool checkGENDER(string gender) {
    if (gender == "Male" || gender == "Female") {
        return true;
    }
    else {
        return false;
    }
}

bool checkYRLVL(int yrlvl) {
    if (yrlvl >= 1 && yrlvl <= 4) {
        return true;
    }
    else {
        return false;
    }
}

void pause() {
    char trash;
    cout << "\nEnter any key to continue..." << flush;
    cin >> trash;
    return;
};
