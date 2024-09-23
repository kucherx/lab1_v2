#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab1.1\lab1.1\lab1.1.cpp" // Шлях до вашого файлу з функціями

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// Тест для кон'юнкції
		TEST_METHOD(TestConjunction)
		{
			Assert::AreEqual(true, getconjunction(true, true));   // true && true = true
			Assert::AreEqual(false, getconjunction(true, false)); // true && false = false
			Assert::AreEqual(false, getconjunction(false, true)); // false && true = false
			Assert::AreEqual(false, getconjunction(false, false));// false && false = false
		}

		// Тест для диз'юнкції
		TEST_METHOD(TestDisjunction)
		{
			Assert::AreEqual(true, getdisjunction(true, true));   // true || true = true
			Assert::AreEqual(true, getdisjunction(true, false));  // true || false = true
			Assert::AreEqual(true, getdisjunction(false, true));  // false || true = true
			Assert::AreEqual(false, getdisjunction(false, false));// false || false = false
		}

		// Тест для альтернативного "або"
		TEST_METHOD(TestExclusiveOr)
		{
			Assert::AreEqual(false, exclusive_or(true, true));    // true != true = false
			Assert::AreEqual(true, exclusive_or(true, false));    // true != false = true
			Assert::AreEqual(true, exclusive_or(false, true));    // false != true = true
			Assert::AreEqual(false, exclusive_or(false, false));  // false != false = false
		}

		// Тест для імплікації
		TEST_METHOD(TestImplication)
		{
			Assert::AreEqual(true, implication(true, true));      // !true || true = true
			Assert::AreEqual(false, implication(true, false));    // !true || false = false
			Assert::AreEqual(true, implication(false, true));     // !false || true = true
			Assert::AreEqual(true, implication(false, false));    // !false || false = true
		}

		// Тест для еквівалентності
		TEST_METHOD(TestEquivalence)
		{
			Assert::AreEqual(true, equivalence(true, true));      // true == true = true
			Assert::AreEqual(false, equivalence(true, false));    // true == false = false
			Assert::AreEqual(false, equivalence(false, true));    // false == true = false
			Assert::AreEqual(true, equivalence(false, false));    // false == false = true
		}
	};
}
