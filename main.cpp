#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
double a[155], b[155], c[155], d[155];  int e[155];
int T=1;//サブセットの個数
int i, j, k, l;
//Set s;
//Tree tr;
//divide_function dv;

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
        cout<<"num:"<<num[ii][jj]<<"["<<ii<<"]["<<jj<<"]"<< " sa:" <<sa[ii][jj]<<" sb:" <<sb[ii][jj]<<" sc:" <<sc[ii][jj] <<" sd:"<<sd[ii][jj]<<" se:"<<se[ii][jj]<<endl;
      }
    }
  }
  bool s_bool(int ii,int p,int y,int x ){
    if(ii==0){
      if(sa[p][y]==x)
        return true;
      return false;
    }
    if(ii==1){
      if(sb[p][y]==x)
        return true;
      return false;
    }
    if(ii==2){
      if(sc[p][y]==x)
        return true;
      return false;
    }
    if(ii==3){
      if(sd[p][y]==x)
        return true;
      return false;
    }
    if(ii==4){
      //      cout<<"se["<<p<<"]["<<y<<"]:"<<se[p][y]<<endl;
      if(se[p][y]==x){
        return true;}
      else{
        return false;}
    }
  }
  double s_out(int i, int j, int k){
    if(i==0){
      //cout<<"return sa["<<j<<"]["<<k<<"]:"<<sa[j][k]<<endl;
      return sa[j][k];
    }
    if(i==1){
      return sb[j][k];
    }
    if(i==2){
      return sc[j][k];
    }
    if(i==3){
      return sd[j][k];
    }
  }
  double se_out(int j, int k){
    return se[j][k];
  }
};


class Tree{
private:
  string tree[16], cur;
public:
  Tree(){
    for(i=0;i<16;i++){
      tree[i]="t";
    }
    cur="t";
  }
  string return_last(int i){
    return tree[tree[i].length()-1];
  }
  bool depth_of_cur_is_max (int D){
    if(cur.length()<D){
      cout<<"cur.length"<<cur.length()<<endl;
      return false;
    }
    else{
      return true;
    }
  }
  void state(){
    Tree::curr();
    for(i=0;i<16;i++){
      Tree::pwd(i);
    }
  }
  string pwd(int i){
    cout<<"tree["<<i<<"]:"<<tree[i]<<endl;
    return tree[i];
  }
  string curr(){
    cout<<"cur: "<<cur<<endl;
    return cur;
  }
  void next(){
    for(i=0;i<16;i++){
      if(tree[i].at(tree[i].length()-1)=='e'){}
      else{
        cur=tree[i];
        cout<<"cur->"<<cur<<endl;
        return;
        cout<<"cant look"<<endl;
      }
    }

  }
  bool next_exist(){
    if(tree[i].at(tree[i].length()-1)=='t')return true;
    for(i=0;i<16;i++){
      if(tree[i].at(tree[i].length()-1)!='e'){
        cout<<"tree last:"<<tree[i].at(tree[i].length()-1)<<endl;
        return true;
      }
    }
    cout<<"tree last:"<<tree[i].at(tree[i].length()-1)<<endl;
    return false;
  }
  void left(int i){
    cout<<"tree["<<i<<"]:"<<tree[i];
    tree[i].append(1, 'l');
    cout<<"->"<<tree[i]<<endl;
  }
  void right(int i){
    cout<<"tree["<<i<<"]:"<<tree[i];
    tree[i].append(1, 'r');
    cout<<"->"<<tree[i]<<endl;
  }
  void end(int i){
    cout<<"tree["<<i<<"]:"<<tree[i];
    tree[i].append(1, 'e');
    cout<<"->"<<tree[i]<<endl;
  }
  bool check_pwd(int i){
    if(tree[i]==cur){
      return true;
    }
    else {
      return false;
    }
  }
};


class divide_function : public Tree, public Set{
public:
  int max, ty,t;
  double *r, *I, Hl, left, right, left_[3], right_[3], tmp, Hr;//I 情報利得
  divide_function(){
    ty=1;
    t=0;//これは仮
    max=0;
    for(i=0;i<3;i++){
      left_[i]=0;
      right_[i]=0;
    }
  }

  bool search(int T){//entropy 0?
    int c1,c2,c3;
    c1=0;c2=0;c3=0;
    if(Tree::return_last(1)=="t"){
      return false;
    }
    for(i=0;i<16;i++){
      if(Tree::curr()==Tree::pwd(i)){
        if(Set::se_out(T-1, i)==1){
          c1++;
        }
        if(Set::se_out(T-1, i)==2){
          c2++;
        }
        if(Set::se_out(T-1, i)==3){
          c3++;
        }
      }
    }
    if(c1==0&&c2==0)return true;
    if(c3==0&&c2==0)return true;
    if(c1==0&&c3==0)return true;
    return false;
  }



  void learn(int depth, int K, int ty, int T){
    depth++;
    for(j=0;j<T;j++){//TkonoSubset nituite
      while(Tree::next_exist()){//mattann made itterumonoganakereba
        if(divide_function::search(T)||Tree::depth_of_cur_is_max(depth)){//entropy 0 or depth max
          if(divide_function::search(T))cout<<"search"<<endl;
          if(Tree::depth_of_cur_is_max(depth))cout<<"depthmax"<<endl;
          for(i=0;i<16;i++){
            if(Tree::check_pwd(i)){
              Tree::end(i);
            }
          }
          Tree::next();
        }
        else{
          divide_function::check(K, ty);
          Tree::next();
        }
      }
    }
  }
  void check(int K, int ty){
    r=(double*)malloc(sizeof(double)*K);
    I=(double*)malloc(sizeof(double)*K);
    switch (ty){//ty候補のタイプ
    case 1:       //候補タイプ1 変数の大きさについて単純にしきい値と比較
      for (i=0;i<K;i++){
        cout<<"K:"<<i<<"  "<<endl;
        left=0; right=0;
        Hl=0;Hr=0;
        for(j=0;j<3;j++){
          left_[i]=0;
          right_[i]=0;
        }
        //r[i]=6;
        //int tmp=100;
        //r[i]=(double)(rand()%100)/(double)100*8+3;
        srand((unsigned)time(NULL));
        r[i]=rand()%6+4;
        cout<<"r["<<i<<"]:"<<r[i]<<endl;

        for (j=0;j<16;j++){
          cout<<"    "<<j<<"bannme"<<endl;
          if(Tree::check_pwd(j)){//データ１６個の中で現在のディレクトリにあるものについて
            cout<<"curr directory:"<<Tree::curr()<<"    ";

            //cout<<"a"<<endl;
            if(Set::s_out(0,t,j)>r[i]){
              left++;
              cout<<"if true sa["<<t<<"]["<<j<<"]:"<<Set::s_out(0,t,j)<<endl;
              //cout<<"b"<<endl;
              cout<<"left:"<<left<<endl;
              if(Set::s_bool(4,t,j,1)){
                left_[0]++;
                cout<<"left_[0]:"<<left_[0]<<endl;
              }
              if(Set::s_bool(4,t,j,2)){
                left_[1]++;
                cout<<"left_[1]:"<<left_[1]<<endl;
              }
              if(Set::s_bool(4,t,j,3)){
                left_[2]++;
                cout<<"left_[2]:"<<left_[2]<<endl;
              }
            }
            else{
              cout<<"else sa["<<t<<"]["<<j<<"]:"<<Set::s_out(0,t,j)<<endl;
              right++;
              cout<<"j:"<<j<<endl;
              cout<<"se:"<<s_out(4, t, j)<<endl;
              cout<<"right:"<<right<<endl;
              if(Set::s_bool(4,t,j,1)){
                right_[0]++;
                cout<<"right_[0]:"<<right_[0]<<endl;
              }
              if(Set::s_bool(4,t,j,2)){
                right_[1]++;
                cout<<"right_[1]:"<<right_[1]<<endl;
              }
              if(Set::s_bool(4,t,j,3)){
                right_[2]++;
                cout<<"right_[2]:"<<right_[2]<<endl;
              }
              else{
                cout<<"else error"<<endl;
              }
            }
          }
        }
        cout<<"H"<<endl;
        for(j=0;j<3;j++){//H(Sl)の計算
          if(left_[j]==0){cout<<"left_["<<j<<"]:0"<<endl;}
          else{
            cout<<"left_["<<j<<"]"<<left_[j];
            cout<<"   left_["<<j<<"]/left:"<<(double)left_[j]/(double)left;
            cout<<"   Hl:"<<Hl<<"->";
            tmp=(double)left_[j]/(double)left;
            //cout<<"tmp:"<<tmp<<endl;
            Hl-=tmp*log2(tmp);
            cout<<"Hl:"<<Hl<<endl;
            //  cout<<"tmp:"<<tmp<<endl;
          }
        }
        for(j=0;j<3;j++){//H(Sr)の計算
          if(right_[j]==0){cout<<"right_["<<j<<"]:0"<<endl;}
          else{
            cout<<"right_["<<j<<"]:"<<right_[j];
            cout<<"   right_["<<j<<"]/right:"<<(double)(right_[j])/(double)right;
            cout<<"    Hr:"<<Hr<<"->";
            tmp=(double)(right_[j])/(double)right;
            //            cout<<"tmp:"<<tmp<<endl;
            Hr-=tmp*log2(tmp);
            cout<<"Hr:"<<Hr<<endl;
            //cout<<"tmp:"<<tmp<<endl;
          }
        }
        //I 情報利得
        I[i]=-(double)(left/(left+right))*Hl-(double)(right/(left+right))*Hr;
        cout<<"I["<<i<<"]:"<<I[i]<<endl;
        if(I[i]>I[max]){
          max=i;//情報利得が最大となるものの更新
        }
        cout<<"max:"<<max<<endl;
      }
      //Kkononakade最大となるrで分岐
      cout<<"r:"<<r[max]<<endl;
      for(j=0;j<16;j++){
        if(Tree::check_pwd(j)){//データ１６個の中で現在のディレクトリにあるものがあれば
          if(Set::s_out(0,t,j)>r[max]){
            Tree::left(j);
            cout<<"Tree::left("<<j<<")   "<<"Set::sa["<<t<<"]["<<j<<"]:"<<Set::s_out(0,t,j)<<endl<<endl;
          }
          else{
            Tree::right(j);
            cout<<"Tree::right("<<j<<")  "<<"Set::sa["<<t<<"]["<<j<<"]:"<<Set::s_out(0,t,j)<<endl<<endl;
          }
        }
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
  
  //Set s;
  divide_function s;
  for (i=0;i<T;i++){//T個のサブセットについて
    for (j=0;j<16;j++){
      s.in(i, j, rand()%150);
      //cout << rand()%150<<endl;
      //cout<< "i"<<i<<"   j"<<j<<endl;
    }
  }
  //s.print();
  

  //サブセットの数だけ木を作成する

  //  Tree tr;
  //divide_function dv;
  /*tr.pwd(0);
    tr.left(0);
    tr.right(0);
    tr.end(0);
    dv.check(1, 1);*/
  //s.check(2,1);
  //"lrle"
  //サブセットデータに現在のディレクトリ情報を持たせておく
  //if エントロピーが０ もしくは深さmax 何もない
  //else 
  for(i=0;i<16;i++){
    //tr.pwd(i);
  }
  //s.next();s.state();
  //s.next();  s.next();  s.next();

  s.learn(3, 1, 1, 1);
  s.state();
  return 0;
}


