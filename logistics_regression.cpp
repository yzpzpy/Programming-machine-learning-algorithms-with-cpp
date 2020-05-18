#include<iostream>
#include<vector>
#include<cmath>
#include<windows.h>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

double model(vector<double> x, vector<double> w){
    double res = 0;
    for (int i=0;i<w.size();i++){
        res += w[i]*x[i];
    }
    return res;
}

double sigmoid(double x){
    return 1/(1+exp(-x));
}

vector<double> gd(vector<vector<double>> &x,vector<double> y, double eta, int iteration, int iter_num){
    int cnt = 1;
    int raws = x.size();  //行
    int cols = x[0].size(); //列
    srand((int)time(0));
    double start = rand()%10;
    vector<double> w = vector<double>(cols,start);
    double de = 1;
    while (cnt<iteration)
    {
        de = 0;
        for (int j=0;j<cols;j++){
            double sum = 0;
            for (int i=0;i<raws;i++){
                sum += (y[i]-sigmoid(model(x[i],w)))*x[i][j];
            }
            w[j] += eta*sum;
            de += fabs(sum);   
        }
        cnt++;
        if(cnt%iter_num==0){
            int num = w.size();
            cout<<"iteration: "<<cnt<<": "<<"gradient: "<<de<<"\tw: ";
            for (int i=0;i<num;i++){
                cout<<w[i]<<"  " ;
            }
            cout<<endl;
        }
        
    }    
    return w;
}

vector<double> sgd(vector<vector<double>> &x,vector<double> y, double eta, int iteration, int iter_num){
    int cnt = 0;
    int raws = x.size();  //行
    int cols = x[0].size(); //列
    srand((int)time(0));
    double start = rand()%10;
    vector<double> w = vector<double>(cols,start);
    double de = 1;
    while (cnt<iteration){
        for (int i=0;i<raws;i++){
            de = 0;
            // cout<<cols<<endl;
            for (int j=0;j<cols;j++){
                double partial_differential = (y[i]-sigmoid(model(x[i],w)))*x[i][j];
                w[j] += eta*partial_differential;
                // cout<< partial_differential<<"\t";
                de += fabs(partial_differential);   
            }
            if(cnt%iter_num==0){
                int num = w.size();
                cout<<"iteration: "<<cnt<<": "<<"gradient: "<<de<<"\tw: ";
                for (int i=0;i<num;i++){
                    cout<<w[i]<<"  " ;
                }
                cout<<endl;
            }
            cnt++;
        }  
    }

    return w;
}

int main(){
    srand((int)time(0));
    vector<vector<double>> x; //train_x
    vector<double> y; //train_y
    int num = 3; //设置feature数量
    vector<double> target; //目标最优化的weight向量
    // vector<double> target = {1,2,3}; //目标最优化的weight向量
    // 生成目标weight向量
    for (int i=0;i<num;i++){
        double wi = rand()%10;
        target.push_back(wi);
    }
    // 生成train data
    for(double i=1;i<=1000;i++){
        vector<double> item1;
        for(int j=0;j<num;j++){
            item1.push_back(rand()%10);
            // item.push_back(2*i);
        }
        x.push_back(item1);
        y.push_back(sigmoid(model(item1,target)));
    }
    // train
    vector<double> result = sgd(x, y, 0.2, 1000000, 10000);
    cout<<"target: "<<endl;
    for (int i=0;i<num;i++){
    cout<<target[i]<<" ";
    }
    cout<<"\npredict: "<<endl;
    for (int i=0;i<num;i++){
    cout<<result[i]<<" ";
    }
    cout<<endl;
    // system("pause");
    return 0;
}