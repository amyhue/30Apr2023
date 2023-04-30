#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int N;
	//const int NUM_COLS = 2;
	//string arr[NUM_COLS];
	cin >> N;

	vector<vector<string>> totData;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<string> data;

		// organize the data w. the number before the color
		// assumes only one input of the two-input data is a number
		if (isdigit(s1[0])) { // first string is a number - need to divide by 2
			double newNum = 0;

			// changes the number based on data error factor
			for (int i = 0; i < s1.size(); i++) {
				int x = s1[i] - '0';
				newNum = newNum*10 + x;
			}
			newNum = newNum / 2;
			s1 = to_string(newNum);

			data.push_back(s1);
			data.push_back(s2);
		}
			
		else { // second string is a number
			data.push_back(s2);
			data.push_back(s1);
		}

		totData.push_back(data);
	}


	/*for (int i = 0; i < totData.size(); i++) {
		cout << totData.at(i).at(0) << " " << totData.at(i).at(1) << endl;
	}*/


	vector<vector<string>> sortedData;
	// sorts the data vectors according to greatest radius/
	// sorting not optimized (b/c haven't learned yet)
	sortedData.push_back(totData[0]);
	for (int i = 0; i < totData.size(); i++) {
		for (int j = 0; j < sortedData.size(); j++) {

			// if the number is smaller, insert it into the sorted data vector
			if (totData.at(i).at(0) < sortedData.at(j).at(0))
				sortedData.insert(sortedData.begin() + j, totData.at(i));

			else {
				if (j == sortedData.size() - 1) // if we've couldn't find a data vector in the sorted vector with a smaller radius
					sortedData.push_back(totData.at(i));
			}
		}
	}

	for (int i = 0; i < sortedData.size(); i++) {
		cout << sortedData.at(i).at(0) << " " << sortedData.at(i).at(1) << endl;
	}

	//output the colors
	/*for (int i = 0; i < sortedData.size(); i++) {
		cout << sortedData.at(i).at(1) << endl;
	}*/

	return 0;
}