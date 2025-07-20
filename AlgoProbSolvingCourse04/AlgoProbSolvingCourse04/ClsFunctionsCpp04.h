#pragma once
using namespace std;
#include <iostream>
#include <string>
class ClsFunctionsCpp04
{
public:
	enum enPassFail{Pass=1,Fail=2};
	enum enEvenOdd { Even = 1, Odd = 2 };
	int ReadNumber()
	{
		int n;
		cout << "Enter a number: ";
		cin >> n;
		return n;
	}
	bool IsValidateNumberInRange(int N, int From, int To)
	{
		return (N >= From && N <= To);
	}
	void PrintValidateNumberInrange(int N)
	{
		if (IsValidateNumberInRange(N, 18, 60))
			cout << "Number " << N << " Is Valide \n";
		else
			cout << "Number " << N << " Is not  Valide \n";
	}
	int  ReadUntilValidNumberInRange(int From, int To)
	{
		int N=0;
		do
		{
			N = ReadNumber();
		} while (!IsValidateNumberInRange(N, From, To));
		//cout << "Number " << N << " Is Valide \n";
	    return N;
	}
	void PrintNumbersFrom1_To_N(int N)
	{
		for (int i = 10; i >= 1; i--)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	void PrintNumbersFrom10_To_N(int N)
	{
		int i = 10;

		while (i >= 1)
		{
			cout << i << " ";
			i--;
		}
		cout << endl;
	}
	void PrintNumbersFromN_To_20(int N)
	{ 
		int i = N + 20;
		do
		{
			cout << i << " ";
			i--;
		} while (i>=N+20);
		cout << endl;
	}
	 static int  FactorialRecursive(int n)
	 {
		if (n <= 1)
			return 1;
		else
			return n * FactorialRecursive(n - 1);
	 }
	 int FactorialIterative(int n)
	 {
		 int result = 1;
		 for (int i = 2; i <= n; ++i)
		 {
			 result *= i;
		 }
		 return result;
	 }
	 int PowerOf(int P,int N)
	 {
		 for (int  i = 1; i <= N; i++)
		 {
			 P += P;
		 }
		 return P;
	 }
	float CalculateHalfOfNumber(int n)
	{
		return n / 2.0f; // Use float division
	}
	float Sum(int n1, int n2, int n3)
	{
		return (float)n1 + n2 + n3;
	}
	float Avg(int n1, int n2, int n3)
	{
		return (float)Sum(n1,n2,n3) / 3;
	}
	void PrintAvg(int n1, int n2, int n3)
	{
		cout << " Avg( " + to_string(n1) + " + " + to_string(n2) + " + "
			+ to_string(n3) + ")  = " + to_string(Avg(n1, n2, n3));
	}
	void PrintSumOfThreeNumbers(int n1,int n2,int n3)
	{
		cout << " Sum( "+ to_string(n1)+" + "+ to_string(n2) +" + "
			+ to_string(n3) +")  = " + to_string(Sum(n1, n2, n3));
	}
	void PrintHalfOfNumber(int n)
	{
		std::cout << "Half of "+to_string(n)+ " is: "+to_string(CalculateHalfOfNumber(n)) << std::endl;
	}
	enPassFail CheckPssfail(int n)
	{
		if(n >= 50)
			return enPassFail::Pass;
		else
			return enPassFail::Fail;
	}
	bool IsPass(enPassFail result)
	{
		return result == enPassFail::Pass;
	}
	void PrintPassFail(enPassFail result)
	{
		if (IsPass(result))
			cout << "You passed." << std::endl;
		else
			cout << "You failed." << std::endl;
	}
	enEvenOdd EvenOdd(int n)
	{

		if (n % 2 == 0)
			return enEvenOdd::Even;
		else
			return enEvenOdd::Odd;
	}
	string PrintEvenOdd(enEvenOdd NumberType)
	{
		return (NumberType == enEvenOdd::Even)? "The number is even.":"The number is odd.";
	}
	struct stContactInfo
	{
		string FirstName;
		string lastName;
		int Age=18;
		bool HasDrivingLicense=false;
		bool hasRecommantion=false;
	};
	stContactInfo ReadContactInfo()
	{
		stContactInfo contactInfo;
		cout << "Enter first name: ";
		cin >> contactInfo.FirstName;
		cout << "Enter last name: ";
		cin >> contactInfo.lastName;

		cout << "Enter age: ";
		cin >> contactInfo.Age;
		cout << "Has driving license (1 for Yes, 0 for No): ";
		int hasLicense;
		cin >> hasLicense;
		contactInfo.HasDrivingLicense = (hasLicense == 1);	
		cout << "Has recommendation (1 for Yes, 0 for No): ";
		int hasRecommendation;
		cin >> hasRecommendation;
		contactInfo.hasRecommantion = (hasRecommendation == 1);
		return contactInfo;
	}
	string GetFullName(stContactInfo contactInfo,bool reversed)
	{
		if (reversed)
			return contactInfo.lastName + " " + contactInfo.FirstName;
		else
		return contactInfo.FirstName + " " + contactInfo.lastName;
	}
	void PrintContactInfo(stContactInfo contactInfo)
	{
		cout << "Full Name: " << GetFullName(contactInfo,true)<< std::endl;
		
		cout << "Age: " << contactInfo.Age << std::endl;
		cout << "Has Driving License: " << (contactInfo.HasDrivingLicense ? "Yes" : "No") << std::endl;
		cout << "Has Recommendation: " << (contactInfo.hasRecommantion ? "Yes" : "No") << std::endl;
	}
	bool IsAdult(stContactInfo contactInfo)
	{
		return contactInfo.Age >= 21;
	}
	bool HasDrivingLicense(stContactInfo contactInfo)
	{
		return contactInfo.HasDrivingLicense;
	}
	bool IsEligibleForDriving(stContactInfo contactInfo)
	{
		if( HasRecommendation(contactInfo))
		{
			cout << "You have a recommendation " << std::endl;
			return true;
		}
		return IsAdult(contactInfo) && HasDrivingLicense(contactInfo);
	}
	bool HasRecommendation(stContactInfo contactInfo)
	{
		return contactInfo.hasRecommantion;
	}
	void PrintEligibility(stContactInfo contactInfo)
	{
		if (IsEligibleForDriving(contactInfo))
			cout << "You are eligible for driving." << std::endl;
		else
			cout << "You are not eligible for driving." << std::endl;
	}
	enPassFail CheckAvg(int n1,int n2,int n3)
	{
	    if(Avg(n1, n2, n3) >= 50)
			return enPassFail::Pass;
		else
			return enPassFail::Fail;
	}
	void PrintResultAvg(int n1, int n2, int n3)
	{
		if (CheckAvg(n1, n2, n3)==enPassFail::Pass)
			cout << "You passed with an average."+to_string(Avg(n1, n2, n3)) << std::endl;
		else
			cout << "You failed with an average." + to_string(Avg(n1, n2, n3)) << std::endl;
	}
	int Max(int n1, int n2, int n3)
	{
		int max = n1;
		if (n2 > max)
			max = n2;
		if (n3 > max)
			max = n3;
		return max;
	}
	void PrintMaxOf3Numbers(int n1, int n2, int n3)
	{
		cout << "The maximum of " << n1 << ", " << n2 << ", and " << n3 << +
			"  is  : " << Max(n1, n2, n3) << std::endl;
	}
	int Swap(int& n1, int& n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
		return 0;
	}
	void SwapAndPrint(int& n1, int& n2)
	{
		cout << "Before swap: n1 = " << n1 << ", n2 = " << n2 << std::endl;
		Swap(n1, n2);
		cout << "After swap: n1 = " << n1 << ", n2 = " << n2 << std::endl;
	}
};

