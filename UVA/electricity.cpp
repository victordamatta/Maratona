#include <iostream>
#define all(x) x.begin(), x.end()
using namespace std;
typedef int num;
//REMEMBER TO DECLARE GLOBAL VARIABLES

int n, e, ans, ans2;
int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mb[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long int d1, d2;

struct date{
    int day;
    int month;
    int year;
    int value;
};

bool bix(date d){
    if(d.year%4==0){
        if(d.year%100==0){
            if(d.year%400==0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

long long int acc(date d){
    long long int day = 0, month = 0, year = 0;
    int cont = 0;
    day += d.day-1;
    if(d.year%4!=0 || d.year%100==0){
        for(int i = 0; i<d.month-1; i++){
            month += m[i];
        }
    }
    else{
        for(int i = 0; i<d.month-1; i++){
            month += mb[i];
        }
    }
    for(int i=1900; i<d.year; i+=4){
        if(i!=2100){
            year += 366;
            cont++;
        }
    }
    year += (d.year-1900-cont)*365;

    return day + month + year;
}

int main(){
    std::ios::sync_with_stdio(false);
    date f;
    date s;
    while(cin >> n, n!=0){
        cin >> f.day >> f.month >> f.year >> f.value;
        d1 = acc(f);
        ans = ans2 = 0;
        n--;
        while(n--){
            cin >> s.day >> s.month >> s.year >> s.value;
            d2 = acc(s);

            if(d2-d1==1 /*|| (f.month == 2 && f.day==28 && bix(f) && f.year==s.year && d2-d1==4)*/){
                ans += s.value-f.value;
                ans2++;
            }

            d1 = d2;
            f = s;
        }
        cout << ans2 << " " << ans << "\n";
    }
}
