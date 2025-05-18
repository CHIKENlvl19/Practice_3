#include <iostream>

using namespace std;

int main() {

    cout << "Введите номер задачи (от 1 до 10): ";
    

    while (true)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                return 0;

        
            default:
                cout << "Неверный номер задачи, пропробуйте еще раз." << endl << "Номер задачи: ";
        }

    }

    
    return 0;
}