#include<iostream>
#include<vector>
#include<cmath>
#include<windows.h>

using namespace std;

double eta = 0.0001;
vector<vector<double>> x_y;

double target_function(double x){

    return 3*x;
}


double model(double x, double w){
    return w*x;
}

double cal_loss(vector<vector<double>> &x_y, double w){
    int raws = x_y.size();  //行
    double sum = 0;
    for (int i=0;i<raws;i++){
        sum += pow((x_y[i][1]-model(x_y[i][0],w)), 2);
    }
    return sum;
}

double derivation(double w, vector<vector<double>> &x_y){
    double delta = 0.00001;
    double deriv = (cal_loss(x_y, w+delta)-cal_loss(x_y,w)) / delta;
    // cout<<deriv<<endl;
    return deriv;
}

double gd(vector<vector<double>> &x_y){
    double w = 0;
    double der = derivation(w, x_y);
    int cnt = 0;
    while(fabs(der)>1.0e-10){
    // while(der>1.0e-10||der<-1.0e-10){
        cout<<fabs(der)<<endl;
        w = w-eta*der;
        der = derivation(w, x_y);
        cout<<cnt++<<"\tw:"<<w<<"\tder:"<<der<<endl;
    }

    return w;
}

double gd1(vector<vector<double>> &x_y, double eta){
    int cnt = 0;
    double w = 0;
    int raws = x_y.size();  //行
    double sum = 1;
    while(fabs(sum)>1.0e-5){
        sum = 0;
        for (int i=0;i<raws;i++){
            sum += (model(x_y[i][0],w)-x_y[i][1])*x_y[i][0];
        }
        w -= eta*sum;
        cout<<cnt++<<"\tw:"<<w<<"\tder:"<<sum<<endl;
    }

    return w;
}

int main(){
    for(int i=1;i<=10;i++){
        vector<double> item;
        item.push_back(i);
        item.push_back(target_function(i));
        x_y.push_back(item);
    }
    // double result = gd(x_y);
    double result = gd1(x_y, 0.0001);
    cout<<result<<endl;

    system("pause");
    return 0;
}