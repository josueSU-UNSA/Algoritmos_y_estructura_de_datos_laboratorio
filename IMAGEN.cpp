 
#include<iostream>
#include "CImg.h"
#include<map>
#include<fstream>
#include<string>


using namespace std;
using namespace cimg_library;

typedef std::map< short int, std::map<short int , short int > >  TMatriz;

CImg<char>   Binarizar(CImg<float> & img, short int umbral)
{
    CImg<char> R(img.width(),img.height(),1);
    for(short int i=0;i<img.width();i++)
       for(short int j=0;j<img.height();j++)
       {
            float s = (img(i,j,0) + img(i,j,1) + img(i,j,2))/3;
            if(s > umbral)
                R(i,j) = 0;
            else
                R(i,j) = 255; 
           
       }
       return R;
}

TMatriz Comprimir(CImg<char> & img)
{
      TMatriz R;
       for(short int i=0;i<img.width();i++)
            for(short int j=0;j<img.height();j++)
            {
                   if(img(i,j)!=0) R[i][j] = -1;           
            }
        return R;
}

CImg<char> Descomprimir(TMatriz & R, short int fil, short int col)
{
    CImg<char> img(fil, col,1); 
    
    for(short int i=0;i<img.width();i++)
        for(short int j=0;j<img.height();j++)
            img(i,j,0) =-1;
        
    TMatriz::iterator it1 = R.begin();
    for(;it1!=R.end();++it1)
    {
       map<short int, short int> & C =     it1->second;
       map<short int, short int>::iterator it2 = C.begin();
       for(;it2!=C.end();++it2)
       {
          img(it1->first,it2->first) = 0; 
       }
       
    }
    // Write the code heare
    return img;
}

void saveDisk(TMatriz & R, string filename)
{
    ofstream file(filename,ios::binary);
    TMatriz::iterator fil = R.begin();
    for(;fil!=R.end();++fil)
    {
       map<short int, short int> & C =     fil->second;
       map<short int, short int>::iterator col = C.begin();
       for(;col!=C.end();++col)
       {
          file<<(char)fil->first;
          file<<(char)col->first; 
         
       }
       file<<(char)fil->first;
       file<<-1;
       cout<<"Grabando disco"<<endl;
    }
    
}
CImg<char> loadDisk(string filename){
    CImg<char> img(fil, col,1); 
    
    for(short int i=0;i<img.width();i++)
        for(short int j=0;j<img.height();j++)
            img(i,j,0) =-1;
        
    TMatriz::iterator it1 = R.begin();
    for(;it1!=R.end();++it1)
    {
       map<short int, short int> & C =     it1->second;
       map<short int, short int>::iterator it2 = C.begin();
       for(;it2!=C.end();++it2)
       {
          img(it1->first,it2->first) = 0; 
       }
       
    }
    // Write the code heare
    return img;

}
 int main()
{
     TMatriz Img;
     CImg<float>  A("foto1.bmp");
     A.display();
     CImg<char> R = Binarizar(A,80);
     R.display();
     Img = Comprimir(R);
     saveDisk(Img, "img.cmp");
    /* TMatriz M = loadDisk("img.cmp");
     CImg<char> D = Descomprimir(M,A.width(), A.height());*/
   //  D.display();
   
    
    return 1;
}
