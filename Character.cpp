/****************************************************************************\
                     Character Tracking Program v1.5
                     (c) 2009 By: RehdBlob
\****************************************************************************/
#include <fstream.h>
#include <stdlib.h>
#include <time.h>

int totalhealth, fullhealth;
void health();
void damage();
void setup();
void stats();
void EXP();
void mainmenu();
void tothealth();
void help();
void SP();

int main()
{
char c1;
ifstream in;
ofstream out;
out.open("character.txt", ios::app);
in.open("character.txt", ios::in);
in >> c1;
if (!in.eof())
   {
   out.close();
   in.close();
   health();
   mainmenu();
   }
else if (in.eof())
     {
     int HP, atk, def, sp, spdef, spd, lvl, exp;
     char character[20];
     cout << "Character Name (20 chars. max): ";
     cin.get(character, 20);
     cin.ignore(1, '\n');
     cout << "--SETUP--\n";
     cout << "Choose high, medium, or low for the following. The stats must balance.\n";
     cout << "HP:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> HP;
     cout << "Attack:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> atk;
     cout << "Defense:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> def;
     cout << "Special:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> sp;
     cout << "Special Defense:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> spdef;
     cout << "Speed:\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> spd;
     cout << "Level: ";
     cin >> lvl;
     cout << "EXP remaining before level up: ";
     cin >> exp;
     out << character << endl;
     out << atk << endl << def << endl;
     out << sp << endl << spdef << endl << spd << endl << lvl << endl;
     if (HP == 1)
        {
        totalhealth = 8 * lvl;
        }
     if (HP == 2)
        {
        totalhealth = 6 * lvl;
        }
     if (HP == 3)
        {
        totalhealth = 4 * lvl;
        }
     out << totalhealth << endl;
     out << exp << endl;
     in.close();
     out.close();
     health();
     mainmenu();
     }
system("PAUSE");
return 0;
}

void mainmenu()
{
char choice;
for (int i = 1; i = 1; i += 0)
      {
      system ("CLS");
      cout << "--MAIN MENU--\n";
      cout << "(1) Current Stats\n(2) EXP\n(3) HP Calculation\n(4) SP Calculation\n";
      cout << "(5) Damage Calculation\n(6) Info/Help\n(7) Exit\n";
      cin >> choice;
      if (choice == '1')
         {
         stats();
         continue;
         }
      if (choice == '2')
         {
         EXP();
         continue;
         }
      if (choice == '3')
         {
         tothealth();
         continue;
         }
      if (choice == '4')
         {
         SP();
         continue;
         }
      if (choice == '5')
         {
         damage();
         continue;
         }
      if (choice == '6')
         {
         help();
         continue;
         }
      if (choice == '7')
         {
         break;
         }
      else
          continue;
      }
}

void health()
{
int HP;
ifstream in;
in.open("character.txt", ios::in);
in.ignore(21, '\n');
for (int j = 1; j <= 6; j++)
    in.ignore(2, '\n');
in >> HP;
totalhealth = fullhealth = HP;
in.close();
}


void EXP()
{
char choice;
int fHP, atk, def, sp, spdef, spd, lvl, exp, gain, remain;
char character[20];
ifstream in;
ofstream out;
in.open("character.txt", ios::in);
in.get (character,20);
in.ignore (1, '\n');
in >> atk >> def >> sp >> spdef >> spd >> lvl >> fHP >> exp;
in.close();
int prevlvl = lvl;
cout << "--EXP CALCULATION--\n";
cout << "(1) Gain EXP\n(2) Check Current EXP\n(3) Exit this submenu\n";
cin >> choice;
if (choice == '1')
   {
   cout << "Gain how much EXP?\n";
   cin >> gain;
   cout << "/me gained " << gain << " EXP.\n";
   exp -= gain;
   if (exp <= 0)
      {
      cout << "/me leveled up to Level ";
      if (fHP == lvl * 4)
         {
         lvl += 1;
         fHP = lvl * 4;
         }
      if (fHP == lvl * 6)
         {
         lvl += 1;
         fHP = lvl * 6;
         }
      if (fHP == lvl * 8)
         {
         lvl += 1;
         fHP = lvl * 8;
         }
      cout << lvl << endl;;
      if (lvl <= 10)
         {
         exp += lvl;
         }
      if (lvl > 10)
         {
         exp += 10;
         }
      }
   if (lvl <= 10)
      {
      remain = lvl;
      }
   if (lvl > 10)
      {
      remain = 10;
      }
   if (lvl <= 10)
      {
      cout << "Level " << lvl << endl << lvl - exp << " / " << remain << " exp"<< endl;
      }
   if (lvl > 10)
      {
      cout << "Level " << lvl << endl << 10 - exp << " / " << remain << " exp"<< endl;
      }
   out.open ("character.txt", ios::out);
   out << character << endl;
   out << atk << endl << def << endl;
   out << sp << endl << spdef << endl << spd << endl << lvl << endl;
   out << fHP << endl;
   out << exp << endl;
   out.close();
   if (lvl != prevlvl)
      {
      health();
      }
   }
if (choice == '2')
   {
   if (lvl <= 10)
      {
      cout << "Level " << lvl << endl << lvl - exp << " / " << lvl << " exp"<< endl;
      }
   if (lvl > 10)
      {
      cout << "Level " << lvl << endl << 10 - exp << " / 10 exp"<< endl;
      }
   }

system("PAUSE");
}


void stats()
{
char character[20];
int atk, def, sp, spdef, spd, lvl, exp, remain;
ifstream in;
in.open("character.txt", ios::in);
in.get (character,20);
in.ignore (1, '\n');
in >> atk >> def >> sp >> spdef >> spd >> lvl >> fullhealth >> exp;
in.close();
cout << "--CURRENT STATS--\n";
cout << character << "\nLevel: " << lvl << endl;
cout << "HP: " << totalhealth << "/" << fullhealth << endl;
if (lvl <= 10)
   {
   remain = lvl;
   }
if (lvl > 10)
   {
   remain = 10;
   }
if (lvl <= 10)
   {
   cout << lvl - exp << " / " << remain << " exp";
   }
if (lvl > 10)
   {
   cout << 10 - exp << " / " << remain << " exp";
   }
if (atk == 1)
   {
   cout << "\nAttack: High";
   }
if (atk == 2)
   {
   cout << "\nAttack: Medium";
   }
if (atk == 3)
   {
   cout << "\nAttack: Low";
   }
if (def == 1)
   {
   cout << "\nDefense: High";
   }
if (def == 2)
   {
   cout << "\nDefense: Medium";
   }
if (def == 3)
   {
   cout << "\nDefense: Low";
   }
if (sp == 1)
   {
   cout << "\nSpecial: High";
   }
if (sp == 2)
   {
   cout << "\nSpecial: Medium";
   }
if (sp == 3)
   {
   cout << "\nSpecial: Low";
   }
if (spdef == 1)
   {
   cout << "\nSp Defense: High";
   }
if (spdef == 2)
   {
   cout << "\nSp Defense: Medium";
   }
if (spdef == 3)
   {
   cout << "\nSp Defense: Low";
   }
if (spd == 1)
   {
   cout << "\nSpeed: High";
   }
if (spd == 2)
   {
   cout << "\nSpeed: Medium";
   }
if (spd == 3)
   {
   cout << "\nSpeed: Low";
   }
cout << endl;
system("PAUSE");
}


void damage()
{
ifstream in;
in.open ("character.txt", ios::in);
in.ignore(21, '\n');
int totnetdamage, percent, special, spatklvl;
double atk, coredamage, attack, defense, damage, netdamage;
srand(time(NULL));
cout << "--DAMAGE CALCULATION--\n";
cout << "Special Attack or Regular Attack?\n";
cout << "(1) Regular\n(2) Special\n";
cin >> atk;
if (atk == 1)
   {
   cout << "Type in your level\n/rolldie ";
   cin >> percent;
   coredamage = rand() % percent + 1;
   cout << "Rolldie resulted in: " << coredamage << endl;
   in >> attack;
   if (attack == 1)
      {
      damage = 1.5 * coredamage;
      }
   if (attack == 2)
      {
      damage = coredamage;
      }
   if (attack == 3)
      {
      damage = 0.5 * coredamage;
      }
   cout <<"What is the enemy's defense?\n(1) High\n(2) Medium\n(3) Low\n";
   cin >> defense;
   if (defense == 1)
      {
      netdamage = 0.5 * damage;
      }
   if (defense == 2)
      {
      netdamage = damage;
      }
   if (defense == 3)
      {
      netdamage = 1.5 * damage;
      }
   totnetdamage = netdamage + 0.75;
   cout << "The damage dealt is " << totnetdamage << " .\n";
   }
else if (atk == 2)
     {
     cout << "Level Skill was learned at: ";
     cin >> spatklvl;
     in.ignore(2, '\n');
     in.ignore(2, '\n');
     in >> attack;
     if (attack == 1)
        {
        special = 2 * spatklvl + 0.5;
        }
     if (attack == 2)
        {
        special = 1 * spatklvl + 0.5;
        }
     if (attack == 3)
        {
        special = 0.5 * spatklvl + 0.5;
        }
     cout << special << " is the amount you need to put into '/rolldie' \n";
     cout << "/rolldie ";
     cin >> percent;
     coredamage = rand() % percent + 1;
     cout << "Rolldie resulted in: " << coredamage << endl;
     if (attack == 1)
        {
        damage = 1.5 * coredamage;
        }
     if (attack == 2)
        {
        damage = coredamage;
        }
     if (attack == 3)
        {
        damage = 0.5 * coredamage;
        }
     cout <<"What is the enemy's defense?\n(1) High\n(2) Medium\n(3) Low\n";
     cin >> defense;
     if (defense == 1)
        {
        netdamage = 0.5 * damage;
        }
     if (defense == 2)
        {
        netdamage = damage;
        }
     if (defense == 3)
        {
        netdamage = 1.5 * damage;
        }
     totnetdamage = netdamage + 0.75;
     cout << "The damage dealt is " << totnetdamage << " .\n";
     }
system("PAUSE");
}

void tothealth()
{
int dmg, damage;
cout << "--HP CALCULATION--\n";
cout << "(1) Take Damage\n(2) Heal Damage\n(3) Check current HP\n";
cin >> dmg;
if (dmg == 1)
   {
   cout << "Damage Taken: ";
   cin >> damage;
   totalhealth -= damage;
   cout << "/me takes " << damage << " damage." << endl;
   }
if (dmg == 2)
   {
   cout << "HP Healed: ";
   cin >> damage;
   totalhealth += damage;
   cout << "/me healed " << damage << " HP.\n";
   }
if (dmg == 3)
   {
   cout << "Current HP: ";
   cout << totalhealth << "/" << fullhealth << endl;
   }
system("PAUSE");
}

void help()
{
char choice;
cout << "INFO: \n(C)2009\nBy: RehdBlob\nCharacter Tracking Program V 1.5\n";
cout << "Made for Mario Paintasy XVI, created by JillSandwich93 and AbsoluteZero255\n";
cout << "aka. 'JS' and 'AZ'\n";
cout << "--HELP MENU--\n";
cout << "(1) Character\n(2) EXP\n(3) Exit\n";
cin >> choice;
if (choice == '1')
   {
   cout << "The text file containing your character information, character.txt,\n";
   cout << "can be deleted at any time should you accidentally have entered the\n";
   cout << "wrong info for the setup.\n";
   cout << "The information is stored in the format:\n";
   cout << "[character name]\nAttack Stat\nDefense Stat\nSpecial Stat\n";
   cout << "Special Defense Stat\nSpeed Stat\nLevel\nHP\nEXP Remaining\n";
   }
if (choice == '2')
   {
   cout << "EXP Table: Amount of EXP Required to level up.\n";
   for (int k = 1; k <= 15; k++)
       {
       if (k < 10)
          cout << "Level: " << k << "   EXP Required to level up: " << k << endl;

       else
          cout << "Level: " << k << "  EXP Required to level up: 10" << endl;
       }
   cout << "All succeeding levels require 10 exp to level up" << endl;
   cout << "A regular battle is worth 1 exp (ALL LEVELS)\n";
   cout << "Overkill gives 1 extra exp.\n";
   cout << "A boss battle is worth 2 exp for levels 1-10\n";
   cout << "A boss battle is worth (Level)/4 exp for levels 11-20, rounded down\n";
   cout << "A boss battle is worth 2 exp for levels 21 onwards\n";
   }
system("PAUSE");
}

void SP();
{
system("PAUSE");
}

