#pragma once
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class mystring{

    friend ostream&operator<<(ostream&out,const mystring&s);
    friend istream&operator>>(istream&in,mystring&s);

private:
    char *p;
    int len;;

public:
    mystring();
    ~mystring();

public :
    mystring(const char *s);
    mystring(mystring const&s);
    char operator[](const int i);
    mystring& operator=(const mystring&s);
    mystring& operator=(const char * s);
    bool operator==(mystring const&s);
    bool operator==(const char *s);
    bool operator!=(const char *s);
    bool operator!=(const mystring&s);
    bool operator<(const mystring&s);
    bool operator<(const char *s);
    bool operator>(const mystring &s);
    int length();
    bool operator>(const char *s);
    int indexof(const char& s);
    int lastIndexOf(const char &s);
    char *substring(int start,int end);
    char * data();
};

int mystring::lastIndexOf(const char& s){
    
    if(len==0){
        return -1;
    }
    for(int i=len-1;i>=0;i--){
        if(p[i]==s)return i;
    }
    return -1;
}
int mystring::length(){
    return len;
}
int mystring::indexof(const char&s){
    for(int i=0;i<len;i++){
        if(p[i]==s){
            return i;
        }
    }
    return -1;
}

bool mystring::operator!=(const mystring&s){
    return strcmp(p,s.p)?true:false;
}

bool mystring ::operator!=(const char*s){
    return strcmp(p,s)?true:false;
}

bool mystring::operator<(const mystring&s){
    if(strcmp(p,s.p)<0){
        return true;
    }
    else{
        return false;
    }
}

bool mystring::operator<(const char*s){ 

    if(strcmp(p,s)>0){
        return false;
    }
    else{
        return true;
    }
}
bool mystring::operator>(const mystring&s){
    
    if(strcmp(p,s.p)>0){
        return true;
    }
    else{
        return false;
    }
}
bool mystring::operator>(const char*s){
    if(strcmp(p,s)>0){
        return true;
    }
    return false;
}
char * mystring::data(){
    return p;
}

bool mystring ::operator==(const mystring&s){
    
    return strcmp(p,s.p)?0:1;
}

bool mystring::operator==(const char *s){
    return strcmp(p,s)?0:1;
}

char mystring::operator[](const int i){
    
    if(i>len){
        cout<<"out of index"<<endl;
        exit(1);
    }
    else{
        return p[i];
    }
}

ostream&operator<<(ostream&out,const mystring &s){
    out<<s.p;
    return out;
}

istream&operator>>(istream&in,mystring &s){

    cin>>s.p;
    return in;
}
mystring ::mystring(){
    
    len = 0 ;
    p = new char[len+1];
    strcpy(p,"");
}
mystring::~mystring(){

    len = 0; 
    delete[]p;
    p =NULL;
}
mystring& mystring::operator=(mystring const&s){
    
    len = s.len ;
    p = new char[len+1];
    strcpy(p,s.p);
    return *this;
}

mystring& mystring::operator=(const char *s){

    if(!strcmp(s,"")||s==NULL){
        len = 0 ;
        p = new char[len+1];
        strcpy(p,"");
    }
    else{
        len = strlen(s);
        p = new char[len+1];
        strcpy(p,s);
    }
    return *this;
}

char* mystring :: substring(int start, int end)
{   

    if((end-start) < 0|| end > len)
    {
        return NULL ;
    }

    char *q ; 
    q = (char* )malloc (end-start+3);
    strncpy(q, p+start, end-start) ;
    return q ;
}

mystring::mystring(const char*s){

    if(!strcmp(s,"")||s==NULL){
        len = 0 ;
        p = new char[len+1];
    }
    else{
        len= strlen(s);
        p = new char[len+1];
        strcpy(p,s);
    }
}

mystring :: mystring(mystring const& s)
{
    if(s.len == 0)
    {
        p = NULL ;
    }
    int len = strlen(s.p) ;
    p = new char[len+1] ;
    strcpy(p, s.p) ;
}
