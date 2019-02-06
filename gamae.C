#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <istream>

using namespace std;

class Encounter 
{
	public:
		Encounter(string monster, int dp, int matc, int hp, int atc, int block)
		{
			cout << "You encounter the " << monster << endl;
			int act, tblock = 0;
			string enc;
			while(hp > 0)
			{
				tblock = block;
				cout << ">Attack\n or\n>Guard\n or\n>Run" << endl;
				
				cin >> enc;
				
				//Action ids
				
				if (enc == "Attack") { act = 1; }
				else if (enc == "Guard") { act = 2; }
				else if (enc == "Run") { act = 3; }
				else { act = 0; }
				//why would i need switch if i have IFs? 
				 
			switch(act)
			{
				case 1 : 
					{	//cout << "[Attack]" << endl;
						dp -=atc;
						if(tblock > 2)
							{ tblock -= 2; }
						else { tblock = 0; }
						cout << "Deal " << atc << " damage, but loose Defence" << endl;
						break;
						}
				case 2 :
					{	//cout << "[Guard]" << endl;
						atc += 5;
						tblock += 2;
						cout << "Gain " << tblock << " Defence points" << endl;
						break;						
						}
				case 3 :
					{	cout << "~~You run away~~" << endl;
						exit(0);
						//how do i come back to the first encounter?
						}
				default :
					{	cout << "Become vulnerable" << endl;
						tblock -= 2;
						break;
						}
				}
				//eof switch	
				
				if(dp <= 0) {cout << "You Win" << endl; break;}
				cout << "	~C++ hits You~" << endl;
				
				hp = hp + tblock - matc;
				//add stun if block >= matc
				cout << "C++: " << dp << "	You: " << hp << endl;
				
				if(hp < 0){ cout << "~!You Lose!~" << endl; exit(0);}
				
			}
			//eof while
			}
			//eof Constructor
			//include Destructor and insert "You Win" screen with continue? button
	};


int main()
{
char answ;
string name;

cout << "Present yourself!" << endl;
cin >> name;
cout << "You are going to regret entering my Lair, " << name << "!" << endl;
cout << "	~C++ prepares for a Fight!~\nEncounter?{Y/N}: ";
cin >> answ;
if(answ == 'Y')
	{
		int dp = 20, matc = 5, hp = 20, atc = 5, block = 0;
		cout << "Encounter" << endl;
		Encounter Guardian("Guardian",dp,matc,hp,atc,block);
		//cout << "	^You Level Up!^" << endl;
		Encounter Guardian1("Head Guardian",dp+3,matc+1,hp,atc,block);
		}
		//eof if
			
else
	{
		cout << ">END OF JOURNEY<" << endl;
		}
		


return 0;
 
}

