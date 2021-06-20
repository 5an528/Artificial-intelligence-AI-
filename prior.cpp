#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std ;

int numberofobject = 0 ;

struct classL
{
    string className ;
    int classFrequency ;
}temp;


struct classS
{
    string classSize ;
    int classNumber ;
}temp1;

vector<classL>classList ;
vector<classS>classLists ;



int main()
{

    char a[100], c[100];
    FILE *fptr;
    if ((fptr = fopen("data.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF){
         numberofobject++ ;
        string c2(a) ;
         bool flag1 = false ;
        string cl(c) ;
         bool flag = false ;
         for(int i = 0 ; i < classList.size() ; i++){
            if(cl == classList[i].className)
            {
                flag = true ;
                classList[i].classFrequency++ ;
            }
         }
         if(!flag)
         {
              temp.classFrequency = 1 ;
              temp.className = cl ;
              classList.push_back(temp) ;

         }
         for(int i = 0 ; i < classLists.size() ; i++){
            if(c2 == classLists[i].classSize)
            {
                flag1 = true ;
                classLists[i].classNumber++ ;
            }
         }
         if(!flag1)
         {
              temp1.classNumber = 1 ;
              temp1.classSize = c2 ;
              classLists.push_back(temp1) ;

         }


    }

    printf("sample size: %d\n", numberofobject) ;
    for(int i = 0 ; i < classList.size() ; i++){
       cout << "P("<< classList[i].className << ")"<< " : "<< (1.00*classList[i].classFrequency)/numberofobject << endl ;

       cout << "P("<< classLists[i].classSize << ")"<< " : "<< (1.00*classLists[i].classNumber)/numberofobject << endl ;

       cout<<"p("<< classList[i].className << "|"<< classLists[i].classSize <<")"<<" : "<<(((1.00*classList[i].classFrequency)/numberofobject)+((1.00*classLists[i].classNumber)/numberofobject)/(1.00*classList[i].classFrequency)/numberofobject  )<<endl;

       cout<<"p("<< classList[0].className << "|"<< classList[1].className <<")"<<" : "<<(((1.00*classList[0].classFrequency)/numberofobject)+((1.00*classList[1].classFrequency)/numberofobject)/(1.00*classList[0].classFrequency)/numberofobject  )<<endl;
       }


}
