#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enPositiveNegativeZero { Positive = 1, Negative = 2, Zero = 3 };
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
enum enPalindromNotPalindrom { Palindrom = 1, NotPalindrom = 2 };
enum enOddOrEven { Odd = 1, Even = 2 };
enum enPerfectNotPerfect { Perfect = 1, NotPerfect = 2 };
enum enOperatorType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mode = 5 };
enum enLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3 };
enum enCaracterType { Capitalletter = 1, SmallLetter = 2, SpecialChar = 3, Degit = 4 };
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

struct stDate
{
	short Year;
	short Month;
	short Day;
};
struct stPeriods
{
	stDate StartDate;
	stDate EndDate;
};

using namespace MyDateFunction;
using namespace MyCmathFunction;
using namespace MyInputFunction;
using namespace MyPrintFunction;
using namespace MyArrayFunction;


namespace MyDateFunction
{
	bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&! IsDate1EqualDate2(Date1, Date2));
	}
	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}
	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1);
	}
	bool IsFirstDayInMonth(stDate Date)
	{
		return (Date.Day == 1);
	}

	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}
	stDate IncreaseDateByOneWeek(stDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		//last check day in date should not exceed max days in thecurrent month
			// example if date is 31/1/2022 increasing one month should notbe 31 / 2 / 2022, it should
			// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate IncreaseDateByXDays(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXMonths(short Months, stDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		return Date;
	}
	stDate IncreaseDateByXYears(short Years, stDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
	{
		Date.Year += Years;
		return Date;
	}
	stDate IncreaseDateByOneDecade(stDate Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}
	stDate IncreaseDateByXDecades(short Decade, stDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}
	stDate IncreaseDateByOneCentury(stDate Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}
	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}


	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			days[Month - 1];
	}

	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int PeriodLengthInDays(stPeriods Period, bool IncludeEndDate = false)
	{
		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
	}

	enDateCompare CompareDates(stDate Date1, stDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month,
					Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}
	stDate DecreaseDateByOneWeek(stDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;
		//last check day in date should not exceed max days in thecurrent month
			// example if date is 31/3/2022 decreasing one month should notbe 31 / 2 / 2022, it should
			// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate DecreaseDateByXDays(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXMonths(short Months, stDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		return Date;
	}
	stDate DecreaseDateByXYears(short Years, stDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
	{
		Date.Year -= Years;
		return Date;
	}
	stDate DecreaseDateByOneDecade(stDate Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}
	stDate DecreaseDateByXDecades(short Decade, stDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
	{
		Date.Year -= Decade * 10;
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	}
	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	}

}

namespace MyCmathFunction
{

	/*______________________declaration function_______________________________________*/
	enPositiveNegativeZero PositiveOrNegativeOrZeroInt(int);
	bool IsZero(int);
	bool IsPositive(int);
	bool IsPositive(float);
	bool IsPositive(short);
	bool IsPositive(double);
	bool IsPositive(long long);
	bool IsNegative(int);
	bool IsNegative(float);
	bool IsNegative(short);
	bool IsNegative(double);
	bool IsNegative(long long);
	bool isLeapYear(short Year);
	int ReverseNum(int);
	short ReverseNum(short);
	bool IsOdd(int);
	bool IsEven(int);
	bool IsPrime(int);
	bool IsPalindrome(int);
	bool IsPerfect(int);
	float FractionPart(float);
	float MyABS(float);
	float MySqrt(float);
	int MyCeil(float);
	int MyFloor(float);
	int MyRound(float);
	int RandomIntNum(int, int);
	int SumDigitsNum(int);
	float Half(float);
	int Opposite(int);
	float Opposite(float);
	short Opposite(short);
	double Opposite(double);
	long long Opposite(long long);
	void Swap(int&, int&);
	void Swap(float&, float&);
	void Swap(short&, short&);
	void Swap(double&, double&);
	void Swap(long long&, long long&);
	enPalindromNotPalindrom PalindromeNotPalindrome(int);
	enPrimeNotPrime PrimeNotPrime(int);
	enOddOrEven OddOrEven(int);
	enPerfectNotPerfect PerfectNotPerfect(int);
	int Sum(int, int, int, int, int);
	float Sum(float, float, float, float, float);
	short Sum(short, short, short, short, short);
	double Sum(double, double, double, double, double);
	long long Sum(long long, long long, long long, long long, long long);
	int Subtract(int, int, int, int, int);
	float Subtract(float, float, float, float, float);
	short Subtract(short, short, short, short, short);
	double Subtract(double, double, double, double, double);
	long long Subtract(long long, long long, long long, long long, long long);
	int Multiplicate(int, int, int, int, int);
	float Multiplicate(float, float, float, float, float);
	short Multiplicate(short, short, short, short, short);
	double Multiplicate(double, double, double, double, double);
	long long Multiplicate(long long, long long, long long, long long, long long);
	int Divide(int, int, int, int, int);
	float Divide(float, float, float, float, float);
	short Divide(short, short, short, short, short);
	double Divide(double, double, double, double, double);
	long long Divide(long long, long long, long long, long long, long long);
	int Mode2Num(int, int);
	short Mode2Num(short, short);
	long long Mode2Num(long long, long long);
	int Calculate2Num(int, int, enOperatorType);
	short Calculate2Num(short, short, enOperatorType);
	short NumberOfDaysInAMonth(short Month, short Year);

	/*_________________definition function____________________*/
	enPositiveNegativeZero PositiveOrNegativeOrZeroInt(int Number)
	{
		if (Number == 0)
			return enPositiveNegativeZero::Zero;
		else if (Number > 0)
			return enPositiveNegativeZero::Positive;
		else
			return enPositiveNegativeZero::Negative;
	}
	bool IsZero(int Number)
	{
		return (Number == 0);
	}
	bool IsPositive(int Number)
	{
		if (Number > 0)
			return 1;
		else
			return 0;
	}
	bool IsPositive(float Number)
	{
		if (Number > 0)
			return 1;
		else
			return 0;
	}
	bool IsPositive(short Number)
	{
		if (Number > 0)
			return 1;
		else
			return 0;
	}
	bool IsPositive(double Number)
	{
		if (Number > 0)
			return 1;
		else
			return 0;
	}
	bool IsPositive(long long Number)
	{
		if (Number > 0)
			return 1;
		else
			return 0;
	}
	bool IsNegative(int Number)
	{
		if (Number < 0)
			return 1;
		else
			return 0;
	}
	bool IsNegative(float Number)
	{
		if (Number < 0)
			return 1;
		else
			return 0;
	}
	bool IsNegative(short Number)
	{
		if (Number < 0)
			return 1;
		else
			return 0;
	}
	bool IsNegative(double Number)
	{
		if (Number < 0)
			return 1;
		else
			return 0;
	}
	bool IsNegative(long long Number)
	{
		if (Number < 0)
			return 1;
		else
			return 0;
	}
	bool isLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	int ReverseNum(int Number)
	{
		int Remainder = 0;
		int Reversed = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Reversed = Reversed * 10 + Remainder;
		}
		return Reversed;
	}
	short ReverseNum(short Number)
	{
		short Remainder = 0;
		short Reversed = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Reversed = Reversed * 10 + Remainder;
		}
		return Reversed;
	}
	bool IsOdd(int Number)
	{
		if (Number % 2 != 0)
			return 1;
		else
			return 0;
	}
	bool IsEven(int Number)
	{
		if (Number % 2 == 0)
			return 1;
		else
			return 0;
	}
	bool IsPrime(int Number)
	{
		int M = round(Number / 2);
		for (int counter = 2; counter <= M; counter++)
			if (Number % counter == 0)
				return 0;
		return 1;
	}
	bool IsPalindrome(int Number)
	{
		return (Number == ReverseNum(Number));
	}
	bool IsPerfect(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
			if (Number % i == 0)
				Sum += i;
		return Number == Sum;
	}
	float FractionPart(float Number)
	{
		return Number - int(Number);
	}
	float MyABS(float Number)
	{
		float ABS = (Number < 0) ? Number * -1 : Number;
		return ABS;
	}
	float MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}
	int MyCeil(float Number)
	{
		if (abs(FractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
			return Number;
	}
	int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}
	int MyRound(float Number)
	{
		int IntPart = int(Number);
		if (abs(FractionPart(Number)) >= .5)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}
		else
			return IntPart;
	}
	int RandomIntNum(int From, int To)
	{
		int RandomNumber = rand() % (To - From + 1) + From;
		return RandomNumber;
	}
	int SumDigitsNum(int Number)
	{
		int Remainder = 0;
		int Sum = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}
		return Sum;
	}
	float Half(float Num)
	{
		return (float)Num / 2;
	}
	int Opposite(int Number)
	{
		return Number * -1;
	}
	float Opposite(float Number)
	{
		return Number * -1;
	}
	short Opposite(short Number)
	{
		return Number * -1;
	}
	double Opposite(double Number)
	{
		return Number * -1;
	}
	long long Opposite(long long Number)
	{
		return Number * -1;
	}
	void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	void Swap(float& A, float& B)
	{
		float Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	void Swap(short& A, short& B)
	{
		short Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	void Swap(long long& A, long long& B)
	{
		long long Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	enPalindromNotPalindrom PalindromeNotPalindrome(int Number)
	{
		if (Number == ReverseNum(Number))
			return enPalindromNotPalindrom::Palindrom;
		else
			return enPalindromNotPalindrom::NotPalindrom;
	}
	enPrimeNotPrime PrimeNotPrime(int Number)
	{
		int M = round(Number / 2);
		for (int counter = 2; counter <= M; counter++)
			if (Number % counter == 0)
				return enPrimeNotPrime::NotPrime;
		return enPrimeNotPrime::Prime;
	}
	enOddOrEven OddOrEven(int Number)
	{
		if (Number % 2 != 0)
			return enOddOrEven::Odd;
		else
			return enOddOrEven::Even;

	}
	enPerfectNotPerfect PerfectNotPerfect(int Number)
	{
		int Sum = 0;
		int M = Number / 2;
		for (int Counter = 1; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
			{
				Sum += Counter;
				if (Sum == Number)
					return enPerfectNotPerfect::Perfect;
			}
		}
		return enPerfectNotPerfect::NotPerfect;
	}

	int Sum(int Num1, int Num2, int Num3 = 0, int Num4 = 0, int Num5 = 0)
	{
		return (Num1 + Num2 + Num3 + Num4 + Num5);
	}
	float Sum(float Num1, float Num2, float Num3 = 0, float Num4 = 0, float Num5 = 0)
	{
		return (Num1 + Num2 + Num3 + Num4 + Num5);
	}
	short Sum(short Num1, short Num2, short Num3 = 0, short Num4 = 0, short Num5 = 0)
	{
		return (Num1 + Num2 + Num3 + Num4 + Num5);
	}
	double Sum(double Num1, double Num2, double Num3 = 0, double Num4 = 0, double Num5 = 0)
	{
		return (Num1 + Num2 + Num3 + Num4 + Num5);
	}
	long long Sum(long long Num1, long long Num2, long long Num3 = 0, long long Num4 = 0, long long Num5 = 0)
	{
		return (Num1 + Num2 + Num3 + Num4 + Num5);
	}
	int Subtract(int Num1, int Num2, int Num3 = 0, int Num4 = 0, int Num5 = 0)
	{
		return (Num1 - Num2 - Num3 - Num4 - Num5);
	}
	float Subtract(float Num1, float Num2, float Num3 = 0, float Num4 = 0, float Num5 = 0)
	{
		return (Num1 - Num2 - Num3 - Num4 - Num5);
	}
	short Subtract(short Num1, short Num2, short Num3 = 0, short Num4 = 0, short Num5 = 0)
	{
		return  (Num1 - Num2 - Num3 - Num4 - Num5);
	}
	double Subtract(double Num1, double Num2, double Num3 = 0, double Num4 = 0, double Num5 = 0)
	{
		return (Num1 - Num2 - Num3 - Num4 - Num5);
	}
	long long Subtract(long long Num1, long long Num2, long long Num3 = 0, long long Num4 = 0, long long Num5 = 0)
	{
		return (Num1 - Num2 - Num3 - Num4 - Num5);
	}
	int Multiplicate(int Num1, int Num2, int Num3 = 1, int Num4 = 1, int Num5 = 1)
	{
		return (Num1 * Num2 * Num3 * Num4 * Num5);
	}
	float Multiplicate(float Num1, float Num2, float Num3 = 1, float Num4 = 1, float Num5 = 1)
	{
		return (Num1 * Num2 * Num3 * Num4 * Num5);
	}
	short Multiplicate(short Num1, short Num2, short Num3 = 1, short Num4 = 1, short Num5 = 1)
	{
		return (Num1 * Num2 * Num3 * Num4 * Num5);
	}
	double Multiplicate(double Num1, double Num2, double Num3 = 1, double Num4 = 1, double Num5 = 1)
	{
		return (Num1 * Num2 * Num3 * Num4 * Num5);
	}
	long long Multiplicate(long long Num1, long long Num2, long long  Num3 = 1, long long Num4 = 1, long long Num5 = 1)
	{
		return (Num1 * Num2 * Num3 * Num4 * Num5);
	}
	int Divide(int Num1, int Num2, int Num3 = 1, int Num4 = 1, int Num5 = 1)
	{
		return (Num1 / Num2 / Num2 / Num3 / Num4 / Num5);
	}
	float Divide(float Num1, float Num2, float Num3 = 1, float Num4 = 1, float Num5 = 1)
	{
		return (Num1 / Num2 / Num2 / Num3 / Num4 / Num5);
	}
	short Divide(short Num1, short Num2, short Num3 = 1, short Num4 = 1, short Num5 = 1)
	{
		return (Num1 / Num2 / Num2 / Num3 / Num4 / Num5);
	}
	double Divide(double Num1, double Num2, double Num3 = 1, double Num4 = 1, double Num5 = 1)
	{
		return (Num1 / Num2 / Num2 / Num3 / Num4 / Num5);
	}
	long long Divide(long long Num1, long long Num2, long long  Num3 = 1, long long Num4 = 1, long long Num5 = 1)
	{
		return (Num1 / Num2 / Num2 / Num3 / Num4 / Num5);
	}
	int Mode2Num(int Num1, int Num2)
	{
		return Num1 % Num2;
	}
	short Mode2Num(short Num1, short Num2)
	{
		return Num1 % Num2;
	}
	long long Mode2Num(long long Num1, long long Num2)
	{
		return Num1 % Num2;
	}
	int Calculate2Num(int Num1, int Num2, enOperatorType OpType)
	{
		switch (OpType)
		{
		case enOperatorType::Add:
			return (Num1 + Num2);
		case enOperatorType::Sub:
			return (Num1 - Num2);
		case enOperatorType::Mul:
			return (Num1 * Num2);
		case enOperatorType::Div:
			return (Num1 / Num2);
		case enOperatorType::Mode:
			return (Num1 % Num2);
		default:
			return (Num1 + Num2);
		}
	}
	short Calculate2Num(short Num1, short Num2, enOperatorType OpType)
	{
		switch (OpType)
		{
		case enOperatorType::Add:
			return (Num1 + Num2);
		case enOperatorType::Sub:
			return (Num1 - Num2);
		case enOperatorType::Mul:
			return (Num1 * Num2);
		case enOperatorType::Div:
			return (Num1 / Num2);
		case enOperatorType::Mode:
			return (Num1 % Num2);
		default:
			return (Num1 + Num2);
		}
	}
	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
	}

}

namespace MyInputFunction
{
	/*___________________declaration function _______________________*/
	short VerifyNum(short);
	int VerifyNum(int);
	float VerifyNum(float);
	double VerifyNum(double);
	long long VerifyNum(long long);
	int ReadIntNumber(string);
	float ReadFloatNumber(string);
	short ReadShortNumber(string);
	double ReadDoubleNumber(string);
	long long ReadLongLongNumber(string);
	bool ReadBoolean(string);
	string ReadString(string);
	char ReadCharacter(string);
	int ReadNumberInRange(string, int, int);
	float ReadNumberInRange(string, float, float);
	short ReadNumberInRange(string, short, short);
	double ReadNumberInRange(string, double, double);
	long long ReadNumberInRange(string, long long, long long);
	int ReadPositiveIntNumber(string);
	float ReadPositiveFloatNumber(string);
	short ReadPositiveShortNumber(string);
	double ReadPositiveDoubleNumber(string);
	long long ReadPositiveLongLongNumber(string);
	int ReadNegativeIntNumber(string);
	float ReadNegativeFloatNumber(string);
	short ReadNegativeShortNumber(string);
	double ReadNegativeDoubleNumber(string);
	long long ReadNegativeLongLongNumber(string);
	enOperatorType ReadOperationType();
	void ReadArrayOfNumber(int[], int);
	void ReadArrayOfNumber(float[], int);
	void ReadArrayOfNumber(short[], int);
	void ReadArrayOfNumber(double[], int);
	void ReadArrayOfNumber(long long[], int);
	void ReadArrayOfCharacter(char[], int);
	void ReadArrayOfString(string[], int);
	int ReadOddNumber();
	int ReadEvenNumber();
	int ReadPerfectNumber();
	int ReadPalindromeNum();
	enLevel ReadQuestionLevel();

	/*__________definition function_____________________________*/

	short VerifyNum(short Number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	int VerifyNum(int Number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	float VerifyNum(float Number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	double VerifyNum(double Number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	long long VerifyNum(long long Number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}

	int ReadIntNumber(string Message)
	{
		int MyIntNumber;
		cout << Message << ": ";
		cin >> MyIntNumber;
		return VerifyNum(MyIntNumber);
	}
	float ReadFloatNumber(string Message)
	{
		float MyFloatNumber;
		cout << Message << ": " << endl;
		cin >> MyFloatNumber;
		return VerifyNum(MyFloatNumber);
	}
	short ReadShortNumber(string Message)
	{
		short MyShortNumber;
		cout << Message << ": " << endl;
		cin >> MyShortNumber;
		return VerifyNum(MyShortNumber);
	}
	double ReadDoubleNumber(string Message)
	{
		double MyDoubleNumber;
		cout << Message << " : " << endl;
		cin >> MyDoubleNumber;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
			cout << Message << " : " << endl;
			cin >> MyDoubleNumber;
		}
		return VerifyNum(MyDoubleNumber);
	}
	long long ReadLongLongNumber(string Message)
	{
		long long MyLongLongNumber;
		cout << Message << ": " << endl;
		cin >> MyLongLongNumber;
		return VerifyNum(MyLongLongNumber);
	}
	bool ReadBoolean(string Message)
	{
		bool MyBoolean;
		cout << Message << " (Answer with 1 or 0) " << endl;
		cin >> MyBoolean;
		return MyBoolean;
	}
	string ReadString(string Message)
	{
		string MyString;
		cout <<"\n" << Message << " : \n";
		getline(cin, MyString);
		return MyString;
	}
	char ReadCharacter(string Message)
	{
		char MyCharacter;
		cout <<"\n" << Message << " : \n";
		cin >> MyCharacter;
		return MyCharacter;
	}
	int ReadNumberInRange(string Message, int From, int To)
	{
		int NumberInRange;
		do
		{
			cout << Message << " From " << From << " To " << To << " : ";
			cin >> NumberInRange;
			VerifyNum(NumberInRange);
		} while (NumberInRange<From || NumberInRange>To);
		return NumberInRange;
	}
	float ReadNumberInRange(string Message, float From, float To)
	{
		float NumberInRange;
		do
		{
			cout << Message << " From " << From << " To " << To << " : ";
			cin >> NumberInRange;
			VerifyNum(NumberInRange);
		} while (NumberInRange<From || NumberInRange>To);
		return NumberInRange;
	}
	short ReadNumberInRange(string Message, short From, short To)
	{
		short ShortNumInRange;
		do
		{
			cout << Message << " (Enter number From " << From << " To " << To << " : ";
			cin >> ShortNumInRange;
			VerifyNum(ShortNumInRange);
		} while (ShortNumInRange<From || ShortNumInRange>To);
		return ShortNumInRange;
	}
	double ReadNumberInRange(string Message, double From, double To)
	{
		double DoublebNumInRange;
		do
		{
			cout << Message << " (Enter number From " << From << " To " << To << " : ";
			cin >> DoublebNumInRange;
			VerifyNum(DoublebNumInRange);
		} while (DoublebNumInRange<From || DoublebNumInRange>To);
		return DoublebNumInRange;
	}
	long long ReadNumberInRange(string Message, long long From, long long To)
	{
		long long LgLgNumInRange;
		do
		{
			cout << Message << " (Enter number From " << From << " To " << To << " : ";
			cin >> LgLgNumInRange;
			VerifyNum(LgLgNumInRange);
		} while (LgLgNumInRange<From || LgLgNumInRange>To);
		return LgLgNumInRange;
	}
	int ReadPositiveIntNumber(string Message)
	{
		int PositiveIntNumber;
		do
		{
			cout << Message << endl;
			cin >> PositiveIntNumber;
			VerifyNum(PositiveIntNumber);
		} while (PositiveIntNumber <= 0);
		return PositiveIntNumber;
	}
	float ReadPositiveFloatNumber(string Message)
	{
		float FloatPositiveNumber;
		do
		{
			cout << Message << endl;
			cin >> FloatPositiveNumber;
			VerifyNum(FloatPositiveNumber);
		} while (FloatPositiveNumber <= 0);
		return FloatPositiveNumber;
	}
	short ReadPositiveShortNumber(string Message)
	{
		short ShortPositiveNumber;
		do
		{
			cout << Message << endl;
			cin >> ShortPositiveNumber;
			VerifyNum(ShortPositiveNumber);
		} while (ShortPositiveNumber <= 0);
		return ShortPositiveNumber;
	}
	double ReadPositiveDoubleNumber(string Message)
	{
		double DoublePositiveNumber;
		do
		{
			cout << Message << (" !(enter just positive Number): ") << endl;
			cin >> DoublePositiveNumber;
			VerifyNum(DoublePositiveNumber);
		} while (DoublePositiveNumber <= 0);
		return DoublePositiveNumber;
	}
	long long ReadPositiveLongLongNumber(string Message)
	{
		long long LgLgPositiveNum;
		do
		{
			cout << Message << (" !(just enter positive Number): ") << endl;
			cin >> LgLgPositiveNum;
			VerifyNum(LgLgPositiveNum);
		} while (LgLgPositiveNum <= 0);
		return LgLgPositiveNum;
	}
	int ReadNegativeIntNumber(string Message)
	{
		int NegativeIntNumber;
		do
		{
			cout << Message << (" !(just enter Negative Number): ") << endl;
			cin >> NegativeIntNumber;
			VerifyNum(NegativeIntNumber);
		} while (NegativeIntNumber >= 0);
		return NegativeIntNumber;
	}
	float ReadNegativeFloatNumber(string Message)
	{
		float NegativeFloatNumber;
		do
		{
			cout << Message << (" !(just enter Negative Number): ") << endl;
			cin >> NegativeFloatNumber;
			VerifyNum(NegativeFloatNumber);
		} while (NegativeFloatNumber >= 0);
		return NegativeFloatNumber;
	}
	short ReadNegativeShortNumber(string Message)
	{
		short NegativeShortNumber;
		do
		{
			cout << Message << endl;
			cin >> NegativeShortNumber;
			VerifyNum(NegativeShortNumber);
		} while (NegativeShortNumber >= 0);
		return NegativeShortNumber;
	}
	double ReadNegativeDoubleNumber(string Message)
	{
		double NegativeDoubleNumber;
		do
		{
			cout << Message << (" !(just enter Negative Number): ") << endl;
			cin >> NegativeDoubleNumber;
			VerifyNum(NegativeDoubleNumber);
		} while (NegativeDoubleNumber >= 0);
		return NegativeDoubleNumber;
	}
	long long ReadNegativeLongLongNumber(string Message)
	{
		long long NegativeLgLgNumber;
		do
		{
			cout << Message << endl;
			cin >> NegativeLgLgNumber;
			VerifyNum(NegativeLgLgNumber);
		} while (NegativeLgLgNumber >= 0);
		return NegativeLgLgNumber;
	}
	enOperatorType ReadOperationType()
	{
		short OperatorType = 1;
		do
		{
			cout << "\nEnter Operation Type ass menu number Add[1] , Sub[2], Mul[3] ,Div[4] ,Mode[5] : ";
			cin >> OperatorType;
			VerifyNum(OperatorType);
		} while (OperatorType < 1 || OperatorType> 5);
		return (enOperatorType)OperatorType;
	}
	void ReadArrayOfNumber(int arr[], int arrLength)
	{
		cout << "\nEnter array elements \n\n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
			VerifyNum(arr[i]);
		}
	}
	void ReadArrayOfNumber(float arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
			VerifyNum(arr[i]);
		}
		cout << endl;
	}
	void ReadArrayOfNumber(short arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
			VerifyNum(arr[i]);
		}
		cout << endl;
	}
	void ReadArrayOfNumber(double arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
			VerifyNum(arr[i]);
		}
		cout << endl;
	}
	void ReadArrayOfNumber(long long arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
			VerifyNum(arr[i]);
		}
		cout << endl;
	}
	void ReadArrayOfCharacter(char arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}
	void ReadArrayOfString(string arr[], int arrLength)
	{
		cout << "\n enter array elements \n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			getline(cin, arr[i]);
		}
		cout << endl;
	}
	int ReadOddNumber()
	{
		int OddNumber;
		do
		{
			cout << "\nEnter odd number : ";
			cin >> OddNumber;
			VerifyNum(OddNumber);
		} while (!MyCmathFunction::IsOdd(OddNumber));
		return OddNumber;
	}
	int ReadEvenNumber()
	{
		int EvenNumber;
		do
		{
			cout << "\nenter Even number : ";
			cin >> EvenNumber;
			VerifyNum(EvenNumber);
		} while (!MyCmathFunction::IsEven(EvenNumber));
		return EvenNumber;
	}
	int ReadPerfectNumber()
	{
		int PerfectNumber;
		do
		{
			cout << "\nEnter Perfect number : ";
			cin >> PerfectNumber;
			VerifyNum(PerfectNumber);
		} while (!MyCmathFunction::IsPerfect(PerfectNumber));
		return PerfectNumber;
	}
	int ReadPalindromeNum()
	{
		int PalindromeNum;
		do
		{
			cout << "\nEnter Palindrome number : ";
			cin >> PalindromeNum;
			VerifyNum(PalindromeNum);
		} while (!MyCmathFunction::IsPalindrome(PalindromeNum));
		return PalindromeNum;
	}
	enLevel ReadQuestionLevel()
	{
		short QuestionLevel = 1;
		do
		{
			cout << " Enter Question level Easy[1], Med[2],Hard[3]: ";
			cin >> QuestionLevel;
			VerifyNum(QuestionLevel);
		} while (QuestionLevel < 1 || QuestionLevel > 3);
		return (enLevel)QuestionLevel;
	}


}

namespace MyPrintFunction
{
	/*_____________________declaration function _________________________*/
	void Print(string);
	string UpperAllString(string);
	string LowerAllString(string);
	char RandomCharacter(enCaracterType);
	void PrintDigitNum(int);
	void PrintRandomNumbers(int, int, int);
	void PrintPrimeNumbers(int, int);
	void PrintOddNumbers(int, int);
	void PrintEvenNumbers(int, int);
	void PrintPalindromeNums(int, int);
	void PrintPerfectNumbers(int, int);
	string Tabs(int);
	string BackSlashN(int);
	string Ring(int);
	string EncryptText(string, int);
	string DecryptText(string, int);
	string GenerateWord(enCaracterType, int);
	string GenerateKey();
	void GenerateKeys(int);
	void ResetScreen();
	char OperationTypeCaracter(enOperatorType);
	string LevelText(enLevel);
	string WinOrFaiLText(bool);
	void SetScreenColor(bool);
	void PrintGameResults();
	void ShowGameOverScreen();

	/*_______________definition function ________________________ */
	void Print(string Text)
	{
		cout << Text;
	}
	string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	char RandomCharacter(enCaracterType CaracterType)
	{
		switch (CaracterType)
		{
		case enCaracterType::SmallLetter:
			return char(MyCmathFunction::RandomIntNum(97, 122));
			break;
		case enCaracterType::Capitalletter:
			return char(MyCmathFunction::RandomIntNum(65, 90));
			break;
		case enCaracterType::SpecialChar:
			return char(MyCmathFunction::RandomIntNum(33, 47));
			break;
		case enCaracterType::Degit:
			return char(MyCmathFunction::RandomIntNum(48, 57));
			break;
		}
	}
	void PrintDigitNum(int Number)
	{
		int ReverceOfNumber = MyCmathFunction::ReverseNum(Number);
		while (ReverceOfNumber > 0)
		{
			int Remainder = 0;
			Remainder = ReverceOfNumber % 10;
			ReverceOfNumber = ReverceOfNumber / 10;
			cout << Remainder << endl;
		}
	}
	void PrintRandomNumbers(int HowManyNumbers, int From, int To)
	{
		for (int i = 0; i < HowManyNumbers; i++)
			cout << MyCmathFunction::RandomIntNum(From, To) << " ";
		cout << endl;
	}
	void PrintPrimeNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (MyCmathFunction::PrimeNotPrime(i) == enPrimeNotPrime::Prime)
				cout << i << " ";
		cout << endl;
	}
	void PrintOddNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (MyCmathFunction::OddOrEven(i) == enOddOrEven::Odd)
				cout << i << " ";
		cout << endl;
	}
	void PrintEvenNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (MyCmathFunction::OddOrEven(i) == enOddOrEven::Even)
				cout << i << " ";
		cout << endl;
	}
	void PrintPalindromeNums(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (MyCmathFunction::PalindromeNotPalindrome(i) == enPalindromNotPalindrom::Palindrom)
				cout << i << " ";
		cout << endl;
	}
	void PrintPerfectNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (MyCmathFunction::PerfectNotPerfect(i) == enPerfectNotPerfect::Perfect)
				cout << i << " ";
		cout << endl;
	}
	string Tabs(int NumberOfTabs)
	{
		string Tab = "";
		for (int i = 1; i <= NumberOfTabs; i++)
			Tab += "\t";
		return Tab;
	}
	string BackSlashN(int NumberOfBackSlashN)
	{
		string BackSlash = "";
		for (int i = 1; i <= NumberOfBackSlashN; i++)
			BackSlash += "\n";
		return BackSlash;
	}
	string Ring(int NumberOfRing)
	{
		string Ring = "";
		for (int i = 1; i <= NumberOfRing; i++)
			Ring += "\a";
		return Ring;
	}
	string EncryptText(string text, int EncriptedKey)
	{
		for (int i = 0; i <= text.length(); i++)
			text[i] = char((int)text[i] + EncriptedKey);
		return text;
	}
	string DecryptText(string text, int EncriptedKey)
	{
		for (int i = 0; i <= text.length(); i++)
			text[i] = char((int)text[i] - EncriptedKey);
		return text;
	}
	string GenerateWord(enCaracterType CaracterType, int lenght)
	{
		string Word = "";
		for (int i = 1; i <= lenght; i++)
			Word = Word + MyPrintFunction::RandomCharacter(CaracterType);
		return Word;
	}
	string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCaracterType::Capitalletter, 4) + "-";
		Key = Key + GenerateWord(enCaracterType::Capitalletter, 4) + "-";
		Key = Key + GenerateWord(enCaracterType::Capitalletter, 4) + "-";
		Key = Key + GenerateWord(enCaracterType::Capitalletter, 4);
		return Key;
	}
	void GenerateKeys(int NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}
	void ResetScreen()
	{
		system("cls");
		system("color 0F");
	}
	char OperationTypeCaracter(enOperatorType OpType)
	{
		char arrOperationType[5] = { '+','-','*','/','%' };
		return arrOperationType[OpType - 1];
	}
	string LevelText(enLevel QuestionLevel)
	{
		string arrQuestionLvel[3] = { "Easy","Med","Hard" };
		return arrQuestionLvel[QuestionLevel - 1];
	}
	string WinOrFaiLText(bool IsWin)
	{
		if (IsWin)
			return " Win :-) \n";
		else
			" Fail :-( \n";
	}
	void SetScreenColor(bool IsCorrect)
	{
		if (IsCorrect)
		{
			system("color 2F");//green screen color

		}
		else
		{
			system("color 4F");//red screen color
			cout << "\a";
		}
	}
	void PrintGameResults()
	{
		cout << Tabs(2) << "______________________________________________________  \n";
		cout << Tabs(2) << "                   +++ Game Result +++ \n";
		cout << Tabs(2) << "--------------------------------------------------------\n\n";
	}
	void ShowGameOverScreen()
	{
		cout << "\n\n____________________________________________________________\n";
		cout << "                    + + + G a m e O v e r + + +                   \n";
		cout << "___________________________________________________________________\n\n";
	}


}

namespace MyArrayFunction
{
	/*______________declaration function_________________________*/
	void PrintArrayOfNumber(int[], int);
	void PrintArrayOfNumber(float[], int);
	void PrintArrayOfNumber(short[], int);
	void PrintArrayOfString(string[], int);
	void PrintArrayOfCharacter(char[], int);
	void PrintArrayOfNumber(double[], int);
	void PrintArrayOfNumber(long long[], int);
	int CountOddNumberInArray(int[], int);
	int CountEvenNumberInArray(int[], int);
	int CountPositiveNumberInArray(int[], int);
	int CountNegativeNumberInArray(int[], int);
	int CountDigitFrequency(int, int);
	int MaxNumberInArray(int[], int);
	float MaxNumberInArray(float[], int);
	short MaxNumberInArray(short[], int);
	double MaxNumberInArray(double[], int);
	long long MaxNumberInArray(long long[], int);
	int MinNumberInArray(int[], int);
	float MinNumberInArray(float[], int);
	short MinNumberInArray(short[], int);
	double MinNumberInArray(double[], int);
	long long MinNumberInArray(long long[], int);
	void ShuffleArrayOfNumber(int[], int);
	void FillArrayWithRandomNumber(int[], int&, int, int);
	void FillArrayWithOddNumber(int[], int&);
	void FillArrayWithEvenNumber(int[], int&);
	void AddNumberInArray(int, int[], int&);
	void AddNumberInArray(float, float[], int&);
	void AddNumberInArray(short, short[], int&);
	void AddNumberInArray(double, double[], int&);
	void AddNumberInArray(long long, long long[], int&);
	void AddCharacterInArray(char, char[], int&);
	void AddStringInArray(string, string[], int&);
	void CopyArray(int[], int[], int);
	void CopyArray(float[], float[], int);
	void CopyArray(short[], short[], int);
	void CopyArray(double[], double[], int);
	void CopyArray(long long[], long long[], int);
	void CopyArray(char[], char[], int);
	void CopyArray(string[], string[], int);
	void AddDistainctNumberToArray(int[], int[], int&);
	void AddDistainctNumberToArray(float[], float[], int&);
	void AddDistainctNumberToArray(short[], short[], int&);
	void AddDistainctNumberToArray(int[], double[], int&);
	void AddDistainctNumberToArray(long long[], long long[], int&);
	void CopyArrayUsingAddNumber(int[], int[], int, int&);
	void CopyPrimeNumbers(int[], int[], int, int&);
	void CopyOddNumbers(int[], int[], int, int&);
	void CopyEvenNumbers(int[], int[], int, int&);
	void CopyPerfectNumbers(int[], int[], int, int&);
	void CopyPalindromNumbers(int[], int[], int, int&);
	short FindPositionOfNumberInArray(int, int[], int);
	bool IsNumberInArray(int, int[], int);
	bool IsNumberInArray(float, float[], int);
	bool IsNumberInArray(short, short[], int);
	bool IsNumberInArray(double, double[], int);
	bool IsNumberInArray(long long, long long[], int);
	bool IsCharacterInArray(char, char[], int);
	bool IsStringInArray(string, string[], int);
	int TimesNumberRepeatedInArray(int, int[], int);
	int TimesNumberRepeatedInArray(float, float[], int);
	int TimesNumberRepeatedInArray(short, short[], int);
	int TimesNumberRepeatedInArray(double, double[], int);
	int TimesNumberRepeatedInArray(long long, long long[], int);
	int TimesCharacterRepeatedInArray(char, char[], int);
	int TimesTextRepeatedInArray(string, string[], int);
	void Sum2Arrays(int[], int[], int[], int);
	void Sum2Arrays(float[], float[], float[], int);
	void Sum2Arrays(short[], short[], short[], int);
	void Sum2Arrays(double[], double[], double[], int);
	void Sum2Arrays(long long[], long long[], long long[], int);
	int SumArrayNumbers(int[], int);
	float SumArrayNumbers(float[], int);
	short SumArrayNumbers(short[], int);
	double SumArrayNumbers(double[], int);
	long long SumArrayNumbers(long long[], int);
	float AverageArrayNumbers(int[], int);
	float AverageArrayNumbers(float[], int);
	float AverageArrayNumbers(short[], int);
	float AverageArrayNumbers(double[], int);
	float AverageArrayNumbers(long long[], int);


	/*__________________definition function_______________________*/
	void PrintArrayOfNumber(int arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfNumber(float arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfNumber(short arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfString(string  arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfCharacter(char  arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfNumber(double arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void PrintArrayOfNumber(long long arr[], int arrLenght)
	{
		for (int i = 0; i < arrLenght; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	int CountOddNumberInArray(int arrSource[], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (MyCmathFunction::IsOdd(arrSource[i]))
				Counter++;
		return Counter;
	}
	int CountEvenNumberInArray(int arrSource[], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (MyCmathFunction::IsEven(arrSource[i]))
				Counter++;
		return Counter;
	}
	int CountPositiveNumberInArray(int arrSource[], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (MyCmathFunction::IsPositive(arrSource[i]))
				Counter++;
		return Counter;
	}
	int CountNegativeNumberInArray(int arrSource[], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (MyCmathFunction::IsNegative(arrSource[i]))
				Counter++;
		return Counter;
	}
	int CountDigitFrequency(int DigitToCheck, int Number)
	{

		int Remainder = 0, FreqCount = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			if (DigitToCheck == Remainder)
				FreqCount++;
		}
		return FreqCount;
	}
	int MaxNumberInArray(int arr[], int arrLength)
	{
		int MaxNumber = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > MaxNumber)
				MaxNumber = arr[i];
		return MaxNumber;
	}
	float MaxNumberInArray(float arr[], int arrLength)
	{
		float MaxNumber = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > MaxNumber)
				MaxNumber = arr[i];
		return MaxNumber;
	}
	short MaxNumberInArray(short arr[], int arrLength)
	{
		int MaxNumber = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > MaxNumber)
				MaxNumber = arr[i];
		return MaxNumber;
	}
	double MaxNumberInArray(double arr[], int arrLength)
	{
		double MaxNumber = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > MaxNumber)
				MaxNumber = arr[i];
		return MaxNumber;
	}
	long long MaxNumberInArray(long long arr[], int arrLength)
	{
		long long MaxNumber = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > MaxNumber)
				MaxNumber = arr[i];
		return MaxNumber;
	}
	int MinNumberInArray(int arr[], int arrLength)
	{
		int Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < Min)
				Min = arr[i];
		return Min;
	}
	float MinNumberInArray(float arr[], int arrLength)
	{
		float Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < Min)
				Min = arr[i];
		return Min;
	}
	short MinNumberInArray(short arr[], int arrLength)
	{
		short Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < Min)
				Min = arr[i];
		return Min;
	}
	double MinNumberInArray(double arr[], int arrLength)
	{
		double Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < Min)
				Min = arr[i];
		return Min;
	}
	long long MinNumberInArray(long long arr[], int arrLength)
	{
		long long Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < Min)
				Min = arr[i];
		return Min;
	}
	void ShuffleArrayOfNumber(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			MyCmathFunction::Swap(arr[MyCmathFunction::RandomIntNum(1, arrLength) - 1], arr[MyCmathFunction::RandomIntNum(1, arrLength) - 1]);
	}
	void FillArrayWithRandomNumber(int arr[], int& arrLength, int From, int To)
	{
		cout << "\n Enter array length \n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = MyCmathFunction::RandomIntNum(From, To);
	}
	void FillArrayWithOddNumber(int Oddarr[], int& arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			Oddarr[i] = MyInputFunction::ReadOddNumber();
	}
	void FillArrayWithEvenNumber(int Evenarr[], int& arrLength)
	{
		for (int j = 0; j < arrLength; j++)
			Evenarr[j] = MyInputFunction::ReadEvenNumber();
	}
	void AddNumberInArray(int Number, int arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Number; }
	void AddNumberInArray(float Number, float arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Number; }
	void AddNumberInArray(short Number, short arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Number; }
	void AddNumberInArray(double Number, double arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Number; }
	void AddNumberInArray(long long Number, long long arr[], int& arrLength)
	{
		arrLength++;
		arr[arrLength - 1] = Number;
	}
	void AddCharacterInArray(char Character, char arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Character; }
	void AddStringInArray(string Text, string arr[], int& arrLength) { arrLength++; arr[arrLength - 1] = Text; }
	void CopyArray(int arrSource[], int arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(float arrSource[], float arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(short arrSource[], short arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(double arrSource[], double arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(long long arrSource[], long long arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(char arrSource[], char arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void CopyArray(string arrSource[], string arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	void AddDistainctNumberToArray(int arrtest[], int arrdistinct[], int& arr2Length)
	{
		for (int i = 0; i < 9; i++)
			if (arrtest[i] != arrtest[i + 1])
				AddNumberInArray(arrtest[i], arrdistinct, arr2Length);
	}
	void AddDistainctNumberToArray(float arrtest[], float arrdistinct[], int& arr2Length)
	{
		for (int i = 0; i < 9; i++)
			if (arrtest[i] != arrtest[i + 1])
				AddNumberInArray(arrtest[i], arrdistinct, arr2Length);
	}
	void AddDistainctNumberToArray(short arrtest[], short arrdistinct[], int& arr2Length)
	{
		for (int i = 0; i < 9; i++)
			if (arrtest[i] != arrtest[i + 1])
				AddNumberInArray(arrtest[i], arrdistinct, arr2Length);
	}
	void AddDistainctNumberToArray(int arrtest[], double arrdistinct[], int& arr2Length)
	{
		for (int i = 0; i < 9; i++)
			if (arrtest[i] != arrtest[i + 1])
				AddNumberInArray(arrtest[i], arrdistinct, arr2Length);
	}
	void AddDistainctNumberToArray(long long arrtest[], long long arrdistinct[], int& arr2Length)
	{
		for (int i = 0; i < 9; i++)
			if (arrtest[i] != arrtest[i + 1])
				AddNumberInArray(arrtest[i], arrdistinct, arr2Length);
	}
	void CopyArrayUsingAddNumber(int arrSource[], int arrDestination[], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			AddNumberInArray(arrSource[i], arrDestination, arrDestinationLength);
	}
	void CopyPrimeNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (MyCmathFunction::PrimeNotPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	void CopyOddNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (MyCmathFunction::OddOrEven(arrSource[i]) == enOddOrEven::Odd)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	void CopyEvenNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (MyCmathFunction::OddOrEven(arrSource[i]) == enOddOrEven::Even)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	void CopyPerfectNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (MyCmathFunction::PerfectNotPerfect(arrSource[i]) == enPerfectNotPerfect::Perfect)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	void CopyPalindromNumbers(int arrSource[], int arrDestination[], int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (MyCmathFunction::PalindromeNotPalindrome(arrSource[i]) == enPalindromNotPalindrom::Palindrom)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	short FindPositionOfNumberInArray(int Number, int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == Number)
				return i;
		return -1;
	}
	bool IsNumberInArray(int Number, int arr[], int arrLength)
	{
		return FindPositionOfNumberInArray(Number, arr, arrLength) != -1;
	}
	bool IsNumberInArray(float NumberToCheck, float arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == NumberToCheck)
				return 1;
		}
		return 0;
	}
	bool IsNumberInArray(short NumberToCheck, short arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == NumberToCheck)
				return 1;
		}
		return 0;
	}
	bool IsNumberInArray(double NumberToCheck, double arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == NumberToCheck)
				return 1;
		}
		return 0;
	}
	bool IsNumberInArray(long long NumberToCheck, long long arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == NumberToCheck)
				return 1;
		return 0;
	}
	bool IsCharacterInArray(char CharacterToCheck, char arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == CharacterToCheck)
				return 1;
		return 0;
	}
	bool IsStringInArray(string TextToCheck, string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == TextToCheck)
				return 1;
		return 0;
	}
	int TimesNumberRepeatedInArray(int Number, int arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Number == arr[i])
				count++;
		return count;
	}
	int TimesNumberRepeatedInArray(float Number, float arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Number == arr[i])
				count++;
		return count;

	}
	int TimesNumberRepeatedInArray(short Number, short arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Number == arr[i])
				count++;
		return count;

	}
	int TimesNumberRepeatedInArray(double Number, double arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Number == arr[i])
				count++;
		return count;

	}
	int TimesNumberRepeatedInArray(long long Number, long long arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Number == arr[i])
				count++;
		return count;

	}
	int TimesCharacterRepeatedInArray(char Caracter, char arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Caracter == arr[i])
				count++;
		return count;

	}
	int TimesTextRepeatedInArray(string Text, string arr[], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
			if (Text == arr[i])
				count++;
		return count;

	}
	void Sum2Arrays(int arr[], int arr2[], int arr3[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr3[i] = arr[i] + arr2[i];
	}
	void Sum2Arrays(float arr[], float arr2[], float arr3[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr3[i] = arr[i] + arr2[i];
	}
	void Sum2Arrays(short arr[], short arr2[], short arr3[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr3[i] = arr[i] + arr2[i];
	}
	void Sum2Arrays(double arr[], double arr2[], double arr3[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr3[i] = arr[i] + arr2[i];
	}
	void Sum2Arrays(long long arr[], long long arr2[], long long arr3[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr3[i] = arr[i] + arr2[i];
	}
	int SumArrayNumbers(int arr[], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += arr[i];
		return Sum;
	}
	float SumArrayNumbers(float arr[], int arrLength)
	{
		float Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += arr[i];
		return Sum;
	}
	short SumArrayNumbers(short arr[], int arrLength)
	{
		short Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += arr[i];
		return Sum;
	}
	double SumArrayNumbers(double arr[], int arrLength)
	{
		double Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += arr[i];
		return Sum;
	}
	long long SumArrayNumbers(long long arr[], int arrLength)
	{
		long long Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += arr[i];
		return Sum;
	}
	float AverageArrayNumbers(int arr[], int arrLength) { return (float)SumArrayNumbers(arr, arrLength) / arrLength; }
	float AverageArrayNumbers(float arr[], int arrLength) { return (float)SumArrayNumbers(arr, arrLength) / arrLength; }
	float AverageArrayNumbers(short arr[], int arrLength) { return (float)SumArrayNumbers(arr, arrLength) / arrLength; }
	float AverageArrayNumbers(double arr[], int arrLength) { return (float)SumArrayNumbers(arr, arrLength) / arrLength; }
	float AverageArrayNumbers(long long arr[], int arrLength) { return (float)SumArrayNumbers(arr, arrLength) / arrLength; }



}