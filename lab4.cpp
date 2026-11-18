#include <iostream>
#include <string>

using namespace std ;

double MAX_GLOBAL_DAMAGE = 200;

class EnchantedWeapon{
	int weaponID;
	char* weaponName;
	double baseDamage;
	double durability;
	char* loreScroll;
	
	public:
		EnchantedWeapon(int, const char*, double, double, const char* );
		~EnchantedWeapon();
		EnchantedWeapon& upgradeDamage(double);
		EnchantedWeapon& repairWeapon(double);
		EnchantedWeapon& infuseElement(const char*);
		EnchantedWeapon& sharpenEdge(double);
		void displayStats();
		friend void inspectWeaponLore(const EnchantedWeapon&);
		
	};

EnchantedWeapon::EnchantedWeapon(int weaponID, const char*weaponName, double baseDamage,double durability, const char*loreScroll )
: weaponID(weaponID), baseDamage(baseDamage), durability(durability)
{
	this->weaponName = new char[200];
	strcpy(this->weaponName, weaponName);
	
	this->loreScroll = new char[200];
	strcpy(this->loreScroll, loreScroll);
}

EnchantedWeapon::~EnchantedWeapon()
{
	cout<<"[Destructor Executed] Weapon ID "<< this->weaponID <<" dynamic memory freed."<< endl;
	
	delete[] this->weaponName; // köşeli parantezler her zaman delete sonrası
	delete[] this->loreScroll;
}


EnchantedWeapon& EnchantedWeapon::upgradeDamage(double upgrade)
{	
	this->baseDamage = this->baseDamage + upgrade;

	if( this->baseDamage>= ::MAX_GLOBAL_DAMAGE )
	{
		cout<<"This weapon is pretty overpowered!"<<endl;
		this->baseDamage = MAX_GLOBAL_DAMAGE;
	}
	
	return *this;
}

EnchantedWeapon& EnchantedWeapon::repairWeapon(double repair)
{
	this->durability = this->durability + repair;
	
	return *this;

}

EnchantedWeapon& EnchantedWeapon::infuseElement(const char* elmnt)
{
	cout<<"Weapon successfully infused with "<<elmnt<<" magic!"<<endl;
	return *this;
}

EnchantedWeapon& EnchantedWeapon::sharpenEdge(double s_bonus)
{
	this->baseDamage = s_bonus + this->baseDamage;
	if( this->baseDamage >= ::MAX_GLOBAL_DAMAGE )
	{
		cout<<"This weapon is pretty overpowered!"<<endl;
		this->baseDamage = MAX_GLOBAL_DAMAGE;
	}
	
	return *this;
}

void EnchantedWeapon::displayStats()
{
	cout<<"Weapon ID: "<<weaponID<<" | Name: "<<weaponName<<" | Damage: "<<baseDamage<<" | Durability: "<<durability<<"%\n";
}

void inspectWeaponLore(const EnchantedWeapon& weapon )
{
	cout<<"Lore Scroll Content: "<<weapon.loreScroll<<endl;
}


int main(){
	
	int id;
	double dmg, dbtiy, upgrading, repairing, sharpening;
	char name[100], lore[250], element[50] ;
	

cout<<"--- RPG Weapon Customization System ---"<<endl;
cout<<"Enter Weapon ID: ";
cin>>id;
cin.ignore();

cout<<"Enter Weapon Name: ";
cin.getline(name, 100);

cout<<"Enter Initial Base Damage: ";
cin>>dmg;
cin.ignore();

cout<<"Enter Initial Durability(0-100): ";
cin>>dbtiy;
cin.ignore();

cout<<"Enter Weapon Lore Description: ";
cin.getline(lore, 250);

cout<<"Enter Elemental Infusion Type(e.g. Fire, Ice): ";
cin.getline(element, 50);

EnchantedWeapon wp1(id, name, dmg, dbtiy,lore);

cout<<"---Initial Weapon Status---"<<endl;
wp1.displayStats();
cout<<endl;

cout<<"Enter Damage Upgrade Amount: ";
cin>>upgrading;

cout<<"Enter Repair Amount: ";
cin>>repairing;

cout<<"Enter Sharpening Bonus Amount: ";
cin>>sharpening;

cout<<"Executing Method Chaining...\n";
wp1.upgradeDamage(upgrading).repairWeapon(repairing).sharpenEdge(sharpening).infuseElement(element);

cout<<"---Updated Weapon Status After Chaining---"<<endl;
wp1.displayStats();
cout<<endl;

cout<<"---Weapon Lore---"<<endl;
inspectWeaponLore(wp1);

return(0);	
	
}