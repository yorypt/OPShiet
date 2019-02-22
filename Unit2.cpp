//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include "Unit1.h"
#include "Math.h"
#include "Unit2.h"
#include <string>
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Memo1Click(TObject *Sender)
{
AnsiString file = "log.txt";
   Memo1->Lines->LoadFromFile(file);

char *str = new char [1024];
int i=0;
ifstream base("log.txt");
while (!base.eof())
{
	base.getline(str, 1024, '\n');
	i++;
}
    base.close();
	delete str;
	Label1->Caption = (i-1)/5;
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseEnter(TObject *Sender)
{
  Image1->Visible = false;
  Image2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2MouseLeave(TObject *Sender)
{
  Image2->Visible = false;
  Image1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
ReleaseCapture();
SendMessage(Form2->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------

