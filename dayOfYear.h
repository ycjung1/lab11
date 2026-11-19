// 2. 클래스1.h: 지난 실습에서 사용한 클래스에 다음을 변경 
// -input: 매개변수를 std::istream&로, 기본값은 std::cin으로
// -입력연산자>>: input함수를 이용
// -print: 매개변수를 std::ostream&로, 기본값은 std::cout으로, 공백채움문자설정과 출력폭설정으로 변경하기
// -출력연산자<<: print함수를 이용

#pragma once
#include <iostream>

namespace JungYunchae2649114
{
    const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};    
    class dayOfYear
    {
        int month; 
        int day;  
        void testMonth() 
        {
            if (month < 1 || month > 12)
            {
                std::cout << "Invalid month\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if (day < 1 || day > daysInMonth[month])
            {
                std::cout << "Invalid day\n";
                std::exit(1);
            }
        }
        void updateDay()
        {
            int maxDay{daysInMonth[month]};
            while (day > maxDay)
            {
                day -= maxDay; month += 1;
                if (month > 12) month = 1;
                maxDay = daysInMonth[month];
            }
        }
    public:
        dayOfYear(int m = 1, int d = 1):month{m}, day{d} 
        {
            testMonth();
            testDay();
        }

        // -input: 매개변수를 std::istream&로, 기본값은 std::cin으로
        // -입력연산자>>: input함수를 이용
        void input(std::istream& is = std::cin) //매개변수 없이도 실행 가능하도록 기본값 설정
        {
            std::cout << "Enter month: ";
            is >> month; testMonth();
            std::cout << "Enter day: ";
            is >> day; testDay();
        }
        friend std::istream& operator>>(std::istream& is, dayOfYear& d)
        {
            d.input(is);
            return is;            
        }
        void setMonth(int m) {month = m; testMonth();}
        void setDay(int d) {day = d; testDay();}

        // -print: 매개변수를 std::ostream&로, 기본값은 std::cout으로, 공백채움문자설정과 출력폭설정으로 변경하기
        // -출력연산자<<: print함수를 이용
        void print(std::ostream& os = std::cout) const
        {
            // os.fill('0');
            // os.width(3);
            // os << month << '/';
            // os.width(2);
            // os << day << std::endl;

            switch(month)
            {
            case 1: os << "Jan. "; break;
            case 2: os << "Feb. "; break;
            case 3: os << "Mar. "; break;
            case 4: os << "Apr. "; break;
            case 5: os << "May. "; break;
            case 6: os << "Jun. "; break;
            case 7: os << "Jul. "; break;
            case 8: os << "Aug. "; break;
            case 9: os << "Sep. "; break;
            case 10: os << "Oct. "; break;
            case 11: os << "Nov. "; break;
            case 12: os << "Dec. "; break;
            } 
            os.fill('0'); os.width(2);
            os << day << "\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
        {
            d.print(os);
            return os;
        }
        int getMonth() const {return month;}
        int getDay() const {return day;}

        dayOfYear& operator++() 
        {
            ++day; updateDay();            
            return *this;
        }
        dayOfYear operator++(int)
        {   
            dayOfYear temp;
            temp = *this;
            ++*this;   
            return temp;
        }
        dayOfYear& operator+=(int d)
        {
            day += d; updateDay();
            return *this;
        }
        friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d1.day == d2.day;
        }

        dayOfYear operator+(int a)
        {
            *this += a;
            return *this;
        }
    };

}