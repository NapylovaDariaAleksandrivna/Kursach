#pragma once
#include"tstack.h"

class functionBin
{
public:
    double operetor(char pref, double a, double b) {
        switch (pref) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (a == 0) {
                return b;
            }
            else
                return b / a; //�� ���������� ��� b=0
        case '^':
            return pow(a, b);
        case 'h':
            return log2(b) / log2(a);//�� ���������� ��� �<=0 ���� �� �����������
        }
        return 0;
    }

};
class functionUn
{
public:

    double DegToRad(double D)
    {
        double M = 3.14 / 180;
        return D * M;
    };

    double operetor(char pref, double a) {
        switch (pref) {
        case 'c':
            return cos(DegToRad(a));
        case 's':
            return sin(DegToRad(a));
        case 't':
            if (int(cos(DegToRad(a)) * 100) == 0) {
                //cur = ukp->getOut().length() + 100;
                return 0;
            }
            else {
                return tan(DegToRad(a));//�� ���������� ��� �=90 � 270
            }
        case 'w':
            if (int(sin(DegToRad(a)) * 100) == 0) {
                //cur = str.length() + 100;
                return 0;
            }
            else {
                return 1 / tan(DegToRad(a));//�� ���������� ��� �=0 � 180
            }
        case 'n':
            if (a <= 0) {
                //cur = str.length() + 100;
                return 0;
            }
            else
                return log(a);//�� ���������� ��� �<=0
        case 'l':
            if (a <= 0) {
                //cur = str.length() + 100;
                return 0;
            }
            else
                return log2(a);//�� ���������� ��� �<=0
        case 'g':
            if (a <= 0) {
                //cur = str.length() + 100;
                return 0;
            }
            else
                return log10(a);//�� ���������� ��� �<=0
        case 'q':
            if (a < 0) {
                //cur = str.length() + 100;
                return 0;
            }
            else
                return sqrt(a);//�� ���������� ��� �<0
        case '|':
            return abs(a);//�� �������� � ������� � ������, ���� |x+3*|x||
        }
        return 0;
    }

}; 
//"cos"=c "sin"=s "tg"= t "ctg"=w "ln"= n "log2"=l "lg"= g "sqrt"=q
