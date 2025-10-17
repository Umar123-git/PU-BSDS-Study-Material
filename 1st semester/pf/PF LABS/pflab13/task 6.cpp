#include <iostream>
#include <string>
using namespace std;


struct Player {
    string name;
    int runs;
    int hundreds;
    int wickets;
    int catches;
    bool availability;
};





void list(Player* players, int size)
{
	if(size==0)
	{
		cout<<"no player";
		return ;
	}
	int i=0;
	while(i<size)
	{
		cout<<"player :"<<i+1<<endl;
		cout<<"name :"<<players[i].name<<endl;
		cout<<"runs :"<<players[i].runs<<endl;
		cout<<"hundreds :"<<players[i].hundreds<<endl;
		cout<<"wickes :"<<players[i].wickets<<endl;
		cout<<"catches :"<<players[i].catches<<endl;
		cout<<"availability :"<< (players[i].availability ? "Yes" : "No")<<endl;
	}
}


void searchPlayer(Player* players, int size, const string& name) {
    for (int i = 0; i < size; ++i) {
        if (players[i].name == name) {
            cout<<"player Found: "<<endl;
            cout<<"name: "<< players[i].name <<endl;
            cout<<"runs: "<< players[i].runs<<endl;
            cout<<"hundreds: "<< players[i].hundreds<<endl;
            cout<<"wickets: "<< players[i].wickets<<endl;
            cout<<"catches: "<< players[i].catches<<endl;
            cout<<"availability: " << (players[i].availability ? "Yes" : "No")<<endl;
            return;
        }
    }
    cout<<"player not found"<<endl;
}

void addNewPlayer(Player* players, int& count, int maxSize) {
    if (count >= maxSize) {
        cout<<"No space to add new player"<<endl;
        return;
    }
    cout<<"enter player details:"<<endl;
    cout<<"name: ";
    cin>>players[count].name;
    cout<< "runs: ";
    cin>>players[count].runs;
    cout<< "hundreds: ";
    cin>>players[count].hundreds;
    cout<< "wickets: ";
    cin>>players[count].wickets;
    cout<< "catches: ";
    cin>>players[count].catches;
    cout<< "availability (1 for Yes, 0 for No): ";
    cin>>players[count].availability;
    ++count;
    cout << "player added successfully"<<endl;
}

void removePlayerByName(Player* players, int& count, const string& name) {
    for (int i = 0; i < count; ++i)
	 {
    if (players[i].name == name) 
	{

        for (int j = i; j < count - 1; ++j)
		 {
            players[j] = players[j + 1];
            }
            --count;
            cout << "Player removed successfully"<<endl;
            return;
        }
    }
    cout << "Player not found"<<endl;
}

void updatePlayerByName(Player* players, int size, const string& name) {
    for (int i = 0; i < size; ++i) {
        if (players[i].name == name) {
            cout<<"enter new details for the player:"<<endl;
            cout<<"runs: ";
            cin>>players[i].runs;
            cout<<"hundreds: ";
            cin>>players[i].hundreds;
            cout<<"wickets: ";
            cin>>players[i].wickets;
            cout<< "catches: ";
            cin>>players[i].catches;
            cout<< "availability (1 for Yes, 0 for No): ";
            cin>>players[i].availability;
            cout<<"player updated successfully"<<endl;
            return;
        }
    }
    cout << "Player not found"<<endl;
}

int main()
{
	int count,num;
	int currentCount = 0; 
	cout<<"enter the no. of players :";
	cin >>count;
	Player* players = new Player[count];
	
	
	
	cout<<"menu :"<<endl;
	cout<<"0: close program"<<endl;
	cout<<"1: list"<<endl;
	cout<<"2: name search"<<endl;
	cout<<"3: add player"<<endl;
	cout<<"4: remove player"<<endl;
	cout<<"5: update player"<<endl<<endl;
	cout<<"press the num you wants to select :";
	cin>>num;
	
	
	switch(num)
	{
		case 0:
		break;
		
		case 1:
		list(players,currentCount);
		
	case 2: {
        string name;
        cout << "Enter player name to search: ";
        cin >> name;
        searchPlayer(players, currentCount, name);
        break;
    }
    case 3:
        addNewPlayer(players, currentCount, count);
        break;
    case 4: {
        string name;
        cout << "Enter player name to remove: ";
        cin >> name;
        removePlayerByName(players, currentCount, name);
        break;
            }
    case 5: {
        string name;
        cout << "Enter player name to update: ";
        cin >> name;
        updatePlayerByName(players, currentCount, name);
        break;
            }
	}
}