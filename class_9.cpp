#include <cmath>
#include <iostream>

class Calculate {
private:
  double x;
  double a;
  int cycle = 0;

public:
  Calculate();
  void iteration();
  void showResult();
};

Calculate::Calculate() {
  std::cout << "平方根を求めたい数値を入力してください" << std::endl;
  std::cout << "> ";
  std::cin >> a;
  x = 1;
}

void Calculate::iteration() {
  double newx = 0;
  for (int i = 1; i <= 100; i++) {
    double b = (a / x - x) / 2;
    newx = x + b;
    if (std::fabs(b) < 0.00000001) {
      std::cout << "break this" << std::endl;
      std::cout << "b = " << b << std::endl;
      cycle = i;
      break;
    }
    cycle = i;
    x = newx;
  }
}

void Calculate::showResult() {
  std::cout << "-------------------------------" << std::endl;
  std::cout << " 計算回数: " << cycle << "回" << std::endl;
  std::cout << "aの平方根: " << x << std::endl;
  std::cout << " 正確な値: " << std::sqrt(a) << std::endl;
  std::cout << "     誤差: " << std::fabs(std::sqrt(a) - x) << std::endl;
}

int main() {
  Calculate calc;
  calc.iteration();
  calc.showResult();
}

/* a=2のときの計算結果
 計算回数: 5回
aの平方根: 1.41421
 正確な値: 1.41421
     誤差: 1.59472e-12

   a=3のときの計算結果
 計算回数: 5回
aの平方根: 1.73205
 正確な値: 1.73205
     誤差: 2.44585e-09
*/
