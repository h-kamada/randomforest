#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
double a[155], b[155], c[155], d[155];  int e[155];
int T=30;//サブセットの個数
int i, j, k, l;
class Set{
private:
  int y, num[30][16];
  double sa[30][16], sb[30][16], sc[30][16], sd[30][16];
  int se[30][16];
public:
  int ii, jj, kk, ll;
  Set(){
    y=0;
  }
  void in(int p, int y, int x){
    sa[p][y]=a[x];
    sb[p][y]=b[x];
    sc[p][y]=c[x];
    sd[p][y]=d[x];
    se[p][y]=e[x];
    num[p][y]=x;
  }
  void print(){
    for (ii=0;ii<30;ii++){
      for (jj=0;jj<16;jj++){
        cout<<num[ii][jj]<< " " <<sa[ii][jj]<<" " <<sb[ii][jj]<<" " <<sc[ii][jj] <<" "<<sd[ii][jj]<<" "<<se[ii][jj]<<endl;
      }
    }
  }
};

int main (int argc, char *argv[]){
  //データの読み込み
  //cout << "ifstream" << endl;
  ifstream ifs("data.txt");
  string str;
  if(ifs.fail()) {
    cerr << "File do not exist.\n";
    return 0;
  }

  while(getline(ifs, str)) {
    a[i]=0; b[i]=0; c[i]=0,d[i]=0;
    sscanf(str.data(), "%lf%lf%lf%lf%d", &a[i], &b[i], &c[i], &d[i], &e[i]);
    /*cout << "a = " << a[i] ;
    cout << " b = " << b[i] ;
    cout << " c = " << c[i] ;
    cout << " d = " << d[i] ;
    cout << " e = " << e[i] << endl;
    */
    /*cout << i<< endl;*/
    i++;
  }

  //サブセット作成 １セットに含まれるデータは16とする
  Set s;
  for (i=0;i<T;i++){//T個のサブセットについて
    for (j=0;j<16;j++){
      s.in(i, j, rand()%150);
      //cout << rand()%150<<endl;
      //cout<< "i"<<i<<"   j"<<j<<endl;
    }
  }
  //s.print();


  //サブセットの数だけ木を作成する
  //"lrle"
  //サブセットデータに現在のディレクトリ情報を持たせておく
  //if エントロピーが０ もしくは深さmax 何もない
  //else 



  return 0;
}


