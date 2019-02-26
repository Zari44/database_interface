#include "TransactionStore.h"
#include "Database.h"





//virtual std::vector<Transaction> findTransactions(const std::string &accNo) = 0;


//virtual double calculateAverageAmount(const std::string &accNo) = 0;

/**
 * Sets list of all transactions (data source) to be used by other methods.
 */
//virtual void setTransactions(const std::vector<Transaction> &transactions) = 0;

/**
 * Finds one transaction by its account number and transaction id.
 * If there are duplicates (by accNo, txNo) returns first matching.
 *
 * Throws exception if not found.
 */
Transaction TransactionStore::findTransaction(const std::string &accNo, int txNo) {

    if (transactions_hashed.count(accNo) == 0)
        throw std::exception();

    if (transactions_hashed[accNo].count(txNo) == 0)
        throw std::exception();

    return transactions_hashed[accNo][txNo];
}

/**
 * Finds all transactions with given account number.
 * Transactions are sorted by txNo without duplicates (same accNo, txNo).
 */
std::vector<Transaction> TransactionStore::findTransactions(const std::string &accNo) {

    std::vector<Transaction> transactions;

    for (const auto& trans_map : transactions_hashed[accNo]){
        transactions.push_back(trans_map.second);
    }

    return transactions;
}

/**
 * Calculates average amount of all transactions with given account number.
 */

double TransactionStore::calculateAverageAmount(const std::string &accNo) {

    int no_transactions = transactions_hashed.count(accNo);

    if (!no_transactions)
        return 0.0;

    double total_amount = 0.0;

    for (const auto& trans : transactions_hashed[accNo]) {
        total_amount += trans.second.amount;
    }

    return static_cast<double>(total_amount / no_transactions);
}

void TransactionStore::setTransactions(const std::vector<Transaction> &transactions) {

    for (const auto& trans : transactions) {
        transactions_hashed[trans.accNo][trans.txNo] = trans;
    }

}


