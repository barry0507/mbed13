#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

PwmOut pin8(D8), pin9(D9);


BBCar car(pin8, pin9, servo_ticker);


int main() {

    // please contruct you own calibration table with each servo

    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table0[] = {-16.667, -16.269, -15.072, -11.882, -5.822, 0.000, 5.822, 11.882, 15.072, 16.269, 16.667};

    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};

    double speed_table1[] = {-16.428, -15.950, -14.833, -11.803, -6.141, 0.000, 6.141, 11.803, 14.833, 15.950, 16.428};


    // first and fourth argument : length of table

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);


    while (1) {

        car.goStraightCalib(5);

        wait(5);

        car.stop();

        wait(5);

    }
}    