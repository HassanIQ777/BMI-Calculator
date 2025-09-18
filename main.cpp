/* Body Mass Index calculator by HassanIQ777 */
/* Made on 2025 Jul 19 */

#include "libutils/src/table.hpp"

double calculateBMI(const double &weight_kg, const double &height_m);
void printTable();
std::string getStatus(const double &BMI);

int main()
{
	double weight_kg, height_m;

	std::cout << "Weight(kg): ";
	std::cin >> weight_kg;

	std::cout << "Height(cm): ";
	std::cin >> height_m;

	double BMI = calculateBMI(weight_kg, height_m / 100);
	BMI = static_cast<int>(BMI * 10) / 10.0f;

	std::cout << "\nYour BMI is " << BMI << "\n";

	std::string status = getStatus(BMI);
	std::cout << "Status: " << status << "\n\n";

	printTable();

	std::cin.ignore();
	std::cin.get();
}

double calculateBMI(const double &weight_kg, const double &height_m)
{
	return weight_kg / (height_m * height_m);
}

void printTable()
{
	static Table BMI_table;
	
	BMI_table.m_setTrailingSpaces(6);
	
	BMI_table.m_setHeader("BMI Category", "BMI Range");

	BMI_table.m_addRow("Underweight", "Below 18.5");
	BMI_table.m_addRow("Healthy", "18.5 - 24.9");
	BMI_table.m_addRow("Overweight", "25.0 - 29.9");
	BMI_table.m_addRow("Obesity", "30.0 - 40.0");
	BMI_table.m_addRow("Extreme Obesity", "40.0 or above");

	std::cout << BMI_table;
}

std::string getStatus(const double &BMI)
{
	std::string status;

	if (BMI < 18.5)
	{
		status = "Underweight";
	}
	else if (BMI >= 18.5 && BMI <= 24.9)
	{
		status = "Healthy";
	}
	else if (BMI >= 24.9 && BMI <= 29.9)
	{
		status = "Overweight";
	}
	else if (BMI >= 30 && BMI < 40)
	{
		status = "Obesity";
	}
	else
	{
		status = "Extreme Obesity";
	}

	return status;
}