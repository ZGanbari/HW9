#ifndef TA_19_LEAFMENU_H
#define TA_19_LEAFMENU_H

#include <string>
#include "Menu.h"

class LeafMenu : public Menu{
public:
    LeafMenu(std::string name, Menu* parent);
    virtual void showSubMenus() const override;
    virtual void run() override;
    void showStudents();
    void  showProf();
    void  showCourse();

};


#endif //TA_19_LEAFMENU_H
