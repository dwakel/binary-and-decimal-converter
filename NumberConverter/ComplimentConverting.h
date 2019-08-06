#pragma once
#include "ConvertData.h"

namespace NumberConverter
{

	public ref class ComplimentConverting sealed
	{
	public:
		ComplimentConverting();
		

		Platform::String^ $1sCompToDec(INT64 _inputVals3);
		Platform::String^ $2sCompliment(INT64 _inputVals4);
		

	protected:


	private:
		ConvertData cd;
		
	};

}