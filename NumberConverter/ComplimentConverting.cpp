#include "pch.h"
#include "ComplimentConverting.h"

using namespace NumberConverter;
using namespace Platform;
using namespace std;


ComplimentConverting::ComplimentConverting(){}

Platform::String ^ NumberConverter::ComplimentConverting::$1sCompToDec(INT64 _inputVals3)
{
	wstring number = to_wstring(_inputVals3);
	int countx = 0;
	int number_length = number.length();
	INT64 negnumber = 0;
	INT64 posnumber = 0;
	wstring nnegnumber = L"";
	wstring pposnumber = L"";

	if (number_length == 8)
	{
		number.erase(0, 1);
		number_length = number.length();
		for (auto x = 0; x < number_length; x++)
		{
			if (number[x].Equals(L'0'))
				number.begin()[x] = L'1';
			else
				number.begin()[x] = L'0';
		}

		wstringstream wwd;
		wwd << number;
		wwd >> negnumber;

		nnegnumber = (cd.BinToDecConv(negnumber))->Data();
		nnegnumber = L'-' + nnegnumber;
		return ref new String(nnegnumber.c_str());
	}

	else
	{
		wstringstream wwd;
		wwd << number;
		wwd >> posnumber;

		pposnumber = (cd.BinToDecConv(posnumber))->Data();

		return ref new String(pposnumber.c_str());
	}
}

Platform::String ^ NumberConverter::ComplimentConverting::$2sCompliment(INT64 _inputVals4)
{
	wstring number = to_wstring(_inputVals4);
	int countx = 0;
	int number_length = number.length();
	INT64 negnumber = 0;
	INT64 posnumber = 0;
	wstring nnegnumber = L"";
	wstring pposnumber = L"";


	if (number_length == 8)
	{
		number.erase(0, 1);
		number_length = number.length();
		for (auto x = 0; x < number_length; x++)
		{
			if (number[x].Equals(L'0'))
				number.begin()[x] = L'1';
			else
				number.begin()[x] = L'0';
		}

		wstring carryforward = L"1";
		int i = number_length - 1;
		while (i >= 0)
		{
			if (number[i].Equals(L'0'))
			{
				number.begin()[i] = L'1';
				i = -1;
				break;
			}

			else
			{
				while (i >= 0)
				{
					if ((number[i].Equals(L'1')))
					{
						if (carryforward[0].Equals(L'1'))
						{
							number.begin()[i] = L'0';
							carryforward = L'1';
							i--;
						}
					}

					else
					{
						if (carryforward[0].Equals(L'0'))
						{
							number.begin()[i] = L'0';
							carryforward[0] = L'0';
							i--;
						}
						else
						{
							number.begin()[i] = L'0';
							carryforward[0] = L'1';
							i--;
						}
					}

					if (carryforward[0].Equals(L'1') && (i < 0))
					{
						number = L'1' + number;
						break;
					}

				}
			}

		}

		wstringstream wwd;
		wwd << number;
		wwd >> negnumber;

		nnegnumber = (cd.BinToDecConv(negnumber))->Data();
		nnegnumber = L'-' + nnegnumber;
		return ref new String(nnegnumber.c_str());
	}

	else
	{
		wstringstream wwd;
		wwd << number;
		wwd >> posnumber;

		pposnumber = (cd.BinToDecConv(posnumber))->Data();

		return ref new String(pposnumber.c_str());
	}
}
