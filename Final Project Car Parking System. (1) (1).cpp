//Reg number : FA23-BCS-152
//Section : BCS-2C
//Final project : Programming Fundamentals.
//Date of submission : 29/05/2024

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

// Function Prototypes
void deletecar();
void login();
void signup();
int homemenu();
void allmenu();
int exit_program();

struct Parking {
    string ownern; // ownern is used to get names of owners.
    string cname;  // cname represents car's name.
    string cnum;   // cnum represents car's number.
};

// Main MENU Function
void allmenu() {
    int choice;
    int totalcars = 0;
    string line;
    fstream file;
    cout << "\t\tBuilding Car Parking System\n";
    cout << "\t\t---------------------------\n";
label:
    cout << "\nSelect your option. \n";
    cout << "1. New Car Registration\n";
    cout << "2. Count Total Cars Entering the Building\n";
    cout << "3. Delete all cars.\n";
    cout << "4. Close the System\n";
    cout << "5  Goto Home Menu \n";
    cout << "\nChoose option: ";
    cin >> choice;
    system("cls");

    switch (choice) {
    case 1:
        // Registration of new cars.
        {
            cout << "\t\tWelcome to Car Registration\n";
            cout << "\t\t---------------------------\n";
            Parking s;
            cout << "Please enter your car details.\n\n";
            cout << "Car #" <<totalcars+1<< endl;
            cout << "---------\n";
            cout << "Enter owner name: ";
            cin.ignore();
            getline(cin, s.ownern);
            cout << "Enter car name: ";
            getline(cin, s.cname);
            cout << "Enter car number: ";
            getline(cin, s.cnum);
            totalcars++;

            file.open("parking.txt", ios::out | ios::app);
            for (int i = 0; i < totalcars; i++) {
                file << "car" << "," << s.ownern << "," << s.cname << "," << s.cnum << endl;
            }

            file.close();
            system("cls");
            goto label;
            break;
        }
   case 2:
        {
            string line;
            int totalcars = 0;
            file.open("parking.txt", ios::in);
            if (!file) 
			{
                cout<<"Unable to open file.\n";
                goto label;
            }
            cout << "\t\tRegistered Cars\n";
            cout << "\t\t---------------\n";
            while (getline(file, line)) {
                totalcars++;
                cout<<line<<endl;
            }
            cout<<"Total cars entered the building: "<<totalcars<<endl;
            file.close();
            goto label;
            break;
        }
        case 3:
        deletecar();
        break;
        
    case 4:
        exit_program();
        break;
      //  case 4:
    	//goto menu;
    case 5:
    	homemenu();
		
    default:
        {
            cout << "Wrong number entered. Please try again!\n";
            goto label;
            break;
        }
    }
}

int exit_program() {
    cout << "Exiting program...\n";
    exit(0); // Ensure the program exits
}

string username, password;

void signup() {
    cin.ignore();
    // Variables are declared above function scope
    cout << "\t=====================\n";
    cout << "\t     SIGNUP PAGE     \n";
    cout << "\t=====================\n";
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    cout << "\nAccount created successfully!\n";
    system("cls");
    ofstream outfile;
    outfile.open("signup_data.txt",ios::app);
    
    outfile << username << " "<< password <<endl;
    
    outfile.close();
}
void deletecar(){
	
	
	ofstream outfile("parking.txt",ios::trunc);
	cout<<endl;
	system("cls");
	cout<<"All record deleted successfly.\n ";
	
	
	
	
}
void login() {
    string username1, password1;
    string storedname,storedpass;
    bool loginsuccessful= false;
    
    cin.ignore();
    jump:
    cout << "\t=====================\n";
    cout << "\t      LOGIN PAGE     \n";
    cout << "\t=====================\n";
    cout << "Enter Username: ";
    getline(cin, username1);
    cout << "Enter Password: ";
    getline(cin, password1);



	ifstream infile;
	infile.open("signup_data.txt");
	while(infile >> storedname >> storedpass){
		
		if(storedname== username1 && storedpass == password1){
			loginsuccessful= true;
			break;
		}
	}
		
		infile.close();
		if(loginsuccessful){
			cout<<"Please wait ";
         for(int i=0; i<5;i++)
        {cout<<".";
         cout.flush();
         sleep(1);
        }
			cout<<"\n2Login Successfully"<<endl;
			system("cls");
			allmenu();
			
		}
      	
      	  
     else {
        cout << "Invalid credentials. Try Again   !\n";
        goto jump;
//    system("cls");
    }
		

//    if ((username1 == username) && (password1 == password)) {
}

int homemenu() {
    int choice;
labelx:
    cout << "\t\tHOME PAGE\n";
    cout << "=========================\n";
    cout << "Press 1 to Signup\n";
    cout << "Press 2 to Login\n";
    cout << "Press 3 to Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        signup();
        goto labelx;
    case 2:
        login();
        goto labelx;
    case 3:
        cout << "Exiting program...\n";
        return 0;
    default:
        cout << "Invalid choice. Please try again.\n";
        goto labelx;
    }
}

int main() {
    homemenu();
}


