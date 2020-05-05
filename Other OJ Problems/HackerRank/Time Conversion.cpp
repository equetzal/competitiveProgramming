//HR - Time Conversion

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
    
    string time;
    cin >> time;
    
    string hh;
    
    switch(time[8]){
        case 'P': case 'p':
            switch(time[0]){
                case '1':
                    switch(time[1]){
                        case '2':
                            hh = "12";
                        break;

                        case '1':
                            hh = "23";
                        break;

                        case '0':
                            hh = "22";
                        break;
                    }
                break;

                case '0':
                    switch(time[1]){
                        case '9':
                            hh = "21";
                        break;

                        case '8':
                            hh = "20";
                        break;

                        case '7':
                            hh = "19";
                        break;

                        case '6':
                            hh = "18";
                        break;

                        case '5':
                            hh = "17";
                        break;

                        case '4':
                            hh = "16";
                        break;

                        case '3':
                            hh = "15";
                        break;

                        case '2':
                            hh = "14";
                        break;

                        case '1':
                            hh = "13";
                        break;
                    }
                break;
            }
        break;

        case 'A': case 'a':
            // cout << "Es Dia";

            switch(time[0]){
                case '1':
                    switch(time[1]){
                        case '2':
                            hh = "00";
                        break;

                        case '1':
                            hh = "11";
                        break;

                        case '0':
                            hh = "10";
                        break;
                    }
                break;

                case '0':
                    switch(time[1]){
                        case '9':
                            hh = "09";
                        break;

                        case '8':
                            hh = "08";
                        break;

                        case '7':
                            hh = "07";
                        break;

                        case '6':
                            hh = "06";
                        break;

                        case '5':
                            hh = "05";
                        break;

                        case '4':
                            hh = "04";
                        break;

                        case '3':
                            hh = "03";
                        break;

                        case '2':
                            hh = "02";
                        break;

                        case '1':
                            hh = "01";
                        break;
                    }
                break;
            }
        break;
    }

    cout << hh << ":" << time[3] << time[4] << ":" << time[6] << time[7];
    
    return 0;
}

