#include <iostream>
#include <string>

using namespace std;

class Guest {
public:
	Guest();
	Guest(string s, int m, int ski);
	~Guest();
	string get_name();
	int get_money();
	int get_skill();
	void Win(int m);
	
private:
	string name;
	int money;
	int skill;
};
Guest :: Guest()
{
    name = '\0';
    money = 0;
    skill = 0;
}
Guest :: Guest(string s, int m, int ski)
{
    name = s;
    money = m;
    skill = ski;
}

Guest :: ~Guest()
{
}

string Guest:: get_name()
{
    return name;
}

int Guest :: get_money()
{
    return money;
}

int Guest :: get_skill()
{
    return skill;
}

void Guest :: Win(int m)
{
    money+= m;
}
class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f);
	void GuestEnter(string s, int m, int ski);
	void Win(string s, int m);
	void EndDay();
	void Result();
	
private:
	int fee;
	
	int guest_num;
	Guest *guest[1009];
	
	int income;
	int list_num;
	string blacklist[1009];
};

Casino :: Casino()
{
    fee = 0;
    guest_num = 0;
    income = 0;
    list_num = 0;
}

Casino :: ~Casino()
{
}

void Casino :: Enterance(int f)
{
    fee = f;
}

void Casino :: GuestEnter(string s, int m, int ski)
{
    for(int i = 0; i<list_num; i++)//blacklist
    {
        if(s == blacklist[i])
        {
            return;
        }
    }
    for(int i = 0; i<guest_num; i++)//udh pernah daftar
    {
        if(guest[i]->get_name() == s)
        {
            return;
        }
    }
    if(m<= fee)//bankrupt
    {
        income+=m;
        blacklist[list_num]=s;
        list_num++;
    }
    else{
        guest[guest_num]=new Guest(s,m-fee,ski);
        guest_num++;
        income+=fee;
    }
}
void Casino :: Win(string s, int m)
{
    for(int i = 0; i<list_num;i++)//blacklist
    {
        if(s == blacklist[i])return;
    }

    for(int i = 0; i<guest_num; i++)
    {
        if(guest[i]->get_name()==s)
        {
            if((guest[i]->get_skill())*2 <m)
            {
                guest[i]->Win(m);
                income-=m;
                blacklist[list_num]=s;
                list_num++;
                return;
            }
            else if(guest[i]->get_money()+m<=0)
            {
                blacklist[list_num]=s;
                list_num++;
                income+= guest[i]->get_money();
            }else{
                guest[i]->Win(m);
                income -= m;
            }
        }
    }
    return;
}

void Casino :: EndDay()
{
    for(int i = 0; i<guest_num;i++)
    {
        delete guest[i];
    }
    guest_num = 0;
}

void Casino :: Result()
{
    cout<<income<<endl;
    for(int i = 0; i<list_num;i++)
    {
        cout<<blacklist[i]<<endl;
    }
}
int n;
Casino casino;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		string op;
		int q, fee;
		
		cin >> op >> q >> fee;
		casino.Enterance(fee);
		for (int j = 0; j < q; ++ j) {
			cin >> op;
			if (op == "Guest") {
				string name; 
				int money, skill;
				cin >> name >> money >> skill;
				casino.GuestEnter(name, money, skill);
			} 
			else if (op == "Win") {
				string name;
				int money;
				cin >> name >> money;
				casino.Win(name, money);
			}
		}
		casino.EndDay();
	}
	casino.Result();
}
