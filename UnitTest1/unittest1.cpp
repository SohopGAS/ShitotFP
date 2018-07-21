#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Common/Label.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/DoubleLineBorder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(testLabel)
		{
			Label l;
			Assert::IsFalse(l.canGetFocus() );
			string v = "val";
			l.setValue(v);
			Assert::AreEqual(v,l.getValue(),false);

		}

		TEST_METHOD(testPanel)
		{
			Panel p;
			Label l;

			p.add(&l);
			BorderType* b = DoubleLineBorder::getinstance();
			p.setBorderType(b);

			Assert::IsTrue( p.canGetFocus());
			Assert::IsNotNull(p.getBorderType());
			Assert::IsNull(l.getBorderType());
		}




	};
}
