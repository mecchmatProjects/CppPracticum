#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Date
{
	Date()
	{
		Day = 0;
		Month = 0;
		Year = 0;
	}

	Date(int otherDay, int otherMonth, int otherYear)
	{
		Day = otherDay;
		Month = otherMonth;
		Year = otherYear;
	}

	int Day;
	int Month;
	int Year;
};

void deleteOther(std::string& otherStr)
{
	for (size_t i = 0; i < otherStr.size(); i++)
	{
		if (!isdigit(otherStr[i]) && otherStr[i] != '/')
		{
			otherStr.erase(otherStr.begin() + i);
			i--;
		}
	}
}

std::vector<Date> getParsedDates(std::vector<std::string> sDates)
{
	std::vector<Date> resultVec;
	for (size_t i = 0; i < sDates.size(); i++)
	{
		deleteOther(sDates[i]);
		if (!sDates[i].empty())
		{
			Date dt;
			std::string tempStr;
			int j = 0;
			while (j < sDates[i].size() && sDates[i][j] != '/')
			{
				if (isdigit(sDates[i][j]))
				{
					tempStr.push_back(sDates[i][j]);
				}
				j++;
			}
			dt.Day = stoi(tempStr);
			j++;
			tempStr.clear();

			while (j < sDates[i].size() && sDates[i][j] != '/')
			{
				if (isdigit(sDates[i][j]))
				{
					tempStr.push_back(sDates[i][j]);
				}
				j++;
			}
			dt.Month = stoi(tempStr);
			j++;
			tempStr.clear();

			while (j < sDates[i].size() && sDates[i][j] != '/')
			{
				if (isdigit(sDates[i][j]))
				{
					tempStr.push_back(sDates[i][j]);
				}
				j++;
			}
			dt.Year = stoi(tempStr);
			tempStr.clear();

			if (dt.Year > 1950 && dt.Year < 2050)
			{
				bool flag = false;
				for (size_t i = 0; i < resultVec.size(); i++)
				{
					if (resultVec[i].Day == dt.Day && 
						resultVec[i].Month == dt.Month &&
						resultVec[i].Year == dt.Year)
					{
						flag = true;
					}
				}
				if (!flag)
				{
					resultVec.push_back(dt);
				}
			}
		}
	}
	return resultVec;
}

int datecmp(Date* d1, Date* d2)
{
	return (d1->Year != d2->Year) ? d1->Year - d2->Year : (d1->Month != d2->Month) ? d1->Month - d2->Month : d1->Day - d2->Day;
}

void datesSort(std::vector<Date>& dates)
{
	for (int i = 0; i < dates.size() - 1; i++) {
		for (int j = 0; j < dates.size() - i - 1; j++) 
		{
			if (datecmp(&dates[j], &dates[j + 1]) < 0) 
			{
				Date temp = dates[j];
				dates[j] = dates[j + 1];
				dates[j + 1] = temp;
			}
		}
	}
}

int main()
{
	std::ifstream fin("fin.txt");

	std::vector<std::string> inputDates;
	if (fin.is_open())
	{
		while (fin)
		{
			std::string tempStr;
			std::getline(fin, tempStr);
			if (!fin)
			{
				break;
			}
			if (!tempStr.empty())
			{
				inputDates.push_back(tempStr);
			}
		}
	}
	fin.close();
	std::vector<Date> res = getParsedDates(inputDates);
	datesSort(res);
	std::ofstream fout("fout.txt");
	if (fout.is_open())
	{
		for (size_t i = 0; i < res.size(); i++)
		{
			fout << res[i].Day << "/";
			fout << res[i].Month << "/";
			fout << res[i].Year << "\n";
		}
	}

	return 0;
}
