#include "stubook.h"

void Student::savetofile(ofstream & fout)
{
   fout<<num<<" "<<name<<" "<<major<<" "<<borrow<<endl;
}

void Student:: memosToobject(TMemo *memo1,TMemo *memo2,TMemo *memo3)
{
    name=memo1->Text;
    num=memo2->Text;
    major=memo3->Text;
}

void Student::StringToStu(AnsiString st)
{
      num=st.SubString(0,4);
      AnsiString cut1=st.SubString(6,st.Length()-5);

      int pos2=cut1.Pos(" ");
      name=cut1.SubString(0,pos2);
      AnsiString cut2=cut1.SubString(pos2+1,cut1.Length()-pos2);

      int pos3=cut2.Pos(" ");
      major=cut2.SubString(0,pos3);
      AnsiString cut3=cut2.SubString(pos3+1,cut2.Length()-pos3);

      borrow=cut3;
}

AnsiString Student::StuToStr()
{
    return num+" "+name+major+borrow;
}

void Student::display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5)
{
   me1->Text=num;
   me2->Text=name;
   me3->Text=major;
   if(borrow=="00")
    {
      me4->Text="可借";
      me5->Text="无";
    }
   else
    {
     me4->Text="已借";
     me5->Text=borrow;
    }
}


void Book::filetobook(TMemo *memo1,TMemo *memo2,TMemo *memo3,TMemo *memo4,TMemo *memo5,TMemo *memo6,Book *a)
{
      a->title=memo1->Text;
      a->nums=memo2->Text;
      a->aurthor=memo3->Text;
      a->publishing=memo4->Text;
      a->edition=memo5->Text;
      a->publishdate=memo6->Text;
}


Book::Book(AnsiString n,AnsiString t,AnsiString au,AnsiString pub
    ,AnsiString edi,AnsiString date,AnsiString er)
{
    nums=n;
    title=t;
    aurthor=au;
    publishing=pub;
    edition=edi;
    publishdate=date;
    lender=er;
}

void Book::booktofile(ofstream & fout)
{
    fout<<nums<<" "<<title<<" "<<aurthor<<" "<<publishing<<" "<<edition<<" "<<publishdate<<" "<<lender<<endl;
}

void Book::readfile(ifstream &fin)
{
   fin>>nums>>title>>aurthor>>publishing>>edition>>publishdate;
}

 void Book::StringToBook(AnsiString boo)
 {
     nums=boo.SubString(0,2);
     AnsiString cut1=boo.SubString(4,boo.Length()-3);

     int pos1=cut1.Pos(" ");
     title=cut1.SubString(0,pos1);
     AnsiString cut2=cut1.SubString(pos1+1,cut1.Length()-pos1);

     int pos2=cut2.Pos(" ");
     aurthor=cut2.SubString(0,pos2);
     AnsiString cut3=cut2.SubString(pos2+1,cut2.Length()-pos2);

     int pos3=cut3.Pos(" ");
     publishing=cut3.SubString(0,pos3);
     AnsiString cut4=cut3.SubString(pos3+1,cut3.Length()-pos3);

     int pos4=cut4.Pos(" ");
     edition=cut4.SubString(0,pos4);
     AnsiString cut5=cut4.SubString(pos4+1,cut4.Length()-pos4);

     int pos5=cut5.Pos(" ");
     publishdate=cut5.SubString(0,pos5);
     AnsiString cut6=cut5.SubString(pos5+1,cut5.Length()-pos5);

     lender=cut6;
 }

AnsiString Book::BookToStr()
{
     return nums+" "+title+aurthor+publishing+edition+publishdate+lender;
}

void Book::ChangeLender(AnsiString le)
{
     lender=le;
}

void Book::display(TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5,TMemo *me6,TMemo *me7,TMemo *me8)
{
     me2->Text=title;
     me3->Text=aurthor;
     me4->Text=publishing;
     me5->Text=edition;
     me6->Text=publishdate;
     if(lender=="无人借阅")
      {
        me7->Text="可借";
        me8->Text="无";
      }
      else
      {
        me7->Text="借出";
        me8->Text=lender;
      }
}
