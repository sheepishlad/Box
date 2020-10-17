/*
Name: ALBERT JOSHUA CANICOSA
Seneca Email: ajcanicosa@myseneca.ca
StudentID: 144404191
Date: 13 OCT 2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Box.h"

using namespace std;

namespace sdds
{
	

	void Box::setName(const char* Cstr) {
		if (Cstr != nullptr) {
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	void Box::setUnusable() {

		m_contentName = nullptr;
		m_width = -1;
		m_height = -1;
		m_length = -1;
		m_contentVolume = -1;
	}

	bool Box::isUnusable()const {
		if (m_width == -1 || m_height == -1 || m_length == -1 ||
			m_contentVolume == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Box::hasContent()const {
		if (quantity() > 0) {
			return true;
		}
		else {
			return false;
		}

	}

	Box::Box() {

		m_contentName = nullptr;
		m_width = 12;
		m_height = 12;
		m_length = 12;
		m_contentVolume = 0;
	}
	Box::Box(int sideLength, const char* contentName) {
		m_contentName = nullptr;
		if (sideLength < 5 || sideLength > 36) {
			setUnusable();
		}

		else {
			m_width = sideLength;
			m_height = sideLength;
			m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
	}


	Box::Box(int width, int height, int length, const char* contentName) {
		m_contentName = nullptr;
		if (width < 5 || width > 36 || length < 5 || length > 36 || height < 5 || height > 36) {
			setUnusable();
		}

		else {
			m_width = width;
			m_height = height;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}
	}


	int Box::capacity()const {
		int volume = 0;

		volume = m_width * m_length * m_height;

	
		return volume;

	}

	int Box::quantity()const {
		
		return m_contentVolume;
	}


	Box& Box::setContent(const char* contentName) {
		if (hasContent() && m_contentName != nullptr) {
			setUnusable();
		}
		else {
			setName(contentName);
		}
		return *this;
	}

	std::ostream& Box::display()const {
		if (isUnusable() == false) {
			cout.width(30);
			cout.setf(ios::left);
			cout.fill('.');
			if (m_contentName == nullptr)
			{
				cout << "Empty box" << " ";
			}
			else {
				cout << m_contentName << " ";
			}
			cout << " ";
			cout.unsetf(ios::left);
			cout.width(2);
			cout.fill('0');
			cout << m_width << "x";
			cout.width(2);
			cout.fill('0');
			cout << m_height << "x";
			cout.width(2);
			cout.fill('0');
			cout << m_length << " ";
			cout << " ";
			cout.width(6);
			cout.setf(ios::right);
			cout.fill(' ');
			cout << quantity() << "/";
			cout << capacity() << " ";
			cout<< "C.I.";
			cout.unsetf(ios::right);
		}
		else {
			cout << "Unusable box, discard the content, and recycle.";
		}

		return cout;
	}

	Box& Box::add(int quantity) {

		if (quantity > 0 && capacity() >= quantity + this->quantity()) {
			m_contentVolume += quantity;
		}
		else {
			setUnusable();
		}
		return *this;
	}

	Box& Box::add(Box& B) {
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}

	Box::~Box()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}
}