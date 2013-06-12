// Made for Mario Paintasy (MPXVI)
// (c) 2009 by RehdBlob
// Version 4.0

#include <iostream.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int restart = 1;
int totnetdamage, percent;
double spattack, atk, spatklvl;
double coredamage, attack, defense, damage, netdamage;
srand(time(NULL));
while (restart > 0)
{
system("CLS");
cout << "Special Attack or Regular Attack?" << endl;
cout << "(1) Regular" << endl << "(2) Special" << endl;
cin >> atk;
if (atk == 1)
{
cout << "Type in your level" << endl;
cout << "/rolldie " ;
cin >> percent;
coredamage = rand() % percent + 1;
cout << "Rolldie resulted in: " << coredamage << endl;
cout <<"What is your attack?"<<endl<<"(1)Medium"<<endl<<"(2)High"<<endl;
cout <<"(3)Low"<<endl;
cin >> attack;
if (attack == 1)
{
damage = coredamage;
}
if (attack == 2)
{
damage = 1.5 * coredamage;
}
if (attack == 3)
{
damage = 0.5 * coredamage;
}
cout <<"What is the enemy's defense?"<<endl<<"(1)Medium"<<endl<<"(2)High"<<endl;
cout <<"(3)Low"<<endl<<"(4)The enemy is weak to my type of attack"<<endl;
cout <<"(5)The enemy is resistant to my type of attack"<<endl;
cin >> defense;
if (defense == 1)
{
netdamage = damage;
}
if (defense == 2)
{
netdamage = 0.5 * damage;
}
if (defense == 3)
{
netdamage = 1.5 * damage;
}
if (defense == 4)
{
netdamage = 1.5 * damage;
}
if (defense == 5)
{
netdamage = 0.5 * damage;
}
totnetdamage = netdamage + 0.75;
cout << "The damage dealt is " << totnetdamage << " ." << endl;
}
else if (atk == 2)
{
cout << "Special Attack: " << endl << "(1) Medium";
cout << endl << "(2) High" << endl << "(3) Low" << endl;
cin >> spattack;
cout << "Level Skill was learned at: ";
cin >> spatklvl;
attack = spattack;
if (spattack == 3)
{
spattack = 0.5;
}
int special = spattack * spatklvl + 0.5;
cout << special << " is the amount you need to put into '/rolldie' " << endl;
cout << "/rolldie " ;
cin >> percent;
coredamage = rand() % percent + 1;
cout << "Rolldie resulted in: " << coredamage << endl;
if (attack == 1)
{
damage = coredamage;
}
if (attack == 2)
{
damage = 1.5 * coredamage;
}
if (attack == 3)
{
damage = 0.5 * coredamage;
}
cout <<"What is the enemy's defense?"<<endl<<"(1)Medium"<<endl<<"(2)High"<<endl;
cout <<"(3)Low"<<endl<<"(4)The enemy is weak to my type of attack"<<endl;
cout <<"(5)The enemy is resistant to my type of attack"<<endl;
cin >> defense;
if (defense == 1)
{
netdamage = damage;
}
if (defense == 2)
{
netdamage = 0.5 * damage;
}
if (defense == 3)
{
netdamage = 1.5 * damage;
}
if (defense == 4)
{
netdamage = 1.5 * damage;
}
if (defense == 5)
{
netdamage = 0.5 * damage;
}
totnetdamage = netdamage + 0.75;
cout << "The damage dealt is " << totnetdamage << " ." << endl;
}

cout << "Do another damage calculation?"<<endl<<"(1)Yes"<<endl<<"(2)No"<<endl;
cin >> restart;
if (restart == 1)
{
restart = 1;
}
else
{
restart = 0;
}
}
system("PAUSE");
return 0;
}
