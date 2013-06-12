/****************************************************************************\
                     Character Tracking Program v1.99
                     (c) 2009-2013 By: RehdBlob
\****************************************************************************/
#include <fstream.h>
#include <stdlib.h>
#include <time.h>

int totalhealth, fullhealth, totalSP, fullSP;
void health();
void damage();
void setup();
void stats();
void EXP();
void mainmenu();
void tothealth();
void help();
void SP();
void totSP();
void items();

int main() {
    char c1;
    ifstream in;
    ofstream out;
    out.open("character.txt", ios::app);
    in.open("character.txt", ios::in);
    in >> c1;
    if (!in.eof()) {
        out.close();
        in.close();
        health();
        SP();
        mainmenu();
    }
    else if (in.eof()) {
        int HP, atk, def, sp, spdef, spd, lvl, exp;
        char character[20];
        cout << "Character Name (20 chars. max): ";
        cin.get(character, 20);
        cin.ignore(1, '\n');
        cout << "--SETUP--\n";
        cout << "Choose high, medium, or low for the following. The stats must balance.\n";
        cout << "aka. If there is a high, there must be a low. Zero for anything counts\n";
        cout << "as a low in the balance. Type number choices only.\n";
        cout << "HP:\n(1) High\n(2) Medium\n(3) Low\n";
        cin >> HP;
        cout << "Attack:\n(1) High\n(2) Medium\n(3) Low\n(4) Zero\n";
        cin >> atk;
        cout << "Defense:\n(1) High\n(2) Medium\n(3) Low\n(4) Zero\n";
        cin >> def;
        cout << "Special:\n(1) High\n(2) Medium\n(3) Low\n(4) Zero\n";
        cin >> sp;
        cout << "Special Defense:\n(1) High\n(2) Medium\n(3) Low\n(4) Zero\n";
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
        switch (HP) {
        case 1:
            totalhealth = 8 * lvl;
            break;
        case 2:
            totalhealth = 6 * lvl;
            break;
        case 3:
            totalhealth = 4 * lvl;
            break;
        default:
            break;
        }
        out << totalhealth << endl;
        out << exp << endl;
        in.close();
        out.close();
        health();
        SP();
        mainmenu();
    }
    system("PAUSE");
    return 0;
}

void mainmenu()
{
    char choice;
    while (1) {
        system ("CLS");
        cout << "--MAIN MENU--\n";
        cout << "(1) Current Stats\n(2) EXP\n(3) HP Calculation\n(4) SP Calculation\n";
        cout << "(5) Damage Calculation\n(6) Items\n(7) Info/Help\n(8) Exit\n";
        cin >> choice;
        if (choice == '1')
            stats();
        else if (choice == '2')
            EXP();
        else if (choice == '3')
            tothealth();
        else if (choice == '4')
            totSP();
        else if (choice == '5')
            damage();
        else if (choice == '6')
            items();
        else if (choice == '7')
            help();
        else if (choice == '8')
            break;
        else
            continue;
    }
}

void health() {
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


void EXP() {
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
    if (choice == '1') {
        cout << "Gain how much EXP?\n";
        cin >> gain;
        cout << "/me gained " << gain << " EXP.\n";
        exp = exp - gain;
        if (exp <= 0) {
            cout << "/me leveled up to Level ";
            int mult;
            if (fHP == lvl * 4)
                mult = 4;
            if (fHP == lvl * 6)
                mult = 6;
            if (fHP == lvl * 8)
                mult = 8;
            lvl++;
            fHP = mult * lvl;
            cout << lvl << endl;
            exp += lvl;
            remain = lvl;
            cout << "Level " << lvl << endl << lvl - exp << " / " << remain << " exp"<< endl;
            out.open ("character.txt", ios::out);
            out << character << endl;
            out << atk << endl << def << endl;
            out << sp << endl << spdef << endl << spd << endl << lvl << endl;
            out << fHP << endl;
            out << exp << endl;
            out.close();
            if (lvl != prevlvl) {
                health();
                SP();
            }
        }
        else
            remain = lvl;
        cout << "Level " << lvl << endl << lvl - exp << " / " << remain << " exp"<< endl;
        out.open ("character.txt", ios::out);
        out << character << endl;
        out << atk << endl << def << endl;
        out << sp << endl << spdef << endl << spd << endl << lvl << endl;
        out << fHP << endl;
        out << exp << endl;
        out.close();
    }
    if (choice == '2') {
        cout << "Level " << lvl << endl << lvl - exp << " / " << lvl << " exp"<< endl;
    }
    system("PAUSE");
}

void stats() {
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
    cout << "SP: " << totalSP << "/" << fullSP << endl;
    remain = lvl;
    cout << lvl - exp << " / " << remain << " exp";
    switch (atk) {
    case 1:
        cout << "\nAttack: High";
        break;
    case 2:
        cout << "\nAttack: Medium";
        break;
    case 3:
        cout << "\nAttack: Low";
        break;
    case 4:
        cout << "\nAttack: Zero";
        break;
    default:
        break;
    }
    switch (def) {
    case 1:
        cout << "\nDefense: High";
        break;
    case 2:
        cout << "\nDefense: Medium";
        break;
    case 3:
        cout << "\nDefense: Low";
        break;
    case 4:
    default:
        cout << "\nDefense: Zero";
        break;
    }
    switch (sp) {
    case 1:
        cout << "\nSpecial: High";
        break;
    case 2:
        cout << "\nSpecial: Medium";
        break;
    case 3:
        cout << "\nSpecial: Low";
        break;
    case 4:
        cout << "\nSpecial: Zero";
        break;
    default:
        break;
    }
    switch (spdef) {
    case 1:
        cout << "\nSp Defense: High";
        break;
    case 2:
        cout << "\nSp Defense: Medium";
        break;
    case 3:
        cout << "\nSp Defense: Low";
        break;
    case 4:
        cout << "\nSp Defense: Zero";
        break;
    default:
        break;
    }
    switch (spd) {
    case 1:
        cout << "\nSpeed: High";
        break;
    case 2:
        cout << "\nSpeed: Medium";
        break;
    case 3:
        cout << "\nSpeed: Low";
        break;
    default:
        break;
    }
    cout << endl;
    system("PAUSE");
}


void damage() {
    ifstream in;
    in.open ("character.txt", ios::in);
    in.ignore(21, '\n');
    int totnetdamage, percent, special, spatklvl;
    double coredamage, attack, damage, netdamage;
    char defense, atk;
    srand(time(NULL));
    cout << "--DAMAGE CALCULATION--\n";
    cout << "Special Attack or Regular Attack?\n";
    cout << "(1) Regular\n(2) Special\n(3) Exit this submenu\n";
    cin >> atk;
    if (atk == '1')
    {
        cout << "Type in your level\n/rolldie ";
        cin >> percent;
        coredamage = rand() % percent + 1;
        cout << "Rolldie resulted in: " << coredamage << endl;
        in >> attack;
        switch (attack)
    case 1:
        if (attack == 1)
            damage = 1.5 * coredamage;
        if (attack == 2)
            damage = coredamage;
        if (attack == 3)
            damage = 0.5 * coredamage;
        cout <<"What is the enemy's defense?\n(1) High\n(2) Medium\n(3) Low\n";
        cin >> defense;
        if (defense == '1')
            netdamage = 0.5 * damage;
        if (defense == '2')
            netdamage = damage;
        if (defense == '3')
            netdamage = 1.5 * damage;
        totnetdamage = netdamage + 0.75;
        cout << "The damage dealt is " << totnetdamage << " .\n";
    }
    else if (atk == '2') {
        cout << "Level Skill was learned at: ";
        cin >> spatklvl;
        in.ignore(2, '\n');
        in.ignore(2, '\n');
        in >> attack;
        switch (attack) {
        case 1:
            special = 2 * spatklvl + 0.5;
            break;
        case 2:
            special = 1 * spatklvl + 0.5;
            break;
        case 3:
            special = 0.5 * spatklvl + 0.5;
            break;
        }
        cout << special << " is the amount you need to put into '/rolldie' \n";
        cout << "/rolldie ";
        cin >> percent;
        coredamage = rand() % percent + 1;
        cout << "Rolldie resulted in: " << coredamage << endl;
        switch(attack) {
        case 1:
            damage = 1.5 * coredamage;
            break;
        case 2:
            damage = coredamage;
            break;
        case 3:
            damage = 0.5 * coredamage;
            break;
        default:
            break;
        }
        totnetdamage = 0;
        while (totnetdamage == 0) {
            cout <<"What is the enemy's defense?\n(1) High\n(2) Medium\n(3) Low\n";
            cin >> defense;
            if (defense == '1') {
                netdamage = 0.5 * damage;
                totnetdamage = netdamage + 0.75;
            } else if (defense == '2') {
                netdamage = damage;
                totnetdamage = netdamage + 0.75;
            } else if (defense == '3') {
                netdamage = 1.5 * damage;
                totnetdamage = netdamage + 0.75;
            } else {
                cout << "Please input a choice\n";
                continue;
            }
        }
        cout << "The damage dealt is " << totnetdamage << " .\n";
    }
    system("PAUSE");
}

void tothealth() {
    int damage;
    char dmg;
    cout << "--HP CALCULATION--\n";
    cout << "(1) Take Damage\n(2) Heal Damage\n(3) Check current HP\n(4) Exit this submenu\n";
    cin >> dmg;
    if (dmg == '1') {
        cout << "Damage Taken: ";
        cin >> damage;
        totalhealth -= damage;
        cout << "/me takes " << damage << " damage." << endl;
    } else if (dmg == '2') {
        cout << "HP Healed: ";
        cin >> damage;
        totalhealth += damage;
        cout << "/me healed " << damage << " HP.\n";
    } else if (dmg == '3') {
        cout << "Current HP: ";
        cout << totalhealth << "/" << fullhealth << endl;
    }
    system("PAUSE");
}

void help() {
    char choice;
    cout << "INFO: \n(C)2009\nBy: RehdBlob\nCharacter Tracking Program V 1.9\n";
    cout << "Made for Mario Paintasy, created by JillSandwich93 and AbsoluteZero255\n";
    cout << "aka. 'JS' and 'AZ'\n";
    cout << "--HELP MENU--\n";
    cout << "(1) Character\n(2) EXP\n(3) Exit\n";
    cin >> choice;
    if (choice == '1') {
        cout << "The text file containing your character information, character.txt,\n";
        cout << "can be deleted at any time should you accidentally have entered the\n";
        cout << "wrong info for the setup.\n";
        cout << "The information is stored in the format:\n";
        cout << "[character name]\nAttack Stat\nDefense Stat\nSpecial Stat\n";
        cout << "Special Defense Stat\nSpeed Stat\nLevel\nHP\nEXP Remaining\n";
        cout << "Items, etc.";
    } else if (choice == '2') {
        cout << "EXP Table: Amount of EXP Required to level up.\n";
        for (int k = 1; k <= 15; k++)
        {
            if (k < 10)
            {
                cout << "Level: " << k << "   EXP Required to level up: " << k << endl;
            }
            if (k > 10)
            {
                cout << "Level: " << k << "  EXP Required to level up: " << k << endl;
            }
        }
        cout << "... etc.\n";
        cout << "A regular battle is worth 1 exp\n";
        cout << "Overkill gives 1 extra exp.\n";
        cout << "A boss battle is worth 2 exp\n";
        cout << "Overkill rules also apply to boss battles.\n";
    }
    system("PAUSE");
}

void SP() {
    int fSP, level;
    ifstream in;
    in.open("character.txt", ios::in);
    in.ignore(21, '\n');
    for (int j = 1; j <= 2; j++)
        in.ignore(2, '\n');
    in >> fSP;
    for (int j = 1; j <= 3; j++)
        in.ignore(2, '\n');
    in >> level;
    in.close();
    int mul;
    switch (fSP) {
    case 1:
        mul = 3;
        break;
    case 2:
        mul = 2;
        break;
    case 3:
        mul = 1;
        break;
    case 4:
        mul = 0;
        break;
    default:
        break;
    }
    totalSP = mul * level;
    fullSP = totalSP;
}

void totSP() {
    int amt;
    char choice;
    cout << "--SP CALCULATION--\n";
    cout << "(1) Use SP\n(2) Regain SP\n(3) Check current SP\n(4) Exit this submenu\n";
    cin >> choice;
    if (choice == '1') {
        cout << "SP Used: ";
        cin >> amt;
        totalSP -= amt;
        cout << "/me used " << amt << " SP." << endl;
    } else if (choice == '2') {
        cout << "SP Regained: ";
        cin >> amt;
        totalSP += amt;
        cout << "/me regained " << amt << " SP.\n";
    } else if (choice == '3') {
        cout << "Current SP: ";
        cout << totalSP << "/" << fullSP << endl;
    }
    system("PAUSE");
}


void items() {
    int cl, itemnumbers;
    char choice, choice2;
    char item[25];
    ifstream in;
    ofstream out;
    out.open("items.txt", ios::app);
    in.open("items.txt", ios::in);
    in >> cl;
    in.ignore(1, '\n');
    if (in.eof()) {
        out << "0\n";
        itemnumbers = 0;
    } else
        itemnumbers = cl;
    in.close();
    out.close();
    cout << "--ITEMS--\n";
    cout << "(1) Gain Items\n(2) Use Items\n(3) Key Items\n(4) Use Key Items\n";
    cout << "(5) Check inventory\n(6)Exit this submenu";
    cin >> choice;
    if (choice == '1') {
        reset:
        cout << "Type the item name (25 chars. max)\n";
        cin.get(item, 25);
        cin.ignore(1, '\n');
        cin.get(item, 25);
        cin.ignore(1, '\n');
        out.open("items.txt", ios::app);
        out << item << endl;
        out.close();
        itemnumbers = itemnumbers + 1;
        cout << "Got " << item << "!\n";
        cout << "Gain more items?\n(1) Yes\n(2) No\n";
        cin >> choice2;
        if (choice2 == '1') {
            goto reset;
        }
        system("copy items.txt temp.txt");
        system("del items.txt");
        out.open("items.txt", ios::app);
        out << itemnumbers << endl;
        in.open("temp.txt", ios::in);
        in.ignore(1, '\n');
        in.get(item, 25);
        in.ignore(1, '\n');
        in.get(item, 25);
        in.ignore(1, '\n');
        out << item << endl;
        for (int j = 1; j <= itemnumbers; j++) {
            in.get(item, 25);
            if (in.eof())
                break;
            in.ignore(1, '\n');
            out << item << endl;
        }
        in.close();
        out.close();
        system("del temp.txt");
    } else if (choice == '2') {
        in.open("items.txt", ios::in);
        in >> itemnumbers;
        if (itemnumbers == 0)
            cout << "You have no items.\n";
        else {
            int j;
            cout << "Use which iten?\n";
            cout << "(0) Don't use items\n";
            in.get(item, 25);
            in.ignore(1, '\n');
            in.get(item, 25);
            in.ignore(1, '\n');
            cout << "(1) " << item << endl;
            for (j = 1; j < itemnumbers; j++) {
                in.get(item, 25);
                in.ignore(1, '\n');
                cout << "(" << j + 1 << ") " << item << endl;
            }
            in.close();
            cin >> choice2;
            int n = choice2 - '0';
            if (n != 0) {
                in.open("items.txt", ios::in);
                in.ignore(2, '\n');
                for (j = 1; j < n; j++)
                    in.ignore(26, '\n');
                in.get(item, 25);
                in.ignore(1, '\n');
                in.close();
                cout << "/me used " << item << endl;
                system("copy items.txt temp.txt");
                in.open("temp.txt", ios::in);
                in >> itemnumbers;
                itemnumbers = itemnumbers - 1;
                in.ignore(1, '\n');
                out.open("items.txt", ios::out);
                out << itemnumbers << endl;
                for (j = 1; j < n; j++) {
                    in.get(item, 25);
                    in.ignore(1, '\n');
                    out << item << endl;
                }
                in.get(item, 25);
                in.ignore(1, '\n');
                for (int k = n; k <= itemnumbers; k++) {
                    in.get(item, 25);
                    in.ignore(1, '\n');
                    out << item << endl;
                }
                in.close();
                out.close();
                system("del temp.txt");
            }
        }
    } else if (choice == '3') {
        in.open("items.txt", ios::in);
        in >> itemnumbers;
        if (itemnumbers == 0)
            cout << "You have no items\n";
        else {
            cout << "Items:\n";
            in.get(item, 25);
            in.ignore(1, '\n');
            in.get(item, 25);
            in.ignore(1, '\n');
            cout << "(1) " << item << endl;
            for (int j = 1; j < itemnumbers; j++) {
                in.get(item, 25);
                in.ignore(1, '\n');
                cout << "(" << j + 1 << ") " << item << endl;
            }
            in.close();
        }
    }
    system("PAUSE");
}
