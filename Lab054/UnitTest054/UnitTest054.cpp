#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
// Підключи файл з розв'язком (змін ім'я папки і файлу на свої, якщо інші)
#include "../Lab054/Lab054.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	// Відносна похибка: значення добутку ~1e-23, тому абсолютну похибку брати не можна
	static bool close(const double a, const double b, const double rel = 1e-12)
	{
		return fabs(a - b) <= rel * fabs(b);
	}

	TEST_CLASS(UnitTest54)
	{
	public:

		// Контрольне значення добутку для K = 1, N = 15
		// (обчислено окремо, поза програмою)
		TEST_METHOD(S0_IterativeMatchesReference)
		{
			const double expected = 8.789229557202994e-23;
			Assert::IsTrue(close(S0(1, 15), expected));
		}

		// Один множник: sin^2(1) + cos^2(1) = 1, ділене на 1*1
		TEST_METHOD(S0_SingleFactorIsOne)
		{
			Assert::IsTrue(close(S0(1, 1), 1.0));
		}

		// Один множник при i = 2, формула написана тут окремо від програми
		TEST_METHOD(S0_SingleFactorI2)
		{
			const double expected = (sin(2.0) * sin(2.0) + cos(0.5) * cos(0.5)) / 4.0;
			Assert::IsTrue(close(S0(2, 2), expected));
		}

		// Порожній діапазон K > N: добуток нічого не множить, результат 1
		TEST_METHOD(S0_EmptyRangeIsOne)
		{
			Assert::AreEqual(1.0, S0(5, 3));
		}

		// Підйом, параметр зростає
		TEST_METHOD(S1_RecursionUpIncreasing)
		{
			Assert::IsTrue(close(S1(1, 15, 1), S0(1, 15)));
		}

		// Підйом, параметр спадає
		TEST_METHOD(S2_RecursionUpDecreasing)
		{
			Assert::IsTrue(close(S2(1, 15, 15), S0(1, 15)));
		}

		// Спуск, параметр зростає (початкове t = 1, не 0)
		TEST_METHOD(S3_RecursionDownIncreasing)
		{
			Assert::IsTrue(close(S3(1, 15, 1, 1), S0(1, 15)));
		}

		// Спуск, параметр спадає (початкове t = 1, не 0)
		TEST_METHOD(S4_RecursionDownDecreasing)
		{
			Assert::IsTrue(close(S4(1, 15, 15, 1), S0(1, 15)));
		}

		// Усі п'ять способів мають збігатися (вимога умови завдання)
		TEST_METHOD(AllFiveMethodsAgree)
		{
			const double ref = S0(1, 15);
			Assert::IsTrue(close(S1(1, 15, 1), ref));
			Assert::IsTrue(close(S2(1, 15, 15), ref));
			Assert::IsTrue(close(S3(1, 15, 1, 1), ref));
			Assert::IsTrue(close(S4(1, 15, 15, 1), ref));
		}
	};
}