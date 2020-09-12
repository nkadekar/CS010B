#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {
	int seed;
	cout << "Enter seed value: ";
	cin >> seed;
	cout << endl;
	
	srand(seed);

	vector<Character *> adventurers;
	adventurers.push_back(new Warrior("Arthur", 100, 5, "King George"));
	adventurers.push_back(new Warrior("Jane", 100, 6, "King George"));
	adventurers.push_back(new Warrior("Bob", 100, 4, "Queen Emily"));
	adventurers.push_back(new Elf("Raegron", 100, 4, "Sylvarian"));
	adventurers.push_back(new Elf("Cereasstar", 100, 3, "Sylvarian"));
	adventurers.push_back(new Elf("Melimion", 100, 4, "Valinorian"));
	adventurers.push_back(new Wizard("Merlin", 100, 5, 10));
	adventurers.push_back(new Wizard("Adali", 100, 5, 8));
	adventurers.push_back(new Wizard("Vrydore", 100, 4, 6));

	unsigned numAttacks = 10 + rand() % 11;
	unsigned attacker, defender;
	for (unsigned i = 0; i < numAttacks; ++i) {
		attacker = rand() % adventurers.size();
		do {
			defender = rand() % adventurers.size();
		} while (defender == attacker);
		
		adventurers.at(attacker)->attack(*adventurers.at(defender));
		cout << endl;
	}
	cout << "-----Health Remaining-----" << endl;
	for (unsigned i = 0; i < adventurers.size(); ++i) {
		cout << adventurers.at(i)->getName() << ": " 
			<< adventurers.at(i)->getHealth() << endl;
	}
    
    //Testing
    //Wizard w1("Nikhil", 100, 23, 2);
//     cout << "Type should be WARRIOR " << endl;
//     cout << w1.getType() << endl;
//     cout << "Name should be Nikhil " << endl;
//     cout << w1.getName() << endl;
//     cout << "Health should be 100" << endl;
//     cout << w1.getHealth() << endl;
//     cout << "Allegiance should be Joe" << endl;
//     cout << w1.getAllegiance() << endl;
    
    //Wizard w2("Ash", 100, 23, 1);
    
//     w1.attack(e1);
//     cout << "Health should be 77" << endl;
//     cout << e1.getHealth() << endl;
    
//     cout << endl;
//     Wizard wi1("Merlin", 100, 5, 10);
//     Wizard wi2("Adali", 100, 5, 8);
//     cout << "Rank should be 10" << endl << wi1.getRank() << endl;
    //wi1.attack(wi2);
    //cout << wi2.getHealth() << endl;
    
    //w1.attack(w2);

	return 0;
}