// CIS023_S2015_Lab14 Zachary Muerle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



Incorrect_Format baseCheck(char cIn, bool& commaFound, bool& decimalFound){
	if ((cIn == ',' && commaFound == true)){
		return Incorrect_Format("Multiple commas");
	}
	else if (cIn == '.' && (decimalFound == true)){
		return Incorrect_Format("Multiple Decimals");
	}
	else if (cIn == '.' && commaFound == false){
		return Incorrect_Format("Decimal in Feet");
	}
	else if (!isdigit(cIn) && (cIn != '.' && cIn != ',')){//if it's not a digit
		return Incorrect_Format("Non-numerical input: \""+ string(1,cIn) + "\"");//invalid_argument
	}
	else{
		return Incorrect_Format("none");
	}
	//if it's not a digit, or (if it's a comma, and we haven't seen one already), or (if it's a decimal, the first we've seen, and it's after the comma)

}

void processInput(string sIn, int& iFt, double& dblIn){
	string stHolder;
	string stFt;
	string stInch;
	bool commaFound = false;
	bool decimalFound = false;
	for each (char cIn in sIn)
	{
		Incorrect_Format error = baseCheck(cIn, commaFound, decimalFound);//this function was originally needlessly complicated, so I kicked it out
		string errWhat = error.what();
		if (errWhat != "none"){
			if (errWhat.find("Non-numerical input: ") != -1){
				throw invalid_argument(errWhat);
			}
			else
				throw error;
		}

		if (cIn == '.'){
			decimalFound = true;
		}
		if (cIn != ','){
			stHolder += cIn;
		}
		else{
			stFt = stHolder;
			stHolder = "";
			commaFound = true;
		}
	}
	stInch = stHolder;
	if (!commaFound){
		throw Incorrect_Format("No comma");
	}
	if (stFt == "")
		throw length_error("Feet was blank");//yes, I could just default them to 0, but the project said to not accept it
	if (stInch == "")
		throw length_error("Inches was blank");
	iFt = stoi(stFt);
	dblIn = stod(stInch);
	if (dblIn >= 12)
		throw range_error("Inches >= 12");
	//I had <0 checking here, but I don't allow putting "-", so they can't possibly put a value < 0

	//damn. just saw that the prject has to "Display a specific error message for each exception.". switch all the return false's to return string.
	//also do it using exception handling, so instead of protecting the code, let it slam into the wall and fix it after.
	//changed all returns to throws, and modified the code to give more explicit errors
}

double convertToCM(int iFeet, double dblInches){
	return ((iFeet * 12) + dblInches)*2.54;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string stInput;
	int iFeet = 0;
	double dblInches = 0;
	cout << "Input a measurement in the form \"*feet*,*inches*\". \n inches may be in decimal, feet may not be. \n  Both must be entered, even if 0.\n  Both values must be positive.\n";
	cin >> stInput;
	try{
		processInput(stInput, iFeet, dblInches);
		cout << "I registered an input of " << iFeet << " Feet, and " << dblInches << " Inches,\n";
		cout << " Which is equal to " << to_string(convertToCM(iFeet, dblInches)) << " cm.\n";
	}
	catch (Incorrect_Format fmtex){
		cout << "The given input, \"" << stInput << "\" has a format exception: " << fmtex.what() << endl;
	}
	catch (invalid_argument IAex){
		cout << "The given input, \"" << stInput << "\" has an invalid input: " << IAex.what() << endl;
	}
	catch (length_error Lengthex){
		cout << "The given input, \"" << stInput << "\" has an invalid length: " << Lengthex.what() << endl;
	}
	catch (range_error Rangeex){
		cout << "The given input, \"" << stInput << "\" has a value outside of the required range: " << Rangeex.what() << endl;
	}
	catch (...){
		cout << "There was an unknown exception. \n";
	}
	system("pause");
	return 0;
}

