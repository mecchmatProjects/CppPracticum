/**
 * Task 30. Bank
 * file for testing functions; main method for starting tests/ main program
 * @author Elina Babakova
 *
 * Described project:
 * https://docs.google.com/document/d/144S7u59e_12W7rRKBAZtp_dD2950rIGO6lY2SUwt2qo/edit?usp=sharing
 * */

#include "Bank.h"
#include <fstream>
#include <sstream>

const int YEAR = 360;


Paper papersForTesting[] = {
        Paper{"Stock 'coca-cola'", 1000, 43, STOCK},
        Paper{"Bond #1", 800, 35, BOND},
        Paper{"Stock 'samsung'", 1300, 51, STOCK},
};

void logSuccess(string testName) {
    cout << "*** " << testName << " PASSED!" << " ***" << endl;
}

void getRandomAttachmentTest() {
    Bank bank{};
    Attachment attachment = bank.getRandomAttachment();
    int term = attachment.getTerm();
    if (!(term == 30 || term == 90 || term == 180 || term == 360)) {
        cout << "getRandomAttachmentTest failed. Expected term value: 30/90/180/360. Actual term value = " << term;
        return;
    }
    logSuccess("getRandomAttachmentTest");
}

void getBalanceTest() {
    Bank bank{};
    bank.setSumReceived(12600);
    bank.setSumPaid(12000);
    double balance = bank.getBalance();
    if (balance != 600) {
        cout << "getBalanceTest failed. Expected balance value: 600. Actual balance value = " << balance;
        return;
    }
    logSuccess("getBalanceTest");
}

void buyPapersTest() {
    Bank bank{};
    bank.setSumReceived(3000);
    bank.setSumPaid(1000);
    bank.buyPapers(papersForTesting);
    bank.buyPapers(papersForTesting);
    if (bank.getTotalPapers() != 1) {
        cout << "buyPapersTest failed. Expected total papers value: 1. Actual total papers value = "
             << bank.getTotalPapers();
        return;
    }
    logSuccess("buyPapersTest");
}

void sellPaperTest() {
    Bank bank{};
    bank.setSumReceived(3000);
    bank.setSumPaid(1000);
    bank.buyPapers(papersForTesting);
    bank.sellPaper(500);
    if (bank.getTotalPapers() != 0) {
        cout << "sellPaperTest failed. Expected total papers value: 0. Actual total papers value = "
             << bank.getTotalPapers();
        return;
    }
    logSuccess("sellPaperTest");
}

void getSumFromPapersTest() {
    Bank bank{};
    bank.setSumReceived(3000);
    bank.setSumPaid(1000);
    bank.buyPapers(papersForTesting);
    double sum = bank.getSumFromPapers();
    if (sum <= 0) {
        cout << "getSumFromPapersTest failed. Expected sum value > 0. Actual sum value = " << sum;
        return;
    }
    logSuccess("getSumFromPapersTest");
}


void fillData(double data[5], int mode) {
    if (mode == 1) {
        cout << "Sum paid=";
        cin >> data[0];
        cout << "Sum received=";
        cin >> data[1];
        cout << "Papers bought=";
        cin >> data[2];
        cout << "Papers sold=";
        cin >> data[3];
        cout << "Sum from papers=";
        cin >> data[4];
    } else {
        string line;
        ifstream statisticsFile("save-statistics-test-data.csv");
        for (int lineno = 0; getline(statisticsFile, line) && lineno < 7;) {
            break;
        }

        int index = 0;
        stringstream ss(line);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            data[index] = atof(substr.c_str());
            index++;
        }
    }
}

void saveStatisticsTest(int mode) {
    BankLogger logger{"log-actions.csv"};
    double data[5];
    fillData(data, mode);
    logger.saveStatistics(data[0], data[1], data[2], data[3], data[4]);

    string line = logger.getLineFromStatistics(1);
    double res[7];
    logger.initValues(res, line);

    if (data[0] != res[0]) {
        cout << "saveStatisticsTest failed! Expected total sum paid: " << data[0] << ", actual: " << res[0] << endl;
        return;
    }
    if (data[1] != res[1]) {
        cout << "saveStatisticsTest failed! Expected total sum received: " << data[0] << ", actual: " << res[0] << endl;
        return;
    }
    if (data[2] != res[2]) {
        cout << "saveStatisticsTest failed! Expected total papers bought: " << data[0] << ", actual: " << res[0]
             << endl;
        return;
    }
    if (data[3] != res[3]) {
        cout << "saveStatisticsTest failed! Expected total sum sold: " << data[0] << ", actual: " << res[0] << endl;
        return;
    }
    if (data[4] != res[4]) {
        cout << "saveStatisticsTest failed! Expected total balance in papers: " << data[0] << ", actual: " << res[0]
             << endl;
        return;
    }
    if (data[1] - data[0] != res[5]) {
        cout << "saveStatisticsTest failed! Expected total balance: " << data[1] - data[0] << ", actual: " << res[5]
             << endl;
        return;
    }
    if (data[1] - data[0] + data[4] != res[6]) {
        cout << "saveStatisticsTest failed! Expected total balance (with papers): " << data[1] - data[0] + data[4]
             << ", actual: " << res[6]
             << endl;
        return;
    }
    logSuccess("saveStatisticsTest");
}

int main() {
    cout << "Start testing or program? (t/p)" << endl;
    string answer;
    cin >> answer;
    if (answer == "t") {
        int mode;
        cout << "==== START TESTING ====" << endl;
        cout << "Choose testing mode" << endl;
        cout << "Input from console (1)" << endl;
        cout << "Input from file save-statistics-test-data.csv (2)" << endl;
        cin >> mode;
        getRandomAttachmentTest();
        getBalanceTest();
        buyPapersTest();
        sellPaperTest();
        getSumFromPapersTest();
        saveStatisticsTest(mode);
        cout << "==== FINISH TESTING ====" << endl;
    } else {
        cout << "==== START PROGRAM ====" << endl;
        Bank bank{};

        for (int i = 1; i <= YEAR; ++i) {
            cout << "DAY #" << i << endl;
            Paper::changePrice();
            bank.acceptCustomers(i);
            bank.payAttachments(i);
            bank.buyPapers(papersForTesting);
        }

        bank.printStatistics();
        bank.updateStatistics();
        cout << "==== FINISH PROGRAM ====" << endl;
    }
}
