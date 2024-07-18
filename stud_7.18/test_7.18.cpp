#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>


using namespace std;
//贪心 分糖果问题
class Solution1 {
public:
    int candy(vector<int>& ratings)
    {
        vector<int> Candy(ratings.size(), 1);

        // 从左到右遍历，保证右边的孩子评分更高时，糖果更多
        for (size_t i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                Candy[i] = Candy[i - 1] + 1;
            }
        }

        // 从右到左遍历，保证左边的孩子评分更高时，糖果更多
        for(size_t i = ratings.size() - 2; i < ratings.size(); i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                Candy[i] = max(Candy[i], Candy[i + 1] + 1);
            }
        }

        // 计算总糖果数
        int ans = 0;
        for (size_t i = 0; i < Candy.size(); i++)
        {
            ans += Candy[i];
        }

        return ans;
    }
};
void test_solution1()
{
   vector<int> ratings1 = { 1, 0, 2 };
    Solution1 solution;
    int result1 = solution.candy(ratings1);
    cout << "Test case 1: Expected 5, Got " << result1 << endl;

    // 测试用例 2
    vector<int> ratings2 = { 1, 2, 2 };
    int result2 = solution.candy(ratings2);
    cout << "Test case 2: Expected 4, Got " << result2 << endl;


}
class Base
{
public:
    virtual void Func1()
    {
        cout << "Base::Func1()" << endl;
    }

    virtual void Func2()
    {
        cout << "Base::Func2()" << endl;
    }

    void Func3()
    {
        cout << "Base::Func3()" << endl;
    }

private:
    int _b = 1;
};

class Derive : public Base
{
public:
    virtual void Func1()
    {
        cout << "Derive::Func1()" << endl;
    }
private:
    int _d = 2;
};

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
	virtual void Func() { cout << "买票-全价" << endl; }

	int _a = 0;

};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

	int _b = 1;
};

void Func(Person& p)
{
	p.BuyTicket();
}
void test_2()
{
    Person mike;
    	Func(mike);
    
    	Student johnson;
    	Func(johnson);
    
    	mike = johnson;
}
class Solution4 {
public:
    // 静态成员函数 cmp 用于比较两个整数 x 和 y，用于 sort 函数中的排序规则
    static bool cmp(const int& x, const int& y) {
        // 将整数 x 和 y 转换为字符串
        string a = to_string(x), b = to_string(y);
        // 比较 a+b 和 b+a 的大小，如果 a+b > b+a，则返回 true，否则返回 false
        // 这里的比较是基于字符串的拼接比较，不是整数的简单比较
        return a + b > b + a;
    }

    // 函数 largestNumber 接收一个整数数组 nums，返回一个字符串
    string largestNumber(vector<int>& nums) {
        string ans;  // 用于存储最终结果的字符串
        // 使用自定义的比较函数 cmp 对 nums 数组进行排序
        sort(nums.begin(), nums.end(), cmp);
        // 遍历排序后的 nums 数组
        for (auto& num : nums) {
            // 将每个整数转换为字符串，并添加到结果字符串中
            ans += to_string(num);
        }
        // 处理特殊情况，如果排序后的数组第一个元素是 0，则直接返回 "0"
        // 因为所有其他元素都是 0，这会导致最终结果是 "000..."
        if (ans[0] == '0') {
            return "0";
        }
        // 返回拼接后的最大数字字符串
        return ans;
    }
};

int main()
{
    test_solution1();
    test_2();
	return 0;
}