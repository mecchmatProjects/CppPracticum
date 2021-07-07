/**
 * Task 30. Bank
 * implementations of classes from Bank.h
 * @see bank/bank_cpp/Bank.h
 * @author Elina Babakova
 *
 * Described project:
 * https://docs.google.com/document/d/144S7u59e_12W7rRKBAZtp_dD2950rIGO6lY2SUwt2qo/edit?usp=sharing
 * */

#include "Bank.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <random>
#include <fstream>
#include <sstream>

Paper papers[] = {
        Paper{"Stock 'coca-cola'", 1000, 63, STOCK},
        Paper{"Bond #1", 800, 42, BOND},
        Paper{"Stock 'samsung'", 500, 55, STOCK},
};

using namespace std;

const double MIN_SUM = 500;
const double MAX_SUM = 2000;
const double SUM_WHEN_BUY_PAPER = 2000;
const int YEAR = 360;

/**
 * @returns random double in range [min, max]
 * */
double randomDouble(double min, double max) {
    return min + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
}

/**
 * @returns random int in range [min, max]
 * */
int randomInt(int min, int max) {
    return rand() % max + min;
}

/**
 * method for accepting 0-5 customers at @param day. Every customer
 * invested with rates according to random attachment. Future bank's
 * pay with rates to user is saved in map<int, double> userAttachments field
 *
 * @see bank/bank_cpp/Bank.h -> Attachment
 * */
void Bank::acceptCustomers(int day) {
    int totalCustomersToday = randomInt(0, 5);

    for (int i = 0; i < totalCustomersToday; ++i) {
        Attachment attachment = getRandomAttachment();
        double sum = randomDouble(MIN_SUM, MAX_SUM);
        int dayToPayUser = attachment.getDayToPay(day);
        double totalToPay = userAttachments.find(dayToPayUser)->second;
        userAttachments.erase(dayToPayUser);
        userAttachments.insert(pair<int, double>(dayToPayUser, totalToPay + sum + sum * attachment.getRate()));
        this->sumReceived += sum;
        this->logAction("User invested " + to_string(sum) + " with rate " + to_string(attachment.getRate()));
    }
}

/**
 * method for paying back attachments to users with rates
 * */
void Bank::payAttachments(int day) {
    double sumToPay = userAttachments.find(day)->second;
    if (sumToPay == 0) return;
    if (getBalance() - sumToPay < 40000) {
        this->sellPaper(sumToPay);
    }
    this->sumPaid += sumToPay;
    this->logAction("Bank pay back with rate, sum = " + to_string(sumToPay));
}

/**
 * @returns random attachment
 * */
Attachment Bank::getRandomAttachment() {
    return this->attachments[randomInt(0, 4)];
}

/**
 * @returns balance of Bank
 * */
double Bank::getBalance() const {
    return this->sumReceived - this->sumPaid;
}

/**
 * method for buying random paper by bank
 * */
void Bank::buyPapers(Paper *papers) {
    if (getBalance() >= SUM_WHEN_BUY_PAPER) {
        int index = randomInt(0, 2);
        Paper paper = papers[index];
        this->papers.push_back(paper);
        this->papersBougth += 1;
        this->sumPaid += paper.getPrice();
        this->logAction("Bank buys " + paper.getTitle());
    }
}

/**
 * method for selling n papers by bank, so that total totalSell >= @param sum
 * */
void Bank::sellPaper(double sum) {
    double totalSell = 0;
    while (totalSell < sum && !this->papers.empty()) {
        Paper toSell = papers[0];
        papers.erase(papers.begin());
        totalSell += toSell.getPrice();

        this->papersSold += 1;
        this->sumReceived += toSell.getPrice();

        this->logAction("Bank sell paper " + toSell.getTitle() + " by price " + to_string(toSell.getPrice()));
    }
}

int Bank::getTotalPapers() {
    return this->papers.size();
}

/**
 * method for printing statistics to console and saving it to csv file
 * */
void Bank::printStatistics() {
    double sumFromPapers = getSumFromPapers();
    cout << "===============================" << endl;
    cout << "TOTAL SUM PAID = " << this->sumPaid << endl;
    cout << "TOTAL SUM RECEIVED = " << this->sumReceived << endl;
    cout << "TOTAL PAPERS BOUGHT = " << this->papersBougth << endl;
    cout << "TOTAL PAPERS SOLD = " << this->papersSold << endl;
    cout << "TOTAL BALANCE = " << this->sumReceived - this->sumPaid << endl;
    cout << "TOTAL BALANCE IN PAPERS = " << sumFromPapers << endl;
    cout << "TOTAL BALANCE (WITH PAPERS) = " << sumFromPapers + this->sumReceived - this->sumPaid << endl;
    cout << "===============================" << endl;
    this->actionLogger.saveStatistics(this->sumPaid, this->sumReceived, this->papersBougth, this->papersSold,
                                      sumFromPapers);
}

/**
 * @returns total sum of bought papers
 * */
double Bank::getSumFromPapers() {
    double res = 0;
    for (auto &paper : papers) {
        res += paper.getPrice();
    }
    return res;
}

/**
 * method for logging an action to actionLogger.filename
 * */
void Bank::logAction(string action) {
    cout << action << ", balance = " << getBalance() << endl;
    this->actionLogger.log(action, getBalance());
}

/**
 * method for updating statistics.csv file by user
 * */
void Bank::updateStatistics() {
    string answer;
    cout << "Do you want to edit statistics.csv? (y/n)" << endl;
    cin >> answer;
    while (answer == "y") {
        cout << "What do you want to edit?" << endl;
        cout << "total sum paid (1)" << endl;
        cout << "total sum received (2)" << endl;
        cout << "total papers bought (3)" << endl;
        cout << "total papers sold (4)" << endl;
        cout << "total balance in papers (5)" << endl;

        int chose;
        cin >> chose;

        if (chose < 1 || chose > 5) {
            cout << "Please provide a valid number" << endl;
            continue;
        }

        cout << "Input new value" << endl;
        double value;
        cin >> value;

        this->actionLogger.updateStatistics(chose, value);

        cout << "Successfully edited!" << endl;
        cout << "Do you want to edit another value? (y/n)" << endl;
        cin >> answer;
    }
}

void Bank::setSumPaid(double sumPaid) {
    Bank::sumPaid = sumPaid;
}

void Bank::setSumReceived(double sumReceived) {
    Bank::sumReceived = sumReceived;
}

void Paper::changePrice() {
    for (auto &paper : papers) {
        paper.changePriceForPaper();
    }
}

double Paper::getPrice() const {
    return price;
}

void Paper::setPrice(double price) {
    Paper::price = price;
}

void Paper::changePriceForPaper() {
    switch (this->type) {
        case STOCK:
            this->changeStockPrice();
            break;
        case BOND:
            this->changeBondPrice();
    }
}

/**
 * method for changing stock price. Price is changed by random percentage from range [rangeX, rangeY]
 * */
void Paper::changeStockPrice() {
    double randPercentage = randomDouble(this->rangeX, this->rangeY);
    this->setPrice(price + (price * randPercentage / 100));
}

/**
 * method for changing bond price. Price is changed by fixed percentage
 * */
void Paper::changeBondPrice() {
    this->setPrice(price + (price * avgDayRate / 100));
}

const string &Paper::getTitle() const {
    return title;
}

/**
 * setting range of daily percentage for stock
 * */
void Paper::setRange() {
    double avgDay = 36500 * ((pow(avgYearRate / 100 + 1, (double) 1 / 365)) - 1) / 365;
    this->avgDayRate = avgDay;
    double start = -0.05 * volatility;
    double end = avgDay * 2 - start;
    this->rangeX = start;
    this->rangeY = end;
}

void Attachment::setRate() {
    this->rate = ((float) term / YEAR * yearRate) / 100;
}

int Attachment::getTerm() const {
    return term;
}

int Attachment::getDayToPay(int currentDay) {
    return this->getTerm() + currentDay;
}

float Attachment::getRate() const {
    return rate;
}

/**
 * method for logging an action to this->filename
 * */
void BankLogger::log(string action, double currentBalance) {
    ofstream logfile(this->filename, ios_base::app);
    increaseId();
    logfile << this->id;
    logfile << COLUMN;
    logfile << action;
    logfile << COLUMN;
    logfile << currentBalance;
    logfile << "\n";
    logfile.close();
}

void BankLogger::increaseId() {
    this->id += 1;
}

/**
 * creating this->filename.scv and saving first row
 * */
void BankLogger::init() {
    remove(this->filename);
    ofstream logfile(this->filename);
    logfile << "id";
    logfile << COLUMN;
    logfile << "action";
    logfile << COLUMN;
    logfile << "current balance";
    logfile << "\n";
    logfile.close();
}

/**
 * method for saving statistics to statistics.csv
 * */
void BankLogger::saveStatistics(double sumPaid, double sumReceived, int papersBougth, int papersSold, double sumFromPapers) {
    ofstream statisticsFile("statistics.csv");
    statisticsFile << "total sum paid";
    statisticsFile << COLUMN;
    statisticsFile << "total sum received";
    statisticsFile << COLUMN;
    statisticsFile << "total papers bought";
    statisticsFile << COLUMN;
    statisticsFile << "total papers sold";
    statisticsFile << COLUMN;
    statisticsFile << "total balance in papers";
    statisticsFile << COLUMN;
    statisticsFile << "total balance";
    statisticsFile << COLUMN;
    statisticsFile << "total balance (with papers)";
    statisticsFile << "\n";

    statisticsFile << sumPaid;
    statisticsFile << COLUMN;
    statisticsFile << sumReceived;
    statisticsFile << COLUMN;
    statisticsFile << papersBougth;
    statisticsFile << COLUMN;
    statisticsFile << papersSold;
    statisticsFile << COLUMN;
    statisticsFile << sumFromPapers;
    statisticsFile << COLUMN;
    statisticsFile << sumReceived - sumPaid;
    statisticsFile << COLUMN;
    statisticsFile << sumReceived - sumPaid + sumFromPapers;
    statisticsFile.close();
}

/**
 * method for updating statistics.csv by @chose value (index in range [1, 5])
 * with @param chosenValue
 * */
void BankLogger::updateStatistics(int chose, double chosenValue) {
    double values[7];
    string line = getLineFromStatistics(1);
    initValues(values, line);
    values[chose - 1] = chosenValue;
    saveStatistics(values[0], values[1], values[2], values[3], values[4]);
}

/**
 * method for splitting a line by comma and filling an array values[7] with converted strings to doubles
 * */
void BankLogger::initValues(double values[7], string line) {
    stringstream ss(line);
    int index = 0;

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        values[index] = atof(substr.c_str());
        index++;
    }
}

/**
 * @returns a line from statistics.csv by @param index
 * */
string BankLogger::getLineFromStatistics(int index) {
    string line;
    ifstream statisticsFile("statistics.csv");
    for (int lineno = 0; getline(statisticsFile, line) && lineno < 7; lineno++) {
        if (lineno == index) {
            break;
        }
    }
    return line;
}