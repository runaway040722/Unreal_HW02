#include <iostream>
#include<string>
using namespace std;


class Player
{
protected:
	string job;
	string name;
	int level;
	int hp;
	int mp;
	int att;
	int def;
	int speed;

public: 
	Player(string nickname) : name(nickname), job("무직"), level(1), hp(1), mp(1), att(1), def(1), speed(1) {}
	virtual void attack() = 0;

	string getJob() { return job; }
	string getName() { return name; }
	int getLevel() { return level; }
	int getHP() { return hp; }
	int getMP() { return mp; }
	int getPower() { return att; }
	int getDefence() { return def; }
	int getSpeed() { return speed; }

	void setname(string nickname) { this->name = nickname; }
	void setHP(int HP) { this->hp = HP; }
	void setMP(int MP) { this->mp = MP; }
	void setPower(int power) { this->att = power; }
	void setDefence(int defence) { this->def = defence; }
	void setSpeed(int speed) {this->speed = speed;
	}

	void printPlayerStatus() {
		cout << "이름: " << name << endl;
		cout << "직업: " << job << endl;
		cout << "레벨: " << level << endl;
		cout << "HP: " << hp << endl;
		cout << "MP: " << mp << endl;
		cout << "공격력: " << att << endl;
		cout << "방어력: " << def << endl;
		cout << "속도: " << speed << endl;
	}


};

class Warrior : public Player
{
public:
	Warrior(string name) : Player(name)
	{ 
	job = "전사"; 
	hp = 100;
	mp = 50;
	att = 30;
	def = 70 ;
	speed = 10;
	level = 1;
	}
	void attack()override
	{
		cout << "전사가 검을 휘두릅니다" << endl;
		cout << att << "만큼의 데미지를 입혔습니다." << endl;
	
	}
	
};

class Magician : public Player
{
public:
	Magician(string name) : Player(name) { 
		job = "마법사"; 
		hp = 50;
		mp = 100;
		att = 70;
		def = 30;
		speed = 20;
		level = 1;
	}
	void attack()override
	{
		cout << "마법사가 주문을 외웁니다" << endl;
		cout << att << "만큼의 데미지를 입혔습니다." << endl;

	}
	
};

class Thief : public Player
{
public:
	Thief(string name) : Player(name) 
	{ 
		job = "도적"; 
		hp = 75;
		mp = 75;
		att = 90;
		def = 10;
		speed = 30;
		level = 1;
	}
	void attack()override
	{
		cout << "도적이 기습을 합니다" << endl;
		cout << att << "만큼의 데미지를 입혔습니다." << endl;
	}
};

class Archer : public Player
{
public:
	Archer(string name) : Player(name)
	{
		job = "궁수"; 
		hp = 80;
		mp = 70;
		att = 50;
		def = 50;
		speed = 20;
		level = 1;;
	}
	void attack()override
	{
		cout << "궁수가 화살을 쏩니다" << endl;
		cout << att << "만큼의 데미지를 입혔습니다." << endl;
	}
};

int main()
{
	int jobChoice;
	int attChoice;
	string name;
	Player* player = nullptr;

	while (true)
	{
		cout << "당신의 이름을 입력해주시오: " ;
		cin >> name;

		cout << "1.전사 2.마법사 3.도적 4.궁수" << endl;
		cout << "직업을 선택하시오: ";
		cin >> jobChoice;

		if (player != nullptr)
		{
			delete player;
			player = nullptr; 
		}
		

		switch (jobChoice)
		{
		case 1:
			player = new Warrior(name);
			break;

		case 2:
			player = new Magician(name);
			break;

		case 3:
			player = new Thief(name);
			break;

		case 4:
			player = new Archer(name);
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		player->printPlayerStatus();

		cout << "공격을 하시겠습니까?" << endl;
		cout << "1. 예  0. 아니오" << endl;
		cin >> attChoice;

		if (attChoice == 1)
		{
			player->attack();
		}
		else if (attChoice == 0)
		{
			cout << "공격을 취소했습니다." << endl;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
		}

	}

	if (player != nullptr)
		delete player;

	return 0;
}