#include <iostream>
#include "head.h"
using namespace std;


int main()
{
    BookShop bookShop1 = BookShop();

    bookShop1.books[0] = Book(200,150,"Roahld Dahl",15,280);
    bookShop1.books[1] = Book(299, 300, "Ivan Drach", 100, 1000);
    bookShop1.books[2] = Book(50, 40, "Dmytro Pavlychko", 5, 28);
    bookShop1.books[3] = Book(1000, 123, "Vasyl Symonenko", 90, 900);
    bookShop1.books[4] = Book(899, 900, "Lina Kostenko", 1, 18000);

    bookShop1.AddBook(Book(1020, 123, "Vasyl Stus", 90, 901));
    bookShop1.DeleteBook(Book(299, 300, "Ivan Drach", 100, 1100));

    bookShop1.PriceTop();
    bookShop1.NumberOfSalesTop();


    return 0;
}
