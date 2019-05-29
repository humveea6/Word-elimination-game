#ifndef PLAYER_H
#define PLAYER_H
#include<qstring.h>
#include"user.h"

class Player : public User
{
public:
    Player();

    int cgs,jyvalue,level;          //闯关数，经验值，闯关等级

    bool operator ==(const Player &x)const{
        return name==x.name;
    }

    bool operator <(const Player &x)const{
        return name<x.name;
    }

//    bool operator =(const Player &x)const{
//        name=x.name;pwd=x.pwd;
//        cgs=x.cgs;jyvalue=x.jyvalue;level=x.level;
//    }
};


#endif // PLAYER_H
