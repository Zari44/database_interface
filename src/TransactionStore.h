
#ifndef INTERVIEW_TRANSACTIONSTORE_H
#define INTERVIEW_TRANSACTIONSTORE_H

#include "Database.h"
#include <unordered_map>
#include <map>

class NoAccountNumberException : public std::runtime_error {
public:
  NoAccountNumberException() :
  std::runtime_error("Error! No account number found in database"){

  }
};

class NoTransactionNumberException : public std::runtime_error {
public:
  NoTransactionNumberException() :
  std::runtime_error("Error! No transaction number found in database"){
  }
};

class TransactionStore : public Database {
public:
    std::vector<Transaction> findTransactions(const std::string &accNo) override;
    Transaction findTransaction(const std::string &accNo, int txNo) override;
    double calculateAverageAmount(const std::string &accNo) override;
    void setTransactions(const std::vector<Transaction> &transactions) override;
private:
    std::unordered_map<std::string, std::map<unsigned int, double> > hashed_transactions;
};

#endif //INTERVIEW_TRANSACTIONSTORE_H
