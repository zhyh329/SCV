#ifndef __PALLETE_H__
#define __PALLETE_H__

class ButtonPallete :public scv::Button {
public:
   ///////////////////////////////////////////////////////////
   ButtonPallete(const scv::Point &p, const std::string &str);
   virtual ~ButtonPallete(void);
   ///////////////////////////////////////////////////////////

   void onMouseClick(const scv::MouseEvent &evt);
};

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

class PanelPalleteComponents : public scv::Panel {
public:
   ///////////////////////////////////////////////////////////
   PanelPalleteComponents(std::string title, const scv::Point &p1, const scv::Point &p2);
   virtual ~PanelPalleteComponents(void);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual void addComponent(std::string name);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   void adjustButtonsWidth(void);
   ///////////////////////////////////////////////////////////

protected:
   void adjustButtons(void);
   bool valid(int componentsPerLine);

   static const int s_defaultGap = 5;
   int _componentsPerLine;
   bool _widthSet;
};

#endif //__PALLETE_H__