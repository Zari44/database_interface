
#ifndef INTERVIEW_TRANSACTIONSTORE_H
#define INTERVIEW_TRANSACTIONSTORE_H

#include "Database.h"

class TransactionStore : public Database {
public:
    std::vector<Transaction> findTransactions(const std::string &accNo) override;
    Transaction findTransaction(const std::string &accNo, int txNo) override;
    double calculateAverageAmount(const std::string &accNo) override;
    void setTransactions(const std::vector<Transaction> &transactions) override;
private:
    std::vector<Transaction> transactions;
};

#endif //INTERVIEW_TRANSACTIONSTORE_H
