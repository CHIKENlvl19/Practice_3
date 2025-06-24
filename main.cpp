#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <string>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <functional>
#include <array>
#include <random>

using namespace std;

struct Ingredient {
    string name;
    int quantity;
    bool is_magical;
};

void Task1() {
    cout << "\nЗадача 1. Гарри Поттер и зелье.\n";

    vector<Ingredient> ingredients = {
        {"mandrake", 3, true}, {"unicorn_hair", 1, true}, {"dragon_scale", 2, false}
    };
    
    stable_sort(ingredients.begin(), ingredients.end(), 
        [](const Ingredient& a, const Ingredient& b) {
            if (a.is_magical != b.is_magical) return a.is_magical;
            return a.quantity > b.quantity;
        });
    
    transform(ingredients.begin(), ingredients.end(), ingredients.begin(),
        [](Ingredient ing) {
            transform(ing.name.begin(), ing.name.end(), ing.name.begin(), ::toupper);
            return ing;
        });
    
    int total_magical = accumulate(ingredients.begin(), ingredients.end(), 0,
        [](int sum, const Ingredient& ing) {
            return sum + (ing.is_magical ? ing.quantity : 0);
        });
    
    cout << "Магические ингредиенты: " << total_magical << endl;
    for (const auto& ing : ingredients)
        cout << ing.name << " (" << ing.quantity << ", " 
             << (ing.is_magical ? "магический" : "обычный") << ")\n";

    cout << endl;
}

struct Friend {
    string name;
    int friendship_level;
};

void Task2() {
    cout << "\nЗадача 2. Шрек и общие друзья.\n";

    list<Friend> shrek_friends = {
        {"Donkey", 8}, {"Fiona", 9}, {"Dragon", 7}
    };
    list<Friend> donkey_friends = {
        {"Dragon", 6}, {"Shrek", 10}, {"Fiona", 8}
    };
    
    shrek_friends.reverse();
    
    set<string> shrek_set, donkey_set;
    transform(shrek_friends.begin(), shrek_friends.end(), inserter(shrek_set, shrek_set.begin()),
        [](const Friend& f) { return f.name; });
    transform(donkey_friends.begin(), donkey_friends.end(), inserter(donkey_set, donkey_set.begin()),
        [](const Friend& f) { return f.name; });
    
    vector<string> common;
    set_intersection(shrek_set.begin(), shrek_set.end(), 
                    donkey_set.begin(), donkey_set.end(),
                    back_inserter(common));
    
    int total_level = 0;
    for_each(shrek_friends.begin(), shrek_friends.end(),
        [&](const Friend& f) {
            if (count(common.begin(), common.end(), f.name))
                total_level += f.friendship_level;
        });
    
    cout << "Общие друзья: ";
    for (const auto& name : common) cout << name << " ";
    cout << "\nСуммарный уровень дружбы: " << total_level << endl;

    cout << endl;
}

struct ReactorData {
    string type;
    double efficiency;
};

void Task3() {
    cout << "\nЗадача 3. Железный человек и реакторы.\n";

    map<string, vector<double>> reactors = {
        {"Arc", {100.0, 150.0}},
        {"Fusion", {200.0, 250.0}}
    };
    
    map<string, double> avg_efficiency;
    for (auto& [type, values] : reactors) {
        double sum = accumulate(values.begin(), values.end(), 0.0);
        avg_efficiency[type] = sum / values.size();
    }
    
    vector<pair<string, double>> eff_pairs(avg_efficiency.begin(), avg_efficiency.end());
    
    sort(eff_pairs.begin(), eff_pairs.end(),
        [](const auto& a, const auto& b) {
            return b.second < a.second;
        });
    
    auto max_it = max_element(eff_pairs.begin(), eff_pairs.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    
    cout << "Реакторы по эффективности:\n";
    for (const auto& [type, eff] : eff_pairs)
        cout << type << ": " << eff << endl;
    cout << "Наиболее эффективный: " << max_it->first << " (" << max_it->second << ")\n";

    cout << endl;
}

struct RoyalEvent {
    string princess;
    int attendance;
};

void Task4() {
    cout << "\nЗадача 4. Диснеевские принцессы и гласные в именах.\n";

    deque<RoyalEvent> events = {
        {"Cinderella", 1000}, {"Aurora", 800}, {"Ariel", 1200}, {"Belle", 900}
    };
    
    rotate(events.begin(), events.begin() + 2, events.end());
    
    unordered_map<char, bool> vowels = {{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
    vector<RoyalEvent> vowel_events;
    copy_if(events.begin(), events.end(), back_inserter(vowel_events),
        [&vowels](const RoyalEvent& e) {
            return vowels[toupper(e.princess[0])];
        });
    
    int total = accumulate(vowel_events.begin(), vowel_events.end(), 0,
        [](int sum, const RoyalEvent& e) { return sum + e.attendance; });
    
    cout << "События с принцессами на гласную:\n";
    for (const auto& e : vowel_events)
        cout << e.princess << " (" << e.attendance << ")\n";
    cout << "Общее посещение: " << total << endl;

    cout << endl;   
}

struct HoneyJar {
    int weight;
    string origin;
};

void Task5() {
    cout << "\nЗадача 5. Винни Пух и горшочки с мёдом.\n";

    priority_queue<HoneyJar, vector<HoneyJar>, 
        function<bool(const HoneyJar&, const HoneyJar&)>> 
        jars([](const HoneyJar& a, const HoneyJar& b) {
            return a.weight < b.weight;
        });
    
    vector<HoneyJar> temp = {
        {150, "Pine"}, {80, "Oak"}, {200, "Linden"}, {50, "Maple"}
    };
    for (auto& jar : temp) jars.push(jar);
    
    vector<HoneyJar> remaining;
    while (!jars.empty()) {
        if (jars.top().weight >= 100)
            remaining.push_back(jars.top());
        jars.pop();
    }
    
    map<string, vector<HoneyJar>> grouped;
    for (auto& jar : remaining)
        grouped[jar.origin].push_back(jar);
    
    cout << "Оставшиеся горшки:\n";
    for (auto& [origin, jars] : grouped) {
        cout << origin << ":\n";
        for (auto& jar : jars)
            cout << "  " << jar.weight << "g\n";
    }

    cout << endl;
}

struct Meal {
    string food;
    int calories;
};

void Task6() {
    cout << "\nЗадача 6. Маша и медведь: диета.\n";

    array<Meal, 7> meals = {{
        {"Пирожное", 300}, {"Торт", 400}, {"cake", 400}, {"jam", 200}, 
        {"jam", 200}, {"tea", 5}, {"tea", 5}
    }};
    
    vector<Meal> result;
    for (size_t i = 0; i < meals.size(); ++i) {
        if (i < meals.size()-1 && meals[i].food == meals[i+1].food) {
            result.push_back({"nothing", 0});
            ++i; // Пропускаем следующий элемент
        } else {
            result.push_back(meals[i]);
        }
    }
    
    sort(result.begin(), result.end(), 
        [](const Meal& a, const Meal& b) {
            return a.calories > b.calories;
        });
    
    int total = accumulate(result.begin(), result.end(), 0,
        [](int sum, const Meal& m) { return sum + m.calories; });
    
    cout << "Обновленное меню:\n";
    for (const auto& m : result)
        cout << m.food << " (" << m.calories << " ккал)\n";
    cout << "Итого калорий: " << total << endl;

    cout << endl;
}

struct Artifact {
    string name;
    int weight;
    bool is_dangerous;
};

void Task7() {
    cout << "\nЗадача 7. Хоббит и артефакты.\n";

    vector<Artifact> artifacts = {
        {"Ring", 5, false}, {"Sword", 15, true}, {"Crown", 8, false}, 
        {"Amulet", 20, true}, {"Book", 3, false}
    };

    random_device rd;
    mt19937 gen(rd());
    shuffle(artifacts.begin(), artifacts.end(), gen);

    auto it = partition(artifacts.begin(), artifacts.end(), 
        [](const Artifact& a) { return a.weight > 10; });

    vector<Artifact> dangerous(artifacts.begin(), it);
    vector<Artifact> safe(it, artifacts.end());

    map<bool, vector<string>> report;
    for (const auto& a : dangerous) report[true].push_back(a.name);
    for (const auto& a : safe) report[false].push_back(a.name);

    int total = artifacts.size();
    int dangerous_count = dangerous.size();
    double danger_percent = (double)dangerous_count / total * 100;

    cout << "Опасные артефакты (" << danger_percent << "%):\n";
    for (const auto& name : report[true]) cout << "- " << name << endl;
    cout << "Безопасные артефакты:\n";
    for (const auto& name : report[false]) cout << "- " << name << endl;

    cout << endl;
}

struct HairMeasurement {
    int length;
    string date;
};

void Task8() {
    cout << "\nЗадача 8. Рапунцель и длина волос.\n";

    list<HairMeasurement> measurements = {
        {50, "2023-01-01"}, {120, "2023-02-01"}, {80, "2023-03-01"},
        {200, "2023-04-01"}, {150, "2023-05-01"}
    };
    
    measurements.reverse();
    
    vector<pair<int, string>> color_map;
    transform(measurements.begin(), measurements.end(), back_inserter(color_map),
        [](const HairMeasurement& m) {
            return make_pair(m.length, m.length < 100 ? "black" : "golden");
        });
    
    auto max_it = max_element(color_map.begin(), color_map.end(),
        [](const pair<int,string>& a, const pair<int,string>& b) {
            return a.first < b.first;
        });
    
    double avg = accumulate(color_map.begin(), color_map.end(), 0.0,
        [](double sum, const pair<int,string>& p) { return sum + p.first; }) 
        / color_map.size();
    
    cout << "Цвет волос по длине:\n";
    for (const auto& [len, color] : color_map)
        cout << len << "cm -> " << color << endl;
    cout << "Самая длинная прядь: " << max_it->first << "cm\n";
    cout << "Средняя длина: " << avg << "cm\n";

    cout << endl;
}

struct Jedi {
    string name;
    int power;
    int experience;
};

void Task9() {
    cout << "\nЗадача 9. Миссия Джедаев.\n";

    multiset<Jedi, function<bool(const Jedi&, const Jedi&)>> jedi_set(
        [](const Jedi& a, const Jedi& b) {
            if (a.power != b.power) return a.power > b.power;
            return a.experience > b.experience;
        }
    );
    
    vector<Jedi> candidates = {
        {"Yoda", 2000, 900}, {"Luke", 1200, 50}, {"Obi-Wan", 1500, 300},
        {"Anakin", 1400, 20}, {"Mace Windu", 1300, 800}
    };
    for (auto& j : candidates) jedi_set.insert(j);
    
    vector<Jedi> strong;
    copy_if(jedi_set.begin(), jedi_set.end(), back_inserter(strong),
        [](const Jedi& j) { return j.power > 1000; });
    
    partial_sort(strong.begin(), strong.begin() + min(5, (int)strong.size()), strong.end(),
        [](const Jedi& a, const Jedi& b) { return a.name < b.name; });
    
    cout << "Сильные джедаи:\n";
    for (const auto& j : strong)
        cout << j.name << " (сила: " << j.power << ", опыт: " << j.experience << ")\n";

    cout << endl;
}

struct Child {
    string name;
    bool arrived;
};

void Task10() {
    cout << "\nЗадача 10. Питер Пен и дети.\n";

    deque<Child> children = {
        {"Wendy", false}, {"John", true}, {"Michael", true}, {"Tinker Bell", true}
    };

    for_each(children.begin(), children.end(), 
        [](Child& c) {
            if (c.name == "Peter Pan") c.arrived = true;
        });

    rotate(children.begin(), children.begin() + 1, children.end());

    vector<Child> not_arrived;
    copy_if(children.begin(), children.end(), back_inserter(not_arrived),
        [](const Child& c) { return !c.arrived; });

    vector<string> missing;
    transform(not_arrived.begin(), not_arrived.end(), back_inserter(missing),
        [](const Child& c) { return c.name; });

    map<bool, vector<string>> groups;
    for (const auto& c : children)
        groups[c.arrived].push_back(c.name);

    cout << "Прилетели:\n";
    for (const auto& name : groups[true]) cout << "- " << name << endl;
    cout << "Не прилетели:\n";
    for (const auto& name : groups[false]) cout << "- " << name << endl;

    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "Выберите задачу (1-10, 0 - выход): ";
        cin >> choice;
        switch(choice) {
            case 1: Task1(); break;
            case 2: Task2(); break;
            case 3: Task3(); break;
            case 4: Task4(); break;
            case 5: Task5(); break;
            case 6: Task6(); break;
            case 7: Task7(); break;
            case 8: Task8(); break;
            case 9: Task9(); break;
            case 10: Task10(); break;
        }
    } while(choice != 0);
   
    return 0;
}