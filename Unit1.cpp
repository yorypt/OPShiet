//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include "Unit1.h"
#include "Math.h"
#include "Unit2.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x;
int count;
int S;
bool voprosik;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image4Click(TObject *Sender)
{
srand(time(NULL));
voprosik = true;
int r;
  if (Edit2->Text.Length() > 0)
  {
  r = StrToInt(Edit2->Text);
  }
	if (Edit2->Text.Length() == 0)
	{
	Label6->Caption = Utf8ToAnsi("Ладно,тогда 100");
	r =  100;
	}
	if (r != 0)
	{
	x = 1 + rand()%r;
	//Label6->Caption = x;
	Form1->Color = clBtnHighlight;
	count = 0;
	 Label3->Caption = " ";
	 Memo1->Lines->Clear();
	 Memo1->Lines->Add("---------------------------------");
	 Memo1->Lines->Add(Utf8ToAnsi("Число от 1 до " + IntToStr(r) + " было"));
	}
 Image14->Visible = false;
 Image16->Visible = false;
 Image10->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (voprosik)
{
if (Edit2->Text.Length() > 0)
{
	count++;
	Label3->Caption = count;
	Label6->Caption = " ";
	int y;
	if (Edit1->Text != "") {
	y = StrToInt(Edit1->Text);
	}
	int a = x;
	int min;
	if (y == x)
	{
	voprosik = false;
	Image14->Visible = true;
	double min = log((double)a)/log(2.0);
	 if (min > (int)min)
		{
		min = (int)min + 1;
		}
	 Label7->Caption = min+1;
	 Form1->Color = clMoneyGreen;
	 Memo1->Lines->Add(Utf8ToAnsi("угадано за ") + IntToStr(count) + Utf8ToAnsi(" попытки(ок)"));
	 Memo1->Lines->Add("---------------------------------");
	if (Edit1->Text.Length() != 0 && Edit2->Text.Length() != 0)
		{
		AnsiString file = "log.txt";
		AnsiString temp = Memo1->Text;
		TStringList *list1 = new TStringList;
		if (FileExists(file))
			{
				list1->LoadFromFile(file);
			}
        list1->Add(temp);
		list1->SaveToFile(file);
        delete list1;
		}
	 Image10->Visible = false;
	 Image16->Visible = false;
	}
	if (y < x)
	{
	Image16->Visible = true;
	Image10->Visible = false;
	}
	if (y > x)
	{
	Image10->Visible = true;
	Image16->Visible = false;
	}
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Label6->Caption = " ";
 Label3->Caption = " ";
 Image14->Visible = false;
 Image16->Visible = false;
 Image10->Visible = false;
 Edit1->Text = "";
 Edit2->Text = "";
 Memo1->Lines->Clear();
 Form1->Color = clBtnHighlight;
 Label7->Caption = " ";
 voprosik = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
ReleaseCapture();
SendMessage(Form1->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
  Image1->Visible = false;
  Image2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3MouseEnter(TObject *Sender)
{
  Image3->Visible = false;
  Image4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4MouseLeave(TObject *Sender)
{
  Image4->Visible = false;
  Image3->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5MouseEnter(TObject *Sender)
{
  Image5->Visible = false;
  Image6->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6MouseLeave(TObject *Sender)
{
  Image6->Visible = false;
  Image5->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseEnter(TObject *Sender)
{
   Image1->Visible = false;
   Image2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseLeave(TObject *Sender)
{
   Image2->Visible = false;
   Image1->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image15MouseLeave(TObject *Sender)
{
   Image15->Visible = false;
   Image8->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8MouseEnter(TObject *Sender)
{
   Image8->Visible = false;
   Image15->Visible = true;
}
//---------------------------------------------------------------------------


