/*
    ==================================================
    Mile Stone 5.1
    ==================================================
    Name   : Kojo Anyane Obese
    ID     : 137653226
    Email  : kaobese@myseneca.ca
    Section: NHH
    Date   : 2023/12/09
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#include "Item.h"
#include "Date.h"

using namespace std;

namespace sdds
{

    class Perishable : public Item
    {

    private:
        char *p_instructions;
        Date p_expiry;

    public:
        // Default constructor
        Perishable();

        // Rule of three: Destructor, Copy Constructor, Copy Assignment Operator
        ~Perishable();
        Perishable(const Perishable &other);
        Perishable &operator=(const Perishable &other);

        // Constant query for expiry date
        const Date &expiry() const;

        // Virtual overrides
        virtual ostream &display(ostream &ostr) const override;
        virtual ofstream &save(ofstream &ofstr) const override;
        virtual ifstream &load(ifstream &ifstr) override;
        virtual istream &read(istream &istr) override;
        virtual int readSku(istream &istr) override;

    private:
        // Helper function to safely deallocate memory
        void clear();
    };
}
