

#include <iostream>
#include <cmath>
#include<string>
using namespace std;

string ReadName()
{
	string name;
	cout << "enter first name\n";
	getline(cin, name);
	return name;
}
void PrintFullName(string Name)
{
	cout << "your name is : " << Name << "\n";
}
enum enNumbertype{od=1,even=2};
int ReadNum()
{
	int num;
	cout << "enter number \n";
	cin >> num;
	return num;
}
void read2Num(int& n1, int& n2)
{
	cout << "enter number1: \n";
	cin >> n1;
	cout << "enter number2: \n";
	cin >> n2;
}
void Swap(int& n1, int& n2)
{
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}
void Print2num(int n1,int n2)
{
	cout << "Num1 : " << n1 << endl;
	cout << "Num2 : " << n2 << endl;
}
enNumbertype checknumbertype(int num)
{
	if (num % 2 == 0) return enNumbertype::even;
	else 
		return enNumbertype::od;
}
void PrintNumType(enNumbertype numbertype)
{	
	switch (numbertype)
	{
	case od:
		cout << " yes is od";
		break;
	case even:
		cout << " not od , even ";
		break;
	}

		
}
struct stInfo { int age; bool HasDriverlicence;bool hasrecommandation; };
stInfo ReadInfo()
{
	stInfo info;
	cout << "enter age ";
	cin >> info.age;
	cout << "has driver licence ? ";
	cin >> info.HasDriverlicence;
	cout << "has recommandation ? ";
	cin >> info.hasrecommandation;
	return info;
}
bool IsAccepted(stInfo info)
{
	return (info.age >= 18 && info.HasDriverlicence == true)||( info.hasrecommandation ==true);
}
void PrintResult(stInfo info)
{
	if (IsAccepted(info))
		cout << "accepted";
	else
		cout << "not accepted";
}
struct stname { string Firstname;string lastName; };
stname Readname()
{
	stname name;
	cout << "enter first name ";
	cin >> name.Firstname;
	cout << "enter lastname";
	cin >> name.lastName;
	return name;
}
string getFullName(stname name,bool isReversed)
{
	if(isReversed)
	return name.lastName + " " + name.Firstname;
	else
	return name.Firstname + " " + name.lastName;
}
void printFullname(string fullname)
{
	cout << "your name is " << fullname;
}
float GetHalfnumber(int num) { return (float)num / 2; }
void PrintHalfNumber(int num) { cout << "half number of  " + to_string(num )+ "  is: " +to_string( GetHalfnumber(num)); }
enum enPassFail{pass=1,fail=2};
enPassFail CheckMark(int mark) { if (mark >= 50)return enPassFail::pass;else return enPassFail::fail; }
void PrintResults(int mark) {
	enPassFail n;
	n = (enPassFail)mark;
	switch (n)
	{
	case pass:cout << " pass";
		break;
	case fail:cout << "fail";
		break;
	default:
		break;
	}
}
void ReadNumbers(int &n1,int &n2,int &n3)
{
	cout << "enter n1";
	cin >> n1;
	cout << "enter n2";
	cin >> n2;
	cout << "enter n3";
	cin >> n3;
}
int Sum3numbers(int n1, int n2, int n3)
{
	return n1 + n2 + n3;
}
void PrintResult3num(float n)
{
	cout << " sum of 3 num is : " + to_string(n) + " \n";
}
float CalcAvrge(int n1, int n2, int n3) { return float(n1 + n2 + n3) / 3; }
enPassFail ChecAverage(float Avr)
{
	if (Avr >= 50)return enPassFail::pass;else return enPassFail::fail;
}
void PrintResultAvrge(float Avr)
{
	cout << "your average is " << Avr << endl;
	if (ChecAverage(Avr) == enPassFail::pass)cout << "passed";else cout << "FAILD";
}
bool IsValidateNumberInRange(int Num,int from, int to)
{
	return (Num >= from && Num <=to);
}
int ReadUntilValidNumInRange(int from, int to)
{
	int num = 0;
	do
	{
		num = ReadNum();
		
	} while(!IsValidateNumberInRange(num, from, to));
	return num;
}
void PrintResulInRange(int  Num)
{
	cout << "your num " <<Num;
}
int Power(int m, int n)
{
	int p = 1;
	for (int i = 0;i < n;i++)
	{
		p *= m;
	}
	return p;
}
int ReadNumber(string Message)
{
	int Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}
char ReadChar()
{
	char C;
	cout << "enter operation \n";
	cin >> C;
	return C;
}
enum enOptype { Add = '+', sub = '-', mult = '*', dv = '/'};
enOptype GetOpType(char C)
{
	if (C == '+')return enOptype::Add;
	if (C == '-')return enOptype::sub;
	if (C == '*')return enOptype::mult;
	if (C == '/')return enOptype::dv;
	else
		return enOptype::Add;
}
float Calculator(int Num1,int Num2,enOptype OT)
{
	switch (OT)
	{
	case Add:return Num1 + Num2;
		break;
	case sub:return Num1 -Num2;
		break;
	case mult:return Num1 * Num2;
		break;
	case dv:return (float)Num1 / Num2;
		break;
	default:return Num1 + Num2;
		break;
	}
}
int SumUntil(int _99)
{
	int Sum = 0;
	int n=0;
	do
	{
		Sum += n;
		n= ReadNumber("Enter a number : ");
	} while (n != _99);
	return Sum;
}
enum enPrime{Prime=1,NotPrime=2};
enPrime CheckPrimeNumber(int Num)
{
	if (Num == 2)
		return enPrime::Prime;
	int N =round( Num / 2);
	for (int i = 2;i <= N;i++)
	{
		if (Num % i == 0)
			return enPrime::NotPrime;;
	}
	return enPrime::Prime;
}
void PrimeNumber(int Num)
{
	switch (CheckPrimeNumber(Num))
	{
	case Prime:cout << " Prime ";
		break;
	case NotPrime:cout << "Not Prime";
		break;
	default:
		break;
	}
		
}
float HoursToDays(int NumberOfHours)
{
	return (float)NumberOfHours / 24;
}
float HoursToWeeks(int NumberOfHours)
{
	return (float)(NumberOfHours) / (24 * 7);
}
float DaysToWeeks(float NumberOfDays)
{
	return (float)(HoursToDays(NumberOfDays)) / 7;
}
int ReadNumberInRange(string Message,int from, int to)
{
	int num = 0;
	do
	{
		cout << Message << from << " " << to;
		cin>>num;
		 
	} while (num<from || num >to);
	return num;
}
enum enDayOfWeek{Mon=1,Tue=2,Wed=3,Thu=4,Fri=5,Sat=6,Sun=7};
enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange("Enter a Number betwen ", 1, 7);
}
string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{
	case Mon:return "Monday";
	case Tue:return "Tuesday";
	case Wed:return "Wednesday";
	case Thu:return "thursday";
	case Fri:return "Friday";
	case Sat:return "Saturday";
	case Sun:return "Sunday";
	default:return " Its not a Day";
	}
}
struct stTaskDuration { int Days, Hours, Minu, second; };
stTaskDuration CalculTDuration(int TotSeconds)
{
	stTaskDuration TD;
	int remainder = 0;
	const int secPerDay=24*60*60;
	const int secPerHour =60 * 60;
	const int secPerMin =  60;
	TD.Days = TotSeconds / secPerDay;
	remainder = TotSeconds % secPerDay;
	TD.Hours = remainder / secPerHour;
	remainder %= secPerHour;
	TD.Minu = remainder / secPerMin;
	remainder %= secPerMin;
	TD.second = remainder;

	return TD;
}
void SecondsTaskDuration(stTaskDuration TD)
{
	cout << TD.Days << ":" << TD.Hours << ":" << TD.Minu << ":" << TD.second << endl;
}
void PrintAToZ()
{
	for (int i = 65;i <= 90;i++)
	{
		cout << char(i) << endl;
	}
}
string ReadPinCode()
{
	cout << "enter pin code \n";
	string pc;
	cin >> pc;
	return pc;
}
bool Login()
{
	string pc;
	int c = 0;
	do
	{
		c++;
		pc = ReadPinCode();
		if (pc == "1234")
		{
			system("color 4F");
			return true;
		}
		cout << "Rowng pin enter again :";

	} while (pc != "1234" && c <=2);
	return false;
}
void MultiplayTable1to10()
{
	cout << "\t\t\t\tMulti tab fr 1 to 10\n";
	cout << "\t\t";
	for (int i = 1;i <= 10;i++) { cout << i << "\t"; }
	cout << "\n\t________________________________________________________________________________________\n";

	string Sepa = "  |";
	for (int i = 1;i <= 10;i++)
	{
		if (i > 9) { Sepa = " |"; }
		cout << "\t"<<i << Sepa << "\t";for (int j = 1;j <= 10;j++) { cout << i * j << "\t"; }
		cout <<"|" << endl;
	}
	cout << "\t________________________________________________________________________________________\n";
}
void PrintPrimNumFrom1ToN(int N)
{
	for (int i = 1;i <= N;i++)
	{
		if (CheckPrimeNumber(i) == enPrime::Prime)
			cout << i << endl;
	}
}
int main()
{
	PrintPrimNumFrom1ToN(ReadNumber("enter a number: \n"));
	return 0;
}




//int n1, n2;
	//read2Num(n1, n2);
	//Print2num(n1, n2);
	//Swap(n1, n2);
	//Print2num(n1, n2);
	//int num = ReadNum();
	//enNumbertype nt = checknumbertype(num);
	//PrintNumType(nt);
	//stInfo info = ReadInfo();
	//PrintResult(info);
	//stname name = Readname();
	//string fullname = getFullName(name, true);
	//printFullname(fullname);
	//int num = ReadNum();
	//PrintHalfNumber(num);
	//int mark = ReadNum();
	//PrintResults(mark);

