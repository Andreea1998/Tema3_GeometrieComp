#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct punct{
    char l;
    float x,y;
};


float determinant(float a1, float b1, float a2, float b2){
   return ((a1*b2)-(b1*a2));
}

float distanta(punct A, punct B){
  return(sqrt((B.y-A.y)*(B.y-A.y)+(B.x-A.x)*(B.x-A.x)));
}
int main(){
    punct v[4];
    punct A,B,C,D;
    cout<<"A(x,y): ";
    cin>>A.x>>A.y;
    cout<<"B(x,y): ";
    cin>>B.x>>B.y;
    cout<<"C(x,y): ";
    cin>>C.x>>C.y;
    cout<<"D(x,y): ";
    cin>>D.x>>D.y;
    A.l='A';
    B.l='B';
    C.l='C';
    D.l='D';
    int i;
    v[0].l=A.l; v[0].x=A.x; v[0].y=A.y;
    v[1].l=B.l; v[1].x=B.x; v[1].y=B.y;
    v[2].l=C.l; v[2].x=C.x; v[2].y=C.y;
    v[3].l=D.l; v[3].x=D.x; v[3].y=D.y;
    cout<<endl;
    float a1,a2,b1,b2,c1,c2;
    a1=A.y-B.y;
    a2=C.y-D.y;
    b1=B.x-A.x;
    b2=D.x-C.x;
    c1=A.x*B.y - A.y*B.x;
    c2=C.x*D.y - C.y*D.x;

    if(determinant(a1,b1,a2,b2)!=0){ //intersectia e un punct
        punct M;
        M.x=determinant(-c1,b1,-c2,b2)/determinant(a1,b1,a2,b2);
        M.y=determinant(a1,-c1,a2,-c2)/determinant(a1,b1,a2,b2); //calculez coordonatele lui M
        cout<<"Avem punctul M"<<"("<<M.x<<","<<M.y<<")"; //coordonatele punctului M;
        if(distanta(A,B)==(distanta(A,M)+distanta(M,B)) && distanta(C,D)==(distanta(C,M)+distanta(M,D)) ){ //verific daca se intersecteaza segmentele (nu doar dreptele)
            cout<<"Intersectia segmentelor [AB] si [CD] este punctul M."<<endl;
        }else
            cout<<"Intersectia segmentelor [AB] si [CD] este vida.\n"<<endl;

    }else
        if(determinant(a1,c1,a2,c2)==0 && determinant(b1,c1,b2,c2)==0 && determinant(a1,b1,a2,b2)==0){
            cout<<"AB si CD sunt pe aceeasi dreapta"<<endl; //se afla pe aceeasi dreapta (AB=CD)

            if(A.x>B.x || ((A.x==B.x) && (A.y>B.y))){
                swap(A,B);
            }

            if(C.x>D.x || ((C.x==D.x) && (C.y>D.y))){
                swap(C,D);
            }

            if((B.x<C.x || ((B.x==C.x) && (B.y<C.y))) || (D.x<A.x || ((D.x==A.x) && (D.y<A.y)))){
                cout<<"Intersectia segmentelor [AB] si [CD] este vida."<<endl;
            }
            else{
                int i,j;
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                        if(v[i].x>v[j].x || (v[i].x==v[j].x && v[i].y>v[j].y))
                            swap(v[i],v[j]);

                cout<<"Intersectia segmentelor [AB] si [CD] este "<<"["<<v[1].l<<v[2].l<<"]"<<endl;

            }

        }else{
            cout<<"AB || CD"<<endl;
            cout<<"Intersectia segmentelor [AB] si [CD] este vida."<<endl;
        }

        return 0;
}
