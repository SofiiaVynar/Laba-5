#include <iostream>
using namespace std;

class Book
{
private:

    double price_;
    int numberOfPages_;
    string author_;
    int quantity_;
    int numberOfSales_;

public:
    Book() {}
    Book(double price,int numberOfPages,string author,int quantity,int numberOfSales)
    {
        price_ = price;
        numberOfPages_ = numberOfPages;
        author_ = author;
        quantity_ = quantity;
        numberOfSales_ = numberOfSales;
    }

    double GetPrice() 
    {
        return price_;
    }
    void SetPrice(double price) 
    {
        price_ = price;
    }
    int GetNumberOfpages() 
    {
        return numberOfPages_;
    }
    string GetAuthor() 
    {
        return author_;
    }
    int GetQuantity() 
    {
        return quantity_;
    }
    int GetNumberOfSales() 
    {
        return numberOfSales_;
    }
    void SetNumberOfSales(int numberOfSales)
    {
        numberOfSales_ = numberOfSales;
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
    void NumberOfSalesTop()
    {
        Book temp;
        for (int i = 0; i < 100; i++)
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (books[j].GetNumberOfSales() < books[i].GetNumberOfSales())
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
            cout << books[i].GetAuthor() << " " << books[i].GetNumberOfSales() << endl;
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
            if (books[i].GetAuthor() == newBook.GetAuthor() && books[i].GetNumberOfpages() == newBook.GetNumberOfpages() && books[i].GetNumberOfSales() == newBook.GetNumberOfSales()
                && books[i].GetPrice() == newBook.GetPrice() && books[i].GetQuantity() == newBook.GetQuantity())
            {
                books[i] = Book();
                return;
            }
        }	
    }
};
