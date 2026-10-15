#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab053/Lab053.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest053
{
	TEST_CLASS(UnitTest053)
	{
	public:

		// Гілка |x| >= 1 або x = 0: h(x) = (cos x + 1) / e^x
		TEST_METHOD(TestBranchOutside)
		{
			Assert::AreEqual(2.0, h(0), 1e-12);
			Assert::AreEqual((cos(1.0) + 1) / exp(1.0), h(1.0), 1e-12);
			Assert::AreEqual(0.566645551517855, h(1.0), 1e-12);
		}

		// Гілка 0 < |x| < 1: сума ряду, поділена на sin(x^2)
		TEST_METHOD(TestBranchSeries)
		{
			double expected = sinh(0.25) / sin(0.25); // ряд з 7 доданків у замкненому вигляді
			Assert::AreEqual(expected, h(0.5), 1e-9);
			Assert::AreEqual(expected, h(-0.5), 1e-9); // функція парна
		}

		// Значення виразу z у точці r = 0: h(1) + h(1)^2 + 1
		TEST_METHOD(TestZ)
		{
			double r = 0;
			double z = h(r + 1) + pow(h(r * r + 1), 2) + 1;
			Assert::AreEqual(1.88773273257283, z, 1e-9);
		}
	};
}