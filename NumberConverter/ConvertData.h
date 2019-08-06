#pragma once



namespace NumberConverter
{
    public ref class ConvertData sealed
    {
    public:
        ConvertData();
		Platform::String^ DeciToBinConv(INT64 _inputVals);
		Platform::String^ BinToDecConv(INT64 _inputVals2);
	

    };
}