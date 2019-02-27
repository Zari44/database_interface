#ifndef TXSTORE_STORAGE_H
#define TXSTORE_STORAGE_H

#include <string>
#include <vector>


//NOTE: I would use fixed point precision for amount because it double precision
//      might cause problems because its representation.
struct Transaction {
    std::string accNo; // account number, not empty, 32 alphanum
    unsigned int txNo; // transaction number >= 0
    double amount;     // amount associated with this transaction, e.g 12.43 (two digits of precision)
};

class Database {
public:
    /**
     * Finds one transaction by its account number and transaction id.
     * If there are duplicates (by accNo, txNo) returns first matching.
     *
     * Throws exception if not found.
     */
    virtual Transaction findTransaction(const std::string &accNo, int txNo) = 0;

    /**
     * Finds all transactions with given account number.
     * Transactions are sorted by txNo without duplicates (same accNo, txNo).
     */
    virtual std::vector<Transaction> findTransactions(const std::string &accNo) = 0;

    /**
     * Calculates average amount of all transactions with given account number.
     */
    virtual double calculateAverageAmount(const std::string &accNo) = 0;

    /**
     * Sets list of all transactions (data source) to be used by other methods.
     */
    virtual void setTransactions(const std::vector<Transaction> &transactions) = 0;
};


#endif //TXSTORE_STORAGE_H
