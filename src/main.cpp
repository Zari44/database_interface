#include <iostream>
#include "gtest/gtest.h"

using namespace std;

//Celem zadania jest implementacja interfejsu Database wraz z zestawem testów.
//W projekcie znajduje się przykładowa (błędna) implementacja interfejsu (TransactionStore) wraz z przykładowym zestawem testów (niekompletnych) (Tests.cpp)
//Projekt buduje się z użyciem CMake’a i korzysta z Google Test. Implementacja może korzystać (ale nie jest to wymagane) z funkcjonalności C++11/14.
//Ocenie będą podlegać następujące elementy:
//    Implementacja interfejsu oraz testów
//    Poprawność działania (dostarczona implementacja zostanie przetestowana na pełnym zestawie testów)
//    Czytelność kodu, złożoność, wydajność
//    Sposób
//Sposób uruchomienia:
//    cd TxStore
//    mkdir build && cd build
//    cmake ../
//    make
//    ./txstore
//W razie potrzeby można dostosować konfigurację projektu do toolchainu na swojej platformie.

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
