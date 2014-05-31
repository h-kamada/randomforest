#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int i, j;
/*
class divide_function{
 public:
  int left, right, left_[3], right_[3], max;
  double r[K], I[K];//I 情報利得
  void divide_function(){
    ty=1;
    max=0;
  }

  void check(int K, int ty){
    switch (ty){//ty候補のタイプ
    case 1:       //候補タイプ1 変数の大きさについて単純にしきい値と比較
      for (i=0;i<K;i++){
        for (j=0;j<16;j++){
          if(tree.pwd(j)==tree.cur()){//データ１６個の中で現在のディレクトリにあるものがあれば
            r[i]=(double)((rand()/(RAND_MAX+1))*8);
            left=0; right=0;
            cout<<"r:"<<r[i]<<endl;
            if(Set::sa[t][j]>r[i]){
              left++;
              if(Set::se[t][j]==1){
                left_[0]++;
              }
              if(Set::se[t][j]==2){
                left_[1]++;
              }
              if(Set::se[t][j]==3){
                left_[2]++;
              }
            }
            else{
              right++;
              if(Set::se[t][j]==1){
                right_[0]++;
              }
              if(Set::se[t][j]==2){
                right_[1]++;
              }
              if(Set::se[t][j]==3){
                right_[2]++;
              }
            }
          }
        }
        for(j=0;j<3;j++){//H(Sl)の計算
          if(left_[j]==0){}
          else{
            Hl-=(double)(left_[j]/left)*log2((double)(left_[j]/left));
          }
        }
        for(j=0;j<3;j++){//H(Sr)の計算
          if(right_[j]==0){}
          else{
            Hr-=(double)(right_[j]/right)*log2((double)(right_[j]/right));
          }
        }
        //I 情報利得
        I[i]=-(double)(left/(left+right))*Hl-(double)(right/(left+right))*Hr;
        if(I[i]>I[max]){
          max=i;//情報利得が最大となるものの更新
        }
      }
      //最大となるrで分岐
      if(tree.pwd(i)==tree.cur()){//データ１６個の中で現在のディレクトリにあるものがあれば
        if(Set::sa[t][j]>r[i]){
          tree.left(i);
        }
        else{
          tree.right(i);
        }
      }
    }      
  }
};
*/
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
  string pwd(int i){
    return tree[i];
  }
  string curr(){
    return cur;
  }
  void next(){
    if(i=0;i<16;i++){
      if(tree[i].endsWith("e")){}//間違ってるっぽい
      else{
        cur=tree[i];
      }
    }
  }
  void left(int i){
  }
  void right(int i){
  }
};

