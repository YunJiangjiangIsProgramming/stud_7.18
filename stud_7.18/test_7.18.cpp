#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>


using namespace std;
//̰�� ���ǹ�����
class Solution1 {
public:
    int candy(vector<int>& ratings)
    {
        vector<int> Candy(ratings.size(), 1);

        // �����ұ�������֤�ұߵĺ������ָ���ʱ���ǹ�����
        for (size_t i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                Candy[i] = Candy[i - 1] + 1;
            }
        }

        // ���ҵ����������֤��ߵĺ������ָ���ʱ���ǹ�����
        for(size_t i = ratings.size() - 2; i < ratings.size(); i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                Candy[i] = max(Candy[i], Candy[i + 1] + 1);
            }
        }

        // �������ǹ���
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

    // �������� 2
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
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual void Func() { cout << "��Ʊ-ȫ��" << endl; }

	int _a = 0;

};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

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
    // ��̬��Ա���� cmp ���ڱȽ��������� x �� y������ sort �����е��������
    static bool cmp(const int& x, const int& y) {
        // ������ x �� y ת��Ϊ�ַ���
        string a = to_string(x), b = to_string(y);
        // �Ƚ� a+b �� b+a �Ĵ�С����� a+b > b+a���򷵻� true�����򷵻� false
        // ����ıȽ��ǻ����ַ�����ƴ�ӱȽϣ����������ļ򵥱Ƚ�
        return a + b > b + a;
    }

    // ���� largestNumber ����һ���������� nums������һ���ַ���
    string largestNumber(vector<int>& nums) {
        string ans;  // ���ڴ洢���ս�����ַ���
        // ʹ���Զ���ıȽϺ��� cmp �� nums �����������
        sort(nums.begin(), nums.end(), cmp);
        // ���������� nums ����
        for (auto& num : nums) {
            // ��ÿ������ת��Ϊ�ַ���������ӵ�����ַ�����
            ans += to_string(num);
        }
        // ���������������������������һ��Ԫ���� 0����ֱ�ӷ��� "0"
        // ��Ϊ��������Ԫ�ض��� 0����ᵼ�����ս���� "000..."
        if (ans[0] == '0') {
            return "0";
        }
        // ����ƴ�Ӻ����������ַ���
        return ans;
    }
};

int main()
{
    test_solution1();
    test_2();
	return 0;
}