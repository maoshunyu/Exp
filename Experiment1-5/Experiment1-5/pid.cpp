//#include <stdio.h>
//#include <Windows.h>
//#pragma warning(disable:4996)
//int main() {
//    double kp = 0.5, ki = 0.3, kd = 0;
//    int vel = 50;
//    double pid = 0;
//    double p_prev = 0, integral = 0;
//    while (1) {
//        integral += vel-pid;
//        p_prev = pid;
//        pid = pid + kp * (vel - pid) + kd * (pid - p_prev) + ki * integral;
//        Sleep(20);
//        printf("%.4f\n", pid);
//    }
//
//    return 0;
//}

#include <stdio.h>
int main() {


    int m = 3;
    if (m++ > 3) {
        printf("+");
    }
    else {
        printf("¡·");
    }
    return 0;
}