#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
#include <string>
#include <vcl.h>
#include <fstream>
using namespace std;
class Student
{
  private:
    AnsiString num;
    AnsiString name;
    AnsiString major;
    AnsiString borrow;
  public:
    Student(AnsiString n="00",AnsiString na="no one",AnsiString ma="on",AnsiString isb="00"):
    num(n),name(na),major(ma),borrow(isb){ }
    void savetofile(ofstream & fout);
    void memosToobject(TMemo *memo1,TMemo *memo2,TMemo *memo3);
    void changeborrow(AnsiString bo){borrow=bo;}
    AnsiString StuToStr();
    void StringToStu(AnsiString st);
    void display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5);
    AnsiString getbook(){return borrow;}
};

class Book
{
  private:
    AnsiString nums;
    AnsiString title;
    AnsiString aurthor;
    AnsiString publishing;
    AnsiString edition;
    AnsiString publishdate;
    AnsiString lender;
  public:
    Book(AnsiString n="00",AnsiString t="no",AnsiString au="on",AnsiString pub="no"
    ,AnsiString edi="no",AnsiString date="no",AnsiString er="无人借阅");
    void filetobook(TMemo *memo1,TMemo *memo2,TMemo *memo3,TMemo *memo4,TMemo *memo5,TMemo *memo6,Book *a);
    void booktofile(ofstream & fout); //将书本存入文本文件
    void readfile(ifstream &fin);
    AnsiString getnums(){return nums;}
    AnsiString gettitle(){return title;}
    AnsiString getaur(){return aurthor;}
    AnsiString getpublish(){return publishing;}
    AnsiString getedi(){return edition;}
    AnsiString getdate(){return publishdate;}
    AnsiString geter(){return lender;}
    void StringToBook(AnsiString boo);
    AnsiString BookToStr();
    void ChangeLender(AnsiString le);
    void display(TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5,TMemo *me6,TMemo *me7,TMemo *me8);
};
#endif
