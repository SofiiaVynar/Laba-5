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

    double GetPrice() 
    {
        return price_;
    }
    void SetPrice(double price) 
    {
        price_ = price;
    }
    int GetNumberofpages() 
    {
        return numberofpages_;
    }
    string GetAuthor() 
    {
        return author_;
    }
    int GetQuantity() 
    {
        return quantity_;
    }
    int GetNumberofsales() 
    {
        return numberofsales_;
    }
    void SetNumberofsales(int numberofsales)
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
                if (books[j].GetPrice() < books[i].GetPrice())
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
            cout << books[i].GetAuthor() << " " << books[i].GetPrice() << endl;
        }
    }
    void NumberofsalesTop()
    {
        Book temp;
        for (int i = 0; i < 100; i++)
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (books[j].GetNumberofsales() < books[i].GetNumberofsales())
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
            cout << books[i].GetAuthor() << " " << books[i].GetNumberofsales() << endl;
        }
    }

    void AddBook(Book newBook) 
    {
        for (int i = 0; i < 100; i++)
        {
            if (books[i].GetAuthor() == "")
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
            if (books[i].GetAuthor() == newBook.GetAuthor() && books[i].GetNumberofpages() == newBook.GetNumberofpages() && books[i].GetNumberofsales() == newBook.GetNumberofsales()
                && books[i].GetPrice() == newBook.GetPrice() && books[i].GetQuantity() == newBook.GetQuantity())
            {
                books[i] = Book();
                return;
            }
        }	
    }
};
