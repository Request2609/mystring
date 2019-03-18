#include"mystring.h"

int main()
{
    mystring s = "changke" ;
    mystring ss = s ;

    if(ss == s){
        cout << ss <<endl ;;
    }
    cout << s << endl ;
    cout << s[1] <<endl;   
    cout<<s.substring(1,4)<<endl ; 

}
