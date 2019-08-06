// Class1.cpp
#include "pch.h"
#include "ConvertData.h"


using namespace NumberConverter;
using namespace Platform;
using namespace std;


ConvertData::ConvertData(){}

Platform::String^ ConvertData::DeciToBinConv(INT64 _inputVals)
{
	wstring _storeFirstOutput;
	std::stack<std::wstring> firstOutput;
	if (_inputVals == 0)
	{
		firstOutput.push(L"0");
		
	}

	else
	{
		while (_inputVals > 0)
		{
			if (_inputVals % 2 == 0)
			{
				_inputVals = _inputVals / 2;
				firstOutput.push(L"0");
			}
			else
			{
				_inputVals = (_inputVals - 1) / 2;
				firstOutput.push(L"1");
			}	
		}
	}
	int countx = 0;
	
	while (countx == 0)
	{
		_storeFirstOutput += firstOutput.top();
		firstOutput.pop();

		if (firstOutput.empty() == true)
			countx = 1;
	}
	
	return ref new String(_storeFirstOutput.c_str());
}

Platform::String ^ ConvertData::BinToDecConv(INT64 _inputVals2)
{
	wstring _returnAns;
	int cummilative = 0;
	double ans = 0;
	wstring temp = L"";
	
	temp = to_wstring(_inputVals2);

	int number_length = 0;

	number_length = temp.length();
	wstring tep = L"";
		tep = temp;
		int n = 0;
		int number_length2 = number_length;
	while (n != number_length)
	{
		wstringstream wwm;
		wwm << tep[n];

		int d = 0;
		wwm >> d;

		ans = pow(2, number_length2 - 1) * d;
		//ans = pow(2, n) * d;
		cummilative += ans;
		n++;
		number_length2--;
	}
	_returnAns = to_wstring(cummilative);

	
	return ref new String(_returnAns.c_str());

}



