#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
	const int MAX_MENU = 15;
    class Menu {
        char* menuContent;
        int numOfOption;

        void setEmpty();
    public:
        Menu(const char* menu);
        int run() const;
        const char* getMenuContent() const;
        int getNumOfOpt() const;
        Menu& operator=(int num);
        Menu& operator=(const char* menu);
        Menu& clear();
        bool isValid() const;
        ~Menu();
    };

}

#endif // SDDS_MENU_H
