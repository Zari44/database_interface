
#ifndef INTERVIEW_TRANSACTIONSTORE_H
#define INTERVIEW_TRANSACTIONSTORE_H

#include "Database.h"
#include <unordered_map>
#include <map>


class TransactionStore : public Database {
public:
    std::vector<Transaction> findTransactions(const std::string &accNo) override;
    Transaction findTransaction(const std::string &accNo, int txNo) override;
    double calculateAverageAmount(const std::string &accNo) override;
    void setTransactions(const std::vector<Transaction> &transactions) override;
private:
//    std::vector<Transaction> transactions;
    std::unordered_map<std::string, std::map<unsigned int, Transaction> > transactions_hashed;
};

#endif //INTERVIEW_TRANSACTIONSTORE_H
