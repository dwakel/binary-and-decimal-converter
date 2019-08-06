//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"







using namespace ConverterCE3Project;

using namespace Platform;
using namespace std;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
	_ConvertData = ref new NumberConverter::ConvertData;
	_ComplConvert = ref new NumberConverter::ComplimentConverting;
	
}



void ConverterCE3Project::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ txt2 = displayAnswer_txbl->Text;
		Object^ hold = DectoBin_rdb->IsChecked;

		bool holds = safe_cast<bool>(hold);

		if (holds == true)
		{		
			wstringstream ss1(takeInput_txb->Text->Data());
			INT64 decinumber = 0;
			ss1 >> decinumber;

			displayAnswer_txbl->Text = _ConvertData->DeciToBinConv(decinumber);			
		}

		Object^ hold2 = BintoDec_rdb->IsChecked;
		bool holds2 = safe_cast<bool>(hold2);

		if (holds2 == true)
		{
			wstringstream ss2(takeInput_txb->Text->Data());

			INT64 Binnumber = 0;
			ss2 >> Binnumber;
			displayAnswer_txbl->Text = _ConvertData->BinToDecConv(Binnumber);
		}


		Object^ hold3 = OnestoDec_rdb->IsChecked;
		bool holds3 = safe_cast<bool>(hold3);

		if (holds3 == true)
		{
			wstringstream ss3(takeInput_txb->Text->Data());
			INT64 Onenumber = 0;
			ss3 >> Onenumber;
			displayAnswer_txbl->Text = _ComplConvert->$1sCompToDec(Onenumber);
		}



		
		Object^ hold4 = to2todec_rdb->IsChecked;
		bool holds4 = safe_cast<bool>(hold4);

		if (holds4 == true)
		{
			wstringstream ss4(takeInput_txb->Text->Data());
			INT64 Twonumber = 0;
			ss4 >> Twonumber;
			displayAnswer_txbl->Text = _ComplConvert->$2sCompliment(Twonumber);
		}
}
