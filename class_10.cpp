#include <cmath>
#include <iomanip>
#include <iostream>

struct Result {
  long double value;
  int count;
};

long double targetFunction(long double x) { return x * x - std::cos(x); }

long double derivativeFunction(long double x) { return 2 * x + std::sin(x); }

long double repeatFunction(long double x) {
  return x - targetFunction(x) / derivativeFunction(x);
}

Result newtonMethod(long double x) {
  int i = 0;
  long double x_new;
  while (i < 2147483647) {
    x_new = repeatFunction(x);
    if (std::abs(x_new - x) < 1.0e-10) {
      break;
    }
    x = x_new;
    i++;
  }

  Result result;
  result.value = x_new;
  result.count = i;
  return result;
}

long double input() {
  std::cout << "Please input init value" << std::endl;
  std::cout << "> ";
  long double x;
  std::cin >> x;
  return x;
}

void output(Result result) {
  std::cout << "試行回数: " << result.count << std::endl;
  std::cout << "      解: " << std::fixed << std::setprecision(15)
            << result.value << std::endl;
}

int main() {
  long double x = input();
  Result res = newtonMethod(x);
  output(res);
}
