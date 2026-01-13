#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;
// ===== INPUT VALIDATION HELPER FUNCTIONS =====
int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "\n? Invalid input! Please enter a number.\n\n";
        } else {
            cin.ignore();
            return value;
        }
    }
}

// Function to safely get positive integer input
int getValidatedPositiveInt(const string& prompt) {
    int value;
    while (true) {
        value = getValidatedInt(prompt);
        if (value > 0) {
            return value;
        }
        cout << "\n? Please enter a positive number!\n\n";
    }
}

// Function to safely get double input with validation
double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value; 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n? Invalid input! Please enter a number.\n\n";
        } else {
            cin.ignore();
            return value;
        }
    }
}
// Function to safely get positive double input
double getValidatedPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        value = getValidatedDouble(prompt);
        if (value > 0) {
            return value;
        }
        cout << "\n? Please enter a positive number!\n\n";
    }
}

// ===== NODE CLASSES WITH GETTERS/SETTERS =====

// Action Node for Stack (System Reports)
class ActionNode {
private:
    string action;
    string timestamp;
    
public:
    ActionNode* next;
    
    ActionNode(string act, string time, ActionNode* nxt = NULL) {
        action = act;
        timestamp = time;
        next = nxt;
    }
    
    string getAction() const { return action; }
    string getTimestamp() const { return timestamp; }
    void setAction(string act) { action = act; }
    void setTimestamp(string time) { timestamp = time; }
};

// Medicine Node for Linked List
class MedicineNode {
private:
    int id;
    string name;
    int quantity;
    double price;
    
public:
    MedicineNode* next;
    
    MedicineNode(int i, string n, int q, double p, MedicineNode* nxt = NULL) {
        id = i;
        name = n;
        quantity = q;
        price = p;
        next = nxt;
    }
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    
    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
};

// Bill Node for Linked List
class BillNode {
private:
    int billID;
    string patientName;
    string itemsDetails;
    double totalAmount;
    bool isPaid;
    
public:
    BillNode* next;
    
    BillNode(int id, string pName, string itm, double amount, BillNode* nxt = NULL) {
        billID = id;
        patientName = pName;
        itemsDetails = itm;
        totalAmount = amount;
        isPaid = false;
        next = nxt;
    }
    
    // Getters
    int getBillID() const { return billID; }
    string getPatientName() const { return patientName; }
    string getItemsDetails() const { return itemsDetails; }
    double getTotalAmount() const { return totalAmount; }
    bool getIsPaid() const { return isPaid; }
    
    // Setters
    void setBillID(int id) { billID = id; }
    void setPatientName(string pName) { patientName = pName; }
    void setItemsDetails(string itm) { itemsDetails = itm; }
    void setTotalAmount(double amount) { totalAmount = amount; }
    void setIsPaid(bool paid) { isPaid = paid; }
};

// Prescription Node for Linked List
class PrescriptionNode {
private:
    int prescriptionID;
    string patientName;
    string doctorName;
    string medicineName;
    int quantity;
    bool isFilled;
    
public:
    PrescriptionNode* next;
    
    PrescriptionNode(int id, string pName, string dName, string mName, int qty, PrescriptionNode* nxt = NULL) {
        prescriptionID = id;
        patientName = pName;
        doctorName = dName;
        medicineName = mName;
        quantity = qty;
        isFilled = false;
        next = nxt;
    }
    
    // Getters
    int getPrescriptionID() const { return prescriptionID; }
    string getPatientName() const { return patientName; }
    string getDoctorName() const { return doctorName; }
    string getMedicineName() const { return medicineName; }
    int getQuantity() const { return quantity; }
    bool getIsFilled() const { return isFilled; }
    
    // Setters
    void setPrescriptionID(int id) { prescriptionID = id; }
    void setPatientName(string pName) { patientName = pName; }
    void setDoctorName(string dName) { doctorName = dName; }
    void setMedicineName(string mName) { medicineName = mName; }
    void setQuantity(int qty) { quantity = qty; }
    void setIsFilled(bool filled) { isFilled = filled; }
};

// Doctor Node Class for Linked List
class DoctorNode {
private:
    int id;
    string name;
    int age;
    string specialization;
    string username;
    string password;
    
public:
    DoctorNode* next;
    
    DoctorNode(int i, string n, int a, string s, string u, string p, DoctorNode* nxt = NULL) {
        id = i;
        name = n;
        age = a;
        specialization = s;
        username = u;
        password = p;
        next = nxt;
    }
    
    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setSpecialization(string s) { specialization = s; }
    void setUsername(string u) { username = u; }
    void setPassword(string p) { password = p; }
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getSpecialization() const { return specialization; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
};

// Patient Node Class for Linked List
class PatientNode {
private:
    int id;
    string name;
    int age;
    string disease;
    string username;
    string password;
    
public:
    PatientNode* next;
    
    PatientNode(int i, string n, int a, string d, string u, string p, PatientNode* nxt = NULL) {
        id = i;
        name = n;
        age = a;
        disease = d;
        username = u;
        password = p;
        next = nxt;
    }
    
    // Setters
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setDisease(string d) { disease = d; }
    void setUsername(string u) { username = u; }
    void setPassword(string p) { password = p; }
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getDisease() const { return disease; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
};

// Appointment Node Class for Queue
class AppointmentNode {
private:
    int appointmentID;
    string patientName;
    string doctorName;
    int priority;
    
public:
    AppointmentNode* next;
    
    AppointmentNode(int id, string pName, string dName, int pri, AppointmentNode* nxt = NULL) {
        appointmentID = id;
        patientName = pName;
        doctorName = dName;
        priority = pri;
        next = nxt;
    }
    
    // Setters
    void setAppointmentID(int id){
        appointmentID = id; 
    }
    void setPatientName(string pName){
        patientName = pName;
    }
    void setDoctorName(string dName){
        doctorName = dName;
    }
    void setPriority(int pri){
        priority = pri;
    }
    int getAppointmentID() const{
        return appointmentID;
    }
    string getPatientName() const{
        return patientName;
    }
    string getDoctorName() const{
        return doctorName;
    }
    int getPriority() const{
        return priority;
    }
};
// ===== STACK FOR ACTION TRACKING =====
class ActionStack {
private:
    ActionNode* top; 
public:
    ActionStack() : top(NULL) {}
    void push(string action) {
        time_t now = time(0);
        string timestamp = ctime(&now);
        timestamp.pop_back(); 
        ActionNode* newNode = new ActionNode(action, timestamp, top);
        top = newNode;
    }
    void display() {
        if (top == NULL) {
            cout << "No actions recorded yet.\n";
            return;
        }
        cout << "\n===== SYSTEM REPORTS (Action Stack) =====\n";
        cout << "Recent Actions (Most Recent First):\n";
        cout << "----------------------------------------\n";
        ActionNode* temp = top;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". " << temp->getAction() << "\n";
            cout << "   Time: " << temp->getTimestamp() << "\n\n";
            temp = temp->next;
            count++;
        }
    }
    ~ActionStack() {
        while (top != NULL) {
            ActionNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
// ===== LINKED LIST FOR PRESCRIPTIONS =====
class PrescriptionList {
private:
    PrescriptionNode* head;
public:
    PrescriptionList() : head(NULL) {}
    
    void addPrescription(int id, string patient, string doctor, string medicine, int quantity) {
        PrescriptionNode* newNode = new PrescriptionNode(id, patient, doctor, medicine, quantity, NULL);
        if (head == NULL) {
            head = newNode;
        } else {
            PrescriptionNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    PrescriptionNode* findById(int id){
        PrescriptionNode* temp = head;
        while (temp != NULL){
            if (temp->getPrescriptionID() == id){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    
    void displayAll(){
        if (head == NULL){
            cout<<"No prescriptions available.\n";
            return;
        }  
        cout << "\n===== ALL PRESCRIPTIONS =====\n";
        PrescriptionNode* temp = head;
        while (temp != NULL) {
            cout << "Prescription ID: " << temp->getPrescriptionID() << "\n";
            cout << "Patient: " << temp->getPatientName() << "\n";
            cout << "Doctor: " << temp->getDoctorName() << "\n";
            cout << "Medicine: " << temp->getMedicineName() << "\n";
            cout << "Quantity: " << temp->getQuantity() << "\n";
            cout << "Status: " << (temp->getIsFilled() ? "Filled" : "Pending") << "\n";
            cout << "--------------------------------\n";
            temp = temp->next;
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
    // File handling
    void saveToFile() {
        ofstream file("prescriptions.txt");
        if (!file) {
            cout << "Error opening file!\n";
            return;
        }
        PrescriptionNode* temp = head;
        while (temp != NULL) {
            file << temp->getPrescriptionID() << "|"
                 << temp->getPatientName() << "|"
                 << temp->getDoctorName() << "|"
                 << temp->getMedicineName() << "|"
                 << temp->getQuantity() << "|"
                 << temp->getIsFilled() << "\n";
            temp = temp->next;
        }
        file.close();
    }
    void loadFromFile() {
        ifstream file("prescriptions.txt");
        if (!file) return;
        int id, quantity;
        string patient, doctor, medicine;
        bool filled;
        char delimiter;
        while (file >> id >> delimiter){
            getline(file, patient, '|');
            getline(file, doctor, '|');
            getline(file, medicine, '|');
            file>>quantity>>delimiter>>filled;
            file.ignore();
            PrescriptionNode* newNode = new PrescriptionNode(id, patient, doctor, medicine, quantity, NULL);
            newNode->setIsFilled(filled);
            if (head == NULL) {
                head = newNode;
            } else {
                PrescriptionNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    }
    ~PrescriptionList() {   // destructor
        while (head != NULL) {
            PrescriptionNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ===== LINKED LIST FOR BILLS =====
class BillList {
private:
    BillNode* head;   
public:
    BillList():head(NULL) {}
    void addBill(int id, string patient, string items, double amount){
        BillNode* newNode = new BillNode(id, patient, items, amount, NULL);
        if (head == NULL) {
            head = newNode;
        } else {
            BillNode* temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    BillNode* findById(int id){
        BillNode* temp = head;
        while (temp != NULL){
            if (temp->getBillID() == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void displayUnpaid(){
        if (head == NULL){
            cout<<"No bills available.\n";
            return;
        }
        cout << "\n===== UNPAID BILLS =====\n";
        bool found = false;
        BillNode* temp = head;
        
        while (temp != NULL){
            if (!temp->getIsPaid()){
                cout<<"Bill ID: " << temp->getBillID() << "\n";
                cout<<"Patient: " << temp->getPatientName() << "\n";
                cout<<"Items:\n" << temp->getItemsDetails() << "\n";
                cout<<"Total Amount: $" << temp->getTotalAmount() << "\n";
                cout<<"Status: Unpaid\n";
                cout<<"========================================\n";
                found = true;
            }
            temp = temp->next;
        }
        
        if (!found) {
            cout << "No unpaid bills.\n";
        }
    }
    void displayAll(){
        if (head == NULL){
            cout<<"No bills available.\n";
            return;
        }
        cout<<"\n===== ALL BILLS =====\n";
        BillNode* temp = head;
        while (temp != NULL) {
            cout << "Bill ID: " << temp->getBillID() << "\n";
            cout << "Patient: " << temp->getPatientName() << "\n";
            cout << "Items:\n" << temp->getItemsDetails() << "\n";
            cout << "Total Amount: $" << temp->getTotalAmount() << "\n";
            cout << "Status: " << (temp->getIsPaid() ? "Paid" : "Unpaid") << "\n";
            cout << "========================================\n";
            temp = temp->next;
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
    // File handling
    void saveToFile() {
        ofstream file("bills.txt");
        if (!file) {
            cout << "Error opening file!\n";
            return;
        }  
        BillNode* temp = head;
        while (temp != NULL) {
            file <<temp->getBillID() << "|"
                 <<temp->getPatientName() << "|"
                 <<temp->getItemsDetails() << "|"
                 <<temp->getTotalAmount() << "|"
                 <<temp->getIsPaid() << "\n";
            temp = temp->next;
        }
        file.close();
    }
    void loadFromFile() {
        ifstream file("bills.txt");
        if (!file) return;
        int id;
        string patient, items;
        double amount;
        bool paid;
        char delimiter;
        while (file >> id >> delimiter) {
            getline(file, patient, '|');
            getline(file, items, '|');
            file >> amount >> delimiter >> paid;
            file.ignore();
            
            BillNode* newNode = new BillNode(id, patient, items, amount, NULL);
            newNode->setIsPaid(paid);
            if (head == NULL) {
                head = newNode;
            } else {
                BillNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    }
    ~BillList() {
        while (head != NULL) {
            BillNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ===== LINKED LIST FOR MEDICINES =====
class MedicineList {
private:
    MedicineNode* head;
public:
    MedicineList() : head(NULL) {}
    bool addMedicine(int id, string name, int quantity, double price) {
        MedicineNode* existing = findById(id);
        if (existing != NULL) {
            cout << "\n? Medicine with ID " << id << " already exists!\n";
            return false;
        } 
        MedicineNode* newNode = new MedicineNode(id, name, quantity, price, NULL);
        if (head == NULL) {
            head = newNode;
        } else {
            MedicineNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return true;
    }
    MedicineNode* findById(int id) {
        MedicineNode* temp = head;
        while (temp != NULL) {
            if (temp->getId() == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    MedicineNode* findByName(string name) {
        MedicineNode* temp = head;
        while (temp != NULL) {
            if (temp->getName() == name) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    bool restockMedicine(int id, int additionalQuantity) {
        MedicineNode* medicine = findById(id);
        if (medicine == NULL) {
            return false;
        }
        medicine->setQuantity(medicine->getQuantity() + additionalQuantity);
        return true;
    }
    bool dispenseMedicine(string name, int quantity) {
        MedicineNode* medicine = findByName(name);
        if (medicine == NULL) {
            return false;
        } 
        if (medicine->getQuantity() < quantity) {
            cout << "\n? Insufficient stock! Available: " << medicine->getQuantity() << "\n";
            return false;
        } 
        medicine->setQuantity(medicine->getQuantity() - quantity);
        return true;
    }
    void display() {
        if (head == NULL) {
            cout << "No medicines in inventory.\n";
            return;
        } 
        cout << "\n===== MEDICINE INVENTORY =====\n";
        cout << "ID\tName\t\t\tQuantity\tPrice\n";
        cout << "--------------------------------------------------------\n";
        MedicineNode* temp = head;
        while (temp != NULL) {
            cout << temp->getId() << "\t" << temp->getName() << "\t\t\t" 
                 << temp->getQuantity() << "\t\t$" << temp->getPrice() << endl;
            temp = temp->next;
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
    // File handling
    void saveToFile() {
        ofstream file("medicines.txt");
        if (!file) {
            cout << "Error opening file!\n";
            return;
        }  
        MedicineNode* temp = head;
        while (temp != NULL) {
            file << temp->getId() << "|"
                 << temp->getName() << "|"
                 << temp->getQuantity() << "|"
                 << temp->getPrice() << "\n";
            temp = temp->next;
        }
        file.close();
    }
    void loadFromFile() {
        ifstream file("medicines.txt");
        if (!file) return;
        
        int id, quantity;
        string name;
        double price;
        char delimiter;
        
        while (file >> id >> delimiter) {
            getline(file, name, '|');
            file >> quantity >> delimiter >> price;
            file.ignore();
            
            MedicineNode* newNode = new MedicineNode(id, name, quantity, price, NULL);
            
            if (head == NULL) {
                head = newNode;
            } else {
                MedicineNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    }
    
    ~MedicineList() {
        while (head != NULL) {
            MedicineNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ===== LINKED LIST FOR DOCTORS =====
class DoctorList {
private:
    DoctorNode* head;
    
public:
    DoctorList() : head(NULL) {}
    
    bool addDoctor(int id, string name, int age, string spec, string user, string pass) {
        if (findByUsername(user) != NULL) {
            return false;
        }
        
        DoctorNode* newNode = new DoctorNode(id, name, age, spec, user, pass, NULL);
        
        if (head == NULL) {
            head = newNode;
        } else {
            DoctorNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return true;
    }
    
    bool removeDoctor(string username) {
        if (head == NULL) {
            return false;
        }
        
        if (head->getUsername() == username) {
            DoctorNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        
        DoctorNode* prev = head;
        DoctorNode* curr = head->next;
        
        while (curr != NULL) {
            if (curr->getUsername() == username) {
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        
        return false;
    }
    
    DoctorNode* findByUsername(string username) {
        DoctorNode* temp = head;
        while (temp != NULL) {
            if (temp->getUsername() == username) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    
    DoctorNode* login(string username, string password) {
        DoctorNode* temp = head;
        while (temp != NULL) {
            if (temp->getUsername() == username && temp->getPassword() == password) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    
    void display() {
        if (head == NULL) {
            cout << "No doctors registered.\n";
            return;
        }
        
        cout << "\n===== DOCTORS LIST =====\n";
        DoctorNode* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->getId() << " | Name: " << temp->getName() 
                 << " | Age: " << temp->getAge() << " | Specialization: " 
                 << temp->getSpecialization() << " | Username: " << temp->getUsername() << endl;
            temp = temp->next;
        }
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    // File handling
    void saveToFile() {
        ofstream file("doctors.txt");
        if (!file) {
            cout << "Error opening file!\n";
            return;
        }
        
        DoctorNode* temp = head;
        while (temp != NULL) {
            file << temp->getId() << "|"
                 << temp->getName() << "|"
                 << temp->getAge() << "|"
                 << temp->getSpecialization() << "|"
                 << temp->getUsername() << "|"
                 << temp->getPassword() << "\n";
            temp = temp->next;
        }
        file.close();
    }
    
    void loadFromFile() {
        ifstream file("doctors.txt");
        if (!file) return;
        
        int id, age;
        string name, spec, username, password;
        char delimiter;
        
        while (file >> id >> delimiter) {
            getline(file, name, '|');
            file >> age >> delimiter;
            getline(file, spec, '|');
            getline(file, username, '|');
            getline(file, password);
            
            DoctorNode* newNode = new DoctorNode(id, name, age, spec, username, password, NULL);
            
            if (head == NULL) {
                head = newNode;
            } else {
                DoctorNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    }
    
    ~DoctorList() {
        while (head != NULL) {
            DoctorNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ===== LINKED LIST FOR PATIENTS =====
class PatientList {
private:
    PatientNode* head;
    
public:
    PatientList() : head(NULL) {}
    
    bool addPatient(int id, string name, int age, string disease, string user, string pass) {
        if (findByUsername(user) != NULL) {
            return false;
        }
        
        PatientNode* newNode = new PatientNode(id, name, age, disease, user, pass, NULL);
        
        if (head == NULL) {
            head = newNode;
        } else {
            PatientNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return true;
    }
    
    PatientNode* findByUsername(string username) {
        PatientNode* temp = head;
        while (temp != NULL) {
            if (temp->getUsername() == username) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    
    PatientNode* login(string username, string password) {
        PatientNode* temp = head;
        while (temp != NULL) {
            if (temp->getUsername() == username && temp->getPassword() == password) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    
    void display() {
        if (head == NULL) {
            cout << "No patients registered.\n";
            return;
        }
        
        cout << "\n===== PATIENTS LIST =====\n";
        PatientNode* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->getId() << " | Name: " << temp->getName() 
                 << " | Age: " << temp->getAge() << " | Disease: " 
                 << temp->getDisease() << endl;
            temp = temp->next;
        }
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    // File handling
    void saveToFile() {
        ofstream file("patients.txt");
        if (!file) {
            cout << "Error opening file!\n";
            return;
        }
        
        PatientNode* temp = head;
        while (temp != NULL) {
            file << temp->getId() << "|"
                 << temp->getName() << "|"
                 << temp->getAge() << "|"
                 << temp->getDisease() << "|"
                 << temp->getUsername() << "|"
                 << temp->getPassword() << "\n";
            temp = temp->next;
        }
        file.close();
    }
    
    void loadFromFile() {
        ifstream file("patients.txt");
        if (!file) return;
        
        int id, age;
        string name, disease, username, password;
        char delimiter;
        
        while (file >> id >> delimiter) {
            getline(file, name, '|');
            file >> age >> delimiter;
            getline(file, disease, '|');
            getline(file, username, '|');
            getline(file, password);
            
            PatientNode* newNode = new PatientNode(id, name, age, disease, username, password, NULL);
            
            if (head == NULL) {
                head = newNode;
            } else {
                PatientNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        file.close();
    }
    
    ~PatientList() {
        while (head != NULL) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ===== QUEUE FOR APPOINTMENTS =====
class AppointmentQueue {
private:
    AppointmentNode* front;
    AppointmentNode* rear;
    
public:
    AppointmentQueue() : front(NULL), rear(NULL) {}
    
    void enqueue(int id, string patient, string doctor, int priority) {
        AppointmentNode* newNode = new AppointmentNode(id, patient, doctor, priority, NULL);
        
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    bool dequeue(int position) {
        if (front == NULL) {
            return false;
        }
        
        if (position == 1) {
            AppointmentNode* temp = front;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            delete temp;
            return true;
        }
        
        AppointmentNode* prev = front;
        AppointmentNode* curr = front->next;
        int count = 2;
        
        while (curr != NULL && count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        if (curr == NULL) {
            return false;
        }
        
        prev->next = curr->next;
        if (curr == rear) {
            rear = prev;
        }
        delete curr;
        return true;
    }
    
    void display() {
        if (front == NULL) {
            cout << "No appointments.\n";
            return;
        }
        
        AppointmentNode* temp = front;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". ID: " << temp->getAppointmentID()
                 << " | Patient: " << temp->getPatientName()
                 << " | Doctor: " << temp->getDoctorName()
                 << " | Priority: " << (temp->getPriority() == 2 ? "Emergency" : "Normal")
                 << endl;
            temp = temp->next;
            count++;
        }
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    int getCount() {
        int count = 0;
        AppointmentNode* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ~AppointmentQueue() {
        while (front != NULL) {
            AppointmentNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// ===== HOSPITAL MANAGEMENT SYSTEM =====
class HospitalSystem {
private:
    DoctorList doctors;
    PatientList patients;
    AppointmentQueue normalQueue;
    AppointmentQueue emergencyQueue;
    MedicineList medicines;
    PrescriptionList prescriptions;
    BillList bills;
    ActionStack actionLog;
    
public:
    HospitalSystem() {
        doctors.loadFromFile();
        patients.loadFromFile();
        medicines.loadFromFile();
        prescriptions.loadFromFile();
        bills.loadFromFile();
    }
    
    ~HospitalSystem() {
        doctors.saveToFile();
        patients.saveToFile();
        medicines.saveToFile();
        prescriptions.saveToFile();
        bills.saveToFile();
    }
    
    void adminAddDoctor() {
        system("cls");
        cout << "\n===== ADD DOCTOR (ADMIN) =====\n";
        
        int id, age;
        string name, spec, username, password;
        
        id = getValidatedPositiveInt("Enter Doctor ID: ");
        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin, name);
        age = getValidatedPositiveInt("Enter Age: ");
        cin.ignore();
        cout << "Enter Specialization: ";
        getline(cin, spec);
        cout << "Create Username: ";
        getline(cin, username);
        cout << "Create Password: ";
        getline(cin, password);
        
        if (doctors.addDoctor(id, name, age, spec, username, password)) {
            cout << "\n? Doctor added successfully by Admin!\n";
            actionLog.push("Admin added Doctor: " + name + " (ID: " + to_string(id) + ")");
            doctors.saveToFile();
        } else {
            cout << "\n? Username already exists!\n";
        }
        system("pause");
    }
    
    void adminRemoveDoctor() {
        system("cls");
        cout << "\n===== REMOVE DOCTOR (ADMIN) =====\n";
        
        if (doctors.isEmpty()) {
            cout << "No doctors to remove.\n";
            system("pause");
            return;
        }
        
        doctors.display();
        
        string username;
        cout << "\nEnter username of doctor to remove: ";
        cin.ignore();
        getline(cin, username);
        
        if (doctors.removeDoctor(username)) {
            cout << "\n? Doctor removed successfully!\n";
            actionLog.push("Admin removed Doctor with username: " + username);
            doctors.saveToFile();
        } else {
            cout << "\n? Doctor not found!\n";
        }
        system("pause");
    }
    
    void viewMedicines() {
        system("cls");
        medicines.display();
        system("pause");
    }
    
    void addOrRestockMedicine() {
        system("cls");
        cout << "\n===== ADD/RESTOCK MEDICINE =====\n";
        cout << "1. Add New Medicine\n";
        cout << "2. Restock Existing Medicine\n";
        int choice = getValidatedInt("Enter choice: ");
        
        if (choice == 1) {
            int id, quantity;
            string name;
            double price;
            
            id = getValidatedPositiveInt("\nEnter Medicine ID: ");
            cin.ignore();
            cout << "Enter Medicine Name: ";
            getline(cin, name);
            quantity = getValidatedPositiveInt("Enter Initial Quantity: ");
            price = getValidatedPositiveDouble("Enter Price per Unit: $");
            
            if (medicines.addMedicine(id, name, quantity, price)) {
                cout << "\n? Medicine added successfully!\n";
                actionLog.push("Medicine added: " + name + " (ID: " + to_string(id) + ")");
                medicines.saveToFile();
            }
        } else if (choice == 2) {
            medicines.display();
            
            int id, quantity;
            id = getValidatedPositiveInt("\nEnter Medicine ID to restock: ");
            quantity = getValidatedPositiveInt("Enter quantity to add: ");
            
            if (medicines.restockMedicine(id, quantity)) {
                cout << "\n? Medicine restocked successfully!\n";
                actionLog.push("Medicine ID " + to_string(id) + " restocked with " + to_string(quantity) + " units");
                medicines.saveToFile();
            } else {
                cout << "\n? Medicine not found!\n";
            }
        }
        system("pause");
    }
    
    void generateBill() {
        system("cls");
        cout << "\n===== GENERATE BILL =====\n";
        
        if (medicines.isEmpty()) {
            cout << "No medicines available in inventory.\n";
            system("pause");
            return;
        }
        
        int billID = rand() % 10000 + 1000;
        string patientName;
        
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, patientName);
        
        cout << "\n--- Available Medicines ---\n";
        medicines.display();
        
        double totalAmount = 0;
        stringstream itemDetails;
        itemDetails << "MEDICINES PURCHASED:\n";
        itemDetails << "-----------------------------------\n";
        
        int numMedicines = getValidatedPositiveInt("\nHow many different medicines to add? ");
        cin.ignore();
        
        for (int i = 0; i < numMedicines; i++) {
            cout << "\n--- Medicine " << (i + 1) << " ---\n";
            string medName;
            int quantity;
            
            cout << "Medicine Name: ";
            getline(cin, medName);
            quantity = getValidatedPositiveInt("Quantity: ");
            cin.ignore();
            
            MedicineNode* med = medicines.findByName(medName);
            if (med != NULL) {
                if (med->getQuantity() >= quantity) {
                    double subtotal = med->getPrice() * quantity;
                    totalAmount += subtotal;
                    
                    itemDetails << (i + 1) << ". " << medName 
                               << " x " << quantity 
                               << " @ $" << med->getPrice() 
                               << " = $" << subtotal << "\n";
                } else {
                    cout << "? Insufficient stock for " << medName << "! Available: " << med->getQuantity() << "\n";
                    i--;
                }
            } else {
                cout << "? Medicine not found!\n";
                i--;
            }
        }
        
        itemDetails << "-----------------------------------\n";
        
        bills.addBill(billID, patientName, itemDetails.str(), totalAmount);
        cout << "\n? Bill generated successfully!\n";
        cout << "Bill ID: " << billID << "\n";
        cout << "Total Amount: $" << totalAmount << "\n";
        cout << "\n? Note: Medicine quantities will be deducted after payment.\n";
        
        actionLog.push("Bill generated for " + patientName + " - Amount: $" + to_string(totalAmount));
        bills.saveToFile();
        system("pause");
    }
    
    void processPayment() {
        system("cls");
        cout << "\n===== PROCESS PAYMENT =====\n";
        
        if (bills.isEmpty()) {
            cout << "No bills available.\n";
            system("pause");
            return;
        }
        
        bills.displayUnpaid();
        
        int billID = getValidatedInt("\nEnter Bill ID to process (0 to cancel): ");
        
        if (billID == 0) return;
        
        BillNode* bill = bills.findById(billID);
        if (bill == NULL) {
            cout << "\n? Bill not found!\n";
            system("pause");
            return;
        }
        
        if (bill->getIsPaid()) {
            cout << "\n? This bill is already paid!\n";
            system("pause");
            return;
        }
        
        cout << "\n========================================\n";
        cout << "BILL DETAILS:\n";
        cout << "========================================\n";
        cout << "Patient: " << bill->getPatientName() << "\n";
        cout << bill->getItemsDetails();
        cout << "TOTAL AMOUNT DUE: $" << bill->getTotalAmount() << "\n";
        cout << "========================================\n";
        
        int confirm = getValidatedInt("\nConfirm payment? (1=Yes, 0=No): ");
        
        if (confirm == 1) {
            string items = bill->getItemsDetails();
            istringstream iss(items);
            string line;
            bool success = true;
            
            getline(iss, line);
            getline(iss, line);
            
            while (getline(iss, line)) {
                if (line.find("---") != string::npos || line.empty()) continue;
                
                size_t xPos = line.find(" x ");
                size_t atPos = line.find(" @ ");
                
                if (xPos != string::npos && atPos != string::npos) {
                    size_t nameStart = line.find(". ") + 2;
                    string medName = line.substr(nameStart, xPos - nameStart);
                    
                    size_t qtyStart = xPos + 3;
                    string qtyStr = line.substr(qtyStart, atPos - qtyStart);
                    int quantity = stoi(qtyStr);
                    
                    if (!medicines.dispenseMedicine(medName, quantity)) {
                        cout << "\n? Error deducting " << medName << " from inventory!\n";
                        success = false;
                    }
                }
            }
            
            if (success) {
                bill->setIsPaid(true);
                cout << "\n? Payment processed successfully!\n";
                cout << "? Medicine quantities have been deducted from inventory.\n";
                actionLog.push("Payment processed for Bill ID " + to_string(billID));
                bills.saveToFile();
                medicines.saveToFile();
            } else {
                cout << "\n? Payment failed due to inventory issues!\n";
            }
        } else {
            cout << "\nPayment cancelled.\n";
        }
        
        system("pause");
    }
    
    void viewActionStack() {
        system("cls");
        actionLog.display();
        system("pause");
    }
    
    void createPrescription(string doctorName) {
        system("cls");
        cout << "\n===== CREATE PRESCRIPTION =====\n";
        
        int prescID = rand() % 10000 + 1000;
        string patientName, medicineName;
        int quantity;
        
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, patientName);
        
        cout << "\n--- Available Medicines ---\n";
        medicines.display();
        
        cout << "\nEnter Medicine Name: ";
        getline(cin, medicineName);
        quantity = getValidatedPositiveInt("Enter Quantity: ");
        
        prescriptions.addPrescription(prescID, patientName, doctorName, medicineName, quantity);
        cout << "\n? Prescription created successfully!\n";
        cout << "Prescription ID: " << prescID << "\n";
        actionLog.push("Prescription created by Dr. " + doctorName);
        prescriptions.saveToFile();
        system("pause");
    }
    
    void viewAllPrescriptions() {
        system("cls");
        prescriptions.displayAll();
        system("pause");
    }
    
    bool registerPatient() {
        system("cls");
        string tempUsername;
        cout << "\n===== PATIENT SIGNUP =====\n";
        cout << "Create Username: ";
        cin.ignore();
        getline(cin, tempUsername);
        
        if (patients.findByUsername(tempUsername) != NULL) {
            cout << "\n? Username already exists!\n";
            system("pause");
            return false;
        }
        
        int id, age;
        string name, disease, pass;
        
        id = getValidatedPositiveInt("Enter Patient ID: ");
        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin, name);
        age = getValidatedPositiveInt("Enter Age: ");
        cin.ignore();
        cout << "Enter Disease/Condition: ";
        getline(cin, disease);
        cout << "Create Password: ";
        getline(cin, pass);
        
        if (patients.addPatient(id, name, age, disease, tempUsername, pass)) {
            cout << "\n? Patient registered successfully!\n";
            actionLog.push("Patient registered: " + name);
            patients.saveToFile();
            system("pause");
            return true;
        }
        system("pause");
        return false;
    }
    
    PatientNode* loginPatient(string username, string password) {
        return patients.login(username, password);
    }
    
    DoctorNode* loginDoctor(string username, string password) {
        return doctors.login(username, password);
    }
    
    void viewDoctors() {
        doctors.display();
    }
    
    void viewPatients() {
        patients.display();
    }
    
    void bookNormalAppointment(string patientName) {
        system("cls");
        if (doctors.isEmpty()) {
            cout << "\n? No doctors available.\n";
            system("pause");
            return;
        }
        
        int apptID = rand() % 10000 + 1000;
        string doctorName;
        
        cout << "\n--- Available Doctors ---\n";
        viewDoctors();
        cout << "\nEnter Doctor Name: ";
        cin.ignore();
        getline(cin, doctorName);
        
        normalQueue.enqueue(apptID, patientName, doctorName, 1);
        cout << "\n? Normal appointment booked!\n";
        cout << "Appointment ID: " << apptID << "\n";
        actionLog.push("Normal appointment booked - Patient: " + patientName);
        system("pause");
    }
    
    void bookEmergencyAppointment(string patientName) {
        system("cls");
        if (doctors.isEmpty()) {
            cout << "\n? No doctors available.\n";
            system("pause");
            return;
        }
        
        int apptID = rand() % 10000 + 1000;
        string doctorName;
        
        cout << "\n--- Available Doctors ---\n";
        viewDoctors();
        cout << "\nEnter Doctor Name: ";
        cin.ignore();
        getline(cin, doctorName);
        
        emergencyQueue.enqueue(apptID, patientName, doctorName, 2);
        cout << "\n? Emergency appointment booked!\n";
        cout << "Appointment ID: " << apptID << "\n";
        actionLog.push("Emergency appointment booked - Patient: " + patientName);
        system("pause");
    }
    
    void viewNormalAppointments() {
        system("cls");
        cout << "\n--- NORMAL APPOINTMENTS ---\n";
        normalQueue.display();
        system("pause");
    }
    
    void viewEmergencyAppointments() {
        system("cls");
        cout << "\n--- EMERGENCY APPOINTMENTS ---\n";
        emergencyQueue.display();
        system("pause");
    }
    
    void viewAllAppointments() {
        system("cls");
        cout << "\n--- EMERGENCY APPOINTMENTS ---\n";
        emergencyQueue.display();
        cout << "\n--- NORMAL APPOINTMENTS ---\n";
        normalQueue.display();
        system("pause");
    }
    
    bool treatEmergencyAppointment() {
        system("cls");
        if (emergencyQueue.isEmpty()) {
            cout << "\n? No emergency appointments.\n";
            system("pause");
            return false;
        }
        
        cout << "\n--- EMERGENCY APPOINTMENTS ---\n";
        emergencyQueue.display();
        
        int choice = getValidatedInt("\nEnter appointment number to treat (0 to cancel): ");
        
        if (choice == 0) return false;
        
        if (emergencyQueue.dequeue(choice)) {
            cout << "\n? Emergency appointment treated!\n";
            actionLog.push("Emergency appointment treated");
            system("pause");
            return true;
        }
        system("pause");
        return false;
    }
    
    bool treatNormalAppointment() {
        system("cls");
        if (normalQueue.isEmpty()) {
            cout << "\n? No normal appointments.\n";
            system("pause");
            return false;
        }
        
        cout << "\n--- NORMAL APPOINTMENTS ---\n";
        normalQueue.display();
        
        int choice = getValidatedInt("\nEnter appointment number to treat (0 to cancel): ");
        
        if (choice == 0) return false;
        
        if (normalQueue.dequeue(choice)) {
            cout << "\n? Normal appointment treated!\n";
            actionLog.push("Normal appointment treated");
            system("pause");
            return true;
        }
        system("pause");
        return false;
    }
};

// ===== MAIN FUNCTION =====
int main() {
    srand(time(0));
    
    HospitalSystem hospital;
    int mainChoice, subChoice;
    string username, password;
    
    do {
        system("cls");
        cout << "\n========================================\n";
        cout << "   HOSPITAL MANAGEMENT SYSTEM (H.M.S.)\n";
        cout << "========================================\n";
        cout << "1. Admin Login\n";
        cout << "2. Doctor Login\n";
        cout << "3. Patient Login\n";
        cout << "4. Patient Registration\n";
        cout << "5. Pharmacy Module\n";
        cout << "6. Exit System\n";
        cout << "========================================\n";
        mainChoice = getValidatedInt("Enter choice: ");
        
        switch (mainChoice) {
            case 1: {
                system("cls");
                cout << "\n===== ADMIN LOGIN =====\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                if (username == "admin" && password == "admin123") {
                    cout << "\n? Login successful!\n";
                    system("pause");
                    
                    do {
                        system("cls");
                        cout << "\n===== ADMIN DASHBOARD =====\n";
                        cout << "1. Add Doctor\n";
                        cout << "2. View Doctors\n";
                        cout << "3. Remove Doctor\n";
                        cout << "4. View Patients\n";
                        cout << "5. System Reports\n";
                        cout << "6. Medicine Management\n";
                        cout << "0. Logout\n";
                        subChoice = getValidatedInt("Enter choice: ");
                        
                        switch (subChoice) {
                            case 1:
                                hospital.adminAddDoctor();
                                break;
                            case 2:
                                system("cls");
                                hospital.viewDoctors();
                                system("pause");
                                break;
                            case 3:
                                hospital.adminRemoveDoctor();
                                break;
                            case 4:
                                system("cls");
                                hospital.viewPatients();
                                system("pause");
                                break;
                            case 5:
                                hospital.viewActionStack();
                                break;
                            case 6:
                                hospital.addOrRestockMedicine();
                                break;
                        }
                    } while (subChoice != 0);
                } else {
                    cout << "\n? Invalid credentials!\n";
                    system("pause");
                }
                break;
            }
            
            case 2: {
                system("cls");
                cout << "\n===== DOCTOR LOGIN =====\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                DoctorNode* doctor = hospital.loginDoctor(username, password);
                if (doctor != NULL) {
                    cout << "\n? Welcome, Dr. " << doctor->getName() << "!\n";
                    system("pause");
                    
                    do {
                        system("cls");
                        cout << "\n===== DOCTOR DASHBOARD =====\n";
                        cout << "Dr. " << doctor->getName() << "\n";
                        cout << "1. View Emergency Appointments\n";
                        cout << "2. View Normal Appointments\n";
                        cout << "3. View All Appointments\n";
                        cout << "4. Treat Emergency\n";
                        cout << "5. Treat Normal\n";
                        cout << "6. Create Prescription\n";
                        cout << "7. View Prescriptions\n";
                        cout << "0. Logout\n";
                        subChoice = getValidatedInt("Enter choice: ");
                        
                        switch (subChoice) {
                            case 1: hospital.viewEmergencyAppointments(); break;
                            case 2: hospital.viewNormalAppointments(); break;
                            case 3: hospital.viewAllAppointments(); break;
                            case 4: hospital.treatEmergencyAppointment(); break;
                            case 5: hospital.treatNormalAppointment(); break;
                            case 6: hospital.createPrescription(doctor->getName()); break;
                            case 7: hospital.viewAllPrescriptions(); break;
                        }
                    } while (subChoice != 0);
                } else {
                    cout << "\n? Invalid credentials!\n";
                    system("pause");
                }
                break;
            }
            
            case 3: {
                system("cls");
                cout << "\n===== PATIENT LOGIN =====\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                
                PatientNode* patient = hospital.loginPatient(username, password);
                if (patient != NULL) {
                    cout << "\n? Welcome, " << patient->getName() << "!\n";
                    system("pause");
                    
                    do {
                        system("cls");
                        cout << "\n===== PATIENT DASHBOARD =====\n";
                        cout << patient->getName() << "\n";
                        cout << "1. Book Normal Appointment\n";
                        cout << "2. Book Emergency Appointment\n";
                        cout << "0. Logout\n";
                        subChoice = getValidatedInt("Enter choice: ");
                        
                        switch (subChoice) {
                            case 1: hospital.bookNormalAppointment(patient->getName()); break;
                            case 2: hospital.bookEmergencyAppointment(patient->getName()); break;
                        }
                    } while (subChoice != 0);
                } else {
                    cout << "\n? Invalid credentials!\n";
                    system("pause");
                }
                break;
            }
            
            case 4:
                hospital.registerPatient();
                break;
            
            case 5: {
                do {
                    system("cls");
                    cout << "\n===== PHARMACY MODULE =====\n";
                    cout << "1. View Medicines\n";
                    cout << "2. Add/Restock Medicine\n";
                    cout << "3. Generate Bill\n";
                    cout << "4. Process Payment\n";
                    cout << "0. Return to Main Menu\n";
                    cout << "===========================\n";
                    subChoice = getValidatedInt("Enter choice: ");
                    
                    switch (subChoice) {
                        case 1: 
                            hospital.viewMedicines(); 
                            break;
                        case 2: 
                            hospital.addOrRestockMedicine(); 
                            break;
                        case 3: 
                            hospital.generateBill(); 
                            break;
                        case 4: 
                            hospital.processPayment(); 
                            break;
                        case 0:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice!\n";
                            system("pause");
                    }
                } while (subChoice != 0);
                break;
            }
            
            case 6:
                cout << "\n? Thank you for using H.M.S.!\n";
                system("pause");
                break;
        }
    } while (mainChoice != 6);
    
    return 0;
}


