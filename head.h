#include <iostream>
using namespace std;

class Book
{
private:

    double price_;
    int numberofpages_;
    string author_;
    int quantity_;
    int numberofsales_;

public:
    Book() {}
    Book(double price,int numberofpages,string author,int quantity,int numberofsales)
    {
        price_ = price;
        numberofpages_ = numberofpages;
        author_ = author;
        quantity_ = quantity;
        numberofsales_ = numberofsales;
    }

    double getPrice() 
    {
        return price_;
    }
    void setPrice(double price) 
    {
        price_ = price;
    }
    int getNumberofpages() 
    {
        return numberofpages_;
    }
    string getAuthor() 
    {
        return author_;
    }
    int getQuantity() 
    {
        return quantity_;
    }
    int getNumberofsales() 
    {
        return numberofsales_;
    }
    void getNumberofsales(int numberofsales)
    {
        numberofsales_ = numberofsales;
    }
};

class BookShop
{
public:
    Book books[100];

    void PriceTop()
    {
        Book temp;
        for (int i = 0; i < 100; i++)
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (books[j].getPrice() < books[i].getPrice())
                {
                    temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        };

        cout << "Top 3 prices:"  << endl;
        for (int i = 99; i > 96; i--)
        {
            cout << books[i].getAuthor() << " " << books[i].getPrice() << endl;
        }
    }
    void NumberofsalesTop()
    {
        Book temp;
        for (int i = 0; i < 100; i++)
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (books[j].getNumberofsales() < books[i].getNumberofsales())
                {
                    temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        };

        cout << "\nTop 3 Numbers of sales:" << endl;
        for (int i = 99; i > 96; i--)
        {
            cout << books[i].getAuthor() << " " << books[i].getNumberofsales() << endl;
        }
    }

    void AddBook(Book newBook) 
    {
        for (int i = 0; i < 100; i++)
        {
            if (books[i].getAuthor() == "")
            {
                books[i] = newBook;
                return;
            }
        }
    }
    void DeleteBook(Book newBook)
    {
        for (int i = 0; i < 100; i++)
        {
            if (books[i].getAuthor() == newBook.getAuthor() && books[i].getNumberofpages() == newBook.getNumberofpages() && books[i].getNumberofsales() == newBook.getNumberofsales()
                && books[i].getPrice() == newBook.getPrice() && books[i].getQuantity() == newBook.getQuantity())
            {
                books[i] = Book();
                return;
            }
        }	
    }
};
