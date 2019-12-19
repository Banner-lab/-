//---------------------------------------------------------------------------
#include <vcl.h>
#include <JPEG.hpp>
#include <JPEG.Hpp>
#include <graphics.hpp>
#pragma  hdrstop
#include "Library.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WinSkinData"
#pragma link "WinSkinStore"
#pragma link "YbBackImage"
#pragma resource "*.dfm"
#include "stubook.h"
#include <fstream>
ofstream fout("books.txt",ios_base::app);
ofstream fout2;
TForm1 *Form1;
int flag=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
    Memo4->Clear();
    Memo5->Clear();
    Memo6->Clear();
    Memo7->Clear();
    Memo8->Clear();
    Memo9->Clear();
    Memo10->Clear();
    Memo11->Clear();
    Memo12->Clear();
    Memo13->Clear();
    Memo14->Clear();
    Memo15->Clear();
    Memo16->Clear();
    Memo17->Clear();
    Memo18->Clear();
    Memo19->Clear();
    Memo20->Clear();
    Memo21->Clear();
    Memo22->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
   if(Memo20->Text=="")
     ShowMessage("请输入学生姓名");
   else if(Memo21->Text=="")
     ShowMessage("请输入学生学号");
   else if(Memo22->Text=="")
     ShowMessage("请输入学生专业");
   else
   {
      fout2.open("stu.txt",ios_base::app);
      Student*st=new Student();
      st->memosToobject(Memo20,Memo21,Memo22);
      st->savetofile(fout2);
      delete st;
      ShowMessage("录入成功！");
      Memo20->Clear();
      Memo21->Clear();
      Memo22->Clear();
      fout2.close();
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
   Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   if((StaticText4->Left-1)==-StaticText4->Width)
   StaticText4->Left=Form1->Width;
   else
   StaticText4->Left-=1;
   StatusBar1->Panels->Items[0]->Text=Date();
   StatusBar1->Panels->Items[1]->Text="时间:"+Time();
   StatusBar1->Panels->Items[2]->Text="李小明";
   StatusBar1->Panels->Items[3]->Text="1807020213";
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)
{
   Form1->Close();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Enter(TObject *Sender)
{
    switch(flag)
     {
       case 14:Memo14->Clear();
         break;
       case 15:Memo15->Clear();
         break;
       case 16:Memo16->Clear();
         break;
       case 17:Memo17->Clear();
         break;
       case 18:Memo18->Clear();
         break;
       case 19:Memo19->Clear();
         break;
     }
     flag=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     if(Memo14->Text=="")
        ShowMessage("请输入书名");
     else if(Memo15->Text=="")
        ShowMessage("请输入序列号");
     else if(Memo16->Text=="")
        ShowMessage("请输入作者");
     else if(Memo17->Text=="")
        ShowMessage("请输入出版社");
     else if(Memo18->Text=="")
        ShowMessage("请输入版次");
     else if(Memo19->Text=="")
        ShowMessage("出版日期");
     else
     {
       Book *bk=new Book();
       bk->filetobook(Memo14,Memo15,Memo16,Memo17,Memo18,Memo19,bk);
       bk->booktofile(fout);
       ShowMessage("录入成功！");
       Memo14->Clear();
       Memo15->Clear();
       Memo16->Clear();
       Memo17->Clear();
       Memo18->Clear();
       Memo19->Clear();

       delete bk;
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo14Enter(TObject *Sender)
{
     flag=14;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo15Enter(TObject *Sender)
{
     flag=15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo16Enter(TObject *Sender)
{
     flag=16;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo17Enter(TObject *Sender)
{
     flag=17;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo18Enter(TObject *Sender)
{
     flag=18;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo19Enter(TObject *Sender)
{
   flag=19;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
   Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    if(Memo1->Text==""||Memo9->Text=="")
       ShowMessage("请输入学生或图书信息");
    else if(Memo12->Text=="已借")
    {
       Memo23->Lines->LoadFromFile("stu.txt");
       Student *st=new Student();
       Book *boo=new Book();
       int loops=Memo23->Lines->Count;
       for(int i=0;i<loops;i++)
       {
          AnsiString temp=Memo23->Lines->Strings[i];
          if(temp.SubString(0,4)==Memo9->Text)
          {
             st->StringToStu(temp);
             st->changeborrow("00");
             Memo23->Lines->Delete(i);
             Memo23->Lines->Insert(i,st->StuToStr());
             break;
          }
       }
       Memo23->Lines->SaveToFile("stu.txt");
       fout.close();
       Memo23->Lines->LoadFromFile("books.txt");
       int lin=Memo23->Lines->Count;
       for(int i=0;i<lin;i++)
       {
          AnsiString bk=Memo23->Lines->Strings[i];
          if(bk.SubString(0,2)==Memo1->Text)
          {
              boo->StringToBook(bk);
              boo->ChangeLender("无人借阅");
              Memo23->Lines->Delete(i);
              Memo23->Lines->Insert(i,boo->BookToStr());
              break;
          }
       }
       ShowMessage("还书成功");
       delete boo;
       delete st;
       Memo1->Clear();
       Memo2->Clear();
       Memo3->Clear();
       Memo4->Clear();
       Memo5->Clear();
       Memo6->Clear();
       Memo7->Clear();
       Memo8->Clear();
       Memo12->Text="可借";
       Memo13->Text="无";
       Button4->Enabled=true;
       Button5->Enabled=false;
       Memo23->Lines->SaveToFile("books.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   if(Memo9->Text==""||Memo1->Text=="")
      ShowMessage("请输入学号和序列号");
   else if(Memo7->Text=="可借"&&Memo12->Text=="可借")
   {
      Memo23->Lines->LoadFromFile("stu.txt");
      Student *st=new Student();
      Book *bk=new Book();
      int count=Memo23->Lines->Count;
      for(int i=0;i<count;i++)
      {
         AnsiString temp=Memo23->Lines->Strings[i];
         if(temp.SubString(0,4)==Memo9->Text)
         {
            st->StringToStu(temp);
            st->changeborrow(Memo1->Text);
            Memo23->Lines->Delete(i);
            Memo23->Lines->Insert(i,st->StuToStr());
            break;
         }
      }
      Memo23->Lines->SaveToFile("stu.txt");
      Memo23->Lines->LoadFromFile("books.txt");
      int coc=Memo23->Lines->Count;
      for(int i=0;i<coc;i++)
      {
         AnsiString tem=Memo23->Lines->Strings[i];
         if(tem.SubString(0,2)==Memo1->Text)
         {
            bk->StringToBook(tem);
            bk->ChangeLender(Memo9->Text);
            Memo23->Lines->Delete(i);
            Memo23->Lines->Insert(i,bk->BookToStr());
         }
      }
      Memo23->Lines->SaveToFile("books.txt");
      ShowMessage("借阅成功!!!");
      Memo1->Clear();
      Memo2->Clear();
      Memo3->Clear();
      Memo4->Clear();
      Memo5->Clear();
      Memo6->Clear();
      Memo7->Clear();
      Memo8->Clear();
      Memo9->Clear();
      Memo10->Clear();
      Memo11->Clear();
      Memo12->Clear();
      Memo13->Clear();
      delete bk;
      delete st;
      Button4->Enabled=true;
      Button5->Enabled=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
    if(Memo1->Text!="")
    {
      Button4->Enabled=true;
      Button5->Enabled=true;
      Memo2->Clear();
      Memo3->Clear();
      Memo4->Clear();
      Memo5->Clear();
      Memo6->Clear();
      Memo7->Clear();
      Memo8->Clear();

      fout.close();
      Memo23->Lines->LoadFromFile("books.txt");
      int count=Memo23->Lines->Count;
      Book boo;
      Student st;
      for(int i=0;i<count;i++)
      {
         AnsiString temp(Memo23->Lines->Strings[i]);
         if(temp.SubString(0,2)==Memo1->Text)
           {
               boo.StringToBook(temp);

               if(boo.geter()!="无人借阅")
                 {
                    Memo24->Lines->LoadFromFile("stu.txt");
                    int sts=Memo24->Lines->Count;
                    for(int j=0;j<sts;j++)
                     {
                        if(Memo24->Lines->Strings[j].SubString(0,4)==boo.geter())
                          {
                             st.StringToStu(Memo24->Lines->Strings[j]);
                             st.display(Memo9,Memo10,Memo11,Memo12,Memo13);
                             break;
                           }
                     }
                    if(boo.geter()!="无人借阅")
                     {
                         Button4->Enabled=false;
                         Button5->Enabled=true;
                     }
                     break;
                }
               else
                {
                    boo.display(Memo2,Memo3,Memo4,Memo5,Memo6,Memo7,Memo8);
                    if(boo.geter()=="无人借阅")
                      {
                        Button4->Enabled=true;
                        Button5->Enabled=false;
                      }
                    break;
                }
           }

          else
           {
               Memo2->Text="查无此书";
               Memo3->Text="查无此书";
               Memo4->Text="查无此书";
               Memo5->Text="查无此书";
               Memo6->Text="查无此书";
               Button4->Enabled=false;
               Button5->Enabled=false;
           }
        }
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo9Change(TObject *Sender)
{

     if(Memo9->Text!="")
     {
         Button4->Enabled=true;
         Button5->Enabled=true;
         Memo10->Clear();
         Memo11->Clear();
         Memo12->Clear();
         Memo13->Clear();
         Memo23->Lines->LoadFromFile("stu.txt");
         int coun=Memo23->Lines->Count;
         fout.close();
         Student st;
         Book bk;
         for(int i=0;i<coun;i++)
         {
              AnsiString temp=Memo23->Lines->Strings[i];
              if(temp.SubString(0,4)==Memo9->Text)
               {
                 st.StringToStu(temp);
                 st.display(Memo9,Memo10,Memo11,Memo12,Memo13);
                 if(st.getbook()!="00")
                 {
                   Memo24->Lines->LoadFromFile("books.txt");
                   int bks=Memo24->Lines->Count;
                   for(int j=0;j<bks;j++)
                   {
                     if(Memo24->Lines->Strings[j].SubString(0,2)==st.getbook())
                     {
                        bk.StringToBook(Memo24->Lines->Strings[j]);
                        Memo1->Text=st.getbook();
                        bk.display(Memo2,Memo3,Memo4,Memo5,Memo6,Memo7,Memo8);
                        break;
                     }
                   }
                 }
                 break;
               }
         }
         if(st.getbook()!="00")//这个学生已经借了书
          {
             Button4->Enabled=false;
             Button5->Enabled=true;
          }
         else
         {
             Button4->Enabled=true;
             Button5->Enabled=false;
         }
     }
}
//---------------------------------------------------------------------------


