#pragma once

/*

*/
#define SIZE 2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using std::ofstream;
using std::setfill;
using std::vector;
using std::swap;

struct Time {
	// TIME
	int hour; // 0 - 23 (24-hîur clîck fîrmàt)
	int minute; // 0 - 59
	int second; // 0 - 59
};

// THE STRUCT INFORMATION
struct Train {
	signed num_train;
	std::string dest;

	Time arrived_time; // INITIALIZE FOR A ARRIVED_TIME
	Time departure_time; // INITIALIZE FOR A DEPARTURE_TIME
};

struct Sort {
	static int partition(Train arr[], int low, int high);
	static void quickSort(Train arr[], int low, int high);
};

// JUST INITIALIZE
struct Information {
	/*static const int size = 5;*/
	Train info[SIZE];

	ofstream textfile;

	Information(); // THE CONSTRUCTOR
	bool textFile(const char* filename);
	void vvod();
	void vivod();

	// SET TIME
	void setTime(Time& time, int, int, int);
	void printStandard(Time& time);
	void printUniversal(Time& time);
	void find();

	//// GETTERS
	//void setHour(int x) { info[size].hîur = x; }
	//void setMinute(int x) { info[size].minutå = x; }
	//void setSeconds(int x) { såcînd = x; }
	//// SETTERS
	//int getHour() const { return hîur; }
	//int getMinute() const { return minutå; }
	//int getSecond() const { return  såcînd; }

	 // ñalculate time difference in minutes between two Time objects
	int getTimeDifference(const Time& t1, const Time& t2) {
		int t1_minutes = t1.hour * 60 + t1.minute; // we convert the first time completely into minutes(2 * 60 = 120, then 120 + 30 = 150)
		int t2_minutes = t2.hour * 60 + t2.minute; // example(1 * 60 = 60, then 60+10 = 70)
		return t1_minutes - t2_minutes; // ñalculate the difference between two times in minutes(example 150 - 70 = 80)
	}

	void sortTrains() {
		Sort::quickSort(info, 0, SIZE - 1);
	}
};