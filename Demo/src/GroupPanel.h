#ifndef __GROUP_PANEL_H__
#define __GROUP_PANEL_H__

#include "Group.h"

class GroupPanel;
class GroupPanelMenu : public scv::ContextMenu {
public:
   ///////////////////////////////////////////////////////////
   GroupPanelMenu(GroupPanel *host);
   virtual ~GroupPanelMenu(void);
   ///////////////////////////////////////////////////////////

   virtual void onMenuAccessed(const std::deque<std::string> &address);
protected:
   GroupPanel *_host;
private:
};

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

class GroupPanel : public scv::Panel {
public:
   enum GroupType {HORIZONTAL, VERTICAL};

   ///////////////////////////////////////////////////////////
   GroupPanel(GroupType type);
   virtual ~GroupPanel(void);
   ///////////////////////////////////////////////////////////

   //Memory Management
   ///////////////////////////////////////////////////////////
   virtual void addChild(scv::Component *object);
   virtual void removeChild(scv::Component *object);
   ///////////////////////////////////////////////////////////

   virtual std::string getCode(void) = 0;

   virtual void display(void);

   virtual void applyColor(void) = 0;

protected:
   scv::Group *_verticalGroup, *_horizontalGroup;
private:
};

#endif //__GROUP_PANEL_H__