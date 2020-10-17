/*
Name: ALBERT JOSHUA CANICOSA
Seneca Email: ajcanicosa@myseneca.ca
StudentID: 144404191
Date: 13 OCT 2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOX_H_
#define SDDS_BOX_H_
#include <iostream>
using namespace std;

namespace sdds
{
    class Box
    {
        char* m_contentName;
        int m_width;
        int m_height;
        int m_length;
        int m_contentVolume;

        void setName(const char* Cstr);
        void setUnusable();
        bool isUnusable()const;
        bool hasContent()const;

      

    public:
        Box();
        Box(int sideLength, const char* contentName = nullptr);
        Box(int width, int height, int length, const char* contentName = nullptr);
        ~Box();
        int capacity()const;
        int quantity()const;
        Box& setContent(const char* contentName);
        std::ostream& display()const;
        Box& add(int quantity);
        Box& add(Box& B);

    };
}

#endif