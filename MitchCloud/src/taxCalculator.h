//------------------------------------------------------------------
//System Name: MitchCloud
//Artifact Name: taxCalculator.h
//Create Date: Nov, 30 2017
//Author: Aaron Liszt
//Version: 1.0
//------------------------------------------------------------------

#ifndef TAXCALCULATOR
#define TAXCALCULATOR

#include <string>
#include <cmath>

class taxCalculator{
public:
        taxCalculator() { tax = .0575; }
        double giveTax(double c){ double taxTotal = c + (c * tax); taxTotal = floor(taxTotal*100+.5)/100; return taxTotal; } //Total cost C + 5.75% tax
private:
        double tax;	
};

#endif

