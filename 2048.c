#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h> 
int X[4][4],W[4][4];
char keyset1;/*记录玩家输入哪个键，用于游戏*/
char keyset2;/*记录玩家输入哪个键，用于交互*/
int keyset3;/*记录玩家输入哪个键，用于交互*/
int round;/*记录玩家玩了几轮*/

void show(int Z[4][4]);/*展示数组*/
int plus1(int a);
int plus2(int b);/*在合并同样的数的时候，前数乘2，后数变为0*/
void swap(int *a,int *b);/*用于交换数组两个元素的位置*/ 
void loser(int a);/*用户输了以后执行的操作*/
void rright(int*Z);void rleft(int*Z);void cup(int*Z);void cdown(int*Z);/* 用于合并同样数的函数*/
void srright(int*Z);void srleft(int*Z);void scup(int*Z);void scdown(int*Z);/*用于将一行（列）中的0放到一边*/
int check(int Z[4][4]);/*输了返回0，否则返回1*/
int equal(int Y[4][4],int Z[4][4]); /*用于比较两数组是否相等，等返回1，不等返回0*/ 
void copy(int *Y,int *Z); /*用于克隆数组*/ 

/*----------------------------分隔符——————————————---------------------------*/
int main(){
srand(time(NULL));  

int a,b,o;/*用于控制循环*/
int i,j,k; /*用于出随机数*/ 
int p,q; 
int lose;/*0/1，看是否输了，0是输*/
int max;
int V[4][4];
printf("欢迎进入2048游戏！！\n");
printf("请问您是否要看游戏规则，是的话请输入k，否的话请输入j直接开始游戏\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='k'){
printf("规则如下：\n");
printf("本游戏在一个4×4的棋盘中进行\n"); 
printf("开始时棋盘内随机出现两个数字，出现的数字仅可能为2或4\n");
printf("玩家可以选择W(上)、A（左）、S（下）、D（右）去移动滑块\n");
printf("玩家选择的方向上若有相同的数字则合并\n");
printf("玩家选择的方向行或列前方有空格则出现位移\n");
printf("每移动一步，空位随机出现一个2或4\n");
printf("棋盘被数字填满，无法进行有效移动，判负，游戏结束\n");
printf("本游戏没有大结局！请尽你所能得到最大数字！\n");
printf("请输入k开始游戏\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='k')
break;}break;}
else if(keyset2=='j'){
break;
}else;}
/*----------------------------------下面正式开始！！-------------------------------------*/

bb: printf("游戏开始!!\n");
for(a=0;a<=3;a++){
for(b=0;b<=3;b++){
X[a][b]=0;
}}

for(round=1;1;round++){

if(round!=1){
if(equal(V,X)==1){
round--;
goto aa;}
q=0;
for(p=0;p<=15;p++){
    if(*(&X[0][0]+p)==0)
    q++;
}
j=(int)((rand()%q)+1);
for(p=0;p<=15;p++){
    if(*(&X[0][0]+p)==0)
    j--;
    if(j==0){
    if(rand()%10<=8)
    *(&X[0][0]+p)=2;
    if(rand()%10==9)
    *(&X[0][0]+p)=4;
    break;}
}
copy(&V[0][0],&X[0][0]);
lose=check(X);
if(lose==0){
printf("第%d轮",round);
show(X);
max=X[0][0];
for(o=1;o<=15;o++){
    if(*(&X[0][0]+o)>=max)
    max=*(&X[0][0]+o);
}
loser(max);}
else
printf("第%d轮",round);
show(X);}


else if(round==1){
i=(int)((rand()%2)*2+2);
j=(int)(rand()%16);
*(&X[0][0]+j)=i;
i=(int)((rand()%2)*2+2);
k=(int)(rand()%16);
for(;k==j;){
k=(int)(rand()%16);}
*(&X[0][0]+k)=i;
printf("第1轮");
show(X);
copy(&V[0][0],&X[0][0]);}

aa:keyset1=getch();
switch(keyset1){   /*a左，d右，s下，w上*/
case 'a':srleft(&X[0][0]);rleft(&X[0][0]);srleft(&X[0][0]);break;
case 'd':srright(&X[0][0]);rright(&X[0][0]);srright(&X[0][0]);break;
case 's':scdown(&X[0][0]);cdown(&X[0][0]);scdown(&X[0][0]);break;
case 'w':scup(&X[0][0]);cup(&X[0][0]);scup(&X[0][0]);break;}    /*end switch*/
}/*end for*/
}/*end main*/

/*-----------------结束----------------------------*/

/*-------------rright函数库---------------------*/
void rright(int *Z){
int b;
for(b=0;b<=12;b=b+4){
    if(*(Z+b+3)==*(Z+b+2)){
    *(Z+b+3)=plus1(*(Z+b+3));
    *(Z+b+2)=plus2(*(Z+b+2));
    if(*(Z+b+1)==*(Z+b+0)){
    *(Z+b+1)=plus1(*(Z+b+1));
    *(Z+b+0)=plus2(*(Z+b+0));}}
    else if(*(Z+b+2)==*(Z+b+1)){  
    *(Z+b+2)=plus1(*(Z+b+2));
    *(Z+b+1)=plus2(*(Z+b+1));}
    else if(*(Z+b+1)==*(Z+b+0)){  
    *(Z+b+1)=plus1(*(Z+b+1));
    *(Z+b+0)=plus2(*(Z+b+0));}

}}

void rleft(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[i/4][3-j]=*(Z+i+j);}}
rright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[i/4][3-j];}}}

void cup(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[j][3-i/4]=*(Z+i+j);}}
rright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[j][3-i/4];}}}


void cdown(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[3-j][i/4]=*(Z+i+j);}}
rright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[3-j][i/4];}}}
int plus1(int a){
    return 2*a;
}
int plus2(int a){
    return 0;
}


/*-------------rright函数库---------------------*/

/*-------------srright函数库---------------------*/
void swap(int*a,int*b){
int c;
c=*a;
*a=*b;
*b=c;}



void srright(int*Z){
int i;
for(i=0;i<=12;i=i+4){
if(*(Z+i+3)!=0){
if(*(Z+i+2)!=0){
if(*(Z+i+1)==0)
swap((Z+i+1),(Z+i));}
else {
swap((Z+i+2),(Z+i+1));
swap((Z+i+1),(Z+i));
if(*(Z+i+2)==0){
swap((Z+i+2),(Z+i+1));}}}

else if(*(Z+i+3)==0){
swap((Z+i+3),(Z+i+2));
swap((Z+i+2),(Z+i+1));
swap((Z+i+1),(Z+i+0));
if(*(Z+i+3)!=0){
if(*(Z+i+2)==0)
swap((Z+i+2),(Z+i+1));}
else if(*(Z+i+3)==0){
swap((Z+i+3),(Z+i+2));
swap((Z+i+2),(Z+i+1));
if(*(Z+i+3)==0)
swap((Z+i+3),(Z+i+2));}}
}}

void srleft(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[i/4][3-j]=*(Z+i+j);}}
srright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[i/4][3-j];}}}

void scup(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[j][3-i/4]=*(Z+i+j);}}
srright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[j][3-i/4];}}}


void scdown(int*Z){
int Y[4][4];
int i,j;
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
    Y[3-j][i/4]=*(Z+i+j);}}
srright(&Y[0][0]);
for(i=0;i<=12;i=i+4){
for(j=0;j<=3;j++){
*(Z+i+j)=Y[3-j][i/4];}}}




/*-------------srright函数库---------------------*/

/*--------------show函数------------------------*/
void show(int Z[4][4]){
int a,b;
printf("\n************************\n");
for(a=0;a<=3;a++){
for(b=0;b<=3;b++){
if(Z[a][b]==0)
printf("[    ]");
else
printf("[%4d]",Z[a][b]);
if(b==3)
printf("\n");}}
printf("************************\n");}

/*--------------show函数------------------------*/

/*------------check函数库-----------------------*/

void copy(int*Y,int*Z){
    int a;
    for(a=0;a<=15;a++){
        *(Y+a)=*(Z+a);
    }
}

int equal(int Y[4][4],int Z[4][4]){
int a,b;
for(a=0;a<=3;a++){
for(b=0;b<=3;b++){
if (Y[a][b]!=Z[a][b])
return 0;}}
return 1;}

int check(int Z[4][4]){
int a,b,c=0,W[4][4];
for(a=0;a<=3;a++){
for(b=0;b<=3;b++){
if(Z[a][b]==0)
c++;}}
if(c==0){
copy(&W[0][0],&Z[0][0]);
rleft(&W[0][0]);
if(equal(W,Z)==1){
rright(&W[0][0]);
if(equal(W,Z)==1){
cdown(&W[0][0]);
if(equal(W,Z)==1){
cup(&W[0][0]);
if(equal(W,Z)==1)
return 0;
else return 1;}
else return 1;}
else return 1;}
else return 1;}
else return 1;}
/*------------check函数库-----------------------*/

/*-------------loser函数-----------------------*/ 
void loser(int a){
printf("你输了！你生存了%d轮！\n",round);
printf("你得到的最大数字是%d\n",a);
printf("继续加油！"); 
printf("输入e来退出！\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='e')
exit(1);
else
;}}

/*-------------loser函数-----------------------*/ 


