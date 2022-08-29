#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE, numOfApples, myMoney;
public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSaleResult() {
		cout << "남은 사과 : " << numOfApples << "\n";
		cout << "판매 수익 : " << myMoney << "\n";
		cout << "\n";
	}
};
class FruitBuyer {
private:
	int myMoney, numOfApples;
public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "현재 잔액 : " << myMoney << "\n";
		cout << "사과 개수 : " << numOfApples << "\n";
		cout << "\n";
	}
};
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	FruitSeller seller;
	FruitBuyer buyer;
	seller.InitMembers(1000, 20, 0);
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 3000);

	cout << "판매자\n";
	seller.ShowSaleResult();
	cout << "구매자\n";
	buyer.ShowBuyResult();
    return 0;
}
