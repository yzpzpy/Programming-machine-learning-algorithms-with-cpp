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
        // cout<<"res: "<<res<<endl;
        res += w[i]*x[i];
    }
    return res;
}

vector<double> gd(vector<vector<double>> &x,vector<double> y, double eta, int iteration, int iter_num, int batch){
    int cnt = 1;
    int raws = x.size();  //行
    int cols = x[0].size(); //列
    srand((int)time(0));
    double start = rand()%10;
    vector<double> w = vector<double>(cols,start);
    double de = 1;
    int num = 0;
    while (cnt<iteration)
    {
        de = 0;
        for (int j=0;j<cols;j++){
            double sum = 0;
            int start_n = num%raws;
            int end_n = start_n+batch;
            for (int i=start_n;i<end_n;i++){
                ++num;
                sum += (model(x[i],w)-y[i])*x[i][j];
            }
            w[j] -= eta*sum;
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
    for(double i=1;i<=1000; i++){
        vector<double> item;
        for(int j=0;j<num;j++){
            item.push_back(rand()%10);
        }
        x.push_back(item);
        y.push_back(model(item,target));
    }
    // train
    vector<double> result = gd(x, y, 0.00001, 5000, 1000, 50);
    cout<<"target: "<<endl;
    for (int i=0;i<num;i++){
    cout<<target[i]<<" ";
    }
    cout<<"\npredict: "<<endl;
    for (int i=0;i<num;i++){
    cout<<result[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}