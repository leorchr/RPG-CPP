#include <iostream>
#include <random>

using namespace std;
void sell(int& money, int price);

int main()
{
    int cost[6]{1,2,12,50,999,50000};
    string objects[6]{ "diamondArmor","plane","chainsaw","wacomTablet","msiFan","letter" };
    
    cout << "Bonjour, je suis le marchand de tapis, combien as-tu d'argent ?"<<endl;
    int money;
    cin >> money;

    cout << "Que veux-tu acheter ? Voici mes articles :" << endl;
    cout << "diamond armor : 1$" << endl;
    cout << "plane : 2$" << endl;
    cout << "chainsaw: 12$" << endl;
    cout << "wacom tablet : 50$" << endl;
    cout << "msi fan : 999$" << endl;
    cout << "letter : 50000$" << endl;
    string wantedObject;
    cin >> wantedObject;

    /*for (string i : objects)
    {
        if (wantedObject == i) {
            cout << i << endl;
        }
    }*/

    for (int i = 0; i < 6; i++) {
        if (objects[i] == wantedObject) {
            cout << "Cet objet coute " << cost[i] << " $" << endl;
            sell(money,cost[i]);
        }
    }
}

void sell(int& money, int price) {
    if (money >= price) {
        money -= price;
        cout << "Il te reste : " << money << " $" << endl;
    }
    else {
        cout << "Tu es pauvre !" << endl;
        cout << "Casse-toi de mon magasin tout de suite !" << endl;
    }
}