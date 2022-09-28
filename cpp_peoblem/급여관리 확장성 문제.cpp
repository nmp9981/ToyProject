#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

//직원
class Empolyee {
private:
	char name[50];
public:
	Empolyee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name : " << name << "\n";
	}
	virtual int GetPay() const {//하위 클래스에서 사용할 수 있게 가상함수 생성
		return 0;
	}
	virtual void ShowSalaryInfo() const {//하위 클래스에서 사용할 수 있게 가상함수 생성

	}
};

//정규직 직원
class PermanentWorker : public Empolyee {
private:
	int salary;//급여
public:
	PermanentWorker(const char* name, int money) :Empolyee(name), salary(money) {}
	int GetPay() const{
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << "\n";
	}
};

//직원 컨트롤 클래스
class EmpolyeeHandler {
private:
	//직원 배열 정의, 주소 값을 저장하는 방식으로 객체 저장, Employee클래스를 상속하는 클래스의 객체도 저장 가능
	Empolyee* empList[50];
	int empNum;//직원 수
public:
	EmpolyeeHandler() : empNum(0) {}//직원 수 초기화
	void AddEmployee(Empolyee* emp) {//Employee 객체의 주소값 전달
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();//상속 받지 않음, Employee에는 ShowYourName()만 있다. 가상함수로 해결
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum+=empList[i]->GetPay();//상속 받지 않음, Employee에는 ShowYourName()만 있다. 가상함수로 해결
		}
		cout << "salary sum : " << sum << "\n";
	}
	~EmpolyeeHandler() {//소멸자
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

//임시직 클래스
class TemporaryWorker : public Empolyee {
private:
	int workTime;//일한 시간
	int payPerHour;//시급
public:
	TemporaryWorker(const char* name, int pay):Empolyee(name),workTime(0),payPerHour(pay){}
	//일한 시간 추가
	void AddWorkTime(int time) {
		workTime += time;
	}
	//이 달의 급여
	int GetPay() const {
		return workTime * payPerHour;
	}
	//월급
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << "\n"<<"\n";
	}
};

//영업직 클래스
class SalesWorker : public PermanentWorker {//영업직도 정규직의 일종
private:
	int salesResult;//월 판매실적
	double bonusRatio;//상여금 비율
public:
	SalesWorker(const char* name,int money, double ratio):PermanentWorker(name,money),salesResult(0),bonusRatio(ratio){}
	//판매실적 추가
	void AddSalesResult(int value) {
		salesResult += value;
	}
	//이 달의 급여
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);//PermanentWorker의 GetPay()호출
	}
	//월급
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << "\n"<<"\n";//SalesWorker의 GetPay()호출
	}
};

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//컨트롤 클래스 객체 생성(직원 관리)
	EmpolyeeHandler handler;

	//정규직 등록
	handler.AddEmployee(new PermanentWorker("PRO", 1000));
	handler.AddEmployee(new PermanentWorker("SR", 1200));
	handler.AddEmployee(new PermanentWorker("Z7", 800));

	//임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("JIU", 700);//주소값으로
	alba->AddWorkTime(6);
	handler.AddEmployee(alba);//주소값을 전달

	//영업직 등록
	SalesWorker* seller = new SalesWorker("HT", 1400, 0.1);//주소값으로
	seller->AddSalesResult(8800);
	handler.AddEmployee(seller);//주소값을 전달

	//이번달 지불할 금액의 정보
	handler.ShowAllSalaryInfo();
	//이번달 지불할 금액의 총합
	handler.ShowTotalSalary();
	return 0;
}
