#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>
#include <stack>
#include <vector>

/*スタックに格納するデータの構造*/
struct data {
  std::size_t left;
  std::size_t right;
};

/*クイックソートを行う関数
 * 引数
 * array: vector<int> 参照渡し
 * 参考文献: http://staryoshi.hatenablog.com/entry/2016/01/27/200157
 */
void quick_sort(std::vector<int> &array) {
  std::stack<data, std::vector<data>> stack;
  stack.push({0, array.size() - 1});

  while (!stack.empty()) {
    auto top = stack.top();
    auto left = top.left;
    auto right = top.right;
    stack.pop();

    auto l = left;
    auto r = right;
    auto pivot = array[(left + right) / 2];

    while (l <= r) {
      while (array[l] < pivot) {
        l++;
      }

      while (array[r] > pivot) {
        r--;
      }

      if (l <= r) {
        std::swap(array[l], array[r]);
        l++;
        r--;
      }
    }

    if (left < r) {
      stack.push({left, r});
    } else if (l < right) {
      stack.push({l, right});
    }
  }
}

/*vectorに数値を格納する関数
 * 引数
 * array: vector<int> 参照渡し
 * n :int 要素数
 */
void input_vector(std::vector<int> &array, int n) {
  std::cout << "please input number" << std::endl;
  int num;
  int i = 0;
  while (i < n) {
    std::cout << "> ";
    std::cin >> num;
    array.push_back(num);
    i++;
  }
}

int main() {
  int n;
  std::cout << "Please input element count" << std::endl;
  std::cout << "> ";
  std::cin >> n;

  std::vector<int> nums;
  input_vector(nums, n);
  quick_sort(nums);

  std::cout << "------result------" << std::endl;
  std::copy(nums.begin(), nums.end(),
            std::ostream_iterator<int>(std::cout, ","));
  std::cout << std::endl;
}
