//
//  main.cpp
//  graph_write
//
//  Created by Nikita on 20.07.16.
//  Copyright (c) 2016 RIT. All rights reserved.
//

//Ui = 6.28/200*k;
//
//F1 = F1 + F1*sin(Ui);
//F2 = F2 + F2*sin(2*Ui);
//F3 = F3 + F3*sin(3*Ui);
//F4 = F4 + F4*sin(4*Ui);


#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <stdio.h>


using namespace std;

int main(int argc, const char * argv[]) {
    
    setlocale( LC_ALL, "Russian");
    
        string vvod_x;
        string vvod_y;
        string vvod_y_cos;
    
    int j = 0; // счетчик для x
    int u = 0; // счетчик для действительных y
    int p = 0; // счетчик для мнимых y
    
    double x[200]; // действительные значения x
    double y[200]; // действительные значения y
    double y_cos[200]; // мнимые значения y
    
    
    double f_x; // временная переменная x
    double f_y; // временная переменная действительных y
    double f_y_cos; // временная переменная мнимых y
    
    char *str1 = nullptr;
    char *str2 = nullptr;
    
    
    float i = 0;
    float S = 0;
    float sinus = 0;
    float cosinus = 0;
    
    int k = 0;
    
    // тестовые первые значения действительные
    
    double F1 = 0;
    double F2 = 0;
    double F3 = 0;
    double F4 = 0;
    
    // тетовые значения кратные 200 дейтсвительные
    
    double F1_200 = 0;
    double F2_200 = 0;
    double F3_200 = 0;
    double F4_200 = 0;
    
    // внтуренние значания действительные
    
    double f1 = 0;
    double f2 = 0;
    double f3 = 0;
    double f4 = 0;
    
    //внутренние значения кратные 200 действительные
    
    double f1_200 = 0;
    double f2_200 = 0;
    double f3_200 = 0;
    double f4_200 = 0;
    
    
    
    // --------------------
    
    
    
    // тестовые первые значения действительные
    
    double U1 = 0;
    double U2 = 0;
    double U3 = 0;
    double U4 = 0;
    
    // тетовые значения кратные 200 дейтсвительные
    
    double U1_200 = 0;
    double U2_200 = 0;
    double U3_200 = 0;
    double U4_200 = 0;
    
    // внтуренние значания действительные
    
    double u1 = 0;
    double u2 = 0;
    double u3 = 0;
    double u4 = 0;
    
    //внутренние значения кратные 200 действительные
    
    double u1_200 = 0;
    double u2_200 = 0;
    double u3_200 = 0;
    double u4_200 = 0;
    
    
    // --------------------
    
    // корни
    
    double Sqrt1 = 0;
    double Sqrt2 = 0;
    double Sqrt3 = 0;
    double Sqrt4 = 0;

    // суммы
    
    double Sum1 = 0;
    double Sum2 = 0;
    double Sum3 = 0;
    double Sum4 = 0;

    
    
    float Ui = 0; // значение функции U(i)
    
    string vntr; // не используется
    
    
    int counter = 0;
    int count = 0;
    
    // объявление вида работ с файлами
    
    ifstream in_file;
    ofstream vvod1;
    ofstream Y_vvod;
    ifstream Y_read;
    ofstream X_vvod;
    ifstream X_read;
    
    ofstream Y_cos_vvod;
    ifstream Y_cos_read;
    
    // пути файлов
    
    vvod1.open("/Users/nikita/Documents/speak_better/obr.csv");
    in_file.open("/Users/nikita/Documents/speak_better/obr.csv");
    Y_vvod.open("/Users/nikita/Documents/speak_better/Y_obr.csv");
    Y_read.open("/Users/nikita/Documents/speak_better/Y_obr.csv");
    X_vvod.open("/Users/nikita/Documents/speak_better/X_obr.csv");
    X_read.open("/Users/nikita/Documents/speak_better/X_obr.csv");
    
    Y_cos_vvod.open("/Users/nikita/Documents/speak_better/Y_cos_obr.csv");
    Y_cos_read.open("/Users/nikita/Documents/speak_better/Y_cos_obr.csv");

    
//    while (!in_file.eof()) {
//        in_file >> vntr;
//        counter++;
//        cout << vntr;
//    }
    
    
    
    
    for (i = 0; i < 6.28; i+=6.28/200) {
        count++;
        S = i;
        
//        fscanf(myfile, "%f;%f", &x, &y); /* чтение из файла */
//        fprintf(stdout, " %f;%f ", x, y); /* вывод на экран */
        
        
        
        
        sinus = 5*sin(i) + 3*sin(2*i) + (0.5)*sin(3*i);
        cosinus = 5*cos(i) + 3*cos(2*i) + (0.5)*cos(3*i);
        
        
        
        Ui = 6.28/200*count;
        

        
        F1 = F1 + sinus*sin(Ui);
        F2 = F2 + sinus*sin(2*Ui);
        F3 = F3 + sinus*sin(3*Ui);
        F4 = F4 + sinus*sin(4*Ui);
        
        U1 = U1 + cosinus*cos(Ui);
        U2 = U2 + cosinus*cos(2*Ui);
        U3 = U3 + cosinus*cos(3*Ui);
        U4 = U4 + cosinus*cos(4*Ui);
        
        //cout << count << " - " << S << " / " << sinus << endl;
        
        
        vvod1 << S << ";" << sinus << endl;  // заполнение файла obr.csv общих значений
        
        Y_vvod << sinus << endl; // заполнение файла Y_obr.csv действительных y-значений
        
        X_vvod << S << endl; // заполнение файла X_obr.csv действительных x-значений
        
        Y_cos_vvod << cosinus << endl; // заполнение файла Y_obr.csv мнимых y-значений
        
        //cout << x << endl << y << endl;
        
        cout << endl << F1 << endl << F2 << endl << F3 << endl << F4 << endl << endl;
        
        

     }
    
    
    //cout << endl << F1 << endl << F2 << endl << F3 << endl << F4 << endl << endl;
    

    // считай значения из файла и посчитай интеграл
    
    
    // считывание и запись в массив данных x-координаты из файла X_obr.csv
    
    while (!X_read.eof()) {
        X_read >> vvod_x;
        //counter++;
        //cout << vvod << endl;
        
        
        for (int k = 0; k < 1; k++) {
            
            str2 = &vvod_x[k];
            
            f_x = atof(str2);
            
            x[j] = f_x; // заполнение массива данных
            
            j++;
            
            printf("%f",f_x);
            cout << endl;
        }
        
    }

    
    // считывание и запись в массив данных Y-координаты из файла Y_obr.csv
    
    
    while (!Y_read.eof()) {
        Y_read >> vvod_y;
        //counter++;
        //cout << vvod << endl;
        
        
        for (int k = 0; k < 1; k++) {
            
            str1 = &vvod_y[k];
            
            f_y = atof(str1);
            
            y[p] = f_y; // заполнение массива данных
            
            p++;
            
            printf("%f",f_y_cos);
            cout << endl;
        }
    }
    
    while (!Y_cos_read.eof()) {
        Y_cos_read >> vvod_y_cos;
        //counter++;
        //cout << vvod << endl;
        
        
        for (int k = 0; k < 1; k++) {
            
            str1 = &vvod_y_cos[k];
            
            f_y_cos = atof(str1);
            
            y_cos[u] = f_y_cos; // заполнение массива данных
            
            u++;
            
            printf("%f",f_y);
            cout << endl;
        }
    }

    
    
    
    //cout << endl << vvod << endl<< endl;
    
    
   // подсчет преобразований Фурье
    
    for (int t = 0; t < 201; t++) {
    
        // сумма не кратных 200
        
        f1 = f1 + y[t]*sin(x[t]);
        f2 = f2 + y[t]*sin(2*x[t]);
        f3 = f3 + y[t]*sin(3*x[t]);
        f4 = f4 + y[t]*sin(4*x[t]);
        
        cout << t << endl;
        
    }
    
    for (int a = 0; a<201; a++) {
        
        u1 = u1 + y_cos[a]*cos(x[a]);
        u2 = u2 + y_cos[a]*cos(2*x[a]);
        u3 = u3 + y_cos[a]*cos(3*x[a]);
        u4 = u4 + y_cos[a]*cos(4*x[a]);

    }
    
    // сумма кратных 200 действительных
    
    f1_200 = f1/200;
    f2_200 = f2/200;
    f3_200 = f3/200;
    f4_200 = f4/200;
    
    F1_200 = F1/200;
    F2_200 = F2/200;
    F3_200 = F3/200;
    F4_200 = F4/200;
    
    // сумма кратных 200 мнимых
    
    u1_200 = u1/200;
    u2_200 = u2/200;
    u3_200 = u3/200;
    u4_200 = u4/200;
    
    U1_200 = U1/200;
    U2_200 = U2/200;
    U3_200 = U3/200;
    U4_200 = U4/200;
    
    // квадратные корни для преобразований Фурье
    
    Sqrt1 = sqrt(f1_200*f1_200 + u1_200*u1_200);
    Sqrt2 = sqrt(f2_200*f2_200 + u2_200*u2_200);
    Sqrt3 = sqrt(f3_200*f3_200 + u3_200*u3_200);
    Sqrt4 = sqrt(f4_200*f4_200 + u4_200*u4_200);
    
    // суммы действительных и мнимых значенией
    
    Sum1 = f1_200+u1_200;
    Sum2 = f2_200+u2_200;
    Sum3 = f3_200+u3_200;
    Sum4 = f4_200+u4_200;
    
   // cout << endl << F1_200 << endl << F2_200 << endl << F3_200 << endl << F4_200 << endl << endl;
    
    cout << endl << f1_200 << endl << f2_200 << endl << f3_200 << endl << f4_200 << endl << endl;
    
    
    //cout << endl << U1_200 << endl << U2_200 << endl << U3_200 << endl << U4_200 << endl << endl;
    
    cout << endl << u1_200 << endl << u2_200 << endl << u3_200 << endl << u4_200 << endl << endl;
    

    cout << Sqrt1 << endl << Sqrt2 << endl << Sqrt3 << endl << Sqrt4 << endl;
    
    //cout << endl << Sum1 << endl << Sum2 << endl << Sum3 << endl << Sum4 << endl;
    
    
    return 0;
    
    
    
}
