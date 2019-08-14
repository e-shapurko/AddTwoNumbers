#include <iostream>
#include <list>
#include <cstring>
#include <iterator>

using namespace std;

void intToReversList(int _number, std::list<int> & _listNumbers)
{
    int reminde;
    do
    {
        reminde = _number % 10;
        _listNumbers.push_back(reminde);
        _number = (_number - reminde)/10;
    }while (_number != 0);
}

std::list<int> sumLists(std::list<int> & firstMemberList, std::list<int> & secondMemberList)
//std::list<int> sumLists(std::list<int> & firstMember, std::list<int> & secondMember)
{
    int firstMember = 0;
    int secondMember = 0;
    int Multiply = 1;

    for (std::list<int>::iterator it = firstMemberList.begin();
         it != firstMemberList.end(); it++)
    {
        firstMember += (*it) * Multiply;
        Multiply *=  10;
    }
    Multiply = 1;
    for (std::list<int>::iterator it = secondMemberList.begin();
         it != secondMemberList.end(); it++)
    {
        secondMember += (*it) * Multiply;
        Multiply *=  10;
    }

    firstMember += secondMember;

    std::list<int> res;

    intToReversList(firstMember, res);

    return res;
}

int main()
{
    std::list<int> listNumber1;
    std::list<int> listNumber2;
    std::list<int> listRes;
    uint i;
//    std::cin >> i;
    i = 123;
    intToReversList(i, listNumber1);
//    std::cin >> i;
    i = 456;
    intToReversList(i, listNumber2);

    listRes = sumLists(listNumber1, listNumber2);

    for (std::list<int>::iterator it = listRes.begin();
         it != listRes.end(); it++)
    {
        std::cout << *it;
    }

    std::cout << std::endl;
    return 0;
}
