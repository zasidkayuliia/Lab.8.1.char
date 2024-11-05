#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1.char/Lab_08.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char testStr2[] = "abcabc";
			char expected2[] = "abcabc";
			Assert::AreEqual(expected2, Change(testStr2), L"Test failed: 'abcabc' should remain 'abcabc'");
		}
	};
}
