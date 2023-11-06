#include<iostream>

using namespace std;

int main() {
    float num1, num2, res;
    char choice;

  
Back:    
cout << "A. Find the root\n";
cout << "B. Addition\n";
cout << "C. Subtraction\n";
cout << "D. Division\n";
cout << "E. Multiplication\n";
cout << "F. Find the log\n";
cout << "G. Exit\n";
cout << "Choice: ";
cin >> choice;

    
        if (choice == 'A' || choice == 'a') {
         
            cout << "Enter number:  ";
            cin >>  num1;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = sqrt(num1);
            cout << "Result: " << res << endl;
            cout << endl;
           
            cout << endl;
            goto Back;
           
        }
        else if (choice == 'B' || choice == 'b') {
         Back2:
            cin >>  num1;
            cin >>  num2;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = num1 + num2;
            cout << "The sum of " << num1 << " and " << num2 << " is " << res << endl;
            cout << endl;
            cout << endl;
            goto Back2;
          
        }
        else if (choice == 'C' || choice == 'c') {
        Back3:
            cin >>  num1;
            cin >>  num2;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = num1 - num2;
            cout << "The difference of " << num1 << " and " << num2 << " is " << res << endl;
            cout << endl;
            cout << endl;
            goto Back3;
        }
        else if (choice == 'D' || choice == 'd') {
         Back4:
          cin >> num1;
            cin >> num2;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = num1 / num2;
            cout << "Result: " << res << endl;
            cout << endl;
            cout << endl;
            goto Back4;
        }
        else if (choice == 'E' || choice == 'e') {
        Back5:
            cin >>  num1;
            cin >>  num2;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = num1 * num2;
            cout << "Result: " << res << endl;
            cout << endl;
            cout << endl;

            goto Back5;
        }
        else if (choice == 'F' || choice == 'f') {
        Back6:
            cin >>  num1;
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR" << endl;
            }
            res = log2(num1);
            cout << "Result: " << res << endl;
            cout << endl;
            cout << endl;
            goto Back6;
        }
        cout << "End" << endl;
        cout << endl;
}

    


