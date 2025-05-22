#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <forward_list>
#include <array>
#include <unordered_set>
#include <map>
#include <numeric>
#include <random>
#include <iomanip>

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
    cout << "Задача 2." << endl;

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
    cout << "Задача 3." << endl;

    struct Student
    {
        string name;
        time_t arrival_time;
    };

    deque<Student> students = { {"Миша", 30600}, {"Настя", 35940}, {"Глеб", 42420}, {"Коля", 48660}, 
    {"Ксюша", 34800}, {"Андрей", 36000}, {"Артур", 29820}, {"Илья", 36840}, {"Арсений", 45840}, {"Ричард", 46980} };
    
    deque<Student> result;
    const time_t deadline = 36000;
    
    copy_if(students.begin(), students.end(), back_inserter(result), 
        [deadline](const Student& student) {
            return student.arrival_time < deadline;
    });

    int barmaid_guess = rand() % 5 + 1;
    for (auto n : result)
    {
        int student_guess = rand() % 5 + 1;
        if (student_guess == barmaid_guess)
        {
            n.name += " (выиграл бесплатную булочку!)";
        }

        cout << n.name << ", время прибытия: " << n.arrival_time / 3600 << ":"
             << setfill('0') << setw(2) <<(n.arrival_time % 3600) / 60 << endl;
    }
    cout << endl;
}

void Task4() {
    cout << "Задача 4." << endl;

    struct Student {
        string name;
        vector <float> semester_grades;

        bool operator<(const Student& other) const {
            return name < other.name;
        }
    };

    set<Student> students = {
        {"Александр Невский", {4.5, 4.6, 4.7, 4.8, 4.5, 4.9, 4.6, 4.7}},
        {"Алина Коваленко", {4.8, 4.7, 4.9, 4.6, 4.5, 4.8, 4.7, 4.9}},
        {"Андрей Чернов", {4.0, 4.2, 4.1, 4.3, 4.4, 4.0, 4.2, 4.1}},
        {"Анна Полякова", {4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5}},
        {"Артём Лебедев", {4.6, 4.7, 4.8, 4.9, 4.7, 4.6, 4.8, 4.9}},
        {"Валерия Соколова", {4.3, 4.4, 4.2, 4.5, 4.3, 4.4, 4.6, 4.2}}, 
        {"Виктор Петров", {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0}},
        {"Глеб Морозов", {4.9, 4.8, 4.95, 4.85, 4.9, 4.95, 4.85, 4.9}},
        {"Даниил Орлов", {4.1, 4.0, 4.3, 4.2, 4.4, 4.1, 4.0, 4.3}}, 
        {"Дарья Кузнецова", {4.5, 4.6, 4.7, 4.8, 4.6, 4.5, 4.7, 4.8}},
        {"Дмитрий Воробьев", {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0}},
        {"Евгения Волкова", {4.4, 4.5, 4.3, 4.6, 4.4, 4.5, 4.3, 4.6}},
        {"Егор Семенов", {4.2, 4.0, 4.1, 4.3, 4.2, 4.0, 4.1, 4.3}}, 
        {"Иван Кириллов", {4.7, 4.8, 4.75, 4.9, 4.7, 4.8, 4.75, 4.9}},
        {"Кирилл Зайцев", {4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5}},
        {"Ксения Белова", {4.6, 4.4, 4.55, 4.5, 4.6, 4.4, 4.55, 4.5}},
        {"Лев Титов", {4.0, 4.1, 3.9, 4.2, 4.0, 4.1, 3.9, 4.2}},
        {"Мария Игнатова", {4.8, 4.85, 4.9, 4.7, 4.8, 4.85, 4.9, 4.7}},
        {"Максим Гришин", {4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5}},
        {"Наталья Васнецова", {4.3, 4.35, 4.4, 4.5, 4.3, 4.35, 4.4, 4.5}},
        {"Олег Степанов", {4.7, 4.6, 4.8, 4.9, 4.7, 4.6, 4.8, 4.9}},
        {"Полина Медведева", {4.9, 4.95, 5.0, 4.8, 4.9, 4.95, 5.0, 4.8}},
        {"Роман Козлов", {4.2, 4.3, 4.25, 4.4, 4.2, 4.3, 4.25, 4.4}}, 
        {"Светлана Фомина", {4.5, 4.6, 4.55, 4.7, 4.5, 4.6, 4.55, 4.7}},
        {"Сергей Баранов", {4.1, 4.0, 3.8, 4.2, 4.1, 4.0, 3.8, 4.2}}, 
        {"София Жукова", {4.7, 4.75, 4.8, 4.85, 4.7, 4.75, 4.8, 4.85}},
        {"Станислав Павлов", {4.4, 4.5, 4.3, 4.6, 4.4, 4.5, 4.3, 4.6}},
        {"Татьяна Комарова", {4.6, 4.65, 4.7, 4.75, 4.6, 4.65, 4.7, 4.75}},
        {"Фёдор Никитин", {4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5}},
        {"Юлия Савельева", {4.8, 4.85, 4.9, 4.95, 4.8, 4.85, 4.9, 4.95}}
    };

    auto it = find_if(students.begin(), students.end(), 
        [](const Student& s) {
            return all_of(s.semester_grades.begin(), s.semester_grades.end(), [](float grade){
                return grade >= 4.5;
            });
    });
    
    if (it != students.end())
    {
        cout << "Идеальный студент найден: " << it->name << endl;
        cout << "Оценки: ";
        for (float grade : it->semester_grades)
        {
            cout << grade << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Идеальный студент не найден. Миф развеян!" << endl;
    }

    cout << endl;
}

void Task5() {
    cout << "Задача 5." << endl;

    struct Book {
        string title;
        string author;
        int year;
    };

    forward_list<Book> books = { 
        {"Clean Code: A Handbook of Agile Software Craftsmanship", "Роберт Мартин", 2008},
        {"The Pragmatic Programmer: Your Journey To Mastery, 20th Anniversary Edition", "Эндрю Хант и Дэвид Томас", 2019},
        {"You Don’t Know JS (book series)", "Кайл Симпсон", 2014},
        {"Python Crash Course", "Эрик Маттес", 2015},
        {"Eloquent JavaScript", "Марийн Хавербеке", 2018},
        {"JavaScript: The Good Parts", "Дуглас Крокфорд", 2008},
        {"Refactoring: Improving the Design of Existing Code", "Мартин Фаулер", 2018},
        {"The Phoenix Project: A Novel About IT, DevOps, and Helping Your Business Win", "Джин Ким, Кевин Бехр, Джордж Спафорд", 2013},
        {"The DevOps Handbook: How to Create World-Class Agility, Reliability, & Security in Technology Organizations", "Джин Ким, Патрик Дебois, Джон Уиллис, Джей Дейвис", 2016},
        {"Artificial Intelligence: A Modern Approach", "Стюарт Рассел и Питер Норвиг", 2010},
        {"The C Programming Language", "Брайан Керниган и Деннис Ритчи", 1988},
        {"Code Complete", "Стив Макконнелл", 1993},
        {"Design Patterns: Elements of Reusable Object-Oriented Software", "Эрих Гамма и др.", 1994},
        {"The Mythical Man-Month: Essays on Software Engineering", "Фредерик Брукс", 1975},
        {"Refactoring: Improving the Design of Existing Code", "Мартин Фаулер", 1999}
    };

    auto it = remove_if(books.begin(), books.end(), 
        [](const Book& book) {
            return book.year < 2000;
        }
    );
    books.erase_after(it, books.end());

    cout << "Актуальные книги по программированию: " << endl;
    for (auto book : books)
    {
        if (book.title == "The C Programming Language")
        {
            cout << book.title << ", " << book.author << ", " << book.year << " - Эта книга - классика жанра!" << endl;
            continue;
        }
        cout << book.title << ", " << book.author << ", " << book.year << " - Эта книга актуальна!" << endl;
    }
    cout << endl;
}

void Task6() {
    cout << "Задача 6." << endl;

    array<int, 30> examination_cards;
    unordered_set<int> used_card_numbers;

    generate(examination_cards.begin(), examination_cards.end(), 
        [&used_card_numbers](){
            int number;
            do
            {
                number = rand() % 100 + 1;
            } while (used_card_numbers.count(number) > 0);
            used_card_numbers.insert(number);
            return number;
    });

    cout << "Номера билетов: " << endl;
    for(auto card : examination_cards)
    {
        if (card == 42)
        {
            cout << "Билет с номером 42 - счастивый. Как зовут преподавателя?" << endl;
            continue;
        }
        cout << card << endl;
    }
    cout << endl;
}

void Task7() {
    cout << "Задача 7." << endl;

    struct Attendance {
        string date;
        int absent_count;
    };
    
    map<string, Attendance> students_attendance = { 
        {"Матанализ", {"01.09.2023", 3}},
        {"Матанализ", {"01.09.2024", 1}},
        {"Иностранный язык", {"01.09.2023", 5}},
        {"Основы проектной деятельности", {"10.02.2024", 1}},
        {"Программирование", {"10.02.2024", 0}},
        {"Информатика", {"01.09.2023", 10}},
        {"Линейная алгебра", {"01.09.2023", 2}},
        {"Физика", {"10.02.2024", 1}},
        {"Теория вероятности и математическая статистика", {"10.02.2024", 12}},
        {"Основы личностной и коммуникативной культуры", {"01.09.2023", 0}},
        {"Основы российской государственности", {"01.09.2023", 15}}
    };

    int total_skips = accumulate(students_attendance.begin(), students_attendance.end(), 0, 
        [](int total, const pair<string, Attendance>& attendance) {
            if (attendance.second.date == "01.09.2023")
            {
                return total + attendance.second.absent_count;
            }
            return total;
        });

    cout << "Всего пропусков у студента в первом семестре: " << total_skips << endl;

}

void Task8() {
    cout << "Задача 8." << endl;
}

void Task9() {
    cout << "Задача 9." << endl;
}

void Task10() {
    cout << "Задача 10." << endl;
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
                continue;
            case 2:
                Task2();
                continue;
            case 3:
                Task3();
                continue;
            case 4:
                Task4();
                continue;
            case 5:
                Task5();
                continue;
            case 6:
                Task6();
                continue;
            case 7:
                Task7();
                continue;
            case 8:
                Task8();
                continue;
            case 9:
                Task9();
                continue;
            case 10:
                Task10();
                continue;

            /*default:
                cout << "Неверный номер задачи, пропробуйте еще раз." << endl << "Номер задачи: ";*/
        }
    }

    return 0;
}