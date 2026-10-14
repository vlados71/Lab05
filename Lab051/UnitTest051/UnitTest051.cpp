#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab051/Lab051.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest051
{
    TEST_CLASS(UnitTest051)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(2.0, h(1, 0), 1e-9);
        }
    };
}