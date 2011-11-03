#ifndef __SCV_PANEL_INTERFACE_H__
#define __SCV_PANEL_INTERFACE_H__

#include "ComponentWithTexture.h"

namespace scv {

class GroupLayout;

class Panel : public ComponentWithTexture {
public:
   ///////////////////////////////////////////////////////////
   Panel(const scv::Point &p1, const scv::Point &p2);
   virtual ~Panel(void);
   ///////////////////////////////////////////////////////////

   //SCVCallbacks
   ///////////////////////////////////////////////////////////
   virtual void onMouseClick(const scv::MouseEvent &evt);
   virtual void onMouseHold (const scv::MouseEvent &evt);
   virtual void onMouseOver (const scv::MouseEvent &evt);
   virtual void onMouseUp   (const scv::MouseEvent &evt);
   virtual void onMouseWheel(const scv::MouseEvent &evt);

   virtual void onKeyPressed(const scv::KeyEvent &evt);
   virtual void onKeyUp     (const scv::KeyEvent &evt);

   virtual void onSizeChange(void);
   virtual void onPositionChange(void);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   void processMouse(const scv::MouseEvent &evt);
   void processKey(const scv::KeyEvent &evt);
   ///////////////////////////////////////////////////////////

   virtual void display(void);

   ///////////////////////////////////////////////////////////
   virtual Point getMinimumSize(void) const;
   virtual Point getPreferredSize(void) const;
   virtual Point getMaximumSize(void) const;
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual inline void setLayout(GroupLayout *layout);
   virtual inline bool isLeftToRight(void);
   ///////////////////////////////////////////////////////////

   //Memory Management
   ///////////////////////////////////////////////////////////
   virtual void addChild(Component *object);
   virtual void removeChild(Component *object);
   ///////////////////////////////////////////////////////////

protected:
   GroupLayout *_layout;
   bool _leftToRight;

   virtual void createTexture(void);
};

///////////////////////////////////////////////////////////
void Panel::setLayout(GroupLayout *layout) {
   _layout = layout;
}

bool Panel::isLeftToRight(void) {
   return _leftToRight;
}
///////////////////////////////////////////////////////////

} // namespace scv

#endif // __SCV_PANEL_INTERFACE_H__
