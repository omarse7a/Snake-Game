#include "Components.h"

/*initializing player's info and getting highest results from scores.txt*/
Player::Player() {
	score = 0;
	cout << "Enter Player Name: ";
	cin >> name;
	ifstream fromFile("scores.txt");
	string line;
	if (fromFile.good()) {
		while (getline(fromFile, line)) {
			string numPart, strPart;
			for (int i = 0; i < line.size(); i++) {
				if (isdigit(line[i])) {	//if digit put in the score part 
					numPart.push_back(line[i]);
				}
				else if (isalpha(line[i])) { //if char put in the name part 
					strPart.push_back(line[i]);
				}
			}
			int n = stoi(numPart);	//converting str to int
			rank.push_back({ n, strPart });
		}
	}
}

/*Incrementing the score*/
void Player::incrementScore() {
	score += 10;
}

/*Getter function for the score*/
int Player::getScore() const{
	return score;
}

/*Getter function for the name*/
string Player::getName() const
{
	return name;
}

/*This funtion sorts the rank vector ascendingly and prints the highest 10 scores*/
void Player::getTopTen()
{
	if(score > 0) rank.push_back({ score, name }); //pushing the current score to the vector
	cout << "Top 10 Players: \n";
	sort(rank.begin(), rank.end());
	int i = 1;
	/*prints the content from the last item to the 10th from the back or less 
	(if the vector has less than 10 items)*/
	for (auto it = rank.rbegin(); it != rank.rend(); it++) {
		if (i > 10) break;	//breaks when 10 items are printed 
		cout << i  << ". " << it->second << ' ';
		cout << it->first << '\n';
		i++;
	}
}

/*Saving the top 10 scores to an external file*/
void Player::saveResults()
{
	ofstream toFile("scores.txt");
	int i = 1;
	/*prints the content from the last item to the 10th from the back or less
	(if the vector has less than 10 items) to the external text file*/
	for (auto it = rank.rbegin(); it != rank.rend(); it++) {
		if (i > 10) break;
		toFile << it->first << ' ';
		toFile << it->second << '\n';
		i++;
	}
}
