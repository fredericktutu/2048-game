#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h> 
int X[4][4],W[4][4];
char keyset1;/*��¼��������ĸ�����������Ϸ*/
char keyset2;/*��¼��������ĸ��������ڽ���*/
int keyset3;/*��¼��������ĸ��������ڽ���*/
int round;/*��¼������˼���*/

void show(int Z[4][4]);/*չʾ����*/
int plus1(int a);
int plus2(int b);/*�ںϲ�ͬ��������ʱ��ǰ����2��������Ϊ0*/
void swap(int *a,int *b);/*���ڽ�����������Ԫ�ص�λ��*/ 
void loser(int a);/*�û������Ժ�ִ�еĲ���*/
void rright(int*Z);void rleft(int*Z);void cup(int*Z);void cdown(int*Z);/* ���ںϲ�ͬ�����ĺ���*/
void srright(int*Z);void srleft(int*Z);void scup(int*Z);void scdown(int*Z);/*���ڽ�һ�У��У��е�0�ŵ�һ��*/
int check(int Z[4][4]);/*���˷���0�����򷵻�1*/
int equal(int Y[4][4],int Z[4][4]); /*���ڱȽ��������Ƿ���ȣ��ȷ���1�����ȷ���0*/ 
void copy(int *Y,int *Z); /*���ڿ�¡����*/ 

/*----------------------------�ָ�������������������������������---------------------------*/
int main(){
srand(time(NULL));  

int a,b,o;/*���ڿ���ѭ��*/
int i,j,k; /*���ڳ������*/ 
int p,q; 
int lose;/*0/1�����Ƿ����ˣ�0����*/
int max;
int V[4][4];
printf("��ӭ����2048��Ϸ����\n");
printf("�������Ƿ�Ҫ����Ϸ�����ǵĻ�������k����Ļ�������jֱ�ӿ�ʼ��Ϸ\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='k'){
printf("�������£�\n");
printf("����Ϸ��һ��4��4�������н���\n"); 
printf("��ʼʱ��������������������֣����ֵ����ֽ�����Ϊ2��4\n");
printf("��ҿ���ѡ��W(��)��A���󣩡�S���£���D���ң�ȥ�ƶ�����\n");
printf("���ѡ��ķ�����������ͬ��������ϲ�\n");
printf("���ѡ��ķ����л���ǰ���пո������λ��\n");
printf("ÿ�ƶ�һ������λ�������һ��2��4\n");
printf("���̱������������޷�������Ч�ƶ����и�����Ϸ����\n");
printf("����Ϸû�д��֣��뾡�����ܵõ�������֣�\n");
printf("������k��ʼ��Ϸ\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='k')
break;}break;}
else if(keyset2=='j'){
break;
}else;}
/*----------------------------------������ʽ��ʼ����-------------------------------------*/

bb: printf("��Ϸ��ʼ!!\n");
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
printf("��%d��",round);
show(X);
max=X[0][0];
for(o=1;o<=15;o++){
    if(*(&X[0][0]+o)>=max)
    max=*(&X[0][0]+o);
}
loser(max);}
else
printf("��%d��",round);
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
printf("��1��");
show(X);
copy(&V[0][0],&X[0][0]);}

aa:keyset1=getch();
switch(keyset1){   /*a��d�ң�s�£�w��*/
case 'a':srleft(&X[0][0]);rleft(&X[0][0]);srleft(&X[0][0]);break;
case 'd':srright(&X[0][0]);rright(&X[0][0]);srright(&X[0][0]);break;
case 's':scdown(&X[0][0]);cdown(&X[0][0]);scdown(&X[0][0]);break;
case 'w':scup(&X[0][0]);cup(&X[0][0]);scup(&X[0][0]);break;}    /*end switch*/
}/*end for*/
}/*end main*/

/*-----------------����----------------------------*/

/*-------------rright������---------------------*/
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


/*-------------rright������---------------------*/

/*-------------srright������---------------------*/
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




/*-------------srright������---------------------*/

/*--------------show����------------------------*/
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

/*--------------show����------------------------*/

/*------------check������-----------------------*/

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
/*------------check������-----------------------*/

/*-------------loser����-----------------------*/ 
void loser(int a){
printf("�����ˣ���������%d�֣�\n",round);
printf("��õ������������%d\n",a);
printf("�������ͣ�"); 
printf("����e���˳���\n");
for(;1;){
scanf("%c",&keyset2);
if(keyset2=='e')
exit(1);
else
;}}

/*-------------loser����-----------------------*/ 


