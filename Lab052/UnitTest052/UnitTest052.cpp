#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab052/Lab052.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
	TEST_CLASS(UnitTest052)
	{
	public:

		// Один крок рекурентності: a_n = a_(n-1) * x^2 * (2n-1)/(2n+1)
		TEST_METHOD(TestA)
		{
			double a = 1.0;
			A(0.5, 1, a);
			Assert::AreEqual(1.0 / 12, a, 1e-12);

			a = 1.0;
			A(0.5, 2, a);
			Assert::AreEqual(0.15, a, 1e-12);
		}

		// Сума ряду має збігатися з ln((1+x)/(1-x))
		TEST_METHOD(TestS)
		{
			double s;
			int n;

			S(0.5, 1e-9, n, s);
			Assert::AreEqual(log(3.0), s, 1e-8);

			S(-0.5, 1e-9, n, s);
			Assert::AreEqual(log(1.0 / 3.0), s, 1e-8);
		}
	};
}