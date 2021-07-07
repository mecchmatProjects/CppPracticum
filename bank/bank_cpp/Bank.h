/**
 * Task 30. Bank
 * declarations of classes and methods
 * @see bank/bank_cpp/Bank.cpp
 * @author Elina Babakova
 *
 * Described project:
 * https://docs.google.com/document/d/144S7u59e_12W7rRKBAZtp_dD2950rIGO6lY2SUwt2qo/edit?usp=sharing
 * */

#include <iostream>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

enum Type {
    STOCK, // акція
    BOND // облігация
};

/**
 * used in class Bank for logging actions and statistics
 * */
class BankLogger {
private:
    int id = 0;
    const char *filename;
    const string COLUMN = ",";

    void increaseId();

    void init();


public:
    BankLogger(const char *filename) {
        this->filename = filename;
        init();
    }

    void log(string action, double currentBalance);

    void saveStatistics(double sumPaid, double sumReceived, int papersBougth, int papersSold, double sumFromPapers);

    void updateStatistics(int chose, double value);

    string getLineFromStatistics(int index);

    void initValues(double values[7], string line);
};

/**
 * used in class Bank for investment of money
 *
 * STOCK - type of paper, avg year rate is passed to constuctor; price is changed
 * everyday from range [rangeX, rangeY];
 *
 * BOND - type of paper, safer and more predictable than stock, but costs less
 *
 * rangeX, rangeY are chosen so that the price of the stock increases by x%;
 * formula present in https://docs.google.com/spreadsheets/d/1okrevlSh0L994-RxtGj2UH00Il8H4fjF6hKIYUdM3D8/edit?usp=sharing
 * */
class Paper {

private:
    string title;
    double price;
    double avgYearRate;
    double avgDayRate;
    Type type;
    double rangeX;
    double rangeY;
    int volatility = 1;

private:
    void changeStockPrice();

    void changeBondPrice();

public:
    Paper() {

    }

    Paper(string title, float price, float avgYearRate, Type type) {
        this->title = title;
        this->price = price;
        this->avgYearRate = avgYearRate;
        this->type = type;
        setRange();
    }

    static void changePrice();

    void changePriceForPaper();

    double getPrice() const;

    void setPrice(double price);

    const string &getTitle() const;


private:
    void setRange();
};

class Attachment {
private:
    int term;
    float yearRate;
    float rate;

public:
    Attachment(int term, float yearRate) {
        this->term = term;
        this->yearRate = yearRate;
        setRate();
    }

    Attachment() {}

    int getDayToPay(int currentDay);


private:
    void setRate();

public:
    int getTerm() const;

    float getRate() const;
};

/**
 * -> map<int, double> userAttachments: field for remembering day and sum to pay
 *    according to attachments
 *
 * -> actionLogger: object for logging actions and saving statistics
 * */
class Bank {
private:
    double sumPaid = 0;
    double sumReceived = 0;
    int papersSold = 0;
    int papersBougth = 0;
    map<int, double> userAttachments;
    vector<Paper> papers;
    Attachment attachments[4] = {
            Attachment{30, 7},
            Attachment{90, 8},
            Attachment{180, 8},
            Attachment{360, 10},
    };

    BankLogger actionLogger{"log-actions.csv"};

    void logAction(string action);


public:
    Bank() {
        for (int i = 1; i <= 360; ++i) {
            this->userAttachments.insert(pair<int, double>(i, 0));
        }
    }

    ~Bank() {
        userAttachments.clear();
        papers.clear();
    }

        void acceptCustomers(int day);

    Attachment getRandomAttachment();

    void payAttachments(int day);

    void buyPapers(Paper availablePapers[]);

    double getBalance() const;

    void sellPaper(double wishSum);

    int getTotalPapers();

    void printStatistics();

    double getSumFromPapers();

    void updateStatistics();

    void setSumPaid(double sumPaid);

    void setSumReceived(double sumReceived);
};