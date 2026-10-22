#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab055/Lab055.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
	TEST_CLASS(UnitTest55)
	{
	public:

		// Базовий випадок Q(1, n) = 1
		TEST_METHOD(Q_BaseCase_M_Equals_1)
		{
			int depth = 0;
			Assert::AreEqual(1, Q(1, 5, 1, depth));
			Assert::AreEqual(1, depth); 
		}

		// Базовий випадок Q(m, 1) = 1
		TEST_METHOD(Q_BaseCase_N_Equals_1)
		{
			int depth = 0;
			Assert::AreEqual(1, Q(5, 1, 1, depth));
			Assert::AreEqual(1, depth);
		}

		// n = m: 1 + Q(m, m - 1)
		TEST_METHOD(Q_N_Equals_M)
		{
			int depth = 0;
			Assert::AreEqual(7, Q(5, 5, 1, depth));
		}

		// n > m: Q(m, n) = Q(m, m)
		TEST_METHOD(Q_N_Greater_Than_M)
		{
			int d1 = 0, d2 = 0;
			Assert::AreEqual(Q(4, 4, 1, d1), Q(4, 9, 1, d2));
			Assert::AreEqual(5, Q(4, 9, 1, d2));
		}

		// n < m: Q(m, n) = Q(m, n - 1) + Q(m - n, n)
		TEST_METHOD(Q_N_Less_Than_M)
		{
			int depth = 0;
			// 7 = 3+3+1 = 3+2+2 = 3+2+1+1 = 3+1+1+1+1 = 2+2+2+1 = 2+2+1+1+1 = 2+1*5 = 1*7
			Assert::AreEqual(8, Q(7, 3, 1, depth));
		}

		// Q(m, m) - це кількість розбиттів числа m: 1, 2, 3, 5, 7, 11, 15, 22, 30, 42
		TEST_METHOD(Q_PartitionNumbers_1_to_10)
		{
			const int expected[10] = { 1, 2, 3, 5, 7, 11, 15, 22, 30, 42 };
			for (int m = 1; m <= 10; m++)
			{
				int depth = 0;
				Assert::AreEqual(expected[m - 1], Q(m, m, 1, depth));
			}
		}

		// Глибина рекурсії для кількох відомих випадків
		TEST_METHOD(Q_Depth_KnownValues)
		{
			int depth;

			depth = 0; Q(2, 2, 1, depth); Assert::AreEqual(2, depth);
			depth = 0; Q(3, 3, 1, depth); Assert::AreEqual(3, depth);
			depth = 0; Q(5, 5, 1, depth); Assert::AreEqual(6, depth);
			depth = 0; Q(6, 6, 1, depth); Assert::AreEqual(8, depth);
			depth = 0; Q(7, 3, 1, depth); Assert::AreEqual(5, depth);
			depth = 0; Q(10, 10, 1, depth); Assert::AreEqual(14, depth);
		}

		// Початковий рівень 1: глибина не може бути меншою за 1
		TEST_METHOD(Q_Depth_AtLeastOne)
		{
			int depth = 0;
			Q(1, 1, 1, depth);
			Assert::IsTrue(depth >= 1);
		}
	};
}