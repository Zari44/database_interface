#include <gtest/gtest.h>
#include "TransactionStore.h"

static std::vector<Transaction> transactions =
        {
                {"35102049000000990200522828", 3517, 3517.00},
                {"35102049000000990200522828", 3515, 3515.00},
                {"6102055610000330200008862",  6103, 6103.00},
                {"56102055610000310200008433", 5610, 5610.00},
                {"56102055610000310200008433", 5610, 5610.00},
                {"56102055610000310200008433", 5611, 5611.00},
                {"4830600000000200003900",     4830, 4830.00},
                {"7230600000000200006669",     7239, 7239.00},
                {"7230600000000200006669",     7238, 7238.00},
                {"7230600000000200006669",     7237, 7237.00},
                {"7230600000000200006669",     7236, 7236.00},
                {"7230600000000200006669",     7235, 7235.00},
                {"7230600000000200006669",     7234, 7234.00},
                {"7230600000000200006669",     7234, 7234.00},
                {"50102055581111101998100048", 501,  501.00},
                {"50102055581111101998100048", 503,  503.00},
                {"50102055581111101998100048", 501,  501.00},
                {"50102055581111101998100050", 1,   -100.00},
                {"50102055581111101998100050", 2,    200.00},
        };


TEST(txTests, findTransaction) {
    Database *db = new TransactionStore();
    db->setTransactions(transactions);

    Transaction transaction = db->findTransaction("56102055610000310200008433", 5611);

    EXPECT_EQ(5611.00, transaction.amount);
    EXPECT_ANY_THROW(db->findTransaction("invalid", 0));
}

TEST(txTests, findTransactions) {
    Database *db = new TransactionStore();
    db->setTransactions(transactions);
    auto t = db->findTransactions("35102049000000990200522828");

    EXPECT_EQ(2, t.size());
    EXPECT_EQ(3515, t[0].txNo);
    EXPECT_EQ(3517, t[1].txNo);

    auto t2 = db->findTransactions("56102055610000310200008433");
    EXPECT_EQ(2, t2.size());
    EXPECT_EQ(5610, t2[0].txNo);
    EXPECT_EQ(5611, t2[1].txNo);

    // when no account number in database return empty vector
    auto t3 = db->findTransactions("invalid");
    EXPECT_EQ(0, t3.size());
}

// check for requirement of throwing exceptions
TEST(txTests, findTransactionIsThrownException){
    Database *db = new TransactionStore();
    db->setTransactions(transactions);
    EXPECT_THROW(
        auto t1 = db->findTransaction("invalid", 5611),
        NoAccountNumberException
    );

    EXPECT_THROW(
        auto t2 = db->findTransaction("35102049000000990200522828", 0),
        NoTransactionNumberException
    );
}

TEST(txTests, calculateAverageAmount) {
    Database *db = new TransactionStore();
    db->setTransactions(transactions);

    double avg1 = db->calculateAverageAmount("7230600000000200006669");
    EXPECT_EQ(723650, (int)(avg1 * 100));

    // no account number found
    double avg2 = db->calculateAverageAmount("invalid");
    EXPECT_EQ(0, (int)(avg2 * 100));

    // negative number
    double avg3 = db->calculateAverageAmount("50102055581111101998100050");
    EXPECT_EQ(5000, (int)(avg3 * 100));
}






