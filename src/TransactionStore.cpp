#include "TransactionStore.h"
#include "Database.h"


Transaction TransactionStore::findTransaction(const std::string &accNo, int txNo) {
    return transactions[0];
}

std::vector<Transaction> TransactionStore::findTransactions(const std::string &accNo) {
    return {transactions[0]};
}

double TransactionStore::calculateAverageAmount(const std::string &accNo) {
    return 0.0;
}

void TransactionStore::setTransactions(const std::vector<Transaction> &transactions) {
    this->transactions = transactions;
}


