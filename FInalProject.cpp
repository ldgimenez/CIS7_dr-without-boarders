#include <iostream>
#include <string>

using namespace std;

//1.Determine the matches of particpants
//2.Code program that match selection based on language and special skill
//- 5 languages for 10 country match
//- at least 5 medical specialaty for selection
//3.Determine the probality of participants match based on language and specialty

int languageOption()
{
	int option;
	// Language Menu
	// Created a meuu for the laguages. Utilize do while loop with switch case to select a language. 
	// If the selection was invalid, menu will start over until a valid selection is made. 
	do
	{	
		cout << "What is your preferred language?" << endl;
		cout << "1. English" << endl;
		cout << "2. Spanish" << endl;
		cout << "3. French" << endl; 
		cout << "4. Russian" << endl;
		cout << "5. Mandarin" << endl; 
		cout << "6. Japanese" << endl; 
		cout << "7. Arabic" << endl; 
		cin >> option;

		switch (option)
		{
			case 1:
				cout << "\nEnglish is your language" << endl;
				break;
			case 2:
				cout << "Spanish is your language" << endl;
				break;
			case 3:
				cout << "French is your language" << endl;
				break;
			case 4:
				cout << "Russian is your language" << endl;
				break;
			case 5:
				cout << "Mandarin is your language" << endl;
				break;
			case 6:
				cout << "Japanese is your language" << endl;
				break;
			case 7:
				cout << "Arabic is your language" << endl;
				break;
			default:
				cout << "Invalid option. Pleasy try again." << endl;
		}
	} while (option <1 || option >7);

	return option;
}

int specializationOption()
{
	int special;
	// Specialization Menu
	// Menu was created with do while loop and swith case. There are 10 specialities to select from. 
	// if the input is invaild the loop will start over until a vaild option is selected. 
	do
	{
		cout << "\nWhat is your area of expertise?" << endl;
		cout << "1. Immunology" << endl;
		cout << "2. Plastic_Surgery" << endl;
		cout << "3. Bariatrics" << endl; 
		cout << "4. Oncology" << endl; 
		cout << "5. Dermatology" << endl; 
		cout << "6. Cardiology" << endl; 
		cout << "7. Orthopedic" << endl; 
		cout << "8. Neurosurgery" << endl; 
		cout << "9. Nephrology" << endl; 
		cout << "10. Psychiatric" << endl;
		cin >> special;

		switch (special)
		{
		case 1:
			cout << "\nYou specialize in Immunology" << endl;
			break;
		case 2:
			cout << "You specialize in Plastic Surgery" << endl;
			break;
		case 3:
			cout << "You specialize in Bariatrics" << endl;
			break;
		case 4:
			cout << "You specialize in Oncology" << endl;
			break;
		case 5:
			cout << "You specialize in Dermatolgy" << endl;
			break;
		case 6:
			cout << "You specialize in Cardiology" << endl;
			break;
		case 7:
			cout << "You specialize in Orthopedic" << endl;
			break;
		case 8:
			cout << "You specialize in Neurosurgery" << endl;
			break;
		case 9:
			cout << "You specialize in Neurology" << endl;
			break;
		case 10:
			cout << "You specialize in Psychiatric" << endl;
			break;
		default:
			cout << "Invalid option. Pleasy try again." << endl;
		}
	} while (special < 1 || special >10);

	return special;
}

double country(int language, int specialization)
{
	string country;
	double matchup=0.0;
	// This function uses if statements to select country based on laguage choice. Each language has 
	// a wieghted value for specilizations out of 10 choices. 
	// If there is no match up the selection it gives a weighted value of 0.
	
	if (language == 1) // English
	{
		if (specialization == 1 || specialization == 5) // Immuno , Dermatolgy
		{
			country = "USA";
		}
		else if (specialization == 8 || specialization == 10) // Neurosurgery, Psychiatric
		{
			country = "United Kingdom";
		}
		
		matchup = 0.4; // 4 out of 10 specializations
		
	}
	else if (language == 2) // Spanish
	{
		if (specialization == 2 || specialization == 6) // Plastic Surgery,  Cardiology
		{
			country = "Coloumbia"; 
		}
		else if (specialization == 3) //Bariatrics
		{
			country = "Mexico";
		}
		else if (specialization == 4 || specialization == 9) // Oncology, Neurology
		{
			country = "Spain";
		}
		matchup = 0.5; // 5 out of 10 specializations
	}
	else if (language == 3) // French
	{
		if (specialization == 5 || specialization == 7) // Dermatolgy, Orthopedic
		{
			country = "France";
		}
		matchup = 0.2; // 2 out of 10 specializations
	}
	else if (language == 4) // Russian
	{
		if (specialization == 6 || specialization == 9) // Cardiology, Neurology
		{
			country = "Russia";
		}
		matchup = 0.2; // 2 out of 10 specializations
	}
	else if (language == 5) // Mandarin
	{
		if (specialization == 7 || specialization == 3 || specialization == 10) // Orthopedic, Bariatrics, Psychiatric
		{
			country = "China";
		}
		matchup = 0.3; // 3 out of 10 specializations
	}
	else if (language == 6) // Japanese
	{
		if (specialization == 8 || specialization == 5 || specialization == 9) // Neurosurgery, Dermatolgy, Neurology 
		{
			country = "Japan";
		}
		matchup = 0.3; // 3 out of 10 specializations
	}
	else if (language == 7) // Arabic
	{
		if (specialization == 9 || specialization == 6 || specialization == 3 || specialization == 7) // Neurology, Cardiology, Bariatrics, Dermatolgy
		{
			country = "Saudi Arabia";
		}
		matchup = 0.4; // 4 out of 10 specializations
	}
	// If there is no match up , then this statement would print out. 
	if (country.empty())
	{
		cout << "\nUnforutanlly, there is not a country that mathces your language and "
			"specialization" << endl;
		matchup = 0.0;
	}
	else
	{
		cout << "\nYour chosen country is " << country << "!" << endl;
	}
	
	return matchup;
}

double probability(int language, int specialization)
{
	// This function calculates the probaility of the language and specilaity that is selected. 
	// Calls the wighted speciality match up value from the coutnry function.
	double langP = 0.14;
	double match = country(language, specialization);
	double prob;
	

	// probability = language probabilty times specialiazation probabilty times 100
	prob = langP * match * 100;
	
	cout << "/nThere is a " << langP << " chance from chooisng a language from 1/7." << "There was " << match
		<< " chance of choosing a speciality with you language." << endl;
	
	cout << " Your language times the specialitey times 100, gives you a " << prob << "% of a matchup!" << endl;

	return prob;

}
// Driver Code
int main()
{
	// Calls the int values of language and speciality to be utilize in the functions 
	// and to print out the menu and statements of each function. 	
	int language = languageOption();
	int specialization = specializationOption();
	probability(language, specialization);
	
	return 0;
}



