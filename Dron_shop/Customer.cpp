#include "Customer.h"

Options Customer::Options = {};


string Customer::MostPopularmakedron()
{
    int max_count = 0, max_idx = 0;
    for (int i = 1; i < Options.GetSize(); i++)
    {
        int counter = count(Options.GetIteratorToBegin(), Options.GetIteratorToEnd(), Options[i]);
        if (counter > max_count)
        {
            max_count = counter;
            max_idx = i;
        }
    }

    return Options.GetDronmake(max_idx);
}

string Customer::mostPopularmodeldron()
{
    int max_count = 0, max_idx = 0;
    for (int i = 1; i < Options.GetSize(); i++)
    {
        int counter = count(Options.GetIteratorToBegin(), Options.GetIteratorToEnd(), Options[i]);
        if (counter > max_count)
        {
            max_count = counter;
            max_idx = i;
        }
    }

    return Options.GetDronModel(max_idx);
}

double Customer::GetTheLeastPrice()
{
    double min_price = Options.GetDronPrice(0);
    int min_idx = 0;

    for (int i = 0; i < Options.GetSize(); i++)
    {
        if (Options.GetDronPrice(i) < min_price)
        {
            min_price = Options.GetDronPrice(i);
            min_idx = i;
        }
    }
    return Options.GetDronPrice(min_idx);
}

double Customer::GetTheMostPrice()
{
    double max_price = Options.GetDronPrice(0);
    int max_idx = 0;

    for (int i = 0; i < Options.GetSize(); i++)
    {
        if (Options.GetDronPrice(i) > max_price)
        {
            max_price = Options.GetDronPrice(i);
            max_idx = i;
        }
    }
    return Options.GetDronPrice(max_idx);
}