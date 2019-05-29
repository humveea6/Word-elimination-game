#ifndef QUESTIONER_H
#define QUESTIONER_H
#include<qstring.h>
#include "user.h"
class Questioner : public User
{
public:
    Questioner();
    int ctnum;    //出题数目，等级

    bool operator ==(const Questioner &x)const{
        return name==x.name;
    }

    bool operator <(const Questioner &x)const{
        return name<x.name;
    }

//    bool operator =(const Questioner &x)const{
//        name=x.name;pwd=x.pwd;
//        ctnum=x.ctnum;level=x.level;
//    }
};

#endif // QUESTIONER_H
