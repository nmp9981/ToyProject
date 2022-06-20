#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    string name;
    int age;

    string position;//직책
    int rank;//순위, 값이 클 수록 높음

public:
    Employee(string name, int age, string position, int rank)
        : name(name), age(age), position(position), rank(rank) {};//생성자 리스트
    //복사 생성자
    Employee(const Employee& employee) {
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

    //디폴트 생성자
    Employee() {}

    //출력
    void print_info() {
        cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만메소\n";
    }
    //월급 결정
    int calculate_pay() { return 200 + rank * 50; }
};

//직원 리스트
class EmployeeList {
    int alloc_employee;//할당한 총 직원수
    int current_employee;//현재 직원 수
    Employee** employee_list;//직원 데이터

public:
    //배열 생성자
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee * [alloc_employee];
        current_employee = 0;
    }

    //직원 추가
    //할당된 크기는 총 직원수보다 많다
    void add_employee(Employee* employee) {
        employee_list[current_employee] = employee;
        current_employee++;
    }
    //현재 직원 수
    int current_employee_num() { return current_employee; }
    //총 비용 출력
    void print_employee_info() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        cout << "총 비용 : " << total_pay << "\n";
    }
    //소멸자
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};

//근속년수
class Manager {
    string name;
    int age;

    string position;//직책
    int rank;//순위
    int year_of_service;//근속년수
public:
    //생성자 리스트
    Manager(string name, int age, string position, int rank, int year_of_service) :
        year_of_service(year_of_service),
        name(name),
        age(age),
        position(position),
        rank(rank) {}
    
    //복사 생성자
    Manager(const Manager& manager) {
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }
    //디폴트 생성자
    Manager() {}

    int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }

    void print_info() {
        cout << name << " (" << position << " , " << age <<" , "<<year_of_service << "년차) ==> " << calculate_pay() << "만메소\n";
    }
};
int main() {
    
    EmployeeList emp_list(10);

    emp_list.add_employee(new Employee("INTJ", 26, "마스터", 5));
    emp_list.add_employee(new Employee("ENFJ", 22, "다이아", 4));
    emp_list.add_employee(new Employee("ENFP", 21, "다이아", 4));
    emp_list.add_employee(new Employee("ISFJ", 24, "팀장", 3));
    emp_list.add_employee(new Employee("INTP", 19, "정회원", 2));
    emp_list.add_employee(new Employee("ESEP", 20, "정회원", 2));
    emp_list.add_employee(new Employee("ESTP", 20, "뉴비", 1));
    emp_list.add_employee(new Employee("INFP", 21, "뉴비", 1));
    
    emp_list.print_employee_info();
    return 0;
}
