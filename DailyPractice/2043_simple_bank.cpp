#include <iostream>
#include <vector>
using namespace std;
class Bank {
 private:
  vector<long long> _balance;

  bool accountValidate(int account) {
    return (account - 1) >= 0 && (account - 1) < this->_balance.size();
  }

  bool accountOverflow(int account, long long money) {
    long long maxMoney = INT64_MAX;
    long long current = this->_balance[account - 1];
    if ((maxMoney - current) >= money) {
      return false;
    }
    return true;
  }

  bool accountNotEnough(int account, long long money) {
    return (this->_balance[account - 1] - money) < 0;
  }

 public:
  Bank(vector<long long>& balance) { this->_balance = balance; }

  bool transfer(int account1, int account2, long long money) {
    // check validate
    if (!accountValidate(account1) || !accountValidate(account2)) {
      return false;
    }
    // check not enough
    if (accountNotEnough(account1, money)) {
      return false;
    }
    // check overflow
    if (accountOverflow(account2, money)) {
      return false;
    }
    // transfer
    this->_balance[account1 - 1] -= money;
    this->_balance[account2 - 1] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    // check validate
    if (!accountValidate(account)) {
      return false;
    }
    // check overflow
    if (accountOverflow(account, money)) {
      return false;
    }
    // transfer
    this->_balance[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    // check validate
    if (!accountValidate(account)) {
      return false;
    }
    // check not enough
    if (accountNotEnough(account, money)) {
      return false;
    }
    // transfer
    this->_balance[account - 1] -= money;
    return true;
  }
};

int main() {
  vector<long long> balance = {10, 100, 20, 50, 30};
  Bank* obj = new Bank(balance);
  cout << obj->withdraw(3, 10) << endl;
  cout << obj->transfer(5, 1, 20) << endl;
  cout << obj->deposit(5, 20) << endl;
  cout << obj->transfer(3, 4, 15) << endl;
  cout << obj->withdraw(10, 50) << endl;
  return 0;
}