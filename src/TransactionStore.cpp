#include "TransactionStore.h"
#include "Database.h"


/**
 * Finds one transaction by its account number and transaction id.
 * If there are duplicates (by accNo, txNo) returns first matching.
 *
 * Throws exception if not found.
 *
 * NOTE: txNo - suoldn't it be unsigned int?
 * Exceptions: probably a new exception type that inherits from, for example, "runtime_error"
 */
Transaction TransactionStore::findTransaction(const std::string &accNo, int txNo) {

    if (hashed_transactions.count(accNo) == 0)
        throw NoAccountNumberException();

    if (hashed_transactions[accNo].count(txNo) == 0)
        throw NoTransactionNumberException();

    Transaction transaction;
    transaction.accNo = accNo;
    transaction.txNo = txNo;
    transaction.amount = hashed_transactions[accNo][txNo];

    return transaction;
}

/**
 * Finds all transactions with given account number.
 * Transactions are sorted by txNo without duplicates (same accNo, txNo).
 *unsigned
 * NOTE:
 * If no transactions found just empty vector is returned (no exception throwing is neccessary).
 * Maybe for cleanliness Transaction could have three-argument constructor defined.
 */
std::vector<Transaction> TransactionStore::findTransactions(const std::string &accNo) {

    std::vector<Transaction> transactions;

    for (const auto& trans_map : hashed_transactions[accNo]) {
        Transaction transaction;
        transaction.accNo = accNo;
        transaction.txNo = trans_map.first;
        transaction.amount = trans_map.second;
        transactions.push_back(transaction);
    }

    return transactions;
}

/**
 * Calculates average amount of all transactions with given account number.
 */

double TransactionStore::calculateAverageAmount(const std::string &accNo) {

    unsigned int no_transactions = hashed_transactions[accNo].size();

    if (!no_transactions)
        return 0.0;

    double total_amount = 0.0;

    for (const auto& transaction_map : hashed_transactions[accNo]) {
        total_amount += transaction_map.second;
    }

    return total_amount / static_cast<double>(no_transactions);
}


/**
 * Sets list of all transactions (data source) to be used by other methods.
 *
 * NOTE:
 * if account number was mentioned to be 32-chars long alphanum string;
 * in my opinion, to avoid errors, all numbers that are shorter than 32
 * should have leadning zeros added
 */

void TransactionStore::setTransactions(const std::vector<Transaction> &transactions) {

    for (const auto& trans : transactions) {
        hashed_transactions[trans.accNo][trans.txNo] = trans.amount;
    }
}


