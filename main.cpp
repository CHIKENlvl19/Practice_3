#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <random>

using namespace std;

void Task1() {
    cout << "Задача 1." << endl;
    
    struct Student {
        string name;
        float average_score;
        int debts;
    };
                
    vector<Student> students = { {"Иванов Пётр", 4.2, 0}, {"Петрова Мария", 4.5, 0}, {"Сергеев Михаил", 3.5, 3}, {"Черных Игорь", 3.1, 2}, {"Иванова Елена", 4.0, 1}, 
    {"Черных Владислав", 2.5, 5}, {"Смирнов Иннокентий", 3.6, 1}, {"Козловская Алина", 5.0, 0}, {"Шишкин Сергей", 4.47, 0} , {"Кузнецов Сергей", 3.0, 2} };


    sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b){

            if (a.debts == b.debts)
            {
                return a.average_score < b.average_score;
            }

        return a.debts > b.debts;
    });

    cout << "Список студентов, отсортированный по количеству долгов:" << endl;
        
    for (auto n : students )
    {
        cout << n.name << ", " << n.debts << " долгов, средний балл: " << n.average_score << endl;
    }
    cout << endl;
}

void Task2() {
    cout << "Задача 2" << endl;

    struct Exam {
        string subject;
        int grade;
    };

    list<Exam> exams = { {"Математический анализ", 2}, {"Информатика", 3}, {"Иностранный язык", 5}, {"История России", 5}, {"Линейная алгебра", 2}, 
    {"Основы личностной и коммуникативной культуры", 4}, {"Основы проектной деятельности", 2}, {"Основыы российской государственности", 5}, 
    {"Учебная практика: ознакомительаня практкика", 5} };

    list<Exam> result(exams.size());
    string mercy = " (преподаватель сжалился)";

    transform(exams.begin(), exams.end(), result.begin(), 
        [mercy](const Exam& exam) {
            if (exam.grade == 2)
            {
                return Exam{exam.subject + mercy, 3};
            }
            else
            {
                return exam;
            }
    });

    cout << "Итоговый список оценок: " << endl;
    for (auto n : result)
    {
        cout << n.subject << ", оценка: " << n.grade << endl;
    }
    cout << endl;
}

void Task3() {
    cout << "Задача 3";

    struct Student
    {
        string name;
        time_t arrival_time;
    };

    deque<Student> students = { {"Миша", 30600}, {"Настя", 35940}, {"Глеб", 42420}, {"Коля", 48660}, 
    {"Ксюша", 73860}, {"Андрей", 36000}, {"Артур", 29820}, {"Илья", 36840}, {"Арсений", 45840}, {"Ричард", 46980} };
    
    deque<Student> result(students.size());
    const time_t deadline = 360000;
    
    copy_if(students.begin(), students.end(), result.begin(), 
        [](const Student& student) {

    });

}

void Task4() {

}

void Task5() {

}

void Task6() {

}

void Task7() {

}

void Task8() {

}

void Task9() {

}

void Task10() {

}

int main() {
    srand(time(NULL));

    while (true)
    {
        cout << "Введите номер задачи (от 1 до 10): ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                Task1();
            case 2:
                Task2();
            case 3:
                Task3();
            case 4:
                Task4();
            case 5:
                Task5();
            case 6:
                Task6();
            case 7:
                Task7();
            case 8:
                Task8();
            case 9:
                Task9();
            case 10:
                Task10();

            /*default:
                cout << "Неверный номер задачи, пропробуйте еще раз." << endl << "Номер задачи: ";*/
        }
    }

    return 0;
}