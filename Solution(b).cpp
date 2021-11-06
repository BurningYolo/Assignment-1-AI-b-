#include<iostream>
using namespace std; 

class world
{
public:
	struct
	{
		string movement[4]{ "east","south","west","north" };
		string rooms[4]{ "A","B","D","C" };

	};
	struct
	{
		int dirt;
		int total_energy;
		int total_dirt;
		int total_time;
		int total_energy_used_for_movement_and_checking;
		int total_energy_used_for_collecting_dirt;
	};

	world()
	{
		dirt = 0;
		total_dirt = 0;
		total_energy = 0;
		total_time = 0;
		total_energy_used_for_collecting_dirt = 0;
		total_energy_used_for_movement_and_checking = 0;

	}

	int dirt_generation()
	{
		dirt = rand() % 4;
		return dirt;
	}

	void autoprocess(int agent, int counter)
	{
		if (counter < 4)
		{
			dirt = dirt_generation();
		}
		else
		{
			dirt = 0;
		}

		if (dirt > 0)
		{
			cout << "In room : " << rooms[agent] << endl;
			cout << "Checking for dirt ... " << endl;
			total_energy_used_for_movement_and_checking++; 
			total_energy++; 
			total_time++; 
			cout << " Dirt found : " << dirt << endl;
			cout << "Cleaning ..." << endl;
			total_energy_used_for_collecting_dirt += dirt * 2; 
			total_energy += dirt * 2; 
			total_time++; 
			cout << "Moving in direction " << movement[agent] << endl;
			total_energy_used_for_movement_and_checking++; 
			total_time++; 
			total_energy++; 
			total_dirt += dirt; 
		}

		else if (dirt == 0)
		{
			cout << "In room : " << rooms[agent] << endl;
			cout << "Checking for dirt ... " << endl;
			total_energy_used_for_movement_and_checking++;
			total_time++;
			total_energy++;
			cout << "Dirt not found : " << dirt << endl;
			cout << "Moving in direction " << movement[agent] << endl;
			total_energy_used_for_movement_and_checking++;
			total_time++;
			total_energy++;
		}


	}


	void finalscreen()
	{
		cout << "**********************" << endl;
		cout << " " << endl;
		cout << "Total Energy consumed :  " << total_energy << endl;
		cout << "Total Dirt Collected :  " << total_dirt << endl;
		cout << "Total Time used :  " << total_time << endl;
		cout << "Total Energy consumed in moving and checking purposes : " << total_energy_used_for_movement_and_checking << endl; 
		cout << "Total Energy consumed while collecting dirt : " << total_energy_used_for_collecting_dirt << endl;
		cout << " " << endl;
		cout << "**********************" << endl;
	}
};



	int main()
	{
		world w;
		int agent = 0;
		int counter = 0;
		int backpath = 0; 

		for (agent = 0; agent <= 3; agent++)
		{
			w.autoprocess(agent, counter);
			counter++;
			if (agent == 3 && backpath == 0  )
			{
				agent = -1; 
				backpath = 1; 
			}

		}

		w.finalscreen(); 

	}
