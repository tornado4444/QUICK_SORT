#include "initializeStructure.hpp"

// INITIALIZE FOR CONSTRUCTOR
Information::Information() {
	for (int i = 0; i < SIZE; i++) {
		info[i].num_train = 0;
		info[i].dest = "";
		info[i].arrived_time = { 0, 0, 0 };
		info[i].departure_time = { 0, 0, 0 };
	}
}

// SET THE TIME
void Information::setTime(Time& time, int h, int m, int s) {
	time.hour = (h >= 0 && h < 24) ? h : 0; // vаlidаtе hоur
	time.minute = (m >= 0 && m < 60) ? m : 0; // vаlidаtе minutе
	time.second = (s >= 0 && s < 60) ? s : 0; // vаlidаtе sеcоnd
}

void Information::printUniversal(Time& time) {
	std::cout << setfill('0') << std::setw(2) << time.hour << ":"
		<< std::setw(2) << time.minute << ":" << std::setw(2) << time.second;
}

void Information::printStandard(Time& time) {
	std::cout << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12)
		<< ":" << std::setfill('0') << std::setw(2) << time.minute
		<< ":" << std::setfill('0') << std::setw(2) << time.second
		<< (time.hour < 12 ? " AM" : " PM");
}

// INITIALIZE FOR TEXT FILE
bool Information::textFile(const char* filename) {
	textfile.open(filename);
	if (!textfile.is_open()) {
		std::cout << "ERROR TO CREATE FILES!";
		return false;
	}
	return true;
}

// VVOD INFORMATION
void Information::vvod() {
	for (int i = 0; i < SIZE; i++) {
		std::cout << "Train " << i + 1 << ":\n";
		std::cout << "Train number: ";
		std::cin >> info[i].num_train;
		std::cout << "Destination: ";
		std::cin >> info[i].dest;

		int h, m, s;
		std::cout << "Arrival time (hours minutes seconds): ";
		std::cin >> h >> m >> s;
		setTime(info[i].arrived_time, h, m, s);

		std::cout << "Departure time (hours minutes seconds): ";
		std::cin >> h >> m >> s;
		setTime(info[i].departure_time, h, m, s);

		// Writing to file
		textfile << "Train " << i + 1 << ":\n"
			<< "Train number: " << info[i].num_train << '\n'
			<< "Destination: " << info[i].dest << '\n'
			<< "Arrival time: ";
		textfile << std::setfill('0') << std::setw(2) << info[i].arrived_time.hour << ":"
			<< std::setfill('0') << std::setw(2) << info[i].arrived_time.minute << ":"
			<< std::setfill('0') << std::setw(2) << info[i].arrived_time.second << '\n';
		textfile << "Departure time: ";
		textfile << std::setfill('0') << std::setw(2) << info[i].departure_time.hour << ":"
			<< std::setfill('0') << std::setw(2) << info[i].departure_time.minute << ":"
			<< std::setfill('0') << std::setw(2) << info[i].departure_time.second << '\n';
		textfile << "------------------------\n";
	}
}

void Information::vivod() {
	for (int i = 0; i < SIZE; i++) {
		std::cout << "\nTrain " << i + 1 << " information:\n"
			<< "Number: " << info[i].num_train << '\n'
			<< "Destination: " << info[i].dest << '\n'
			<< "Time (24-hour): ";
		printUniversal(info[i].arrived_time);
		std::cout << '\n' << "Arrival time (12-hour): ";
		printStandard(info[i].arrived_time);
		std::cout << '\n' << "Departure time (24-hour): ";
		printUniversal(info[i].departure_time);
		std::cout << '\n' << "Departure time (12-hour): ";
		printStandard(info[i].departure_time);
		std::cout << "\n------------------------\n";
	}
}

// THE FIND 
void Information::find() {
	std::cout << "\nTrains with journey time exceeding 7 hours 20 minutes:\n";
	for (int i = 0; i < SIZE; i++) {
		int journey_time = getTimeDifference(info[i].arrived_time, info[i].departure_time);
		if (journey_time > 440) { // 440 minutes = 7 hours 20 minutes
			std::cout << "\nTrain " << info[i].num_train
				<< "\nDestination: " << info[i].dest
				<< "\nDeparture time: ";
			printUniversal(info[i].departure_time);
			std::cout << "\nArrival time: ";
			printUniversal(info[i].arrived_time);
			std::cout << "\n------------------------\n";
		}
	}
}

/*
 ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄    ▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌ ▐░▌      ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀
▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          ▐░▌▐░▌       ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌
▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          ▐░▌░▌        ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌
▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          ▐░░▌         ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░▌
▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          ▐░▌░▌         ▀▀▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░█▀▀▀▀█░█▀▀      ▐░▌
▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          ▐░▌▐░▌                 ▐░▌▐░▌       ▐░▌▐░▌     ▐░▌       ▐░▌
 ▀▀▀▀▀▀█░█▀▀ ▐░█▄▄▄▄▄▄▄█░▌ ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌ ▐░▌       ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌      ▐░▌      ▐░▌
		▐░▌  ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌  ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌
		 ▀    ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀    ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀       ▀

*/
int Sort::partition(Train arr[], int low, int high) {
	std::string pivot = arr[high].dest;
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (arr[j].dest <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void Sort::quickSort(Train arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}