#include <iostream>
// 1. Создать несколько Human.
// 2. Добавить несколько дополнительных полей (не забывать добавить значимые поля в конструктор)
// 3. Добавить getter'ы и setter'ы
// 4. Продемонстрировать обращение к полям объектов дочерних и родительских классов
// 5. Добавить несколько наследников от различных родителей (сделать дерево из 5 классов)

enum SEX {
    Undefined,
    Male,
    Female
};

class Human {
    int age;
    SEX sex;

public:

    Human(int age, SEX sex) {
        this->age = age;
        this->sex = sex;
    }

    int getAge() {
        return this->age;
    }

    void setAge(int age) {
        this->age = age;
    }

    SEX getSex() {
        return sex;
    }

    void setSex(SEX sex) {
        this->sex = sex;
    }
};

class Student: public Human {
    std::string number;

public:
    Student(int age, SEX sex, const std::string &number) : Human(age, sex) {
        this->number = number;
    }

    const std::string &getNumber() const {
        return number;
    }

    void setNumber(const std::string &number) {
        Student::number = number;
    }
};

class Teacher: public Human {
private:
    int salary;                 // Зарплата
    int experience;             // Стаж работы
public:
    Teacher(int age, SEX sex, int salary, int experience) : Human(age, sex) {
        this-> salary = salary;
        this->experience = experience;
    }

    int getSalary() const {
        return salary;
    }

    void setSalary(int salary) {
        Teacher::salary = salary;
    }

    int getExperience() const {
        return experience;
    }

    void setExperience(int experience) {
        Teacher::experience = experience;
    }
};

class SeniorTeacher: public Teacher {
private:
    int subordination;                  // Кол-во подчиненных

public:
    SeniorTeacher(int age, SEX sex, int salary, int experience, int subordination) : Teacher(age, sex, salary, experience) {
        this->subordination = subordination;
    }

    int getSubordination() const {
        return subordination;
    }

    void setSubordination(int subordination) {
        SeniorTeacher::subordination = subordination;
    }
};

class Postgraduate: public Teacher, Student {
public:
    Postgraduate(int age, SEX sex, int salary, int experience, const std::string &number) : Teacher(
            age, sex, salary, experience), Student(age, sex, number) {}
};

int main() {
    Postgraduate petya(26, Male, 23000, 3, "1523761258312");
    SeniorTeacher zhenya(45, Female, 31000, 10, 4);

    std::cout << petya.Teacher::getAge() << " ";
    std::cout << petya.getSalary() << " ";
    std::cout << petya.getExperience() << "\n";

    std::cout << zhenya.getSubordination() << " ";
    std::cout << zhenya.getSalary() << " ";
    std::cout << zhenya.getExperience() << "\n";

    return 0;
}
